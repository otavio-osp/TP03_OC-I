# Trabalho Prático 03 – Hierarquia de Memória

**Disciplina:** CCF 252 – Organização de Computadores I  
**Instituição:** Universidade Federal de Viçosa (UFV) - Campus Florestal  
**Professor:** José Augusto Miranda Nacif  
**Alunos:** Otávio Soares Pedroso (6593) e Pedro Mendes Gonzaga (6563)

---

## 🎯 Objetivo do Trabalho
Este repositório contém a implementação do Trabalho Prático 03, cujo objetivo principal é demonstrar, na prática, como as operações de acesso à memória e a arquitetura de **Memória Cache** (tamanho, blocos, associatividade, etc.) impactam diretamente o desempenho geral de algoritmos, utilizando ferramentas de simulação e análise como o `perf` e o `valgrind`.

## 📁 Estrutura do Repositório

O repositório foi modularizado para facilitar a compilação e o entendimento de cada etapa exigida:

### 1. Código-fonte dos Algoritmos de Ordenação (Tópicos 2 a 5)
Implementação de quatro algoritmos clássicos para análise de desempenho e testes com o Valgrind:
- `main.c`: Ponto de entrada que orquestra as chamadas dos algoritmos, geração de vetores aleatórios e contagem de tempo.
- `sort.h`: Arquivo de cabeçalho com as assinaturas das funções.
- `bubblesort.c`: Implementação do Bubblesort (O(n²)).
- `insertionsort.c`: Implementação do Insertionsort (O(n²)).
- `quicksort.c`: Implementação do Quicksort (O(n log n)).
- `radixsort.c`: Implementação do Radixsort (O(nk)).
- `utils.c`: Funções auxiliares (como `troca`/swap).

### 2. Otimização de Memória Exclusiva (Tópico 6)
- `aos_soa.c`: Arquivo C independente que contém o código do tópico 6. Este arquivo implementa e compara o desempenho entre **AoS (Array of Structures)** e **SoA (Structure of Arrays)**, demonstrando puramente os efeitos da Localidade Espacial (Data-Oriented Design) no carregamento das linhas de cache L1.

### 3. Resultados Brutos e Relatórios
- `resultados/`: Diretório contendo os *logs* brutos das execuções do `perf` e do `valgrind` (cachegrind) documentando a experimentação.
- `6593-6563-otavio-pedro-relatorio-tp03.md`: Relatório final completo descrevendo a arquitetura da máquina (Core i7-13620H), análise dos algoritmos e discussão detalhada sobre as miss rates reportadas pelo simulador.
- `6593-6563-otavio-pedro-colab-tp03.ipynb`: Notebook exportado contendo as células de execução no ambiente do Google Colaboratory (Tópico 7).

---

## 🚀 Como Compilar e Executar

Como o projeto foi modularizado, existem duas formas principais de compilar manualmente os arquivos dependendo de qual experimento deseja rodar.

### Experimento A: Algoritmos de Ordenação (`perf` / `valgrind`)
Para compilar todos os arquivos relacionados aos algoritmos de ordenação, execute:
```bash
gcc -O2 main.c utils.c bubblesort.c radixsort.c quicksort.c insertionsort.c -o sort
```
Para executar (exemplo com Radixsort e 10.000 elementos):
```bash
./sort radix 10000
```
Opções de algoritmos disponíveis: `bubble`, `radix`, `quick`, `insert`.

### Experimento B: AoS vs SoA (Otimização de Layout de Memória)
Para compilar exclusivamente o simulador de física do experimento de Data-Oriented Design:
```bash
gcc -O2 aos_soa.c -o aos_soa
```
Para executar e comparar:
```bash
./aos_soa aos
./aos_soa soa
```

---

*Repositório criado para fins acadêmicos - CCF252 Organização de Computadores I.*
