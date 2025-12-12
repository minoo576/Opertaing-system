/*
 * vm_fault.c
 *
 * This program shows how virtual memory and page faults work.
 * It creates a VERY big array (bigger than your RAM) and writes
 * to each page inside it. This forces the computer to use
 * demand paging and causes many page faults.
 *
 * You can measure how long it takes using:
 *
 *   /usr/bin/time -v ./vm_fault 8
 *
 * Here "8" means 8GB of memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <size_in_GB>\n", argv[0]);
        return 1;
    }

    long gb = atol(argv[1]);
    if (gb <= 0) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    size_t bytes = (size_t)gb * 1024 * 1024 * 1024;
    size_t page_size = sysconf(_SC_PAGESIZE);
    size_t pages = bytes / page_size;

    printf("Allocating %ld GB of memory...\n", gb);
    printf("Page size: %zu bytes\n", page_size);
    printf("Total pages to touch: %zu\n", pages);

    // Allocate the big array
    unsigned char *arr = malloc(bytes);
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Touching each page...\n");

    // Write 1 byte to each memory page
    for (size_t i = 0; i < pages; i++) {
        arr[i * page_size] = 1;   // Touch the page

        if (i % (pages / 10 + 1) == 0) {
            printf("Progress: %.1f%%\n", (100.0 * i) / pages);
        }
    }

    printf("Finished touching all pages!\n");

    free(arr);
    return 0;
}