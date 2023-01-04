#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list_int.h"

void error_at_insert(array_list_int *l, int v) {
    fprintf(stderr, "Erro! Valor %d nao inserido!\n", v);
    fprintf(stderr, "A lista possui %d elementos.\n", array_list_size(l));
    exit(1);
}

void empty_list(array_list_int *l) {
    fprintf(stderr, "Lista vazia!\n");
    exit(2);
}

void print_list(array_list_int *l) {
    int v, error;
    for (unsigned int i = 0; i < array_list_size(l); i++) {
        v = array_list_get(l, i, &error);
        if (!error) {
        printf("%d ", v);
        } else {
            fprintf(stderr, "Erro! Indice %d nao eh valido!\n", i);
            exit(3);
        }
    }
    printf("\n");
}

int main() {
    clock_t t;
    unsigned int i, n, x;
    array_list_int *l3 = array_list_create();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        increase_memory(l3); // aloca mais memória quando necessário
        if (array_list_push_back(l3, x) != (i + 1)) {
            error_at_insert(l3, x);
        }
    }
    int err, num = array_list_get(l3, array_list_size(l3)-1, &err);
    printf("Tamanho atual do vetor: %d\n", array_list_size(l3));
    print_list(l3);
    t = clock();
    if (array_list_pop_back(l3) == 0) empty_list(l3);
    t = clock() - t;
    double total_time = (((double) t) / CLOCKS_PER_SEC) * 1000; 
    printf("Tamanho do vetor: %d\n", array_list_size(l3));
    print_list(l3);
    fprintf(stderr, "Remocao do elemento %d em %.4lf milissegundos.\n", num, total_time);
    return 0;
}