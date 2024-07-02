#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of left subarray
 * @mid: Middle index of the array
 * @right: Ending index of right subarray
 */
static void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}


/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int left_size = mid;
    int right_size = size - mid;

    // Create temporary arrays for left and right halves
    int left[left_size], right[right_size];

    // Copy data to temporary arrays
    for (int i = 0; i < left_size; i++)
        left[i] = array[i];
    for (int i = 0; i < right_size; i++)
        right[i] = array[mid + i];

    // Recursively sort left and right halves
    merge_sort(left, left_size);
    merge_sort(right, right_size);

    // Merge the sorted halves
    merge(array, 0, left_size - 1, size - 1);
}

