#include "point_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stddef.h>
#include <assert.h>

void my_print_point(intrusive_node *node, char *format) {
	point_node *cur_node = get_point(node);
	printf(format, cur_node->x, cur_node->y);
	printf("\n");
	return;
}

void counter(intrusive_node *node, int *c) {
	*c = *c + 1;
	return;
}

void save_text(intrusive_node *node, FILE *fout) {
	point_node *cur_node = get_point(node);
	//printf("6 ");
	//printf("%d %d\n", cur_node->x, cur_node->y);
	fprintf(fout, "%d %d\n", cur_node->x, cur_node->y);
	return;
}


void save_bin(intrusive_node *node, FILE *fout) {
	point_node *cur_node = get_point(node);
	int32_t cur_num;
	cur_num = cur_node->x;
	//printf("%d %d\n", cur_node->x, cur_node->y);
//	fprintf(fout, "%d %d\n", cur_node->x, cur_node->y);
	unsigned char c;
	//printf("123 ");
	for (int i = 0; i < 3; i++) {
		c = cur_num;
		//printf("%c", c);
		fwrite(&c, sizeof(char), 1, fout);
		cur_num = cur_num >> 8;
	}	
	//printf(" ");
	cur_num = cur_node->y;
	for (int i = 0; i < 3; i++) {
		c = cur_num;

		//printf("%c", c);
		fwrite(&c, sizeof(char), 1, fout);
		cur_num = cur_num >> 8;
	}	
	//printf("\n");
	return;
}

int main(int argc, char *argv[]) {
	intrusive_list list;
	intrusive_list* l = &list;
	init_list(l);
	//printf("%s\n", "1");
//	if (argv[1] == "loadtext") {	
	if (strcmp(argv[1], "loadtext") == 0) {	
		FILE* fin = fopen(argv[2], "r");
		if (!fin) {
			return 1;
		}
		int32_t new_x, new_y;
		while (fscanf(fin, "%d %d", &new_x, &new_y) >= 0) {
			add_point(l, new_x, new_y);
		}
		fclose(fin);
	}
	else {
		FILE* fin = fopen(argv[2], "rb");
		if (!fin) {
			return 1;
		}
		int32_t new_x, new_y;
		unsigned char buf[6];
		while (fread(buf, sizeof(char), 6, fin) == 6) {
			new_x = buf[2] * 256 * 256 + buf[1] * 256 + buf[0];
			new_y = buf[5] * 256 * 256 + buf[4] * 256 + buf[3];
			add_point(l, new_x, new_y);
		}
		fclose(fin);
	}
//	printf("%s\n", "2");
	/*FILE* fin = fopen(argv[2], "r");

	if (!fin) {
		return 1;
	}
	int new_x, new_y;
	while (fscanf(fin, "%d %d", &new_x, &new_y) >= 0) {
		add_point(l, new_x, new_y);
	}*/	
	if (strcmp(argv[3], "savetext") == 0) {
		FILE* fout = fopen(argv[4], "w");
		//printf("%s\n", "3");
		if (!fout) {
			remove_all_points(l);
			return 1;
		}
		apply(l, save_text, fout);
		//printf("%s\n", "4");
		fclose(fout);
	}
	if (strcmp(argv[3], "savebin") == 0) {
		FILE* fout = fopen(argv[4], "wb");
		if (!fout) {
			remove_all_points(l);
			return 1;
		}
		apply(l, save_bin, fout);
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
