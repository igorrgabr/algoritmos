#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list_int.h"

void print_list(array_list_int *l) {
    int v, error;
    for (unsigned int i = 0; i < array_list_size(l); i++) {
        v = array_list_get(l, i, &error);
        if (!error) {
        printf("%d ", v);
        } else {
            fprintf(stderr, "Erro! Indice %d nao eh valido!\n", i);
            exit(1);
        }
    }
    printf("\n");
}

int main() {
    clock_t t;
    int size;

    // CRIAR A LISTA
    array_list_int *l1 = array_list_create();
    printf("Lista criada.\n");
    printf("\n");

    // INSERIR ELEMENTOS NO FINAL DA LISTA
    t = clock();
    int i = 0, count_mem = 0;
    while (i++ < 100) {
        if (increase_memory(l1)) {
            count_mem++;
        }
        size = array_list_push_back(l1, i);
    }
    t = clock() - t;

    printf("Tempo para insercao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("Foi necessario acrescentar memoria %d vezes.\n", count_mem);
    printf("\n");

    t = clock();
    print_list(l1);
    printf("\n");
    t = clock() - t;

    printf("Tempo para impressao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    // PEGAR ELEMENTO DO ÍNDICE
    t = clock();
    size = array_list_pop_back(l1);
    t = clock() - t;

    printf("Tempo para pegar elemento: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");
    // printf nova lista

    // PEGAR TAMANHO DA LISTA
    t = clock();
    size = array_list_size(l1);
    t = clock() - t;

    printf("Tempo para pegar tamanho: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");
    // printf nova lista

    // ACHAR ÍNDICE DE ELEMENTO
    t = clock();
    int ind = array_list_find(l1, 10);
    t = clock() - t;

    printf("Tempo para achar indice: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("Indice do elemento: %d\n", ind);
    printf("\n");
    // printf nova lista

    // ADICIONAR NO ÍNDICE
    t = clock();
    size = array_list_insert_at(l1, 5, 10);
    t = clock() - t;

    printf("Tempo para adicionar: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");
    // printf nova lista

    // REMOVER DO ÍNDICE
    t = clock();
    size = array_list_remove_from(l1, 3);
    t = clock() - t;

    printf("Tempo para remover: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");
    
    t = clock();
    print_list(l1);
    printf("\n");
    t = clock() - t;

    printf("Tempo para impressao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);
    printf("\n");

    // CAPACIDADE
    printf("Capacidade: %d.\n", array_list_capacity(l1));
    printf("\n");

    // PERCENTUAL
    printf("Percentual usado: %.1lf.\n", array_list_percent_occupied(l1));
    printf("\n");

    // LIBERAR MEMÓRIA DA LISTA
    t = clock();
    array_list_destroy(l1);
    t = clock() - t;

    printf("Tempo para liberacao: %.4lf milissegundos.\n", ((double) t / CLOCKS_PER_SEC) * 1000);

    return 0;
}
