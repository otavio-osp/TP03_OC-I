#include "sort.h"

// 3. Quicksort
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, pi - 1);
        quicksort(vetor, pi + 1, fim);
    }
}
