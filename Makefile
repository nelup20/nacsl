.PHONY: clean release run

CC := gcc
COMPILER_FLAGS := -g
COMPILER_FLAGS_RELEASE := -O3 -strip
BUILD_DIR :=./build
RELEASE_DIR :=./release
SRC_DIR :=./src

MAIN_FILE := $(SRC_DIR)/program.c
BINARY := $(BUILD_DIR)/program.exe

C_FILES := $(filter-out $(MAIN_FILE),$(shell find $(SRC_DIR) -name '*.c'))
OBJECT_FILES := $(addprefix build/,$(patsubst %.c,%.o,$(C_FILES)))

all: $(BINARY)

$(BINARY): $(OBJECT_FILES) $(MAIN_FILE)
	$(CC) $(COMPILER_FLAGS) $(OBJECT_FILES) $(MAIN_FILE) -o $@

build/%.o: %.c %.h
	@mkdir -p $(dir $@)
	$(CC) $(COMPILER_FLAGS) -c $< -o $@

release: clean
	@echo "TODO: release"

clean:
	@rm -rf $(BUILD_DIR)/*

run:
	@$(BINARY)