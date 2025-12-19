# MIT License
#
# Copyright (c) 2025 Xgui4 Studio
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Variables
CC = gcc
BUILD_DIR = bin 
TARGET = bin/hello-world-gtk-app
PREFIX ?= /usr

RES_XML := myresources.xml
RES_C := src/myresources.c
RES_H := src/myresources.h

SRC = src/main.c src/config.c src/utils.c src/window.c src/cli.c $(RES_C)

# Compilation flags
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

# Default target (Compile and run))
all: $(TARGET)

$(TARGET): $(SRC) | $(BUILD_DIR)
	@echo "Compiling the program with GCC"
	$(CC) $(GTK_CFLAGS) -g -O0 -Wall -Wextra -o $@ $^ $(GTK_LIBS) -fsanitize=address 

# Rule to create the build directory
$(BUILD_DIR):
	@echo "Creating Build directory"
	mkdir -p $(BUILD_DIR)

# Define a dependency: myresources.c depends on myresources.xml
$(RES_C): $(RES_XML)
	@echo "Compiling the GIO resources files"
	glib-compile-resources --target=$(RES_C) --generate-source $<
	glib-compile-resources --target=$(RES_H) --generate-header $<

# Target to run the program
run: $(TARGET)
	./$(TARGET)

# Target to clean up generated files and the directory
clean:
	rm -rf $(BUILD_DIR) $(RES_C) $(RES_H)
	@echo "Cleaned up build artifacts and generated resource files."

build: $(TARGET)

.PHONY: all run build clean