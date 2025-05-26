#include <stdio.h>

// Função recursiva para movimentação da Torre (direita)
void move_torre(int passos) {
    if (passos <= 0) return;
    printf("Direita\n");
    move_torre(passos - 1);
}

// Função recursiva para movimentação da Rainha (esquerda)
void move_rainha(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    move_rainha(passos - 1);
}

// Função recursiva para movimentação do Bispo (diagonal: cima+direita)
// utiliza loops aninhados: externo para vertical, interno para horizontal
void move_bispo(int passos) {
    if (passos <= 0) return;

    // um “passo” diagonal: primeiro imprime vertical, depois horizontal
    for (int v = 0; v < 1; v++) {
        printf("Cima, ");
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }

    move_bispo(passos - 1);
}

int main() {
    // define quantas casas cada peça deve percorrer
    int BISPO  = 5, TORRE  = 5, RAINHA = 8;

    // Bispo
    printf("Bispo:\n");
    move_bispo(BISPO);

    printf("\nTorre:\n");
    move_torre(TORRE);

    printf("\nRainha:\n");
    move_rainha(RAINHA);

    // Cavalo: movimento em "L" para cima e direita (2 para cima, 1 para a direita)
    // usa loops aninhados com condições, continue e break
    printf("\nCavalo:\n");
    for (int etapa = 0; etapa < 2; etapa++) {
        // primeiro, duas iterações de "Cima"
        printf("Cima\n");
        // em cada iteração, entra num loop interno que só faz algo na 2ª vez
        for (int sub = 0; sub < 1; sub++) {
            if (etapa == 1) {
                printf("Direita\n");
                break;        // sai do interno após imprimir
            }
            continue;         // nas demais, volta para o interno
        }
    }

    return 0;
}