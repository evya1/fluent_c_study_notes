# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main
SRCS = $(wildcard src/*.c) $(wildcard src/assertion/*.c) $(wildcard src/aggregate/*.c)
OBJS = $(SRCS:%.c=build/%.o)
BUILD_DIR = build
INC_DIRS = -Isrc/assertion -Isrc/aggregate

# Targets
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -o $@ $^

build/%.o: %.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c -o $@ $<

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/src
	@mkdir -p $(BUILD_DIR)/src/assertion
	@mkdir -p $(BUILD_DIR)/src/aggregate

run: $(BUILD_DIR)/$(TARGET)
	./$<
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
