#include <stdio.h>
#include "funcoes.h"

// LIMPA BUFFER
void limpa_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
}


//VALIDACOES

int validar_opcao(int limite_inferior, int limite_superior) {
    int opcao;

    while (1) {
        printf("-> Escolha sua opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); 
        } else if (opcao < limite_inferior || opcao > limite_superior) {
            printf("Opção fora do intervalo permitido (%d - %d). Tente novamente.\n", limite_inferior, limite_superior);
        } else {
            break;
        }
    }
    return opcao;
}
