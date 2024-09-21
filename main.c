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
#include <windows.h>


// FUNÇÕES
void menu_principal(void);

// FUNÇÃO MAIN
int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    menu_principal();
}

// MENU_PRINCIPAL
void menu_principal(void) {
    printf("_____--------------------------------------------------------_____\n");
    printf("|   |                  == SIG-Rent-a-Car ==                  |   |\n");
    printf("|   |             Sistema de Locação de Veículos             |   |\n");
    printf("------------------------------------------------------------------\n");
    printf("|                 1 - Pessoas                                    |\n");
    printf("|                 2 - Veículos                                   |\n");
    printf("|                 3 - Serviços                                   |\n");
    printf("|                 4 - Sobre                                      |\n");
    printf("|                 0 - Sair                                       |\n");
    printf("------------------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: \n");
}