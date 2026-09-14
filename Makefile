SOURCE_DIR=.
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

all: test.z64

test.z64: $(BUILD_DIR)/test.dfs

$(BUILD_DIR)/test.elf: $(BUILD_DIR)/main.o
$(BUILD_DIR)/test.dfs: $(wildcard $(SOURCE_DIR)/filesystem/)
	mkdfs $@ $^
	
test.z64: N64_ROM_TITLE="test RDP"
	
clean:
	rm -rf $(BUILD_DIR) *.z64