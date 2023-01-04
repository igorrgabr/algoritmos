#include "array_list_int.h"
#include <stdlib.h>

struct array_list_int {
int *a;
unsigned int size, capacity;
};

int increase_memory(array_list_int *list) {
    if (list->size < list->capacity) return 0;
    int *new_a, i;
    list->capacity += 10;
    new_a = (int *) malloc(sizeof(int) * list->capacity);
    for (i = 0; i < list->size; i++) {
        new_a[i] = list->a[i];
    }
    int *old_a = list->a;
    list->a = new_a;
    free(old_a);
    return 1;
}

array_list_int * array_list_create() {
    array_list_int *new_list = (array_list_int *) malloc(sizeof(array_list_int));
    if (new_list == 0) return 0; // não conseguiu alocar memória para a lista
    new_list->a = (int *) malloc(sizeof(int) * 10); // tamanho inicial: 10
    if (new_list->a == 0) { // não conseguiu alocar memória para os elementos
        array_list_destroy(new_list);
        return 0;
    }
    new_list->size = 0;
    new_list->capacity = 10;
    return new_list;
}

int array_list_get(array_list_int * list, int index, int *error) {
    *error = 0;
    if (index < 0 || index >= list->size) {
        *error = 1;
        return 0;
    }
    return list->a[index];
}

unsigned int array_list_push_back(array_list_int * list, int value) {
    if (list->size == list->capacity) return array_list_size(list); // precisa alocar mais memória
    list->a[list->size] = value;
    list->size++;
    return array_list_size(list);
}

unsigned int array_list_pop_back(array_list_int * list) {
    if (list->a == 0) return 0;
    if (--list->size == 0) {    // se o novo tamanho da lista for zero, libera memória
        array_list_destroy(list);
        return 0;
    }
    list->a[list->size] = 0;
    return array_list_size(list);
}

unsigned int array_list_size(array_list_int * list) {
    return list->size;
}

int array_list_find(array_list_int * list, int element) {
    if (list->a == 0) return -1;
    for (int i = 0; i < list->size; i++) {
        if (list->a[i] == element) return i;
    }
    return -1;
}

unsigned int array_list_insert_at(array_list_int * list, int index, int value) {
    if (list->a == 0) return 0;
    if (list->size < list->capacity) list->size++;
    else if (list->size == list->capacity) return array_list_size(list); // precisa alocar mais memória
    int old, aux;
    old = list->a[index]; // guarda o valor antigo do indice solicitado
    list->a[index] = value; // substitui o indice pelo valor solicitado
    for (int i = index+1; i < list->size; i++) { // desloca os proximos elementos em um indice
        aux = list->a[i];
        list->a[i] = old;
        old = aux;
    }
    return array_list_size(list);
}

int array_list_remove_from(array_list_int * list, int index) {
    if (list->a == 0) return 0;
    if (--list->size == 0) { // se o novo tamanho da lista for zero, libera a memória
        array_list_destroy(list);
        return 0;
    }
    for (int i = index; i < list->size; i++) {  // substitui cada elemento (a partir do elemento a ser removido) pelo seu proximo
        list->a[i] = list->a[i+1];
    }
    return array_list_size(list);
}

unsigned int array_list_capacity(array_list_int * list) {
    return list->capacity;
}

double array_list_percent_occupied(array_list_int * list) {
    return (double) list->size / (double) list->capacity;
}

void array_list_destroy(array_list_int * list) {
    free(list);
}