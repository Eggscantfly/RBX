# =====================================================
# Robox Decomp Build System (Starter)
# Matching build requires MWCC 4.3 build 145
# Non-matching fallback uses devkitPPC GCC for testing
# =====================================================

# Choose build mode:
# make          → non-matching test build (devkitPro)
# make MATCH=1  → matching build (requires MWCC)

# -----------------------------------------------------

GAME      := robox
BUILD     := build
SRC       := src
INCLUDE   := include

C_FILES   := $(wildcard $(SRC)/*.c)
O_FILES   := $(C_FILES:$(SRC)/%.c=$(BUILD)/%.o)

# -----------------------------------------------------
# Matching compiler (MWCC) - user must provide
# Do NOT distribute the compiler.
# -----------------------------------------------------
ifeq ($(MATCH),1)
    CC := tools/mwcc_4_3_145/mwcceppc.exe
    CFLAGS := -O4,p -inline off -lang=c -char unsigned -enum int -Cpp_exceptions off -Rtti off -use_lmw_stmw on -sym on -fp hard
else
# -----------------------------------------------------
# Non-matching fallback (devkitPro GCC)
# Safe, legal, and good for playtesting.
# -----------------------------------------------------
    CC := powerpc-eabi-gcc
    CFLAGS := -O2 -ffunction-sections -fdata-sections -nostdlib
endif

# -----------------------------------------------------

all: $(BUILD)/$(GAME).dol

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(BUILD)/$(GAME).dol: $(O_FILES)
	# placeholder link step — we fill this later
	cp $^ $@   # temporary fake output so it builds something

clean:
	rm -rf $(BUILD)

.PHONY: all clean
