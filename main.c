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
#include <stdlib.h>
//#include <windows.h>


// ATIVANDO FUNÇÕES
void menu_principal(void);
void menu_sobre(void);

    // PESSOAS
void menu_pessoas(void);
void menu_cadastrar_pessoa(void);
void menu_checar_pessoa(void);
void menu_alterar_pessoa(void);
void menu_excluir_pessoa(void);

    // VEÍCULOS
void menu_veiculos(void);
void menu_cadastrar_veiculo(void);

    // LOCAÇÕES
void menu_locacoes(void);

// FUNÇÃO MAIN
int main(void) {
    //SetConsoleOutputCP(CP_UTF8);
    menu_principal();
    menu_sobre();

    menu_pessoas();
    menu_cadastrar_pessoa();
    menu_checar_pessoa();
    menu_alterar_pessoa();
    menu_excluir_pessoa();

    menu_veiculos();
    menu_cadastrar_veiculo();

    menu_locacoes();
    return 0;
}

// FUNÇÕES

// MENU_PRINCIPAL
void menu_principal(void) {
    system("clear||cls");
    int opcao;
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                    OPÇÕES                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                    1 - Pessoas                         |\n");
    printf("|                    2 - Veículos                        |\n");
    printf("|                    3 - Serviços                        |\n");
    printf("|                    4 - Sobre                           |\n");
    printf("|                    0 - Sair                            |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opcao);
}

// MENU_SOBRE
void menu_sobre(void) {
    system("clear||cls");
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
    printf("|          curso, como forma de avaliação. \u00A9 2024                |\n");
    printf("|                                                                |\n");
    printf("------------------------------------------------------------------\n");
    printf("|                                                                |\n");
    printf("|                          Developed by:                         |\n");
    printf("|           Pedro Vitor (https://github.com/PVeeeeeee) and       |\n");
    printf("|             Elder Bruno (https://github.com/veraxqy)           |\n");
    printf("|                                                                |\n");
    printf("|                       Universidade Federal do                  |\n");
    printf("|               Rio Grande do Norte (UFRN) \u00A9 2024                |\n");
    printf("|                                                                |\n");
    printf("------------------------------------------------------------------\n");
}

// MENU PESSOAS
void menu_pessoas(void) {
    system("clear||cls");
    int opcao;
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                   PESSOAS                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                 1 - Cadastrar Pessoa                   |\n");
    printf("|                 2 - Checar Pessoa                      |\n");
    printf("|                 3 - Relatório                          |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opcao);
}

// MENU CADASTRAR PESSOA
void menu_cadastrar_pessoa(void) {
    system("clear||cls");

    // VARIÁVEIS
    char nome[51];
    char cpf[12];
    char data_nasc[9];
    char telefone[12];
    char email[26];
    char fun[2];

    // FORM
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          CADASTRAR PESSOA          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | Nome: \n");
    printf("|   | ");
    scanf("%50s", nome);
    printf("|   | CPF: \n");
    printf("|   | ");
    scanf("%11s", cpf);
    printf("|   | Dtd. Nascimento: \n");
    printf("|   | ");
    scanf("%8s", data_nasc);
    printf("|   | Telefone: \n");
    printf("|   | ");
    scanf("%11s", telefone);
    printf("|   | E-mail:  \n");
    printf("|   | ");
    scanf("%25s", email);
    printf("|   | Funcionário (S/N): \n");
    printf("|   | ");
    scanf("%1s", fun);
    printf("|   |\n");
    printf("--------------------------------------\n");
    printf("|   | Pessoa Cadastrada com Sucesso! ");
    printf("\n");
}

// MENU CHECAR PESSOA
void menu_checar_pessoa(void) {
    system("clear||cls");
    char cpf[12];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            CHECAR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o CPF: ");
    scanf("%11s", cpf);
    printf("----------------------------------------------\n");

}

// MENU ALTERAR PESSOA
void menu_alterar_pessoa(void) {
    system("clear||cls");
    char cpf[12];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           ALTERAR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o CPF: ");
    scanf("%11s", cpf);
    printf("----------------------------------------------\n");
}

// MENU EXCLUIR PESSOA
void menu_excluir_pessoa(void) {
    system("clear||cls");
    char cpf[12];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           EXCLUIR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o CPF: ");
    scanf("%11s", cpf);
    printf("----------------------------------------------\n");
}

// MENU VEÍCULOS
void menu_veiculos(void) {
    system("clear||cls");
    int opcao;
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                  VEÍCULOS                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                 1 - Cadastrar Veículo                  |\n");
    printf("|                 2 - Checar Veículo                     |\n");
    printf("|                 3 - Relatório                          |\n");
    printf("|                 4 - Cadastrar Marca                    |\n");
    printf("|                 5 - Cadastrar Tipo                     |\n");
    printf("|                 6 - Cadastrar Combustível              |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opcao);
}

// MENU CADASTRAR VEÍCULO
void menu_cadastrar_veiculo(void) {
    system("clear||cls");

    // VARIÁVEIS
    char chassi[18];
    char placa[8];
    char marca[15];
    char modelo[25];
    char tipo[12];
    char combustivel[15];
    int ano;
    int lugares;
    float valor;

    // FORM
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CADASTRAR VEÍCULO          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | Chassi:  \n");
    printf("|   | ");
    scanf("%17s", chassi);
    printf("|   | Placa: \n");
    printf("|   | ");
    scanf("%7s", placa);
    printf("|   | Marca: \n");
    printf("|   | ");
    scanf("%14s", marca);
    printf("|   | Modelo: \n");
    printf("|   | ");
    scanf("%24s", modelo);
    printf("|   | Tipo: \n");
    printf("|   | ");
    scanf("%11s", tipo);
    printf("|   | Combustível: \n");
    printf("|   | ");
    scanf("%14s", combustivel);
    printf("|   | Ano: \n");
    printf("|   | ");
    scanf("%d", &ano);
    printf("|   | Lugares: \n");
    printf("|   | ");
    scanf("%d", &lugares);
    printf("|   | Valor: \n");
    printf("|   | ");
    scanf("%f", &valor);
    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Veículo Cadastrado com Sucesso! ");
    printf("\n");
}

// MENU LOCAÇÕES
void menu_locacoes(void) {
    system("clear||cls");
    int opcao;
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                  LOCAÇÕES                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                1 - Cadastrar Locação                   |\n");
    printf("|                2 - Checar Locação                      |\n");
    printf("|                3 - Relatório                           |\n");
    printf("|                0 - Menu Principal                      |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opcao);
}