// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../funcoes/funcoes.h"
#include "pessoas.h"


//BANCO DE DADOS
void salvar_pessoa(Pessoa *pessoa) {
    salvar_entidade(pessoa, sizeof(Pessoa), "modulos/pessoas/pessoas.dat");
}

int carregar_pessoa(Pessoa *data, const char *fileName, const char *cpf) {
    char caminho[50] = "modulos/pessoas/";
    strcat(caminho, fileName);

    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        printf("Erro: O arquivo de pessoas não existe.\n");
        return 0;
    }

    while (fread(data, sizeof(Pessoa), 1, file)) {
        if (strcmp(data->cpf, cpf) == 0 && data->status == 1) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

/**
 * Ler o arquivo e monta uma Linked List de pessoas
 * 
 * @return Pessoa*: Primeiro item da lista
 */
Pessoa* get_lista_pessoas() {
    Pessoa *head = NULL, *current = NULL;
    Pessoa temp;

    FILE *file = fopen("modulos/pessoas/pessoas.dat", "rb");

    if (file == NULL) {
        printf("Erro: O arquivo de pessoas não existe.\n");
        return NULL;
    }

    while (fread(&temp, sizeof(Pessoa), 1, file) == 1) {
        if (temp.status == 0) continue; 

        Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));

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

void limpar_lista_pessoas(Pessoa *head) {
    Pessoa *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
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
    printf("|                 4 - Recuperar Pessoa                   |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_pessoas = validar_opcao(0, 4);
    return opc_pessoas;
}


int promover_cliente_funcionario(const char *cpf) {
    Pessoa p;
    Pessoa p_funcionario;
    FILE *file = fopen("modulos/pessoas/pessoas.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de pessoas para promoção!\n");
        return 0;
    }

    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (strcmp(p.cpf, cpf) == 0 && p.funcao == 0) {
            memcpy(&p_funcionario, &p, sizeof(Pessoa));
            p_funcionario.funcao = 1;

            fseek(file, -sizeof(Pessoa), SEEK_CUR);

            fwrite(&p, sizeof(Pessoa), 1, file);
            fclose(file);
            
            salvar_pessoa(&p_funcionario);
            printf("Cliente com CPF %s promovido a Funcionário!\n", cpf);
            return 1;
        }
    }

    fclose(file);
    printf("Cliente com CPF %s não encontrado ou já é Funcionário!\n", cpf);
    return 0;
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
    Pessoa p, *head = get_lista_pessoas();
    int opcao;

    do {
        int isCliente = validar_cliente(head, p.cpf),
            isFuncionario = validar_funcionario(head, p.cpf);

        cabecalho_cadastro_pessoa();
        printf("|   | Deseja cadastrar como:\n");
        printf("|   | 1 - Cliente\n");
        printf("|   | 2 - Funcionário\n");
        printf("|   | 3 - Cliente e Funcionário\n");
        printf("|   | Escolha: ");
        opcao = validar_opcao(1, 3);

        cabecalho_cadastro_pessoa();
        printf("|   | CPF: ");
        scanf(" %11s", p.cpf);

        while (!validar_cpf(p.cpf)) {
            printf("|   | Por favor, insira um CPF válido: ");
            scanf(" %11s", p.cpf);
        }

        if (isCliente && isFuncionario) {
            printf("|   | O CPF informado já está cadastrado como Cliente e Funcionário!\n");
            printf("|   | Não é possível criar um novo cadastro.\n");
            break;
        }

        if (isCliente) {
            printf("|   | O CPF informado já está cadastrado como Cliente.\n");
            printf("|   | Deseja promover esse Cliente a Funcionário?\n");
            printf("|   | 1 - Sim  |  0 - Não\n");
            int promover = validar_opcao(0, 1);

            if (promover == 1) {
                promover_cliente_funcionario(p.cpf);
                printf("|   | Cliente promovido a Funcionário com sucesso!\n");
            } else {
                printf("|   | Operação cancelada.\n");
            }
            break;
        }

        if (isFuncionario) {
            printf("|   | O CPF informado já está cadastrado como Funcionário!\n");
            printf("|   | Não é possível criar um novo cadastro.\n");
            break;
        }

        printf("|   | Nome: ");
        scanf(" %49[^\n]", p.nome);

        while (!validar_nome(p.nome)) {
            printf("|   | Por favor, insira um Nome válido: ");
            scanf(" %49[^\n]", p.nome);
        }

        printf("|   | Data de Nascimento (ddmmaaaa): ");
        scanf(" %8s", p.data_nasc);

        while (!validar_data(p.data_nasc)) {
            printf("|   | Por favor, insira um Data válido: ");
            scanf(" %8s", p.data_nasc);
        }

        printf("|   | Telefone: ");
        scanf(" %14s", p.telefone);

        while (!validar_telefone(p.telefone)) {
            printf("|   | Por favor, insira um Telefone válido: ");
            scanf(" %14s", p.telefone);
        }

        printf("|   | E-mail: ");
        getchar();
        scanf(" %49[^\n]", p.email);

        while (!validar_email(p.email)) {
            printf("|   | Por favor, insira um E-mail válido: ");
            getchar();
            scanf(" %49[^\n]", p.email);
        }

        if (opcao == 1) {
            p.funcao = 0;
            p.status = 1;
            salvar_pessoa(&p);
            printf("|   | Cliente cadastrado com sucesso!\n");
        } else if (opcao == 2) {
            p.funcao = 1;
            p.status = 1;
            salvar_pessoa(&p);
            printf("|   | Funcionário cadastrados com sucesso!\n");
        } else {
            p.funcao = 0;
            p.status = 1;
            salvar_pessoa(&p);

            p.funcao = 1;
            p.status = 1;
            salvar_pessoa(&p);
            printf("|   | Cliente e Funcionário cadastrados com sucesso!\n");
        }
    } while (0);  

    printf("Tecle <ENTER> para prosseguir... ");
    limpa_buffer();
    limpar_lista_pessoas(head);
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
    Pessoa p, *head = get_lista_pessoas();

    do {
        cabecalho_checar_pessoa();
        printf("|   | CPF: ");
        scanf(" %11s", cpf);
    } while (!validar_cpf(cpf));

    if (carregar_pessoa(&p, "pessoas.dat", cpf)) {
        cabecalho_checar_pessoa();
        printf("|   | CPF: %s\n", p.cpf);
        printf("|   | Nome: %s\n", p.nome);
        printf("|   | Data de Nascimento: %c%c/%c%c/%c%c%c%c\n",
        p.data_nasc[0], p.data_nasc[1],
        p.data_nasc[2], p.data_nasc[3],
        p.data_nasc[4], p.data_nasc[5], p.data_nasc[6], p.data_nasc[7]
        );
        printf("|   | Telefone: %s\n", p.telefone);
        printf("|   | E-mail: %s\n", p.email);

        if (validar_funcionario(head, cpf) && p.funcao == 0) {
            printf("|   | Função: Cliente e Funcionário\n");
        } else if (p.funcao == 0) {
            printf("|   | Função: Cliente\n");
        } else if (p.funcao == 1) {
            printf("|   | Função: Funcionário\n");
        }

        if (p.status == 1) {
            printf("|   | Status: Ativo\n");
        } else if (p.status == 0) {
            printf("|   | Status: Excluído\n");
        }

        printf("----------------------------------------------\n");
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
    }
    limpa_buffer();
    limpar_lista_pessoas(head);
    getchar();
}


// MENU ALTERAR PESSOA ----- Feito com base no menu_excluir_pessoa do ChatGPT
void menu_alterar_pessoa(const char *cpf) {
    int opc_altr_pessoa;
    Pessoa *pessoa, *head = get_lista_pessoas();
    pessoa = head;
    int achou = 0;

    while (pessoa != NULL) {
        if (strcmp(pessoa->cpf, cpf) == 0 && pessoa->status == 1) {
            achou = 1;
            break;
        }
        pessoa = pessoa->next;
    }

    if (!achou) {
        printf("CPF não encontrado ou já excluído.\n");
        limpar_lista_pessoas(head);
        return;
    }    

    do {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |           ALTERAR PESSOA           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | CPF: %s\n", pessoa->cpf);
        printf("|   | Nome: %s\n", pessoa->nome);
        printf("|   | Idade: %s\n", pessoa->data_nasc);
        printf("|   | Telefone: %s\n", pessoa->telefone);
        printf("|   | E-mail: %s\n", pessoa->email);
        printf("----------------------------------------------\n");
        printf("|   | O que você deseja alterar?:\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Nome       2 - Idade           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | 3 - Telefone   4 - E-mail          |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | 0 - Sair                           |   |\n");
        printf("_____------------------------------------_____\n");

        opc_altr_pessoa = validar_opcao(0, 4);

        switch (opc_altr_pessoa) {
            case 1:
                printf("Novo Nome: ");
                limpa_buffer();
                fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
                pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';
                
                while (!validar_nome(pessoa->nome)) {
                    printf("Por favor, insira um Nome válido: ");
                    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
                    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';
                }
                break;

            case 2:
                printf("Nova data de nascimento (ddmmaaaa): ");
                scanf(" %8s", pessoa->data_nasc);
                
                while (!validar_data(pessoa->data_nasc)) {
                    printf("Por favor, insira uma Data válida: ");
                    scanf(" %8s", pessoa->data_nasc);
                }
                break;

            case 3:
                printf("Novo Telefone: ");
                limpa_buffer();
                fgets(pessoa->telefone, sizeof(pessoa->telefone), stdin);
                pessoa->telefone[strcspn(pessoa->telefone, "\n")] = '\0';
                
                while (!validar_telefone(pessoa->telefone)) {
                    printf("Por favor, insira um Telefone válido: ");
                    fgets(pessoa->telefone, sizeof(pessoa->telefone), stdin);
                    pessoa->telefone[strcspn(pessoa->telefone, "\n")] = '\0';
                }
                break;

            case 4:
                printf("Novo E-mail: ");
                limpa_buffer();
                fgets(pessoa->email, sizeof(pessoa->email), stdin);
                pessoa->email[strcspn(pessoa->email, "\n")] = '\0';
                
                while (!validar_email(pessoa->email)) {
                    printf("Por favor, insira um E-mail válido: ");
                    fgets(pessoa->email, sizeof(pessoa->email), stdin);
                    pessoa->email[strcspn(pessoa->email, "\n")] = '\0';
                }
                break;

            case 0:
                printf("Alterações concluidas.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opc_altr_pessoa != 0);

    atualizar_lista_pessoas(head);
    limpar_lista_pessoas(head);
    printf("Dados alterados com sucesso!\n");
}


// MENU EXCLUIR PESSOA ----- feito e adaptado com ChatGPT
void menu_excluir_pessoa(const char *cpf) {
    Pessoa *pessoa, *head = get_lista_pessoas();
    pessoa = head;
    int achou = 0;

    while (pessoa != NULL) {
        if (strcmp(pessoa->cpf, cpf) == 0 && pessoa->status == 1) {
            achou = 1;
            pessoa->status = 0;
            break;
        }
        pessoa = pessoa->next;
    }

    if (!achou) {
        printf("CPF não encontrado ou já excluído.\n");
        limpar_lista_pessoas(head);
        return;
    }

    char opc_exclr_pessoa[3];  // Aumentar espaço para evitar erro
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           EXCLUIR PESSOA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: %s\n", pessoa->nome);
    printf("|   | Data de Nascimento: %s\n", pessoa->data_nasc);
    printf("|   | Telefone: %s\n", pessoa->telefone);
    printf("|   | E-mail: %s\n", pessoa->email);
    printf("|   | Status: %s\n", pessoa->status == 1 ? "Ativo" : "Excluído");
    printf("----------------------------------------------\n");
    printf("|   | Você tem certeza que deseja excluir? (s/n): ");
    limpa_buffer(); // Certifique-se de que o buffer está limpo
    fgets(opc_exclr_pessoa, sizeof(opc_exclr_pessoa), stdin);
    opc_exclr_pessoa[strcspn(opc_exclr_pessoa, "\n")] = '\0'; // Remove o '\n'

    printf("Entrada recebida: '%s'\n", opc_exclr_pessoa);
    if (strcmp(opc_exclr_pessoa, "s") == 0) {
        printf("Excluindo pessoa com o CPF: %s\n", cpf);
        printf("%s\n", atualizar_lista_pessoas(head) ? "Pessoa excluída com sucesso!" : "Erro ao atualizar o registro no arquivo!");
    } else {
        printf("Exclusão cancelada.\n");
    }
    limpar_lista_pessoas(head);
    limpa_buffer();
}

int atualizar_lista_pessoas(Pessoa *head) {
    if (remove("modulos/pessoas/pessoas.dat") != 0) return 0;
    
    Pessoa *pessoa = head;
    while (pessoa != NULL) {
        salvar_pessoa(pessoa);
        pessoa = pessoa->next;
    }

    return 1;
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
    Pessoa *head = get_lista_pessoas(), *pessoaAtual = head;
    ordenar_lista_pessoas(head);
    while (pessoaAtual != NULL) {
        if (pessoaAtual->funcao == 0) {
            printf("\nNome: %s\nCPF: %s\nData Nascimento: %s\nTelefone: %s\nE-mail: %s\nStatus: %s\n", pessoaAtual->nome, pessoaAtual->cpf, pessoaAtual->data_nasc, pessoaAtual->telefone, pessoaAtual->email, pessoaAtual->status ? "Ativo" : "Inativo");
            printf("------------------------------------------------\n");
        }
        pessoaAtual = pessoaAtual->next;
    }

    limpar_lista_pessoas(head);
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
    Pessoa *head = get_lista_pessoas(), *pessoaAtual = head;
    ordenar_lista_pessoas(head);
    while (pessoaAtual != NULL) {
        if (pessoaAtual->funcao == 1) {
            printf("\nNome: %s\nCPF: %s\nData Nascimento: %s\nTelefone: %s\nE-mail: %s\nStatus: %s\n", pessoaAtual->nome, pessoaAtual->cpf, pessoaAtual->data_nasc, pessoaAtual->telefone, pessoaAtual->email, pessoaAtual->status ? "Ativo" : "Inativo");
            printf("------------------------------------------------\n");
        }
        pessoaAtual = pessoaAtual->next;
    }

    limpar_lista_pessoas(head);
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
    Pessoa *head = get_lista_pessoas(), *pessoaAtual = head;
    ordenar_lista_pessoas(head);
    while (pessoaAtual != NULL) {
        printf("\nNome: %s\nCPF: %s\nData Nascimento: %s\nTelefone: %s\nE-mail: %s\nStatus: %s\n", pessoaAtual->nome, pessoaAtual->cpf, pessoaAtual->data_nasc, pessoaAtual->telefone, pessoaAtual->email, pessoaAtual->status ? "Ativo" : "Inativo");
        printf("------------------------------------------------\n");
        pessoaAtual = pessoaAtual->next;
    }

    limpar_lista_pessoas(head);
    
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

void menu_recuperar_pessoa(void) {
    char cpf[15];

    printf("Digite o CPF da pessoa para recuperação (somente números): ");
    scanf("%s", cpf);

    int resultado = recuperar_pessoa(cpf);

    if (resultado == 1) {
        printf("A recuperação foi realizada com sucesso.\n");
    } else {
        printf("Falha na recuperação do CPF %s.\n", cpf);
    }

    printf("Tecle <ENTER> para prosseguir... ");
    limpa_buffer();
    getchar();
}


int recuperar_pessoa(const char *cpf) {
    Pessoa p;
    FILE *file = fopen("modulos/pessoas/pessoas.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para recuperação.\n");
        return 0;
    }

    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (strcmp(p.cpf, cpf) == 0 && p.status == 0) {
            p.status = 1; // Marca como ativo novamente
            fseek(file, -sizeof(Pessoa), SEEK_CUR);
            fwrite(&p, sizeof(Pessoa), 1, file);
            fclose(file);
            printf("Registro com CPF %s recuperado com sucesso.\n", cpf);
            return 1;
        }
    }

    fclose(file);
    printf("CPF %s não encontrado ou já ativo.\n", cpf);
    return 0;
}


/**
 * Ordena a lista de pessoas usando bubble sort baseado na ordem alfabética
 * 
 * @param Pessoa *head
 * @return void
 * 
 * Authors:
 *  - https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/
 */
void ordenar_lista_pessoas(Pessoa *head)  
{  
    int swapped;  
    Pessoa *p1, *p2 = NULL;

    if (head == NULL) return;
  
    do {
        swapped = 0;  
        p1 = head;  
  
        while (p1->next != p2) {
            if (strcmp(p1->nome, p1->next->nome) > 0) {
                swap(p1, p1->next);  
                swapped = 1;  
            }
            p1 = p1->next;  
        }  
        p2 = p1;  
    }  
    while (swapped);  
}

/**
 * Realiza o swap/troca no algoritmo de BubbleSort para ordenação de nome
 * 
 * @param Pessoa *p1
 * @param Pessoa *p2
 * 
 * @return void
 */
void swap(Pessoa *p1, Pessoa *p2) 
{
    char temp[51];
    strcpy(temp, p1->nome);
    strcpy(p1->nome, p2->nome);
    strcpy(p2->nome, temp);
} 
