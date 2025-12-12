"""
vm_test.py
This Python program also allocates a large block of memory and writes to it.
You can compare the time taken with:

    /usr/bin/time -v python3 vm_test.py 4
"""

import sys
import mmap
import os
import time

if len(sys.argv) < 2:
    print("Usage: python3 vm_test.py <size_in_GB>")
    sys.exit(1)

gb = int(sys.argv[1])
bytes_needed = gb * 1024 * 1024 * 1024
page_size = os.sysconf("SC_PAGESIZE")
pages = bytes_needed // page_size

print(f"Allocating {gb} GB of memory...")
print(f"Touching {pages} pages...\n")

# Create large anonymous memory area
mm = mmap.mmap(-1, bytes_needed)

start = time.time()

# Touch every page
for i in range(pages):
    mm[i * page_size] = 1

end = time.time()

print(f"\nDone! Time taken: {end - start:.2f} seconds")
