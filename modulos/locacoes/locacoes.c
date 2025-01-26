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
    salvar_entidade(locacao, sizeof(Locacao), "modulos/locacoes/locacoes.dat");
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

Locacao* get_lista_locacoes() {
    Locacao *head = NULL, *current = NULL;
    Locacao temp;

    FILE *file = fopen("modulos/locacoes/locacoes.dat", "rb");

    if (file == NULL) {
        printf("Erro: O arquivo de locações não existe.\n");
        return NULL;
    }

    while (fread(&temp, sizeof(Locacao), 1, file) == 1) {
        if (temp.status == 0) continue; 

        Locacao *novo = (Locacao*) malloc(sizeof(Locacao));

        *novo = temp;
        novo->next = NULL;

        if (head == NULL) {
            head = novo;
        } else {
            current->next = novo;
        }

        current = novo;
    }

    fclose(file);
    return head;
}

Locacao* get_lista_locacoes_por_veiculos(const char *placa) {
    Locacao *head = NULL, *current = NULL;
    Locacao temp;

    FILE *file = fopen("modulos/locacoes/locacoes.dat", "rb");

    if (file == NULL) {
        printf("Erro: O arquivo de locações não existe.\n");
        return NULL;
    }

    while (fread(&temp, sizeof(Locacao), 1, file) == 1) {
        if (temp.status == 0 || strcmp(temp.placa_veiculo, placa) != 0) {
            continue;
        } 

        Locacao *novo = (Locacao*) malloc(sizeof(Locacao));

        *novo = temp;
        novo->next = NULL;

        if (head == NULL) {
            head = novo;
        } else {
            current->next = novo;
        }

        current = novo;
    }

    fclose(file);
    return head;
}

void limpar_lista_locacoes(Locacao *head) {
    Locacao *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int atualizar_lista_locacoes(Locacao *head) {
    if (remove("modulos/locacoes/locacoes.dat") != 0) return 0;
    
    Locacao *locacao = head;
    while (locacao != NULL) {
        salvar_locacao(locacao);
        locacao = locacao->next;
    }

    return 1;
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

    int loop = 1;

    do {
        printf("|   | Cliente (CPF): ");
        scanf("%11s", l.cpf_cliente);
        if (!validar_cliente(head, l.cpf_cliente)) {
            printf("|   | Erro: CPF do cliente não encontrado ou inválido!\n");
            continue;
        }
        loop = 0;
    } while(loop);

    loop = 1;
    do {
        printf("|   | Funcionário (CPF): ");
        scanf("%11s", l.cpf_funcionario);

        if (!validar_funcionario(head, l.cpf_funcionario)) {
            printf("|   | Erro: CPF do funcionário não encontrado ou inválido!\n");
            continue;
        }
        loop = 0;
    } while (loop);

    loop = 1;
    do {
        printf("|   | Placa do Veículo: ");
        scanf("%7s", l.placa_veiculo);

        if (!validar_placa(l.placa_veiculo)) {
            printf("|   | Erro: Placa inválida!\n");
            continue;
        }
        loop = 0;
    } while (loop);

    loop = 1;
    do {
        printf("|   | Data Início (DD/MM/AAAA): ");
        scanf("%10s", l.data_inic);
        if (!validar_data(l.data_inic)) {
            printf("|   | Erro: Data inválida!\n");
            continue;
        }
        loop = 0;
    } while (loop);

    do {
        printf("|   | Data Final (DD/MM/AAAA): ");
        scanf("%10s", l.data_final);
        if (!validar_data(l.data_inic)) {
            printf("|   | Erro: Data inválida!\n");
            continue;
        }
        loop = 0;
    } while (loop);

    loop = 1;
    do {
        printf("|   | Valor Final: ");
        scanf("%f", &l.valor_final);
        if (!validar_float(&l.valor_final, 50, 10000)) {
            printf("|   | Erro: Valor inválido!\n");
            continue;
        }
        loop = 0;
    } while (loop);

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
    Locacao *locacao, *head = get_lista_locacoes();
    locacao = head;
    int achou = 0;

    while (locacao != NULL) {
        if (strcmp(locacao->cpf_cliente, cpf_cliente) == 0 && locacao->status == 1) {
            achou = 1;
            locacao->status = 0;
            break;
        }
        locacao = locacao->next;
    }

    if (!achou) {
        printf("CPF não encontrado ou já excluído.\n");
        limpar_lista_locacoes(head);
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
    printf("|   | Cliente (CPF): %s\n", locacao->cpf_cliente);
    printf("|   | Funcionário (CPF): %s\n", locacao->cpf_funcionario);
    printf("|   | Placa do Veículo: %s\n", locacao->placa_veiculo);
    printf("|   | Data Início: %s\n", locacao->data_inic);
    printf("|   | Data Final: %s\n", locacao->data_final);
    printf("|   | Valor Final: %.2f\n", locacao->valor_final);
    printf("|   | Situação: %c\n", locacao->situacao);
    printf("|   | Status: %s\n", locacao->status == 1 ? "Ativo" : "Excluído");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    limpa_buffer();
    fgets(opc_exclr_locacao, sizeof(opc_exclr_locacao), stdin);
    opc_exclr_locacao[strcspn(opc_exclr_locacao, "\n")] = '\0';

    if (strcmp(opc_exclr_locacao, "s") == 0 || strcmp(opc_exclr_locacao, "S") == 0) {
        printf("%s\n", atualizar_lista_locacoes(head) ? "Locação excluída com sucesso!" : "Erro ao atualizar o registro no arquivo!");
    } else {
        printf("Exclusão cancelada.\n");
    }
    limpar_lista_locacoes(head);
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
    printf("|         1 - Geral          2 - Veículo       |\n");
    printf("|                                              |\n");
    printf("|                  0 - Voltar                  |\n");
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
    Locacao *head = get_lista_locacoes(), *locacao = head;
    while (locacao != NULL) {
        printf("\nCPF Cliente: %s\nCPF Funcionário: %s\nPlaca do veículo: %s\nData início: %s\nData final: %s\nValor Final: %.2f\nSituação: %d\n", locacao->cpf_cliente, locacao->cpf_funcionario, locacao->placa_veiculo, locacao->data_inic, locacao->data_final, locacao->valor_final, locacao->situacao);
        printf("------------------------------------------------\n");
        locacao = locacao->next;
    }
    limpar_lista_locacoes(head);
    limpa_buffer();
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
    scanf("%s", placa);

    Locacao l, *head = get_lista_locacoes_por_veiculos(placa), *locacao = head;

    while (locacao != NULL) {
        char nome_cliente[40];
        char nome_funcionario[40];

        Pessoa cliente;
        if (carregar_pessoa(&cliente, "pessoas.dat", locacao->cpf_cliente)) {
            strcpy(nome_cliente, cliente.nome);
        }

        Pessoa funcionario;
        if (carregar_pessoa(&funcionario, "pessoas.dat", locacao->cpf_funcionario)) {
            strcpy(nome_funcionario, funcionario.nome);
        }

        printf("\nNome do Cliente: %s\nNome do Funcionário: %s\nPlaca do veículo: %s\nData início: %s\nData final: %s\nValor Final: %.2f\nSituação: %d\n", nome_cliente, nome_funcionario, locacao->placa_veiculo, locacao->data_inic, locacao->data_final, locacao->valor_final, locacao->situacao);
        printf("------------------------------------------------\n");
        locacao = locacao->next;
    }

    limpar_lista_locacoes(head);
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