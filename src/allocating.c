/*
 * src/allocating.c
 *
 * This file contains functions to allocate the arrays where
 * the pictures will reside.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 16/07/2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "allocating.h"
#include "error.h"

/*
 * Allocate a two-dimensional array filled with zeroes.
 * You can precise in the arguments the size of each elements :
 * 1, 2 or 4 bytes.
 * The function returns the address of the array on success and
 * NULL on error.
 */
void **alloc_image(int lines, int columns, size_t bytes_per_element)
{
	void **image;

	image = calloc(lines, sizeof(void *));
	if (image == NULL) {
		perror("Allocation error");
		return NULL;
	}
	*image = calloc(lines * columns, bytes_per_element);
	if(*image == NULL)
	{
		perror("Allocation error");
		free(image);
		return NULL;
	}
	for (int i = 1; i < lines; i++)
		image[i] = image[i - 1] + columns;

	return image;
}

/*
 * Free the array containing the image.
 */
void free_image(void **image)
{
	free(*image);
	free(image);
}
