# ROM -> symbols pipeline.  `make -C analysis` regenerates everything.
#
#   stage 1  find_functions.py   -> out/functions.json
#   stage 2  ident_libultra.py   -> out/libultra_names.json   (n64sym cached in out/n64sym)
#   stage 3  gen_syms.py         -> ../config/*.toml
#   recomp                       -> ../build/RecompiledFuncs

ROOT     := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
PY       := $(ROOT)/.venv/bin/python
OUT      := $(ROOT)/analysis/out
CONFIG   := $(ROOT)/config
ROM      := $(ROOT)/build/knife_edge.z64
N64RECOMP:= $(ROOT)/deps/N64Recomp/build/N64Recomp

FUNCS    := $(OUT)/functions.json
NAMES    := $(OUT)/libultra_names.json
SYMS     := $(CONFIG)/knife_edge.us.syms.toml
CFG      := $(CONFIG)/knife_edge.us.toml

.PHONY: all syms recomp smoke clean refresh
all: syms

$(FUNCS): $(ROOT)/analysis/find_functions.py $(OUT)/segments.json $(ROM)
	$(PY) $(ROOT)/analysis/find_functions.py -q

$(NAMES): $(ROOT)/analysis/ident_libultra.py $(FUNCS)
	$(PY) $(ROOT)/analysis/ident_libultra.py -q

$(SYMS) $(CFG): $(ROOT)/analysis/gen_syms.py $(FUNCS) $(NAMES)
	$(PY) $(ROOT)/analysis/gen_syms.py -q

syms: $(SYMS) $(CFG)

# Force a fresh n64sym scan (~10 min); the default reuses out/n64sym/*.txt.
refresh:
	$(PY) $(ROOT)/analysis/ident_libultra.py --refresh -q
	$(PY) $(ROOT)/analysis/gen_syms.py -q

recomp: syms
	rm -rf $(ROOT)/build/RecompiledFuncs
	$(N64RECOMP) $(CFG)

# Compile-smoke a sample of the generated C.
smoke: recomp
	@set -e; for f in 0 2 4 6 8 10 12 14 16 19; do \
	  clang -c -std=c11 -O1 -I $(ROOT)/deps/N64Recomp/include \
	    -I $(ROOT)/build/RecompiledFuncs \
	    $(ROOT)/build/RecompiledFuncs/funcs_$$f.c -o /tmp/ke_smoke_$$f.o; \
	  echo "funcs_$$f ok"; \
	done

clean:
	rm -f $(FUNCS) $(NAMES) $(SYMS) $(CFG) \
	      $(OUT)/functions_report.txt $(OUT)/libultra_report.txt $(OUT)/syms_report.txt
