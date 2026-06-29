// Otimizacao de Memoria Cache: AoS vs SoA (Array of Structs vs Struct of Arrays)

// Este codigo demonstra de forma pratica o principio de "Localidade Espacial" na Cache L1.
// Simula uma atualizacao de 10 milhoes de particulas (x = x + vx).

// Abordagem 1 (AoS): Entope a linha de cache (64 bytes) com variaveis inuteis para
// a iteracao atual (y, z, massa...), causando milhoes de Cache Misses e lentidao.

// Abordagem 2 (SoA): Separa as variaveis em arrays isolados. A linha de cache
// carregara exclusivamente blocos uteis de posicoes 'x', tirando total proveito
// da arquitetura, diminuindo os misses em quase 10x e rodando muito mais rapido!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10000000 // 10 milhoes de particulas

// -- Abordagem 1: Array de Estruturas (AoS) --
typedef struct {
    float x, y, z;
    float vx, vy, vz;
    float massa;
    float tempo_vida;
} Particula_AoS;

void atualizar_aos(Particula_AoS *particulas) {
    // Atualiza apenas a posicao x usando a velocidade x
    for (int i = 0; i < N; i++) {
        particulas[i].x += particulas[i].vx;
    }
}

// -- Abordagem 2: Estrutura de Arrays (SoA) --
typedef struct {
    float *x, *y, *z;
    float *vx, *vy, *vz;
    float *massa;
    float *tempo_vida;
} Particulas_SoA;

void atualizar_soa(Particulas_SoA *particulas) {
    // Atualiza apenas a posicao x usando a velocidade x
    for (int i = 0; i < N; i++) {
        particulas->x[i] += particulas->vx[i];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <aos|soa>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "aos") == 0) {
        Particula_AoS *p_aos = (Particula_AoS *)malloc(N * sizeof(Particula_AoS));
        // Inicializacao para garantir que as paginas entrem na memoria
        for (int i = 0; i < N; i++) {
            p_aos[i].x = 0.0f;
            p_aos[i].vx = 1.0f;
        }
        
        atualizar_aos(p_aos);
        
        volatile float resultado = p_aos[0].x; // Evita otimizacao do compilador
        free(p_aos);
    } 
    else if (strcmp(argv[1], "soa") == 0) {
        Particulas_SoA p_soa;
        p_soa.x = (float *)malloc(N * sizeof(float));
        p_soa.y = (float *)malloc(N * sizeof(float));
        p_soa.z = (float *)malloc(N * sizeof(float));
        p_soa.vx = (float *)malloc(N * sizeof(float));
        p_soa.vy = (float *)malloc(N * sizeof(float));
        p_soa.vz = (float *)malloc(N * sizeof(float));
        p_soa.massa = (float *)malloc(N * sizeof(float));
        p_soa.tempo_vida = (float *)malloc(N * sizeof(float));
        
        for (int i = 0; i < N; i++) {
            p_soa.x[i] = 0.0f;
            p_soa.vx[i] = 1.0f;
        }

        atualizar_soa(&p_soa);

        volatile float resultado = p_soa.x[0];
        free(p_soa.x); free(p_soa.y); free(p_soa.z);
        free(p_soa.vx); free(p_soa.vy); free(p_soa.vz);
        free(p_soa.massa); free(p_soa.tempo_vida);
    } 
    else {
        printf("Metodo desconhecido.\n");
    }

    return 0;
}
