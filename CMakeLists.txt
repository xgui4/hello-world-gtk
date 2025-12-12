# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify the language as C
project(hello-world-gtk C)

# Add an executable target from the source file
add_executable(hello-world-gtk hello-world-gtk.c)