#include "sort.h"
/**
 * quick_sort - Quicksort.
 * @array: Array.
 * @size: Size.
*/
void quick_sort(int *array, size_t size)
{
    int limit = size - 1;

    if (size < 2)
        return;

    partition(array, size, 0, limit);
}
/**
 * partition - Lomute.
 * @arr: Array.
 * @size: Ssize.
 * @lower_limit: Lower limit.
 * @limit: Limit.
*/
void partition(int *arr, size_t size, int lower_limit, int limit)
{
    int pivot;

    if (lower_limit < limit)
    {
        pivot = sort(arr, size, lower_limit, limit);
        partition(arr, size, lower_limit, pivot - 1);
        partition(arr, size, pivot + 1, limit);
    }
}
/**
 * sort - Sort.
 * @arr: Array.
 * @lower_limit: lower limit.
 * @limit: Limit.
 * @size: Size.
*/
int sort(int *arr, size_t size, int lower_limit, int limit)
{
    int pivot = arr[limit], swap_index = lower_limit, i;

    for (i = lower_limit; i < limit; i++)
        if (arr[i] < pivot)
        {
            if (i != swap_index && arr[i] != arr[swap_index])
                swap(&arr[i], &arr[swap_index], size, arr);

            swap_index++;
        }

    if (limit != swap_index && arr[limit] != arr[swap_index])
        swap(&arr[limit], &arr[swap_index], size, arr);

    return (swap_index);
}
/**
 * swap - swaps two elements in an array.
 * @one: First swap.
 * @two: Second swap.
 * @arr: Array.
 * @size: Size.
*/
void swap(int *one, int *two, size_t size, int *arr)
{
    int tmp;

    tmp = *one;
    *one = *two;
    *two = tmp;

    print_array(arr, size);
}
