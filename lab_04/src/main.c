#include "mergesort.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int int_gt_comparator(const void *a, const void *b) {
	return *(int*)a - *(int*)b; 
}

int char_gt_comparator(const void *a, const void *b) {
	return *(char*)a - *(char*)b; 
}

int str_gt_comparator(const void *first_str, const void *second_str) {
	return strcmp(*(char**)first_str, *(char**)second_str);
}

int main(int argc, char *argv[]) {
	if (argc <= 2) {
		return 0;
	}
	if (strcmp(argv[1], "int") == 0) {
		int array_int[argc - 2];
		for (int i = 0; i < argc - 2; i++) {
			array_int[i] = atoi(argv[i + 2]);
		}
		int failed = mergesort(array_int, sizeof(array_int) / sizeof(int), sizeof(int), int_gt_comparator);
		if (failed == 1) {
			printf("Error: memory allocation failed\n");
			return 0;
		}
		for (int i = 0; i < argc - 2; i++) {
			printf("%d ", array_int[i]);
		}
	}
	if (strcmp(argv[1], "char") == 0) {
		char array_char[argc - 2];
		for (int i = 0; i < argc - 2; i++) {
			array_char[i] = *argv[i + 2];
		}
		int failed = mergesort(array_char, sizeof(array_char) / sizeof(char), sizeof(char), char_gt_comparator);
		if (failed == 1) {
			printf("Error: memory allocation failed\n");
			return 0;
		}
		for (int i = 0; i < argc - 2; i++) {
			printf("%c ", array_char[i]);
		}
	}
	if (strcmp(argv[1], "str") == 0) {
		char* array_str[argc - 2];
		for (int i = 0; i < argc - 2; i++) {
			array_str[i] = argv[i + 2];
		}
		int failed = mergesort(array_str, sizeof(array_str) / sizeof(array_str[0]), sizeof(array_str[0]), str_gt_comparator);
		if (failed == 1) {
			printf("Error: memory allocation failed\n");
			return 0;
		}
		for (int i = 0; i < argc - 2; i++) {
			printf("%s ", array_str[i]);
		}
	}
	return 0;
}
