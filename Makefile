# =====================================================
# Robox Decomp Build System (Starter)
# Matching build requires MWCC 4.3 Build 145 (Wii MW 1.0)
# Non-matching fallback uses devkitPPC GCC for testing.
# =====================================================

GAME      := robox
BUILD     := build
SRC       := src
INCLUDE   := include

C_FILES   := $(wildcard $(SRC)/*.c)
O_FILES   := $(C_FILES:$(SRC)/%.c=$(BUILD)/%.o)

# =====================================================
# Build Type Selection
# make          → non-matching (devkitPPC) build
# make MATCH=1  → matching build (MWCC 4.3 build 145)
# =====================================================

ifeq ($(MATCH),1)
    # Matching Compiler (User must provide this manually)
    CC := tools/mwcc_4_3_145/mwcceppc.exe
    LD := tools/mwcc_4_3_145/mwldeppc.exe
    CFLAGS := -O4,p -inline off -lang=c -char unsigned -enum int -Cpp_exceptions off -Rtti off -use_lmw_stmw on -sym on -fp hard
else
    # Non-matching fallback (Legal, good for testing)
    CC := powerpc-eabi-gcc
    LD := powerpc-eabi-ld
    CFLAGS := -O2 -ffunction-sections -fdata-sections -nostdlib
endif

# =====================================================

all: $(BUILD)/$(GAME).dol

$(BUILD):
	mkdir -p $(BUILD)

# Compile C -> .o
$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Linking rules differ depending on MATCH flag

ifeq ($(MATCH),1)

# ----------------------- MATCHING BUILD -----------------------
$(BUILD)/$(GAME).elf: $(O_FILES)
	$(LD) -o $@ -MAP $(BUILD)/$(GAME).map -lcf linker.ld $(O_FILES)

else

# ------------------- NON-MATCHING TEST BUILD -------------------
$(BUILD)/$(GAME).elf: $(O_FILES)
	$(CC) $(CFLAGS) -T linker.ld -Wl,-Map,$(BUILD)/$(GAME).map -o $@ $(O_FILES)

endif

# Convert ELF → DOL
$(BUILD)/$(GAME).dol: $(BUILD)/$(GAME).elf
	elf2dol $< $@

# Clean
clean:
	rm -rf $(BUILD)

.PHONY: all clean
