#!/bin/bash
echo "Compiling vm_fault.c..."
gcc vm_fault.c -o compile

echo
echo "Running program with 4 GB memory..."
/usr/bin/time -v ./compile 4
