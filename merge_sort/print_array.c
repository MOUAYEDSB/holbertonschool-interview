#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size) {
    size_t i;

    if (array == NULL) {
        printf("NULL array\n");
        return;
    }

    for (i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}
