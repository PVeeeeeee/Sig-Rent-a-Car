///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto Sistema de Locação de Veículos                   ///
///               Developed by Pedro Vitor and Elder Bruno                  ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>

// FUNÇÕES
void menu_principal(void);

// FUNÇÃO MAIN
int main(void) {
    menu_principal();
}

// MENU_PRINCIPAL
void menu_principal(void) {
    printf("_____--------------------------------------------------------_____");
    printf("|   |                  == SIG-Rent-a-Car ==                  |   |");
    printf("|   |             Sistema de Locação de Veículos             |   |");
    printf("------------------------------------------------------------------");
    printf("|                       1 - Módulo Pessoas                       |");
    printf("|                       2 - Módulo Veículos                      |");
    printf("|                       3 - Módulo Serviços                      |");
    printf("|                       3 - Módulo Sobre                         |");
    printf("|                       0 - Sair                                 |");
    printf("------------------------------------------------------------------");
    printf(" ");
    printf("-> Escolha sua opção: ");
}