// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include "../../funcoes.h"


// MENU PESSOAS
int menu_pessoas(void) {
    int opc_pessoas;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                   PESSOAS                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                 1 - Cadastrar Pessoa                   |\n");
    printf("|                 2 - Checar Pessoa                      |\n");
    printf("|                 3 - Relatórios                         |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_pessoas = validar_opcao(0, 3);
    return opc_pessoas;
}

// MENU CADASTRAR PESSOA
void menu_cadastrar_pessoa(void) {
    // VARIÁVEIS
    char nome[51];
    char cpf[12];
    char data_nasc[9];
    char telefone[12];
    char email[26];
    char fun[2];

    // FORM
    system("clear||cls");
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
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU CHECAR PESSOA
void menu_checar_pessoa(void) {
    char cpf[12];
    int opc_check_pessoa;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            CHECAR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o CPF: ");
    scanf("%11s", cpf);
    printf("|   | Nome: \n");
    printf("|   | Idade: \n");
    printf("|   | Telefone: \n");
    printf("|   | E-mail: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    printf("\n");
    opc_check_pessoa = validar_opcao(0, 2);

    if (opc_check_pessoa == 1) {
        menu_alterar_pessoa();
    } else if (opc_check_pessoa == 2) {
        menu_excluir_pessoa();
    }
}

// MENU ALTERAR PESSOA
void menu_alterar_pessoa(void) {
    int opc_altr_pessoa;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           ALTERAR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("|   | Idade: \n");
    printf("|   | Telefone: \n");
    printf("|   | E-mail: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja alterar?:\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Nome       2 - Dta. Nascimento |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | 3 - Telefone   4 - E-mail          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | 5 - Função     0 - Sair            |   |\n");
    printf("_____------------------------------------_____\n");
    printf("\n");
    printf("----------------------------------------------\n");
    opc_altr_pessoa = validar_opcao(0, 5);
    // fazer demais menus
}

// MENU EXCLUIR PESSOA
void menu_excluir_pessoa(void) {
    char opc_exclr_pessoa;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           EXCLUIR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("|   | Idade: \n");
    printf("|   | Telefone: \n");
    printf("|   | E-mail: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_pessoa);
    getchar();
    printf("----------------------------------------------\n");
}

// MENU RELATÓRIO PESSOA
int menu_relatorio_pessoa(void) {
    int opc_relt_pessoa;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |              RELATÓRIO               |   |\n");
    printf("------------------------------------------------\n");
    printf("|                                              |\n");
    printf("|               1 - Clientes                   |\n");
    printf("|               2 - Funcionários               |\n");
    printf("|               3 - Geral                      |\n");
    printf("|               0 - Voltar                     |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    opc_relt_pessoa = validar_opcao(0, 3);
    return opc_relt_pessoa;
}
    

// RELATÓRIO CLIENTES
void relatorio_clientes(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - CLIENTES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|            ORDEM ALFABÉTICA [A-Z]            |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO FUNCIONÁRIOS
void relatorio_funcionarios(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |       RELATÓRIO - FUNCIONÁRIOS       |   |\n");
    printf("------------------------------------------------\n");
    printf("|            ORDEM ALFABÉTICA [A-Z]            |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO PESSOAS GERAL
void relatorio_geral_pessoas(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |          RELATÓRIO - PESSOAS         |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}