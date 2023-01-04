#ifndef _ARRAY_LIST_INT_H_
#define _ARRAY_LIST_INT_H_

typedef struct array_list_int array_list_int;

int increase_memory(array_list_int *list);

array_list_int * array_list_create();
// Cria uma nova lista em memória. Retorna um ponteiro para a lista recém criada.

int array_list_get(array_list_int * list, int index, int *error);
// Retorna um elemento localizado no índice index.

unsigned int array_list_push_back(array_list_int * list, int value);
// Adiciona um novo elemento ao final da lista.

unsigned int array_list_pop_back(array_list_int * list);
// Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.

unsigned int array_list_size(array_list_int * list);
// Retorna a quantidade de elementos na lista.

int array_list_find(array_list_int * list, int element);
// Busca um elemento na lista. Retorna o índice onde ele se encontra ou −1 se ele não estiver na lista.

unsigned int array_list_insert_at(array_list_int * list, int index, int value);
// Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.

int array_list_remove_from(array_list_int * list, int index);
// Remove elemento localizado no índice index.

unsigned int array_list_capacity(array_list_int * list);
// Retorna o espaço efetivamente reservado para a lista.

double array_list_percent_occupied(array_list_int * list);
// Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0,0 e 1,0.

void array_list_destroy(array_list_int * list);
// Libera memória usado pela lista list.

#endif