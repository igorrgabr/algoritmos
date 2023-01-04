#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int r, i, qtd;
    scanf("%d", &qtd);
    printf("%d\n",qtd);
    for (i = 0; i < qtd; i++) {
        r = rand();
        printf("%d ", r);
    }
}