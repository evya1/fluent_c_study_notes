# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = aggregate_example
SRC = aggregate_instance.c
BUILD_DIR = build

# Targets
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(SRC)

run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
