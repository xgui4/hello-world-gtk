# Variables
CC = gcc
SRC = main.c config.c 

BUILD_DIR = bin 
TARGET = $(BUILD_DIR)/hello-world-gtk-app

PREFIX ?= /usr/

# Compilation flags
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

# Default target (Compile and run)
all: clean run

# Target to clean up generated files and the directory
clean:
	rm -rf $(BUILD_DIR)

# Rule to build the target executable
$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(GTK_CFLAGS) -o $@ $^ $(GTK_LIBS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Target to install
run: $(TARGET)
	./$(TARGET)

build: $(TARGET)

# Target to stage files for installation (via DESTDIR)
install: build
	mkdir -p $(DESTDIR)$(PREFIX)/bin/
	@echo "Staging $(TARGET) to $(DESTDIR)$(PREFIX)/bin/"
	mv $(TARGET) $(DESTDIR)$(PREFIX)/bin/
	@echo "Staging finished."

.PHONY: all run build clean install
