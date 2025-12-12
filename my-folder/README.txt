GROUP 5 PROJECT
==============================
Virtual Memory & Page Fault Demonstration
==============================

This project shows how computers use Virtual Memory and Demand Paging.

When a program uses more memory than the physical RAM available,
the operating system must load memory pages from disk.
This causes PAGE FAULTS, which slow the program down.

By using a very large array, we can observe:
- High REAL time
- Low USER time
This difference shows time spent handling page faults.

----------------------------------
FILES IN THIS PROJECT
----------------------------------

vm_fault.c       (C program)
vm_test.py       (Python program)
run.sh           (Shell script)
Makefile         (Build file)
README.txt       (this file)

----------------------------------
HOW TO COMPILE (C PROGRAM)
----------------------------------

Inside this folder run:

    make

Or manually:

    gcc -O2 -o vm_fault vm_fault.c

----------------------------------
HOW TO RUN (C PROGRAM)
----------------------------------

Run it like this:

    /usr/bin/time -v ./vm_fault 4

This will allocate 4GB of memory.
We can change 4 to any number (8, 12, etc).

----------------------------------
HOW TO RUN THE PYTHON VERSION
----------------------------------

    python3 vm_test.py 4

You can also measure time with:

    /usr/bin/time -v python3 vm_test.py 4

----------------------------------
DEPENDENCIES
----------------------------------

C program:
- gcc
- Linux OS
- /usr/bin/time
- strace (optional)

Python script:
- Python3
- Standard library only

Shell script:
- bash

----------------------------------
WHAT TO OBSERVE
----------------------------------

Compare:

- REAL time
- USER time

REAL time will be much higher because:
    The system is handling many PAGE FAULTS.

We can also see this using:

    strace -c ./vm_fault 4

----------------------------------
END OF FILE
----------------------------------