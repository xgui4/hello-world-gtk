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
SRC = main.c config.c $(RES_C)
BUILD_DIR = bin 
TARGET = $(BUILD_DIR)/hello-world-gtk-app
PREFIX ?= /usr

RES_XML := myresources.xml
RES_C := myresources.c
RES_H := myresources.h

# Compilation flags
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

# Default target (Compile and run))
all: $(TARGET)

$(TARGET): $(SRC) | $(BUILD_DIR)
	@echo "Compiling the program with GCC"
	$(CC) $(GTK_CFLAGS) -o $@ $^ $(GTK_LIBS)

# Rule to create the build directory
$(BUILD_DIR):
	@echo "Creating Build directory"
	mkdir -p $(BUILD_DIR)

# Define a dependency: myresources.c depends on myresources.xml
$(RES_C): $(RES_XML)
	@echo "Compiling the GIO resources files"
	glib-compile-resources --generate-source --generate-header --target=$(basename $@) $<

# Target to run the program
run: $(TARGET)
	./$(TARGET)

# Target to clean up generated files and the directory
clean:
	rm -rf $(BUILD_DIR) $(RES_C) $(RES_H)
	@echo "Cleaned up build artifacts and generated resource files."

build: $(TARGET)

.PHONY: all run build clean