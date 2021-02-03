#include "sort.h"
/**
 *counting_sort- Sort an array of integers using counting sort.
 *@array: Pointer to an array of integers.
 *@size: size of the array.
 *Return: NULL
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j;
	int max = array[0];
	int *output = malloc(sizeof(int) * size);
	int *count = malloc(sizeof(int) * size + 400);

	if (output == NULL || count == NULL)
		return;


/*Store the count of each character*/
	for (i = 0; array[i]; ++i)
		++count[array[i]];
/*Find the largest element in the array*/
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
/*Change count[i] so that  count[i] now contains actual position*/
	for (j = 1; j <= (max + 1); ++j)
	{
		count[j] += count[j - 1];
	}
	print_array(count, (max + 1));

/*Build the output array.*/
	for (i = 0; array[i]; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
/*copy output array to array*/
	for (i = 0; array[i]; ++i)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
