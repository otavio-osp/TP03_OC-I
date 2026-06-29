#include <stdlib.h>
#include "sort.h"

// 2. Radixsort
int obterMaximo(int vetor[], int tam) {
    int maior = vetor[0];
    for (int i = 1; i < tam; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    return maior;
}

void ordenacaoContagem(int vetor[], int tam, int exp) {
    int *saida = (int *)malloc(tam * sizeof(int));
    int i, contagem[10] = { 0 };
    for (i = 0; i < tam; i++) contagem[(vetor[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (i = tam - 1; i >= 0; i--) {
        saida[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }
    for (i = 0; i < tam; i++) vetor[i] = saida[i];
    free(saida);
}

void radixsort(int vetor[], int tam) {
    int maior = obterMaximo(vetor, tam);
    for (int exp = 1; maior / exp > 0; exp *= 10)
        ordenacaoContagem(vetor, tam, exp);
}
