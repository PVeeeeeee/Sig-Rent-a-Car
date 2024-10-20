// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// FUNÇÕES

// MENU_PRINCIPAL
void menu_principal(void) {
    int opcao = -1;
    while (opcao != 0) {
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
        printf("|                    3 - Serviços                        |\n");
        printf("|                    4 - Sobre                           |\n");
        printf("|                    0 - Sair                            |\n");
        printf("|                                                        |\n");
        printf("----------------------------------------------------------\n");
        printf("\n");
        printf("-> Escolha sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            menu_pessoas();
        } else if (opcao == 2) {
            menu_veiculos();
        } else if (opcao == 3) {
            menu_locacoes();
        } else if (opcao == 4) {
            menu_sobre();
        }
    }
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
    printf("Tecle <ENTER> para prosseguir...");
    
    // Limpa o buffer de entrada
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 

    getchar();
}

// MENU PESSOAS
void menu_pessoas(void) {
    int opcao = -1;
    while (opcao != 0) {
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
        printf("|                 3 - Relatório                          |\n");
        printf("|                 0 - Menu Principal                     |\n");
        printf("|                                                        |\n");
        printf("----------------------------------------------------------\n");
        printf("\n");
        printf("-> Escolha sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            menu_cadastrar_pessoa();
        } else if (opcao == 2) {
            menu_checar_pessoa();
        } else if (opcao == 3) {
            // menu_relatorio_pessoa();
        }
    }
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
    char cpf[12];
    int opcao = -1;
    while (opcao != 0) {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |            CHECAR PESSOA           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | Digite o CPF: ");
        scanf("%11s", cpf);
        printf("|   | O que você deseja fazer?\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("_____------------------------------------_____\n");
        scanf("%d", &opcao);
        printf("----------------------------------------------\n");

        if (opcao == 1) {
            menu_alterar_pessoa();
        } else if (opcao == 2) {
            menu_excluir_pessoa();
        }
    }

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
    int opcao = -1;
    while (opcao != 0) {
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
        printf("|                 3 - Relatório                          |\n");
        printf("|                 4 - Marcas                             |\n");
        printf("|                 5 - Tipos                              |\n");
        printf("|                 6 - Combustíveis                       |\n");
        printf("|                 0 - Menu Principal                     |\n");
        printf("|                                                        |\n");
        printf("----------------------------------------------------------\n");
        printf("\n");
        printf("-> Escolha sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            menu_cadastrar_veiculo();
        } else if (opcao == 2) {
            menu_checar_veiculo();
        } else if (opcao == 3) {
            // menu_relatorio_veiculo();
        } else if (opcao == 4) {
            // menu_marcas();
        } else if (opcao == 5) {
            // menu_tipos();
        } else if (opcao == 6) {
            // menu_combustiveis();
        }
    }
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

// MENU CHECAR VEÍCULO
void menu_checar_veiculo(void) {
    char placa[8];
    int opcao = -1;
    while (opcao != 0) {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |           CHECAR VEÍCULO           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | Digite a Placa: ");
        scanf("%7s", placa);
        printf("|   | O que você deseja fazer?\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("_____------------------------------------_____\n");
        scanf("%d", &opcao);
        printf("----------------------------------------------\n");

        if (opcao == 1) {
            menu_alterar_veiculo();
        } else if (opcao == 2) {
            menu_excluir_veiculo();
        }
    }
}

// MENU ALTERAR VEÍCULO
void menu_alterar_veiculo(void) {
    system("clear||cls");
    char placa[8];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          ALTERAR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite a Placa: ");
    scanf("%7s", placa);
    printf("----------------------------------------------\n");
}

// MENU EXCLUIR VEÍCULO
void menu_excluir_veiculo(void) {
    system("clear||cls");
    char placa[8];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite a Placa: ");
    scanf("%7s", placa);
    printf("----------------------------------------------\n");
}

// MENU LOCAÇÕES
void menu_locacoes(void) {
    int opcao = -1;
    while (opcao != 0) {
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
        scanf("%d", &opcao);

        if (opcao == 1) {
            menu_cadastrar_locacao();
        } else if (opcao == 2) {
            menu_checar_locacao();
        } else if (opcao == 3) {
            // menu_relatorio_locacao();
        }
    }
}

// MENU CADASTRAR LOCAÇÃO
void menu_cadastrar_locacao(void) {
    system("clear||cls");

    // VARIÁVEIS
    char id_locacao[11];
    char cpf_cliente[12];
    char cpf_vendedor[12];
    char placa_veiculo[8];
    char data_inic[9];
    char data_final[9];
    float valor_final;
    char situacao[2];

    // FORM
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
    printf("|   | Vendedor (CPF): \n");
    printf("|   | ");
    scanf("%11s", cpf_vendedor);
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
}

// MENU CHECAR LOCAÇÃO
void menu_checar_locacao(void) {
    char id_locacao[11];
    int opcao = -1;
    while (opcao != 0) {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |           CHECAR LOCAÇÃO           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | Digite o ID: ");
        scanf("%10s", id_locacao);
        printf("|   | O que você deseja fazer?\n");
        printf("_____------------------------------------_____\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("_____------------------------------------_____\n");
        scanf("%d", &opcao);
        printf("----------------------------------------------\n");

        if (opcao == 1) {
            menu_alterar_locacao();
        } else if (opcao == 2) {
            menu_excluir_locacao();
        }
    }
}

// MENU ALTERAR LOCAÇÃO
void menu_alterar_locacao(void) {
    system("clear||cls");
    char id_locacao[11];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          ALTERAR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_locacao);
    printf("----------------------------------------------\n");

}

// MENU EXCLUIR LOCAÇÃO
void menu_excluir_locacao(void) {
    system("clear||cls");
    char id_locacao[11];
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR LOCAÇÃO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_locacao);
    printf("----------------------------------------------\n");

}
