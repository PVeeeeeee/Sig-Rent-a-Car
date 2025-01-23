// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../funcoes/funcoes.h"
#include "locacoes.h"
#include "../pessoas/pessoas.h"


//BANCO DE DADOS
void salvar_locacao(Locacao *locacao) {
    char caminho[50] = "modulos/locacoes/locacoes.dat";

    FILE *file = fopen(caminho, "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de locações!\n");
        return;
    }
    
    fwrite(locacao, sizeof(Locacao), 1, file);
    fclose(file);
}

int carregar_locacoes(Locacao *l, const char *caminho, const char *cpf_cliente) {
    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de locações!\n");
        return 0;
    }

    int encontrado = 0;
    while (fread(l, sizeof(Locacao), 1, file)) {
        if (strcmp(l->cpf_cliente, cpf_cliente) == 0 && l->status == 1) {
            encontrado = 1;
            break;
        }
    }

    fclose(file);
    return encontrado;
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
    printf("|                4 - Recuperar Locação                   |\n");
    printf("|                0 - Menu Principal                      |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_locacoes = validar_opcao(0, 4);
    return opc_locacoes;
}

// MENU CADASTRAR LOCAÇÃO
void menu_cadastrar_locacao(void) {
    Locacao l;
    Pessoa *head = get_lista_pessoas();

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CADASTRAR LOCAÇÃO          |   |\n");
    printf("----------------------------------------------\n");

    printf("|   | Cliente (CPF): ");
    scanf("%11s", l.cpf_cliente);

    if (!validar_cliente(head, l.cpf_cliente)) {
        printf("|   | Erro: CPF do cliente não encontrado ou inválido!\n");
        return;
    }

    printf("|   | Funcionário (CPF): ");
    scanf("%11s", l.cpf_funcionario);

    if (!validar_funcionario(head, l.cpf_funcionario)) {
        printf("|   | Erro: CPF do funcionário não encontrado ou inválido!\n");
        return;
    }

    printf("|   | Placa do Veículo: ");
    scanf("%7s", l.placa_veiculo);

    printf("|   | Data Início (DD/MM/AAAA): ");
    scanf("%10s", l.data_inic);

    printf("|   | Data Final (DD/MM/AAAA): ");
    scanf("%10s", l.data_final);

    printf("|   | Valor Final: ");
    scanf("%f", &l.valor_final);

    l.situacao = 1;
    l.status = 1;
    salvar_locacao(&l);

    printf("|   | Locação Cadastrada com Sucesso!\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    limpar_lista_pessoas(head);
    getchar();
}

// MENU CHECAR LOCAÇÃO
void menu_checar_locacao(void) {
    char cpf_cliente[12];
    Locacao l;
    Pessoa *head = get_lista_pessoas();

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           CHECAR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    do {
        printf("|   | Digite o CPF do Cliente: ");
        scanf(" %11s", cpf_cliente);
    } while (!validar_cliente(head, cpf_cliente));

    if (carregar_locacoes(&l, "modulos/locacoes/locacoes.dat", cpf_cliente)) {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |           CHECAR LOCAÇÃO           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | CPF Cliente: %s\n", l.cpf_cliente);
        printf("|   | CPF Funcionário: %s\n", l.cpf_funcionario);
        printf("|   | Placa do Veículo: %s\n", l.placa_veiculo);
        printf("|   | Data Início: %c%c/%c%c/%c%c%c%c\n",
        l.data_inic[0], l.data_inic[1],
        l.data_inic[2], l.data_inic[3],
        l.data_inic[4], l.data_inic[5], l.data_inic[6], l.data_inic[7]
        );
        printf("|   | Data Final: %c%c/%c%c/%c%c%c%c\n",
        l.data_final[0], l.data_final[1],
        l.data_final[2], l.data_final[3],
        l.data_final[4], l.data_final[5], l.data_final[6], l.data_final[7]
        );
        printf("|   | Valor Final: %.2f\n", l.valor_final);

        if (l.situacao) {
            printf("|   | Situação: Ativa\n");
        } else {
            printf("|   | Situação: Inativa\n");
        }
        printf("----------------------------------------------\n");
        printf("\n");
        printf("|   | O que você deseja fazer?\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("_____------------------------------------_____\n");
        printf("\n");

        int opc_check_locacao = validar_opcao(0, 2);

        if (opc_check_locacao == 1) {
            menu_alterar_locacao(cpf_cliente);
        } else if (opc_check_locacao == 2) {
            menu_excluir_locacao(cpf_cliente);
        }
        limpa_buffer();
        getchar();
    } else {
        printf("Nenhuma locação encontrada para o CPF fornecido.\n");
    }

    printf("\nTecle <ENTER> para prosseguir... ");
    limpa_buffer();
    limpar_lista_pessoas(head);
    getchar();
}


// MENU ALTERAR LOCAÇÃO
void menu_alterar_locacao(const char *cpf_cliente) {
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
void menu_excluir_locacao(const char *cpf_cliente) {
    Locacao l;
    int achou = 0;

    FILE *file = fopen("modulos/locacoes/locacoes.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de locacoes.\n");
        return;
    }

    // Verifica se a locacao existe no arquivo
    while (fread(&l, sizeof(Locacao), 1, file)) {
        if (strcmp(l.cpf_cliente, cpf_cliente) == 0 && l.status == 1) {
            achou = 1;
            break;
        }
    }
    fclose(file);

    if (!achou) {
        printf("CPF não encontrado ou já excluído.\n");
        return;
    }

    char opc_exclr_locacao[3];
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Cliente (CPF): %s\n", l.cpf_cliente);
    printf("|   | Funcionário (CPF): %s\n", l.cpf_funcionario);
    printf("|   | Placa do Veículo: %s\n", l.placa_veiculo);
    printf("|   | Data Início: %s\n", l.data_inic);
    printf("|   | Data Final: %s\n", l.data_final);
    printf("|   | Valor Final: %.2f\n", l.valor_final);
    printf("|   | Situação: %c\n", l.situacao);
    printf("|   | Status: %s\n", l.status == 1 ? "Ativo" : "Excluído");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    limpa_buffer();
    fgets(opc_exclr_locacao, sizeof(opc_exclr_locacao), stdin);
    opc_exclr_locacao[strcspn(opc_exclr_locacao, "\n")] = '\0';

    if (strcmp(opc_exclr_locacao, "s") == 0 || strcmp(opc_exclr_locacao, "S") == 0) {
        printf("Chamada da função excluir_locacao com CPF do cliente: %s\n", cpf_cliente);
        excluir_locacao(cpf_cliente);
    } else {
        printf("Exclusão cancelada.\n");
    }
}

int excluir_locacao(const char *cpf_cliente) {
    Locacao l;
    FILE *file = fopen("modulos/locacoes/locacoes.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para exclusão.\n");
        return 0;
    }

    while (fread(&l, sizeof(Locacao), 1, file)) {
        if (strcmp(l.cpf_cliente, cpf_cliente) == 0 && l.status == 1) {
            l.status = 0;
            fseek(file, -sizeof(Locacao), SEEK_CUR);
            fwrite(&l, sizeof(Locacao), 1, file);
            printf("Locação excluída com sucesso!\n");
            return 1;
        }
    }

    fclose(file);
    printf("Locação %s não encontrado ou já excluído.\n", cpf_cliente);
    return 0;
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

void menu_recuperar_locacao(void) {
    char cpf_cliente[12];

    printf("Digite o CPF da pessoa da locação para recuperação (somente números): ");
    scanf("%s", cpf_cliente);

    int resultado = recuperar_locacao(cpf_cliente);

    if (resultado == 1) {
        printf("A recuperação foi realizada com sucesso.\n");
    } else {
        printf("Falha na recuperação %s.\n", cpf_cliente);
    }

    printf("Tecle <ENTER> para prosseguir... ");
    limpa_buffer();
    getchar();
}


int recuperar_locacao(const char *cpf_cliente) {
    Locacao l;
    FILE *file = fopen("modulos/locacoes/locacoes.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para recuperação.\n");
        return 0;
    }

    while (fread(&l, sizeof(Locacao), 1, file)) {
        if (strcmp(l.cpf_cliente, cpf_cliente) == 0 && l.status == 0) {
            l.status = 1; // Marca como ativo novamente
            fseek(file, -sizeof(Locacao), SEEK_CUR);
            fwrite(&l, sizeof(Locacao), 1, file);
            fclose(file);
            printf("Registro com CPF %s recuperado com sucesso.\n", cpf_cliente);
            return 1;
        }
    }

    fclose(file);
    printf("CPF %s não encontrado ou já ativo.\n", cpf_cliente);
    return 0;
}