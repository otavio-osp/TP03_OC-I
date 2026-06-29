#include "sort.h"

// 1. Bubblesort
void bubblesort(int vetor[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1])
                troca(&vetor[j], &vetor[j + 1]);
        }
    }
}
