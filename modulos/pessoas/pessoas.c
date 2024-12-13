// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../funcoes/funcoes.h"
#include "pessoas.h"


//BANCO DE DADOS
void salvar_pessoa(Pessoa *data, const char *fileName) {
    char caminho[50] = "modulos/pessoas/";
    strcat(caminho, fileName);

    FILE *file = fopen(caminho, "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    fwrite(data, sizeof(Pessoa), 1, file);
    fclose(file);
}

int carregar_pessoa(Pessoa *data, const char *fileName, const char *cpf) {
    char caminho[50] = "modulos/pessoas/";
    strcat(caminho, fileName);

    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para carregar!\n");
        return 0;
    }

    while (fread(data, sizeof(Pessoa), 1, file)) {
        if (strcmp(data->cpf, cpf) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
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
    opc_pessoas = validar_opcao(0, 3);
    return opc_pessoas;
}

// MENU CADASTRAR PESSOA
void cabecalho_cadastro_pessoa(void){

system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          CADASTRAR PESSOA          |   |\n");
    printf("----------------------------------------------\n");

}


void menu_cadastrar_pessoa(void) {
    Pessoa p;

    do {
        cabecalho_cadastro_pessoa();
        printf("|   | Nome: ");
        scanf(" %50[^\n]", p.nome);
    } while (!validar_nome(p.nome));

    do {
        cabecalho_cadastro_pessoa();
        printf("|   | CPF: ");
        scanf(" %11s", p.cpf);
    } while (!validar_cpf(p.cpf));

    do {
        cabecalho_cadastro_pessoa();
        printf("|   | Dtd. Nascimento: ");
        scanf(" %10s", p.data_nasc);
    } while (!validar_data(p.data_nasc));

    do {
        cabecalho_cadastro_pessoa();
        printf("|   | Telefone: ");
        scanf(" %11s", p.telefone);
    } while (!validar_telefone(p.telefone));

    do {
        cabecalho_cadastro_pessoa();
        printf("|   | E-mail: ");
        scanf(" %25s", p.email);
    } while (!validar_email(p.email));

    cabecalho_cadastro_pessoa();
    printf("|   | Qual função: 1- cliente 2- funcionário\n");
    printf("|   | ");
    int funcao_pes = validar_opcao(1, 2);
    if (funcao_pes == 1) {
        strcpy(p.funcao, "Cliente");
    } else {
        strcpy(p.funcao, "Funcionário");
    }

    salvar_pessoa(&p, "pessoas.dat");

    printf("|   | Pessoa Cadastrada com Sucesso!\n");
    printf("Tecle <ENTER> para prosseguir... ");
    limpa_buffer();
    getchar();
}

void cabecalho_checar_pessoa(void){

system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            CHECAR PESSOA           |   |\n");
    printf("----------------------------------------------\n");

 }


// MENU CHECAR PESSOA
void menu_checar_pessoa(void) {
    char cpf[12];
    Pessoa p;

    do {
        cabecalho_checar_pessoa();
        printf("|   | CPF: ");
        scanf(" %11s", cpf);
    } while (!validar_cpf(cpf));

    if (carregar_pessoa(&p, "pessoas.dat", cpf)) {
        cabecalho_checar_pessoa();
        printf("|   | CPF: %s\n", p.cpf);
        printf("|   | Nome: %s\n", p.nome);
        printf("|   | Data de Nascimento: %s\n", p.data_nasc);
        printf("|   | Telefone: %s\n", p.telefone);
        printf("|   | E-mail: %s\n", p.email);
        printf("|   | Função: %s\n", p.funcao);
        printf("----------------------------------------------\n");
        printf("\n");
        printf("|   | O que você deseja fazer?\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("_____------------------------------------_____\n");
        printf("\n");

        int opc_check_pessoa = validar_opcao(0, 2);

        if (opc_check_pessoa == 1) {
            menu_alterar_pessoa(cpf);
        } else if (opc_check_pessoa == 2) {
            menu_excluir_pessoa(cpf);
        }
    } else {
        printf("Pessoa com CPF %s não encontrada!\n", cpf);
        printf("Tecle <ENTER> para prosseguir... ");
        limpa_buffer();
        getchar();
    }
}


// MENU ALTERAR PESSOA
void menu_alterar_pessoa(const char *cpf) {
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
void menu_excluir_pessoa(const char *cpf) {
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