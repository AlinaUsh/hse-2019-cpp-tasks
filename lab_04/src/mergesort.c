#include "mergesort.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

void merge(char* array, char* buf, int size, size_t element_size, int (*comparator)(const void*, const void*), size_t elements) {
	memcpy(buf, array, size * element_size);
	int ind_buf = 0, ind_array = size, pos = 0;
	while (ind_buf < size && ind_array < (int)elements) {
		if (comparator(buf + ind_buf * element_size, array + ind_array * element_size) >= 0) {	
			memcpy(array + pos * element_size, array + ind_array * element_size, element_size);
			ind_array++;
		}
		else {
			memcpy(array + pos * element_size, buf + ind_buf * element_size, element_size);
			ind_buf++;
		}
		pos++;
	}
	while (ind_buf < size) {
		memcpy(array + pos * element_size, buf + ind_buf * element_size, element_size);
		ind_buf++;
		pos++;
	}
	return;
}

int mergesort(void *array, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
	if ((int)elements <= 1) {
		return 0;
	}
	int size = (int)elements / 2;
	int correct;	
	correct = mergesort(array, size, element_size, comparator);
	if (correct == 1) {
		return 1;
	}
	correct = mergesort(array + size * element_size, elements - size, element_size, comparator);
	if (correct == 1) {
		return 1;
	}
	void *buf = malloc(size * element_size);
	if (buf == NULL) {
		return 1;
	}
	merge(array, buf, size, element_size, comparator, elements);
	free(buf);
	return 0;
}
