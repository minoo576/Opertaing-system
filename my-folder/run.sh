#!/bin/bash
# This script compiles and runs the C program.

echo "Compiling vm_fault.c..."
gcc -O2 -o vm_fault vm_fault.c

echo "Running the program with 4GB..."
/usr/bin/time -v ./vm_fault 4