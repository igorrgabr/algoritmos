#ifndef _LINKED_LIST_INT_H_
#define _LINKED_LIST_INT_H_

typedef struct linked_list_int linked_list_int;
typedef struct linked_list_int_node linked_list_int_node;

linked_list_int * linked_list_create();
// Cria uma nova lista em memória. Retorna um ponteiro para a lista recém criada.

int linked_list_get(linked_list_int * list, int index);
// Retorna um elemento localizado no índice index.

unsigned int linked_list_push_back(linked_list_int * list, int value);
// Adiciona um novo elemento ao final da lista.

unsigned int linked_list_pop_back(linked_list_int * list);
// Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.

unsigned int linked_list_size(linked_list_int * list);
// Retorna a quantidade de elementos na lista.

int linked_list_find(linked_list_int * list, int element);
// Busca um elemento na lista. Retorna o índice onde ele se encontra ou −1 se ele não estiver na lista.

unsigned int linked_list_insert_at(linked_list_int * list, int index, int value);
// Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.

int linked_list_remove_from(linked_list_int * list, int index);
// Remove elemento localizado no índice index.

unsigned int linked_list_capacity(linked_list_int * list);
// Retorna o espaço efetivamente reservado para a lista.

double linked_list_percent_occupied(linked_list_int * list);
// Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0,0 e 1,0.

void linked_list_destroy(linked_list_int * list);
// Libera memória usado pela lista list.

#endif