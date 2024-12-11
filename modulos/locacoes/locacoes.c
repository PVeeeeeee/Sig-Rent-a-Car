// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../funcoes/funcoes.h"
#include "locacoes.h"


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
    opc_locacoes = validar_opcao(0, 3);
    return opc_locacoes;
}

// MENU CADASTRAR LOCAÇÃO
void menu_cadastrar_locacao(void) {
    Locacao l; 

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CADASTRAR LOCAÇÃO          |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");

    printf("|   | Cliente (CPF): ");
    scanf("%11s", l.cpf_cliente);

    printf("|   | Funcionário (CPF): ");
    scanf("%11s", l.cpf_funcionario);

    printf("|   | Placa do Veículo: ");
    scanf("%7s", l.placa_veiculo);

    printf("|   | Data Início (DD/MM/AAAA): ");
    scanf("%10s", l.data_inic);

    printf("|   | Data Final (DD/MM/AAAA): ");
    scanf("%10s", l.data_final);

    printf("|   | Valor Final: ");
    scanf("%f", &l.valor_final);

    printf("|   | Situação (F/A): ");
    scanf("%1s", l.situacao);

    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Locação Cadastrada com Sucesso!\n");
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
    printf("----------------------------------------------\n");
    opc_check_locacao = validar_opcao(0, 2);

    if (opc_check_locacao == 1) {
        menu_alterar_locacao();
    } else if (opc_check_locacao == 2) {
        menu_excluir_locacao();
    }
}

// MENU ALTERAR LOCAÇÃO
void menu_alterar_locacao(void) {
    int opc_altr_locacao;
    
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
    printf("---------------------------------------------\n");
    opc_altr_locacao = validar_opcao(0, 4);
}

// MENU EXCLUIR LOCAÇÃO
void menu_excluir_locacao(void) {
    char opc_exclr_locacao[2];

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
    
    getchar(); 
    scanf("%1s", opc_exclr_locacao);

    printf("----------------------------------------------\n");
}


// MENU RELATÓRIO LOCAÇÃO
int menu_relatorio_locacao(void) {
    int opc_relt_locacao;

    system("clear||cls");
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|     Os relatórios podem ser visualizados     |\n");
    printf("|           por ordem destas opções:           |\n");
    printf("------------------------------------------------\n");
    printf("|                                              |\n");
    printf("|         1 - Geral          2 - Data          |\n");
    printf("|                                              |\n");
    printf("|         3 - Veículo        0 - Voltar        |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    opc_relt_locacao = validar_opcao(0, 3);
    return opc_relt_locacao;
}

// RELATÓRIO LOCAÇÃO GERAL
void relatorio_geral_locacoes() {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|                   ORDEM ID                   |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO LOCAÇÃO DATA
int relatorio_data_locacoes(void) {
    int opc_data_relt;

    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           RELATÓRIO - DATA           |   |\n");
    printf("------------------------------------------------\n");
    printf("|     Os relatórios podem ser visualizados     |\n");
    printf("|           por ordem destas opções:           |\n");
    printf("------------------------------------------------\n");
    printf("|                                              |\n");
    printf("|      1 - Recentes           2 - Antigas      |\n");
    printf("|                                              |\n");
    printf("|      3 - Data Específica    0 - Voltar       |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    opc_data_relt = validar_opcao(0, 3);
    return opc_data_relt;
}

// RELATÓRIO LOCAÇÃO DATA RECENTE
void relatorio_locacoes_recentes(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|             RECENTES -> ANTIGAS              |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO LOCAÇÃO DATA ANTIGA
void relatorio_locacoes_antigas(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ANTIGAS -> RECENTES              |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO LOCAÇÕES DATA ESPECÍFICA
void relatorio_locacoes_data(void) {
    char data[9];

    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite a Data: ");
    scanf("%c", data);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// RELATÓRIO LOCAÇÕES VEÍCULO
void relatorio_veiculo_locacoes(void) {
    char placa[8];

    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |         RELATÓRIO - LOCAÇÕES         |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite a Placa: ");
    scanf("%c", placa);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}