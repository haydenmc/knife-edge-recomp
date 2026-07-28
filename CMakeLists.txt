cmake_minimum_required(VERSION 3.20)

# Knife Edge Recompiled — top-level build for the PC port.
#
# This is a build-system *skeleton*: it wires together the vendored N64Recomp
# runtime (ultramodern + librecomp) and RT64 renderer, and produces a
# KnifeEdgeRecompiled executable that links and runs even before any game
# code has been recompiled from the ROM. See analysis/docs/build-notes.md for
# how this was put together and what's still open.

if (APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "Minimum OS X deployment version")
endif()

project(KnifeEdgeRecompiled LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (APPLE)
    enable_language(OBJC OBJCXX)
endif()

# ---------------------------------------------------------------------------
# Prebuilt host tools (N64Recomp / RSPRecomp)
# ---------------------------------------------------------------------------
# These are built out-of-band today (see deps/N64Recomp/build/, produced by
# the devcontainer bootstrap) rather than as part of this configure. They're
# imported here by path so future custom commands (running N64Recomp on a
# config.toml to regenerate RecompiledFuncs/) have a real CMake target to
# depend on.
#
# TODO(superbuild): once the ROM -> C recompilation step is driven from this
# CMake project instead of a manual script invocation, replace this
# IMPORTED-by-path shim with an add_subdirectory/ExternalProject_Add of
# deps/N64Recomp itself so a clean checkout doesn't need a side-channel build.
set(N64RECOMP_HOST_TOOL "${CMAKE_SOURCE_DIR}/deps/N64Recomp/build/N64Recomp" CACHE FILEPATH
    "Path to the prebuilt N64Recomp host tool binary (deps/N64Recomp/build/N64Recomp)")
set(RSPRECOMP_HOST_TOOL "${CMAKE_SOURCE_DIR}/deps/N64Recomp/build/RSPRecomp" CACHE FILEPATH
    "Path to the prebuilt RSPRecomp host tool binary (deps/N64Recomp/build/RSPRecomp)")

if (EXISTS "${N64RECOMP_HOST_TOOL}")
    add_executable(N64RecompHostTool IMPORTED GLOBAL)
    set_target_properties(N64RecompHostTool PROPERTIES IMPORTED_LOCATION "${N64RECOMP_HOST_TOOL}")
    message(STATUS "Knife Edge: found prebuilt N64Recomp host tool at ${N64RECOMP_HOST_TOOL}")
else()
    message(STATUS "Knife Edge: prebuilt N64Recomp host tool NOT found at ${N64RECOMP_HOST_TOOL} "
                    "(build deps/N64Recomp first, see analysis/docs/build-notes.md)")
endif()

if (EXISTS "${RSPRECOMP_HOST_TOOL}")
    add_executable(RSPRecompHostTool IMPORTED GLOBAL)
    set_target_properties(RSPRecompHostTool PROPERTIES IMPORTED_LOCATION "${RSPRECOMP_HOST_TOOL}")
endif()

# ---------------------------------------------------------------------------
# Generated-code switch
# ---------------------------------------------------------------------------
# KE_GENERATED_DIR should point at an N64Recomp output directory containing
# RecompiledFuncs/*.c (or *.cpp), recomp_overlays.inl and funcs.h (see
# analysis/docs/n64recomp-formats.md). When it's unset, src/stub_game/ is
# compiled instead so KnifeEdgeRecompiled still links and runs (it just has
# no game code to boot into yet).
set(KE_GENERATED_DIR "" CACHE PATH
    "Directory of N64Recomp output (RecompiledFuncs/*.c + recomp_overlays.inl + funcs.h). Leave empty to build against src/stub_game/ instead.")

# Recompiler output is a build artifact and is NOT committed (see .gitignore).
# Point KE_ROM at a Knife Edge (USA) ROM and the build regenerates it for you:
# byteswap/verify the ROM, run the analysis pipeline, then N64Recomp + RSPRecomp.
# Without a ROM the build falls back to KE_GENERATED_DIR, then to src/stub_game/.
set(KE_ROM "" CACHE FILEPATH
    "Path to a Knife Edge (USA) ROM (.z64/.v64/.n64). When set, the recompiled game code is generated at configure time.")

if (KE_ROM)
    if (NOT EXISTS "${KE_ROM}")
        message(FATAL_ERROR "KE_ROM is set to '${KE_ROM}' but that file does not exist.")
    endif()
    if (NOT EXISTS "${N64RECOMP_HOST_TOOL}")
        message(FATAL_ERROR
            "KE_ROM is set but the N64Recomp host tool is missing at ${N64RECOMP_HOST_TOOL}.\n"
            "Build it first: cmake -S deps/N64Recomp -B deps/N64Recomp/build -G Ninja "
            "-DCMAKE_BUILD_TYPE=Release && cmake --build deps/N64Recomp/build")
    endif()

    # The analysis pipeline needs tomlkit/rabbitizer. Prefer the project venv
    # (created by the devcontainer's postCreateCommand) over the system python.
    if (EXISTS "${CMAKE_SOURCE_DIR}/.venv/bin/python")
        set(KE_PYTHON "${CMAKE_SOURCE_DIR}/.venv/bin/python")
    else()
        find_program(KE_PYTHON NAMES python3 python REQUIRED)
    endif()
    execute_process(COMMAND "${KE_PYTHON}" -c "import tomlkit, rabbitizer"
                    RESULT_VARIABLE KE_PYDEPS_RESULT ERROR_QUIET)
    if (NOT KE_PYDEPS_RESULT EQUAL 0)
        message(FATAL_ERROR
            "KE_ROM is set but ${KE_PYTHON} is missing the analysis dependencies.\n"
            "Install them, e.g.: python3 -m venv .venv && .venv/bin/pip install rabbitizer capstone tomlkit")
    endif()
    set(KE_ROM_Z64 "${CMAKE_BINARY_DIR}/knife_edge.z64")
    set(KE_REGEN_DIR "${CMAKE_BINARY_DIR}/generated")

    # Configure-time so the glob below sees the results. The analysis pipeline
    # is deterministic, so re-running is idempotent; it is skipped when the
    # normalized ROM and the recompiled output are already present and newer.
    if (NOT EXISTS "${KE_ROM_Z64}")
        message(STATUS "Knife Edge: normalizing ROM -> ${KE_ROM_Z64}")
        execute_process(
            COMMAND "${KE_PYTHON}" "${CMAKE_SOURCE_DIR}/analysis/byteswap.py" "${KE_ROM}" "${KE_ROM_Z64}"
            RESULT_VARIABLE KE_BYTESWAP_RESULT
            OUTPUT_VARIABLE KE_BYTESWAP_OUTPUT
            ERROR_VARIABLE KE_BYTESWAP_OUTPUT)
        if (NOT KE_BYTESWAP_RESULT EQUAL 0)
            message(FATAL_ERROR "ROM ingest failed:\n${KE_BYTESWAP_OUTPUT}")
        endif()
    endif()

    if (NOT EXISTS "${KE_REGEN_DIR}/funcs.h")
        message(STATUS "Knife Edge: recompiling game code (this takes a minute)")
        file(MAKE_DIRECTORY "${KE_REGEN_DIR}")
        execute_process(
            COMMAND "${KE_PYTHON}" "${CMAKE_SOURCE_DIR}/analysis/gen_syms.py" -q
                    --rom-path "${KE_ROM_Z64}" --output-func-path "${KE_REGEN_DIR}"
            RESULT_VARIABLE KE_GENSYMS_RESULT
            ERROR_VARIABLE KE_GENSYMS_OUTPUT)
        if (NOT KE_GENSYMS_RESULT EQUAL 0)
            message(FATAL_ERROR "gen_syms.py failed:\n${KE_GENSYMS_OUTPUT}")
        endif()
        execute_process(
            COMMAND "${N64RECOMP_HOST_TOOL}" "${CMAKE_SOURCE_DIR}/config/knife_edge.us.toml"
            RESULT_VARIABLE KE_RECOMP_RESULT
            OUTPUT_VARIABLE KE_RECOMP_OUTPUT
            ERROR_VARIABLE KE_RECOMP_OUTPUT)
        if (NOT KE_RECOMP_RESULT EQUAL 0)
            message(FATAL_ERROR "N64Recomp failed:\n${KE_RECOMP_OUTPUT}")
        endif()
        if (EXISTS "${RSPRECOMP_HOST_TOOL}" AND EXISTS "${CMAKE_SOURCE_DIR}/config/aspMain.us.toml")
            file(MAKE_DIRECTORY "${KE_REGEN_DIR}/rsp")
            # config/aspMain.us.toml carries paths relative to config/ for the
            # `make -C analysis` workflow. Write a copy pointing at this build
            # tree instead of editing the checked-in config.
            file(READ "${CMAKE_SOURCE_DIR}/config/aspMain.us.toml" KE_RSP_CFG)
            string(REGEX REPLACE "rom_file_path[ ]*=[ ]*\"[^\"]*\""
                   "rom_file_path = \"${KE_ROM_Z64}\"" KE_RSP_CFG "${KE_RSP_CFG}")
            string(REGEX REPLACE "output_file_path[ ]*=[ ]*\"[^\"]*\""
                   "output_file_path = \"${KE_REGEN_DIR}/rsp/aspMain.cpp\"" KE_RSP_CFG "${KE_RSP_CFG}")
            file(WRITE "${CMAKE_BINARY_DIR}/aspMain.build.toml" "${KE_RSP_CFG}")
            execute_process(
                COMMAND "${RSPRECOMP_HOST_TOOL}" "${CMAKE_BINARY_DIR}/aspMain.build.toml"
                RESULT_VARIABLE KE_RSP_RESULT
                OUTPUT_VARIABLE KE_RSP_OUTPUT
                ERROR_VARIABLE KE_RSP_OUTPUT)
            if (NOT KE_RSP_RESULT EQUAL 0)
                message(FATAL_ERROR "RSPRecomp failed:\n${KE_RSP_OUTPUT}")
            endif()
        endif()
    endif()

    set(KE_GENERATED_DIR "${KE_REGEN_DIR}")
    message(STATUS "Knife Edge: using regenerated game code at ${KE_GENERATED_DIR}")
endif()

# ---------------------------------------------------------------------------
# RT64 / ultramodern / librecomp configuration
# ---------------------------------------------------------------------------
set(RT64_STATIC TRUE)
set(RT64_SDL_WINDOW_VULKAN TRUE)
add_compile_definitions(HLSL_CPU)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    # rt64 pulls in nativefiledialog-extended, which on Linux needs either
    # GTK3 dev headers or the xdg-desktop-portal/dbus backend. This
    # devcontainer doesn't have GTK3 headers installed, so use the portal
    # backend instead.
    set(NFD_PORTAL ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/deps/rt64 ${CMAKE_BINARY_DIR}/rt64)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/N64ModernRuntime ${CMAKE_BINARY_DIR}/N64ModernRuntime)

set(KE_N64MODERNRUNTIME_DIR ${CMAKE_SOURCE_DIR}/deps/N64ModernRuntime)

# ---------------------------------------------------------------------------
# RecompiledFuncs — recompiler output, or the stub placeholder
# ---------------------------------------------------------------------------
add_library(RecompiledFuncs STATIC)

target_compile_options(RecompiledFuncs PRIVATE
    -fno-strict-aliasing
    -Wno-unused-variable
    -Wno-implicit-function-declaration
)

target_include_directories(RecompiledFuncs PRIVATE
    ${KE_N64MODERNRUNTIME_DIR}/ultramodern/include
    ${KE_N64MODERNRUNTIME_DIR}/librecomp/include
    ${KE_N64MODERNRUNTIME_DIR}/N64Recomp/include
)

if (KE_GENERATED_DIR)
    message(STATUS "Knife Edge: compiling recompiled game code from ${KE_GENERATED_DIR}")
    file(GLOB KE_FUNC_C_SOURCES "${KE_GENERATED_DIR}/*.c")
    file(GLOB KE_FUNC_CXX_SOURCES "${KE_GENERATED_DIR}/*.cpp")
    target_sources(RecompiledFuncs PRIVATE ${KE_FUNC_C_SOURCES} ${KE_FUNC_CXX_SOURCES})
    set(KE_OVERLAYS_DIR "${KE_GENERATED_DIR}")
else()
    message(STATUS "Knife Edge: KE_GENERATED_DIR not set, compiling src/stub_game/ placeholder instead")
    target_sources(RecompiledFuncs PRIVATE ${CMAKE_SOURCE_DIR}/src/stub_game/recomp_entrypoint.c)
    set(KE_OVERLAYS_DIR "${CMAKE_SOURCE_DIR}/src/stub_game")
endif()

set_source_files_properties(${CMAKE_SOURCE_DIR}/src/stub_game/recomp_entrypoint.c PROPERTIES COMPILE_FLAGS -fno-strict-aliasing)

# ---------------------------------------------------------------------------
# Main executable
# ---------------------------------------------------------------------------
# Recompiled RSP microcode (RSPRecomp output, e.g. generated/us/rsp/aspMain.cpp).
# Kept out of the RecompiledFuncs glob above because it is C++ and, unlike the
# CPU code, needs SSE4.1 for librecomp's rsp_vu_impl.hpp vector backend.
set(KE_RSP_SOURCES "")
if (KE_GENERATED_DIR)
    file(GLOB KE_RSP_SOURCES "${KE_GENERATED_DIR}/rsp/*.cpp")
    if (KE_RSP_SOURCES)
        message(STATUS "Knife Edge: compiling recompiled RSP microcode from ${KE_GENERATED_DIR}/rsp")
    else()
        message(STATUS "Knife Edge: no RSP microcode found in ${KE_GENERATED_DIR}/rsp "
                       "(run RSPRecomp on config/aspMain.us.toml)")
    endif()
endif()

# ---------------------------------------------------------------------------
# Build stamp
# ---------------------------------------------------------------------------
# Print the commit a binary was built from at startup, so a bug report can be
# tied to an exact tree ("I'm not sure which binary I ran" cost us a whole
# debugging detour once). Re-run cmake to refresh; a stale stamp is worse than
# none, so the dirty flag is included.
find_package(Git QUIET)
set(KE_BUILD_COMMIT "unknown")
set(KE_BUILD_DIRTY 0)
if (GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
    execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse --short HEAD
                    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                    OUTPUT_VARIABLE KE_BUILD_COMMIT
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    ERROR_QUIET)
    execute_process(COMMAND "${GIT_EXECUTABLE}" status --porcelain
                    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                    OUTPUT_VARIABLE KE_GIT_STATUS
                    ERROR_QUIET)
    if (NOT KE_GIT_STATUS STREQUAL "")
        set(KE_BUILD_DIRTY 1)
    endif()
endif()
configure_file(${CMAKE_SOURCE_DIR}/src/main/build_info.h.in
               ${CMAKE_BINARY_DIR}/generated_include/build_info.h @ONLY)

add_executable(KnifeEdgeRecompiled
    ${CMAKE_SOURCE_DIR}/src/main/main.cpp
    ${CMAKE_SOURCE_DIR}/src/main/audio.cpp
    ${CMAKE_SOURCE_DIR}/src/main/config.cpp
    ${CMAKE_SOURCE_DIR}/src/main/support.cpp
    ${CMAKE_SOURCE_DIR}/src/main/register_overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/main/rcp_timing.cpp
    ${CMAKE_SOURCE_DIR}/src/main/rt64_render_context.cpp
    ${KE_RSP_SOURCES}
)

target_include_directories(KnifeEdgeRecompiled PRIVATE
    ${CMAKE_BINARY_DIR}/generated_include
    ${CMAKE_SOURCE_DIR}/src/main
    ${KE_N64MODERNRUNTIME_DIR}/N64Recomp/include
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/contrib
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/contrib/hlslpp/include
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/contrib/dxc/inc
    ${CMAKE_SOURCE_DIR}/deps/rt64/src
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/rhi
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/render
    ${CMAKE_SOURCE_DIR}/deps/rt64/src/contrib/nativefiledialog-extended/src/include
)

# register_overlays.cpp includes "recomp_overlays.inl" (and, transitively,
# "funcs.h"), which live either in KE_GENERATED_DIR or in src/stub_game/.
set_source_files_properties(${CMAKE_SOURCE_DIR}/src/main/register_overlays.cpp PROPERTIES
    INCLUDE_DIRECTORIES "${KE_OVERLAYS_DIR}")

if (KE_RSP_SOURCES)
    # Lets src/main/main.cpp reference `aspMain` only when it has actually been
    # generated, so the stub configuration still links.
    target_compile_definitions(KnifeEdgeRecompiled PRIVATE KE_HAVE_ASPMAIN)
endif()

if (CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    target_compile_options(KnifeEdgeRecompiled PRIVATE -march=nehalem -fno-strict-aliasing -fms-extensions)
else()
    target_compile_options(KnifeEdgeRecompiled PRIVATE -fno-strict-aliasing -fms-extensions)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(SDL2 REQUIRED)
    add_compile_definitions("RT64_SDL_WINDOW_VULKAN")
    target_include_directories(KnifeEdgeRecompiled PRIVATE ${SDL2_INCLUDE_DIRS})

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

    target_link_libraries(KnifeEdgeRecompiled PRIVATE -latomic ${CMAKE_DL_LIBS} Threads::Threads SDL2::SDL2)
endif()

if (APPLE)
    find_package(SDL2 REQUIRED)
    target_include_directories(KnifeEdgeRecompiled PRIVATE ${SDL2_INCLUDE_DIRS})

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

    target_link_libraries(KnifeEdgeRecompiled PRIVATE ${CMAKE_DL_LIBS} Threads::Threads SDL2::SDL2)
endif()

# tomlplusplus is vendored by deps/N64ModernRuntime/N64Recomp/lib/tomlplusplus
# and already built as part of the add_subdirectory(deps/N64ModernRuntime)
# above (N64Recomp/RSPRecomp use it for their own config.toml format); reused
# here (src/main/config.cpp) instead of vendoring a second TOML parser -- see
# analysis/docs/enhancements.md.
target_link_libraries(KnifeEdgeRecompiled PRIVATE
    RecompiledFuncs
    librecomp
    ultramodern
    rt64
    tomlplusplus::tomlplusplus
)

set_property(TARGET KnifeEdgeRecompiled PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
