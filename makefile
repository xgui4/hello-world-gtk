# Variables
CC = gcc
SRC = main.c config.c 

BUILD_DIR = bin 
TARGET = $(BUILD_DIR)/hello-world-gtk-app
INSTALL_DIR = output
TARGET_INSTALL = output/hello-world-gtk-app

# Compilation flags
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

# Default target (Compile and run)
all: clean run

# Rule to build the target executable
$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(GTK_CFLAGS) -o $@ $^ $(GTK_LIBS)

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Target to run the program
run: $(TARGET)
	./$(TARGET)

build:
	$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(GTK_CFLAGS) -o $@ $^ $(GTK_LIBS)

# Target to clean up generated files and the directory
clean:
	rm -rf $(BUILD_DIR)

# Target to configure the installation
install: build
	mkdir -p $(INSTALL_DIR)
	@echo "Preparing $(TARGET_INSTALL) 
	mv $(TARGET) $(PREFIX)
	@echo "Preparation finished."

.PHONY: all run build clean install
