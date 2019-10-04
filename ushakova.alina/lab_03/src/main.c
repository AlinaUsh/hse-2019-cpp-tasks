#include "clist.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct point {
  int x, y;
  struct intrusive_node node;
};

void add_point(struct intrusive_list *head, int x, int y) {
	struct point *new_point = malloc(sizeof(struct point));
	new_point->x = x;
	new_point->y = y;
	add_node(head, &(new_point->node));
	return;
}

void remove_point(struct intrusive_list *list, int x, int y) { // removes all (x, y) pairs
	struct intrusive_node *cur = list->head;
	struct intrusive_node *next_point;
	struct point * cur_point;
	while (cur != NULL)
	{
		next_point = cur->next;
		cur_point = container_of(cur, struct point, node);
		if ((cur_point->x == x) && (cur_point->y == y)) {
			remove_node(list, cur);
			free(cur_point);
		}
		cur = next_point;
	}
	return;
}

void show_all_points(struct intrusive_list *list) {
	struct intrusive_node *cur = list->head;
	struct point * cur_point;
	while (cur != NULL)
	{
		cur_point = container_of(cur, struct point, node);
		printf("(%d %d)%c", cur_point->x, cur_point->y, ' ');
		cur = cur->next;
	}
	printf("%c", '\n');
	return;
}

void remove_all_points(struct intrusive_list *list) {
	struct intrusive_node *cur = list->head;
	struct point *del; 
	while (cur != NULL) {
		list->head = cur->next;
		del = container_of(cur, struct point, node);
		cur = list->head;
		free(del);
	}
	return;
}

int main() {
	struct intrusive_list *list = malloc(sizeof(struct intrusive_list));
	init_list(list);
	int correct = 0;
	while (1 == 1) {
		correct = 0;
		char *str = malloc(240 * sizeof(char));
		scanf("%239s", str);
		if (strcmp(str, "add") == 0) {
			correct = 1;
			int new_x, new_y;
			scanf("%d%d", &new_x, &new_y);
			add_point(list, new_x, new_y);
		}
		if (strcmp(str, "rm") == 0) {
			correct = 1;
			int del_x, del_y;
			scanf("%d%d", &del_x, &del_y);
			remove_point(list, del_x, del_y);
		}
		if (strcmp(str, "rma") == 0) {
			correct = 1;
			remove_all_points(list);
		}
		if (strcmp(str, "len") == 0) {
			correct = 1;
			int len = get_length(list);
			printf("%d\n", len);
		}
		if (strcmp(str, "exit") == 0) {
			correct = 1;
			remove_all_points(list);
			free(list);
			free(str);
			return 0;
		}
		if (strcmp(str, "print") == 0) {
			correct = 1;
			show_all_points(list);
		}
		if (correct == 0) {
			printf("%s\n", "Unknown command");
		}
		free(str);
	}
	return 0;
}
