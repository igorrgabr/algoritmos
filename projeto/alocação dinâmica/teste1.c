#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list_int.h"

void error_at_insert(array_list_int *l, int v) {
    fprintf(stderr, "Erro! Valor %d nao inserido!\n", v);
    fprintf(stderr, "A lista possui %d elementos.\n", array_list_size(l));
    exit(1);
}

void print_list(array_list_int *l) {
    int v, error;
    for (unsigned int i = 0; i < array_list_size(l); i++) {
        v = array_list_get(l, i, &error);
        if (!error) {
        printf("%d ", v);
        } else {
            fprintf(stderr, "Erro! Indice %d nao eh valido!\n", i);
            exit(2);
        }
    }
    printf("\n");
}

int main() {
    clock_t t;
    unsigned int i, n, x;
    array_list_int *l1 = array_list_create();
    scanf("%d", &n);
    t = clock();
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        increase_memory(l1); // aloca mais memória quando necessário
        if (array_list_push_back(l1, x) != (i + 1)) {
            error_at_insert(l1, x);
        }
    }
    t = clock() - t;
    double total_time = (((double) t) / CLOCKS_PER_SEC) * 1000; 
    print_list(l1);
    printf("Tamanho do vetor: %d\n", array_list_size(l1));
    fprintf(stderr, "Insercao de %d elementos em %.4lf milissegundos.\n", n, total_time);
    return 0;
}