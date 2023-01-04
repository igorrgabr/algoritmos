#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list_int.h"

void error_at_insert(array_list_int *l, int v) {
    fprintf(stderr, "Erro! Valor %d nao inserido!\n", v);
    fprintf(stderr, "A lista possui %d elementos.\n", array_list_size(l));
    exit(1);
}

void error_at_find(array_list_int *l, int v) {
    fprintf(stderr, "Erro! Valor %d nao encontrado!\n", v);
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
    array_list_int *l2 = array_list_create();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        increase_memory(l2); // aloca mais memória quando necessário
        if (array_list_push_back(l2, x) != (i + 1)) {
            error_at_insert(l2, x);
        }
    }
    int num;
    t = clock();
    scanf("%d", &num);
    int res = array_list_find(l2, num);
    t = clock() - t;
    if (res == -1) error_at_find(l2, num);
    else printf("Valor %d encontrado no indice %d.\n", num, res);
    double tempo_total = ((double) t / CLOCKS_PER_SEC) * 1000;
    printf("Tempo de busca: %.4lf milissegundos.\n", tempo_total);
    return 0;
}