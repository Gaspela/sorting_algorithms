#include "sort.h"
/**
 * selection_sort - Select.
 * @array: The array to be printed.
 * @size: Number of elements in array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, mimnum = 0, tmp = 0, flag = 0;

	for (i = 0; i < size; i++)
	{
		mimnum = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mimnum])
			{
				mimnum = j;
				flag = 1;
			}
		}
		/*swap*/
		if (flag)
		{
			tmp = array[i];
			array[i] = array[mimnum];
			array[mimnum] = tmp;
			print_array(array, size);
		}
	}
}
