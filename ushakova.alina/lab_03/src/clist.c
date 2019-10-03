#include "clist.h"

void init_list(struct intrusive_list *list) {
	list->head = NULL;
	return;
}

void add_node(struct intrusive_list *list, struct intrusive_node *new_node) {
	new_node->next = list->head;
	new_node->prev = NULL;
	if (list->head != NULL)
		list->head->prev = new_node;
	list->head = new_node;
	return;
}

void remove_node(struct intrusive_list *list, struct intrusive_node *node) {
	if (node == list->head) {
		if (node->next == NULL) {
			list->head = NULL;
			return;
		}
		list->head = node->next;
		node->next->prev = NULL;
		return;		
	}
	if (node->next != NULL) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		return;
	}
	node->prev->next = NULL;
	return;
}

int get_length(struct intrusive_list *list) {
	struct intrusive_node* ptr = list->head;
	int size = 0;
	while (ptr != NULL) {
		size++;
		ptr = ptr->next;
	}
	return size;
}
