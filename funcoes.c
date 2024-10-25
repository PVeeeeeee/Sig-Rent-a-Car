// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// FUNÇÕES

// LIMPA BUFFER
void limpa_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
}

// MENU_PRINCIPAL
int menu_principal(void) {
    int opc_principal;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                    OPÇÕES                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                    1 - Pessoas                         |\n");
    printf("|                    2 - Veículos                        |\n");
    printf("|                    3 - Locações                        |\n");
    printf("|                    4 - Sobre                           |\n");
    printf("|                    0 - Sair                            |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_principal);
    getchar();
    return opc_principal;
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
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

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
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_pessoas);
    getchar();
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
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_check_pessoa);
    printf("----------------------------------------------\n");

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
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_altr_pessoa);
    printf("----------------------------------------------\n");
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
    printf("|               0 - Menu Principal             |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_relt_pessoa);
    getchar();
    return opc_relt_pessoa;
}

// RELATÓRIO CLIENTES
void relatorio_clientes(void) {
    system("clear||cls");
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

// MENU VEÍCULOS
int menu_veiculos(void) {
    int opc_veiculos;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                  VEÍCULOS                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                 1 - Cadastrar Veículo                  |\n");
    printf("|                 2 - Checar Veículo                     |\n");
    printf("|                 3 - Relatórios                         |\n");
    printf("|                 4 - Marcas                             |\n");
    printf("|                 5 - Tipos                              |\n");
    printf("|                 6 - Combustíveis                       |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_veiculos);
    getchar();
    return opc_veiculos;
}

// MENU CADASTRAR VEÍCULO
void menu_cadastrar_veiculo(void) {
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
    system("clear||cls");
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
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU CHECAR VEÍCULO
void menu_checar_veiculo(void) {
    char placa[8];
    int opc_check_veiculo;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           CHECAR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite a Placa: ");
    scanf("%7s", placa);
    printf("|   | Chassi:  \n");
    printf("|   | Marca: \n");
    printf("|   | Modelo: \n");
    printf("|   | Tipo: \n");
    printf("|   | Combustível: \n");
    printf("|   | Ano: \n");
    printf("|   | Lugares: \n");
    printf("|   | Valor: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_check_veiculo);
    printf("----------------------------------------------\n");

    if (opc_check_veiculo == 1) {
        menu_alterar_veiculo();
    } else if (opc_check_veiculo == 2) {
        menu_excluir_veiculo();
    }
}

// MENU ALTERAR VEÍCULO
void menu_alterar_veiculo(void) {
    int opc_altr_veiculo;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          ALTERAR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Chassi:  \n");
    printf("|   | Marca: \n");
    printf("|   | Modelo: \n");
    printf("|   | Tipo: \n");
    printf("|   | Combustível: \n");
    printf("|   | Ano: \n");
    printf("|   | Lugares: \n");
    printf("|   | Valor: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja alterar?:\n");
    printf("_____--------------------------------_____\n");
    printf("|   |  1 - Chassi        2 - Marca   |   |\n");
    printf("------------------------------------------\n");
    printf("|   |  3 - Modelo        4 - Tipo    |   |\n");
    printf("------------------------------------------\n");
    printf("|   |  5 - Combustível   6 - Ano     |   |\n");
    printf("------------------------------------------\n");
    printf("|   |  7 - Lugares       8 - Valor   |   |\n");
    printf("------------------------------------------\n");
    printf("|   |            0 - Sair            |   |\n");
    printf("_____--------------------------------_____\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_altr_veiculo);
    printf("------------------------------------------\n");
}

// MENU EXCLUIR VEÍCULO
void menu_excluir_veiculo(void) {
    char opc_exclr_veiculo;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Chassi:  \n");
    printf("|   | Marca: \n");
    printf("|   | Modelo: \n");
    printf("|   | Tipo: \n");
    printf("|   | Combustível: \n");
    printf("|   | Ano: \n");
    printf("|   | Lugares: \n");
    printf("|   | Valor: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_veiculo);
    getchar();
    printf("----------------------------------------------\n");
}

// MENU RELATÓRIO VEÍCULO
int menu_relatorio_veiculo(void) {
    int opc_relt_veiculo;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - VEÍCULOS         |   |\n");
    printf("------------------------------------------------\n");
    printf("|     Os relatórios podem ser visualizados     |\n");
    printf("|           por ordem destas opções:           |\n");
    printf("------------------------------------------------\n");
    printf("|                                              |\n");
    printf("|         1 - Geral          2 - Marca         |\n");
    printf("|                                              |\n");
    printf("|         3 - Modelo         4 - Ano           |\n");
    printf("|                                              |\n");
    printf("|         5 - Combustível    6 - Tipo          |\n");
    printf("|                                              |\n");
    printf("|         7 - Lugares        8 - Valor         |\n");
    printf("|                                              |\n");
    printf("|         9 - Disponíveis    0 - Sair          |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_relt_veiculo);
    getchar();
    return opc_relt_veiculo;
}

// RELATÓRIO VEÍCULO GERAL
void relatorio_geral_veiculos(void) {
    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           VEÍCULOS - GERAL           |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO MARCA
void relatorio_marca_veiculos(void) {
    char marca[15];

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           VEÍCULOS - MARCA           |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite a Marca: ");
    scanf("%14s", marca);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO MODELO
void relatorio_modelo_veiculos(void) {
    char modelo[25];

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           VEÍCULOS - MODELO          |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Modelo: ");
    scanf("%24s", modelo);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO ANO
void relatorio_ano_veiculos(void) {
    int ano;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |            VEÍCULOS - ANO            |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Ano: ");
    scanf("%d", &ano);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO COMBUSTÍVEL
void relatorio_combustivel_veiculos(void) {
    char combustivel[15];

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |        VEÍCULOS - COMBUSTÍVEL        |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Combustível: ");
    scanf("%14s", combustivel);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO TIPO
void relatorio_tipo_veiculos(void) {
    char tipo[12];

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           VEÍCULOS - TIPO            |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Tipo: ");
    scanf("%11s", tipo);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO LUGARES
void relatorio_lugares_veiculos(void) {
    int lugares;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         VEÍCULOS - LUGARES           |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite quantos Lugares: ");
    scanf("%d", &lugares);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO VALOR
void relatorio_valor_veiculos(void) {
    float valor;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |          VEÍCULOS - VALOR            |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Valor: ");
    scanf("%f", valor);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO DISPONIBILIDADE
void relatorio_disponivel_veiculos(void) {
    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |        VEÍCULOS - DISPONÍVEIS        |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// MENU MARCAS
int menu_marcas(void) {
    int opc_marcas;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                     MARCAS                     |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                1 - Cadastrar Marca                     |\n");
    printf("|                2 - Checar Marca                        |\n");
    printf("|                3 - Relatório                           |\n");
    printf("|                0 - Menu Principal                      |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_marcas);
    getchar();
    return opc_marcas;
}

// MENU CADASTRAR MARCA
void menu_cadastrar_marca(void) {
    // VARIÁVEIS
    char nome[25];

    // FORM
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CADASTRAR MARCA          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | Nome:  \n");
    printf("|   | ");
    scanf("%24s", nome);
    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Marca Cadastrada com Sucesso! ");
    printf("\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU TIPOS
int menu_tipos(void) {
    int opc_tipos;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                     TIPOS                      |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                1 - Cadastrar Tipo                      |\n");
    printf("|                2 - Checar Tipo                         |\n");
    printf("|                3 - Relatório                           |\n");
    printf("|                0 - Menu Principal                      |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_tipos);
    getchar();
    return opc_tipos;
}

// MENU COMBUSTÍVEL
int menu_combustiveis(void) {
    int opc_combustiveis;

    system("clear||cls");
    printf("_____------------------------------------------------_____\n");
    printf("|   |              == SIG-Rent-a-Car ==              |   |\n");
    printf("|   |         Sistema de Locação de Veículos         |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|   |                  COMBUSTÍVEIS                  |   |\n");
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                1 - Cadastrar Combustível               |\n");
    printf("|                2 - Checar Combustível                  |\n");
    printf("|                3 - Relatório                           |\n");
    printf("|                0 - Menu Principal                      |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_combustiveis);
    getchar();
    return opc_combustiveis;
}

// MENU LOCAÇÕES
int menu_locacoes(void) {
    int opc_locacoes;

    system("clear||cls");
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
    scanf("%d", &opc_locacoes);
    getchar();
    return opc_locacoes;
}

// MENU CADASTRAR LOCAÇÃO
void menu_cadastrar_locacao(void) {
    // VARIÁVEIS
    char id_locacao[11];
    char cpf_cliente[12];
    char cpf_funcionario[12];
    char placa_veiculo[8];
    char data_inic[9];
    char data_final[9];
    float valor_final;
    char situacao[2];

    // FORM
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CADASTRAR LOCAÇÃO          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | ID:  \n");
    printf("|   | ");
    scanf("%10s", id_locacao);
    printf("|   | Cliente (CPF): \n");
    printf("|   | ");
    scanf("%11s", cpf_cliente);
    printf("|   | Funcionário (CPF): \n");
    printf("|   | ");
    scanf("%11s", cpf_funcionario);
    printf("|   | Placa do Veículo: \n");
    printf("|   | ");
    scanf("%7s", placa_veiculo);
    printf("|   | Data Início: \n");
    printf("|   | ");
    scanf("%8s", data_inic);
    printf("|   | Data Final: \n");
    printf("|   | ");
    scanf("%8s", data_final);
    printf("|   | Valor Final: \n");
    printf("|   | ");
    scanf("%f", &valor_final);
    printf("|   | Situação (F/A): \n");
    printf("|   | ");
    scanf("%1s", situacao);
    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Locação Cadastrada com Sucesso! ");
    printf("\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU CHECAR LOCAÇÃO
void menu_checar_locacao(void) {
    char id_locacao[11];
    int opc_check_locacao;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           CHECAR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_locacao);
    printf("|   | Cliente (CPF): \n");
    printf("|   | Funcionário (CPF): \n");
    printf("|   | Placa do Veículo: \n");
    printf("|   | Data Início: \n");
    printf("|   | Data Final: \n");
    printf("|   | Valor Final: \n");
    printf("|   | Situação (F/A): \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_check_locacao);
    printf("----------------------------------------------\n");

    if (opc_check_locacao == 1) {
        menu_alterar_locacao();
    } else if (opc_check_locacao == 2) {
        menu_excluir_locacao();
    }
}

// MENU ALTERAR LOCAÇÃO
void menu_alterar_locacao(void) {
    char opc_altr_locacao;
    
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          ALTERAR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Cliente (CPF): \n");
    printf("|   | Funcionário (CPF): \n");
    printf("|   | Placa do Veículo: \n");
    printf("|   | Data Início: \n");
    printf("|   | Data Final: \n");
    printf("|   | Valor Final: \n");
    printf("|   | Situação (F/A): \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja alterar?:\n");
    printf("_____-----------------------------------_____\n");
    printf("|   |  1 - Veículo      2 - Dtd. Inicio |   |\n");
    printf("---------------------------------------------\n");
    printf("|   |  3 - Dtd. Final   4 - Situação    |   |\n");
    printf("---------------------------------------------\n");
    printf("|   |              0 - Sair             |   |\n");
    printf("_____-----------------------------------_____\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_altr_locacao);
    printf("---------------------------------------------\n");
}

// MENU EXCLUIR LOCAÇÃO
void menu_excluir_locacao(void) {
    char opc_exclr_locacao;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Cliente (CPF): \n");
    printf("|   | Funcionário (CPF): \n");
    printf("|   | Placa do Veículo: \n");
    printf("|   | Data Início: \n");
    printf("|   | Data Final: \n");
    printf("|   | Valor Final: \n");
    printf("|   | Situação (F/A): \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_locacao);
    getchar();
    printf("----------------------------------------------\n");
}