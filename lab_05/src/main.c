#include "point_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stddef.h>
#include <assert.h>

void my_print_point(intrusive_node *node, void *format) {
	point_node *cur_node = get_point(node);
	printf((char*)format, cur_node->x, cur_node->y);
	return;
}

void counter(intrusive_node *node, void *c) {
	*(int*)c = *(int*)c + 1;
	return;
}

void save_text(intrusive_node *node, void *fout) {
	fout = (FILE*)fout;
	point_node *cur_node = get_point(node);
	fprintf(fout, "%d %d\n", cur_node->x, cur_node->y);
	return;
}


void save_bin(intrusive_node *node, void *fout) {
	fout = (FILE*)fout;
	point_node *cur_node = get_point(node);
	int32_t cur_num;
	cur_num = cur_node->x;
	unsigned char c;
	for (int i = 0; i < 3; i++) {
		c = cur_num;
		fwrite(&c, sizeof(char), 1, fout);
		cur_num = cur_num >> 8;
	}	
	cur_num = cur_node->y;
	for (int i = 0; i < 3; i++) {
		c = cur_num;
		fwrite(&c, sizeof(char), 1, fout);
		cur_num = cur_num >> 8;
	}	
	return;
}

void get_coordinates(int32_t *x, int32_t *y, unsigned char *buf) {
	int32_t base = 256;
	*x = (int32_t)buf[2] * base * base + (int32_t)buf[1] * base + (int32_t)buf[0];
	*y = (int32_t)buf[5] * base * base + (int32_t)buf[4] * base + (int32_t)buf[3];
	return;
}

void save_points(intrusive_list *list, void (*save)(intrusive_node *node, void *fout), FILE* fout) {
	if (!fout) {
		remove_all_points(list);
		return;
	}
	apply(list, save, fout);
	return;
}

void read_text(intrusive_list *l, FILE* fin) {
	if (!fin) {
		return;
	}
	int32_t new_x, new_y;
	while (fscanf(fin, "%d %d", &new_x, &new_y) >= 0) {
		add_point(l, new_x, new_y);
	}
	return;
}

void read_bin(intrusive_list *l, FILE* fin) {
	if (!fin) {
		return;
	}
	int32_t new_x, new_y;
	unsigned char buf[6];
	while (fread(buf, sizeof(char), 6, fin) == 6) {
		get_coordinates(&new_x, &new_y, buf);
		add_point(l, new_x, new_y);
	}
	return;
}

int main(int argc, char *argv[]) {
	intrusive_list list;
	intrusive_list* l = &list;
	init_list(l);
	if (strcmp(argv[1], "loadtext") == 0) {	
		FILE* fin = fopen(argv[2], "r");
		read_text(l, fin);
		fclose(fin);
	}
	else {
		FILE* fin = fopen(argv[2], "rb");
		read_bin(l, fin);
		fclose(fin);
	}
	if (strcmp(argv[3], "savetext") == 0) {
		FILE* fout = fopen(argv[4], "w");
		save_points(l, save_text, fout);
		fclose(fout);
	}
	if (strcmp(argv[3], "savebin") == 0) {
		FILE* fout = fopen(argv[4], "wb");
		save_points(l, save_bin, fout);
		fclose(fout);
	}
	if (strcmp(argv[3], "print") == 0) {
		apply(l, my_print_point, argv[4]);
	}
	if (strcmp(argv[3], "count") == 0) {
		int cnt = 0;
		apply(l, counter, &cnt);
		printf("%d\n", cnt);
	}
	remove_all_points(l);
	return 0;
}
