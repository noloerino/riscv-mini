base_dir = $(abspath ..)

# Override implicit variables
CC = riscv64-unknown-elf-gcc
LDFLAGS = -march="rv32im" -mabi="ilp32"

# For custom benchmarks
RISCV_TEST_DIR     ?= $(base_dir)/riscv-tools-priv1.7/riscv-tests
CUSTOM_BMARK_BIN   ?= main
CUSTOM_BMARK_C_SRC ?= main.c syscalls.c
CUSTOM_BMARK_S_SRC ?= add.S crt.S

CUSTOM_BMARK_OBJS := \
	$(foreach f,$(CUSTOM_BMARK_C_SRC),$(patsubst %.c,%.o,$f)) \
	$(foreach f,$(CUSTOM_BMARK_S_SRC),$(patsubst %.S,%.o,$f))

riscv_bmark_dir = $(RISCV_TEST_DIR)/benchmarks

RISCV_GCC     = riscv64-unknown-elf-gcc
RISCV_CFLAGS  = -march="rv32im" -mabi="ilp32" -Wa,-mpriv-spec=1.10 \
	-static -std=gnu99 -fno-common -fno-builtin-printf \
	-I$(RISCV_TEST_DIR)/env -I$(RISCV_TEST_DIR)/benchmarks/common
RISCV_LDFLAGS = -march="rv32im" -mabi="ilp32" \
	-T $(RISCV_TEST_DIR)/benchmarks/common/test.ld \
	-I$(RISCV_TEST_DIR)/env -I$(RISCV_TEST_DIR)/benchmarks/common

VPATH += $(RISCV_TEST_DIR)/benchmarks/common 

all: $(CUSTOM_BMARK_BIN) $(CUSTOM_BMARK_BIN).hex $(CUSTOM_BMARK_BIN).dump

%.o: %.c
	$(RISCV_GCC) $(RISCV_CFLAGS) -c -o $@ $<

%.o: %.S
	$(RISCV_GCC) $(RISCV_CFLAGS) -D__ASSEMBLY__=1 -c -o $@ $<

$(CUSTOM_BMARK_BIN): $(CUSTOM_BMARK_OBJS)
	$(RISCV_GCC) $(RISCV_LDFLAGS) -o $@ $^ -nostdlib -nostartfiles -lc -lgcc

%.hex: %
	elf2hex 16 32768 $< > $@

%.dump: %
	riscv64-unknown-elf-objdump \
	--target="elf32-littleriscv" --architecture="riscv:rv32" \
	--disassemble-all --disassemble-zeroes --section=.text --section=.text.startup --section=.data \
	$< > $@

clean:
	rm -rf *.o $(CUSTOM_BMARK_BIN) $(CUSTOM_BMARK_BIN).hex $(CUSTOM_BMARK_BIN).dump

.PHONY: all clean
