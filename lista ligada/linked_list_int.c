#include "linked_list_int.h"
#include <stdlib.h>

struct linked_list_int_node {
int value;
struct linked_list_int_node *prev, *next;
};

struct linked_list_int {
struct linked_list_int_node *first, *last;
unsigned int size;
};

linked_list_int * linked_list_create() {
    linked_list_int *new_list = (linked_list_int *) malloc(sizeof(linked_list_int));
    new_list->first = 0;
    new_list->last = 0;
    new_list->size = 0;
    return new_list;
}

int linked_list_get(linked_list_int * list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    linked_list_int_node *new_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    new_node = list->first;
    int i = 0;
    while (i++ < index) {
        new_node = new_node->next;
    }
    return new_node->value;
}

unsigned int linked_list_push_back(linked_list_int * list, int value) {
    linked_list_int_node *node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    linked_list_int_node *old_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    node->value = value;
    node->next = 0;
    if (list->first == 0) {
        node->prev = 0;
        list->first = node;
    } else {
        old_node = list->last;
        node->prev = old_node;
        old_node->next = node;
    }
    list->last = node;
    list->size++;
    return linked_list_size(list);
}

unsigned int linked_list_pop_back(linked_list_int * list) {
    linked_list_int_node *node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    linked_list_int_node *old_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    old_node = list->last;
    node = old_node->prev;
    node->next = 0;
    free(old_node);
    list->last = node;
    list->size--;
    return linked_list_size(list);
}

unsigned int linked_list_size(linked_list_int * list) {
    return list->size;
}

int linked_list_find(linked_list_int * list, int element) {
    linked_list_int_node *node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    node = list->first;
    for (int i = 0; i < list->size; i++) {
        if (element == node->value) return i;
        node = node->next;
    }
    return -1;
}

unsigned int linked_list_insert_at(linked_list_int * list, int index, int value) {
    if (index < 0 || index > list->size) return 0;
    linked_list_int_node *current = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    linked_list_int_node *new_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    current = list->first;
    new_node->value = value;
    for (int i = 0; i < index; i++) current = current->next;
    new_node->next = current->next;
    current->next = new_node;
    if (index == 1) list->first = new_node;
    list->size++;
    return linked_list_size(list);
}

int linked_list_remove_from(linked_list_int * list, int index) {
    linked_list_int_node *node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    linked_list_int_node *prev_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    linked_list_int_node *next_node = (linked_list_int_node *) malloc(sizeof(linked_list_int_node));
    node = list->first;
    if (index < list->size) {
        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        if (index == list->size-1) {
            linked_list_pop_back(list);
        } else {
            prev_node = node->prev;
            next_node = node->next;
            prev_node->next = next_node;
            next_node->prev = prev_node;
            list->size--;
        }
    }
    return linked_list_size(list);
}

double linked_list_percent_occupied(linked_list_int * list) {
    return 1.0;
}

void linked_list_destroy(linked_list_int * list) {
    free(list);
}