COMPILER := gcc
COMPILER_FLAGS := -g
COMPILER_FLAGS_RELEASE := -O3 -strip
BUILD_DIR :=./build
RELEASE_DIR :=./release
SRC_DIR :=./src

C_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJECT_FILES := $(patsubst %.c,%.o,$(C_FILES))

BINARY := program.exe

.PHONY: clean release

all: $(BINARY)

$(BINARY):
	@echo $(C_FILES)

release: clean
	@echo "TODO: release"

clean:
	@rm $(BUILD_DIR)/*