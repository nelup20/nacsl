CC := gcc
COMPILER_FLAGS := -g
COMPILER_FLAGS_RELEASE := -O3 -strip
BUILD_DIR :=./build
RELEASE_DIR :=./release
SRC_DIR :=./src

MAIN_FILE := $(SRC_DIR)/program.c
BINARY := $(BUILD_DIR)/program.exe

C_FILES := $(filter-out $(MAIN_FILE),$(shell find $(SRC_DIR) -name '*.c'))
OBJECT_FILES := $(subst src,build,$(patsubst %.c,%.o,$(C_FILES)))

.PHONY: clean release

all: $(BINARY)

$(BINARY): $(OBJECT_FILES)
	$(CC) $(COMPILER_FLAGS) $(OBJECT_FILES) $(MAIN_FILE) -o $@

// TODO: stop recompiling all files on change
$(OBJECT_FILES): $(C_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(COMPILER_FLAGS) -c $(subst build,src,$(patsubst %.o,%.c,$@)) -o $@

release: clean
	@echo "TODO: release"

clean:
	@rm -rf $(BUILD_DIR)/*