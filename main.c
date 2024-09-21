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
//#include <windows.h>


// FUNÇÕES
void menu_principal(void);
void menu_sobre(void);
void menu_desenvolvedores(void);

// FUNÇÃO MAIN
int main(void) {
    //SetConsoleOutputCP(CP_UTF8);
    menu_principal();
    menu_sobre();
}

// MENU_PRINCIPAL
void menu_principal(void) {
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("---------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                    1 - Pessoas                         |\n");
    printf("|                    2 - Veículos                        |\n");
    printf("|                    3 - Serviços                        |\n");
    printf("|                    4 - Sobre                           |\n");
    printf("|                    0 - Sair                            |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: \n");
}

// MENU_SOBRE
void menu_sobre(void) {
    printf("_____--------------------------------------------------------_____\n");
    printf("|   |                  == SIG-Rent-a-Car ==                  |   |\n");
    printf("|   |             Sistema de Locação de Veículos             |   |\n");
    printf("------------------------------------------------------------------\n");
    printf("|   |                         SOBRE                          |   |\n");
    printf("------------------------------------------------------------------\n");
    printf("|                                                                |\n");
    printf("| Esse é um projeto referente à disciplina DCT1106 - PROGRAMAÇÃO |\n");
    printf("|   do curso de Sistemas de Informação, da Universidade Federal  |\n");
    printf("|      do Rio Grande do Norte (UFRN). Seu objetivo é criarmos    |\n");
    printf("|    um Sistema para gestão de Locação de Veículos, utilizando   |\n");
    printf("|    o conhecimento adquirido durante o todo o 2° semestre do    |\n");
    printf("|          curso, como forma de avaliação. \u00A9 2024           |\n");
    printf("|                                                                |\n");
    printf("------------------------------------------------------------------\n");
}

// MENU DESENVOLVEDORES
void menu_desenvolvedores(void) {
    printf("_____--------------------------------------------------------_____\n");
    printf("|   |                  == SIG-Rent-a-Car ==                  |   |\n");
    printf("|   |             Sistema de Locação de Veículos             |   |\n");
    printf("------------------------------------------------------------------\n");
    printf("|   |                     DESENVOLVEDORES                        |   |\n");
    printf("------------------------------------------------------------------\n");
    printf("|                                                                |\n");
    printf("|                          Developed by:                         |\n");
    printf("|           Pedro Vitor (https://github.com/PVeeeeeee) and       |\n");
    printf("|              Elder Bruno (https://github.com/veraxqy           |\n");
    printf("|                                                                |\n");
    printf("|                       Universidade Federal do                  |\n");
    printf("|               Rio Grande do Norte (UFRN) \u00A9 2024           |\n");
    printf("|                                                                |\n");
    printf("------------------------------------------------------------------\n");
}