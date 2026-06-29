#include "sort.h"

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
