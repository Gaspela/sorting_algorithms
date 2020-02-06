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
 * @lowlimit: Lower limit.
 * @limit: Limit.
*/
void partition(int *arr, size_t size, int lowlimit, int limit)
{
    int pivot;

    if (lowlimit < limit)
    {
        pivot = sort(arr, size, lowlimit, limit);
        partition(arr, size, lowlimit, pivot - 1);
        partition(arr, size, pivot + 1, limit);
    }
}
/**
 * sort - Sort.
 * @arr: Array.
 * @lowlimit: lower limit.
 * @limit: Limit.
 * @size: Size.
*/
int sort(int *arr, size_t size, int lowlimit, int limit)
{
    int pivot = arr[limit], swapcurrent = lowlimit, i;

    for (i = lowlimit; i < limit; i++)
        if (arr[i] < pivot)
        {
            if (i != swapcurrent && arr[i] != arr[swapcurrent])
                swap(&arr[i], &arr[swapcurrent], size, arr);

            swapcurrent++;
        }

    if (limit != swapcurrent && arr[limit] != arr[swapcurrent])
        swap(&arr[limit], &arr[swapcurrent], size, arr);

    return (swapcurrent);
}
/**
 * swap - Swap.
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
