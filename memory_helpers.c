#include "shell.h"

/**
  * free_array - free an array of strings
  * @array: array to free
  * Return: nothing
  */

void free_array(char **array)
{
	size_t i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
	}
	free(array);
}
