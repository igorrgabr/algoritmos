#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list_int.h"

void linked_list_print(linked_list_int *l) {
    int v;
    for (int i = 0; i < linked_list_size(l); i++) {
        v = linked_list_get(l, i);
        if (v == -1) {
            fprintf(stderr, "Erro! Indice %d nao eh valido!", i);
            exit(1);
        } else {
            printf("%d ", v);
        }
    }
    printf("\n");
}

int main() {
    clock_t t;
    int size;

    // CRIAR A LISTA
    linked_list_int *l1 = linked_list_create();
    printf("Lista criada.\n");
    printf("\n");

    // INSERIR ELEMENTOS NO FINAL DA LISTA
    t = clock();
    int i = 0;
    while (i++ < 10) {
        size = linked_list_push_back(l1, i);
    }
    t = clock() - t;

    printf("Tempo para insercao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    t = clock();
    linked_list_print(l1);
    printf("\n");
    t = clock() - t;

    printf("Tempo para impressao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    // REMOVER ELEMENTO DO FINAL DA LISTA
    t = clock();
    size = linked_list_pop_back(l1);
    t = clock() - t;

    printf("Tempo para remocao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    // PEGAR TAMANHO DA LISTA
    t = clock();
    size = linked_list_size(l1);
    t = clock() - t;

    printf("Tempo para pegar tamanho: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("Tamanho: %d\n", size);
    printf("\n");
    // printf nova lista

    // ACHAR ÍNDICE DE ELEMENTO
    t = clock();
    int ind = linked_list_find(l1, 5);
    t = clock() - t;

    printf("Tempo para achar indice: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    if (ind == -1) printf("Indice nao encontrado.\n");
    else printf("Indice do elemento: %d\n", ind);
    printf("\n");
    // printf nova lista

    // ADICIONAR NO ÍNDICE
    t = clock();
    size = linked_list_insert_at(l1, 5, 10);
    t = clock() - t;

    printf("Tempo para adicionar: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");
    // printf nova lista

    // REMOVER DO ÍNDICE
    t = clock();
    size = linked_list_remove_from(l1, 3);
    t = clock() - t;

    printf("Tempo para remover: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    t = clock();
    linked_list_print(l1);
    printf("\n");
    t = clock() - t;

    printf("Tempo para impressao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    // PERCENTUAL
    printf("Percentual usado: %.1lf.\n", linked_list_percent_occupied(l1));
    printf("\n");

    // LIBERAR MEMÓRIA DA LISTA
    t = clock();
    linked_list_destroy(l1);
    t = clock() - t;

    printf("Tempo para liberacao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);

    return 0;
}
