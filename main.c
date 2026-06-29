#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

// Referências dos Algoritmos de Ordenação:
// As implementações base dos algoritmos abaixo (Bubblesort, Radixsort, Quicksort e Insertionsort)
// foram inspiradas e adaptadas a partir de referências clássicas de C do GeeksforGeeks:
// https://www.geeksforgeeks.org/sorting-algorithms/

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <algoritmo> <tamanho>\n", argv[0]);
        return 1;
    }

    char *algoritmo = argv[1];
    int tamanho = atoi(argv[2]);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    srand(42); 
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000;
    }

    // Variavel para evitar que o compilador otimize o vetor
    volatile int resultado = 0;

    if (strcmp(algoritmo, "bubble") == 0) {
        bubblesort(vetor, tamanho);
    } else if (strcmp(algoritmo, "radix") == 0) {
        radixsort(vetor, tamanho);
    } else if (strcmp(algoritmo, "quick") == 0) {
        quicksort(vetor, 0, tamanho - 1);
    } else if (strcmp(algoritmo, "insert") == 0) {
        insertionsort(vetor, tamanho);
    } else {
        printf("Algoritmo desconhecido\n");
    }

    resultado += vetor[0]; 
    free(vetor);
    return 0;
}
