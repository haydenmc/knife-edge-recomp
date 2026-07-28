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

add_executable(KnifeEdgeRecompiled
    ${CMAKE_SOURCE_DIR}/src/main/main.cpp
    ${CMAKE_SOURCE_DIR}/src/main/audio.cpp
    ${CMAKE_SOURCE_DIR}/src/main/support.cpp
    ${CMAKE_SOURCE_DIR}/src/main/register_overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/main/rt64_render_context.cpp
    ${KE_RSP_SOURCES}
)

target_include_directories(KnifeEdgeRecompiled PRIVATE
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

target_link_libraries(KnifeEdgeRecompiled PRIVATE
    RecompiledFuncs
    librecomp
    ultramodern
    rt64
)

set_property(TARGET KnifeEdgeRecompiled PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
