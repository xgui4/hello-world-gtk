# Define variables
CC = gcc
SRC = main.c

# Define the build directory and the final target path
BUILD_DIR = bin
TARGET = $(BUILD_DIR)/hello-world-gtk-app # Name the executable something descriptive

# Define GTK flags using shell expansion
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

# Default target
all: $(TARGET)

# Rule to build the target executable
# The | $(BUILD_DIR) makes the directory an "order-only" prerequisite
$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(GTK_CFLAGS) -o $@ $< $(GTK_LIBS)

# Rule to create the build directory
# The -p flag prevents errors if the directory already exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Target to run the program
run: $(TARGET)
	./$(TARGET)

# Target to clean up generated files and the directory
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
