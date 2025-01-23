// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../funcoes/funcoes.h"
#include "veiculos.h"

// BANCO DE DADOS
void salvar_veiculos(Veiculo *data, size_t size, const char *fileName) {
    char caminho[50] = "modulos/veiculos/";
    strcat(caminho, fileName);

    FILE *file = fopen(caminho, "ab"); 
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fwrite(data, size, 1, file);
    fclose(file);
}

void carregar_veiculos(Veiculo *data, size_t size, const char *fileName) {
    char caminho[50] = "modulos/veiculos/";
    strcat(caminho, fileName);

    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fclose(file);
}

Veiculo* get_lista_veiculos() {
    Veiculo *head = NULL, *current = NULL;
    Veiculo temp;

    FILE *file = fopen("modulos/veiculos/veiculos.dat", "rb");
    
    if (file == NULL) {
        printf("Erro: O arquivo de veículos não existe.\n");
        return NULL;
    }

    while (fread(&temp, sizeof(Veiculo), 1, file) == 1) {
        if (temp.status == 0) continue; 
        
        Veiculo *novo = (Veiculo*) malloc(sizeof(Veiculo));
        
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

void limpar_lista_veiculos(Veiculo *head) {
    Veiculo *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
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
    printf("|                 7 - Recuperar Veículo                  |\n");
    printf("|                 0 - Menu Principal                     |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_veiculos = validar_opcao(0, 7);
    return opc_veiculos;
}


void cabecalho_cadastrar_veiculo() {
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          CADASTRAR VEÍCULO         |   |\n");
    printf("----------------------------------------------\n");
}

void exibir_veiculo(const Veiculo *v) {
    cabecalho_cadastrar_veiculo();
    printf("---------------------------------------\n");
    printf("|   | Chassi: %s\n", v->chassi);
    printf("|   | Placa: %s\n", v->placa);
    printf("|   | Marca: %s\n", v->marca);
    printf("|   | Modelo: %s\n", v->modelo);
    printf("|   | Cor: %s\n", v->cor);
    printf("|   | Tipo: %s\n", v->tipo);
    printf("|   | Combustível: %s\n", v->combustivel);
    printf("|   | Ano: %d\n", v->ano);
    printf("|   | Lugares: %d\n", v->lugares);
    printf("|   | Valor: R$ %.2f\n", v->valor);
    printf("---------------------------------------\n");
}

const char* selecionar_opcao(const char *opcoes[], int tamanho, const char *titulo) {
    int escolha;

    do {
        cabecalho_cadastrar_veiculo();
        printf("\n===== %s =====\n", titulo);
        for (int i = 0; i < tamanho; i++) {
            printf("%d - %s\n", i + 1, opcoes[i]);
        }
        printf("Escolha uma opção (1-%d): ", tamanho);
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > tamanho);

    return opcoes[escolha - 1];
}


// MENU CADASTRAR VEÍCULO
void menu_cadastrar_veiculo(void) {
    Veiculo v, *head = get_lista_veiculos();

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Chassi (17 caracteres):  \n|   | ");
        scanf("%17s", v.chassi);
    } while (!validar_chassi(v.chassi) || verificar_existencia_chassi(v.chassi));

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Placa (ABC1D23): \n|   | ");
        scanf("%7s", v.placa);
    } while (!validar_placa(v.placa) || verificar_existencia_placa(v.placa));

    strcpy(v.marca, selecionar_opcao(marcas, 5, "Selecione a Marca"));

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Modelo: \n|   | ");
        scanf("%24s", v.modelo);
    } while (!validar_texto(v.modelo, 24));

    strcpy(v.tipo, selecionar_opcao(tipos, 5, "Selecione o Tipo"));
    strcpy(v.cor, selecionar_opcao(cores, 5, "Selecione a Cor"));
    strcpy(v.combustivel, selecionar_opcao(combustiveis, 5, "Selecione o Combustível"));

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Ano: \n|   | ");
        scanf("%d", &v.ano);
    } while (!validar_inteiro(&v.ano, 1886, 2025));

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Lugares: \n|   | ");
        scanf("%d", &v.lugares);
    } while (!validar_inteiro(&v.lugares, 1, 50));

    do {
        cabecalho_cadastrar_veiculo();
        printf("|   | Valor: \n|   | ");
        scanf("%f", &v.valor);
    } while (!validar_float(&v.valor, 50, 5000));

    v.disponibilidade = 1;
    v.status = 1;
    salvar_veiculos(&v, sizeof(Veiculo), "veiculos.dat");

    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Veículo Cadastrado com Sucesso!\n");
    printf("|   | Dados Cadastrados:\n");
    exibir_veiculo(&v);

    printf("\nTecle <ENTER> para prosseguir...");
    limpa_buffer();
    limpar_lista_veiculos(head);
    getchar();
}


void cabecalho_checar_veiculo(void){

system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           CHECAR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");

}

// MENU CHECAR VEÍCULO
void menu_checar_veiculo() {
    char placa[8];
    Veiculo v, *head = get_lista_veiculos();
    int opc_check_veiculo;
    int veiculo_encontrado = 0;

    do {
        cabecalho_checar_veiculo();
        printf("|   | Digite a Placa (ABC1D23): \n|   | ");
        scanf("%7s", placa);
    } while (!validar_placa(placa));

    FILE *arquivo = fopen("modulos/veiculos/veiculos.dat", "rb");  
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    while (fread(&v, sizeof(Veiculo), 1, arquivo)) {
        if (strcmp(v.placa, placa) == 0 && v.status == 1) {
            veiculo_encontrado = 1;
            break;  
        }
    }

    fclose(arquivo);

    if (veiculo_encontrado) {
        cabecalho_checar_veiculo();
        if (v.disponibilidade == 1) {
        printf("|   | Disponível\n");
        } else {
        printf("|   | Indisponível\n");
        }
        printf("|   | Placa: %s\n", v.placa);
        printf("|   | Chassi: %s\n", v.chassi);
        printf("|   | Marca: %s\n", v.marca);
        printf("|   | Modelo: %s\n", v.modelo);
        printf("|   | Cor: %s\n", v.cor);
        printf("|   | Tipo: %s\n", v.tipo);
        printf("|   | Combustível: %s\n", v.combustivel);
        printf("|   | Ano: %d\n", v.ano);
        printf("|   | Lugares: %d\n", v.lugares);
        printf("|   | Valor: %.2f\n", v.valor);
        printf("----------------------------------------------\n");

        printf("|   | O que você deseja fazer?\n");
        printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
        printf("----------------------------------------------\n");

        opc_check_veiculo = validar_opcao(0, 2);
        if (opc_check_veiculo == 1) {
            menu_alterar_veiculo(placa);
        } else if (opc_check_veiculo == 2) {
            menu_excluir_veiculo(placa);
        } else if (opc_check_veiculo == 0)
        {
            limpa_buffer();
            return;
        }
        
    } else {
        printf("Veículo com a placa %s não encontrado.\n", placa);
    }

    printf("\nTecle <ENTER> para prosseguir...");
    limpa_buffer();
    limpar_lista_veiculos(head);
    getchar(); 
}


// MENU ALTERAR VEÍCULO
void menu_alterar_veiculo(const char *placa) {
    Veiculo *veiculo, *head = get_lista_veiculos();
    veiculo = head;
    int achou = 0;

    while (veiculo != NULL) {
        if (strcmp(veiculo->placa, placa) == 0 && veiculo->status == 1) {
            achou = 1;
            veiculo->status = 0;
            break;
        }
        veiculo = veiculo->next;
    }

    if (!achou) {
        printf("Placa não encontrado ou já excluída.\n");
        limpar_lista_veiculos(head);
        return;
    }

    int opc_altr_veiculo;
    do {
        system("clear||cls");
        printf("_____------------------------------------_____\n");
        printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
        printf("|   |   Sistema de Locação de Veículos   |   |\n");
        printf("----------------------------------------------\n");
        printf("|   |          ALTERAR VEÍCULO           |   |\n");
        printf("----------------------------------------------\n");
        printf("|   | Placa: %s\n", veiculo->placa);
        printf("|   | Chassi: %s\n", veiculo->chassi);
        printf("|   | Marca: %s\n", veiculo->marca);
        printf("|   | Modelo: %s\n", veiculo->modelo);
        printf("|   | Cor: %s\n", veiculo->cor);
        printf("|   | Tipo: %s\n", veiculo->tipo);
        printf("|   | Combustível: %s\n", veiculo->combustivel);
        printf("|   | Ano: %d\n", veiculo->ano);
        printf("|   | Lugares: %d\n", veiculo->lugares);
        printf("|   | Valor: %.2f\n", veiculo->valor);
        printf("----------------------------------------------\n");

        printf("|   | O que você deseja alterar?:\n");
        printf("_____--------------------------------_____\n");
        printf("|   |  1 - Chassi        2 - Marca   |   |\n");
        printf("------------------------------------------\n");
        printf("|   |  3 - Modelo        4 - Cor     |   |\n");
        printf("------------------------------------------\n");
        printf("|   |  5 - Tipo          6 - Ano     |   |\n");
        printf("------------------------------------------\n");
        printf("|   |  7 - Lugares       8 - Valor   |   |\n");
        printf("------------------------------------------\n");
        printf("|   |            0 - Sair            |   |\n");
        printf("_____--------------------------------_____\n");
        opc_altr_veiculo = validar_opcao(0, 8);

        switch (opc_altr_veiculo) {
            case 1:
                printf("Novo Chassi: ");
                limpa_buffer();
                fgets(veiculo->chassi, sizeof(veiculo->chassi), stdin);
                veiculo->chassi[strcspn(veiculo->chassi, "\n")] = '\0';
                break;
            case 2:
                printf("Nova Marca: ");
                limpa_buffer();
                fgets(veiculo->marca, sizeof(veiculo->marca), stdin);
                veiculo->marca[strcspn(veiculo->marca, "\n")] = '\0';
                break;
            case 3:
                printf("Novo Modelo: ");
                limpa_buffer();
                fgets(veiculo->modelo, sizeof(veiculo->modelo), stdin);
                veiculo->modelo[strcspn(veiculo->modelo, "\n")] = '\0';
                break;
            case 4:
                printf("Nova Cor: ");
                limpa_buffer();
                fgets(veiculo->cor, sizeof(veiculo->cor), stdin);
                veiculo->cor[strcspn(veiculo->cor, "\n")] = '\0';
                break;
            case 5:
                printf("Novo Tipo: ");
                limpa_buffer();
                fgets(veiculo->tipo, sizeof(veiculo->tipo), stdin);
                veiculo->tipo[strcspn(veiculo->tipo, "\n")] = '\0';
                break;
            case 6:
                printf("Novo Ano: ");
                scanf("%d", &veiculo->ano);
                break;
            case 7:
                printf("Novo Número de Lugares: ");
                scanf("%d", &veiculo->lugares);
                break;
            case 8:
                printf("Novo Valor: ");
                scanf("%f", &veiculo->valor);
                break;
            case 0:
                printf("Alterações concluídas.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opc_altr_veiculo != 0);

    atualizar_lista_veiculos(head);
    limpar_lista_veiculos(head);
    printf("Dados do veículo atualizados com sucesso!\n");
}


// MENU EXCLUIR VEICULO  ----- feito e adaptado com ChatGPT
void menu_excluir_veiculo(const char *placa) {
    Veiculo v;
    int achou = 0;

    FILE *file = fopen("modulos/veiculos/veiculos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de veiculos.\n");
        return;
    }

    // Verifica se o veículo existe no arquivo
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (strcmp(v.placa, placa) == 0 && v.status == 1) {
            achou = 1;
            break;
        }
    }
    fclose(file);

    if (!achou) {
        printf("Placa não encontrada ou já excluída.\n");
        return;
    }

    char opc_exclr_veiculo[3];
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           EXCLUIR VEÍCULO           |   |\n");
    printf("----------------------------------------------\n");
    if (v.disponibilidade == 1) {
        printf("|   | Disponível\n");
    } else {
        printf("|   | Indisponível\n");
    }
    printf("|   | Placa: %s\n", v.placa);
    printf("|   | Chassi: %s\n", v.chassi);
    printf("|   | Marca: %s\n", v.marca);
    printf("|   | Modelo: %s\n", v.modelo);
    printf("|   | Cor: %s\n", v.cor);
    printf("|   | Tipo: %s\n", v.tipo);
    printf("|   | Combustível: %s\n", v.combustivel);
    printf("|   | Ano: %d\n", v.ano);
    printf("|   | Lugares: %d\n", v.lugares);
    printf("|   | Valor: %.2f\n", v.valor);
    printf("----------------------------------------------\n");
    printf("|   | Status: %s\n", v.status == 1 ? "Ativo" : "Excluído");
    printf("----------------------------------------------\n");
    printf("|   | Você tem certeza que deseja excluir? (s/n): ");
    limpa_buffer(); // Certifique-se de que o buffer está limpo
    fgets(opc_exclr_veiculo, sizeof(opc_exclr_veiculo), stdin);
    opc_exclr_veiculo[strcspn(opc_exclr_veiculo, "\n")] = '\0'; // Remove o '\n'

    printf("Entrada recebida: '%s'\n", opc_exclr_veiculo);
    if (strcmp(opc_exclr_veiculo, "s") == 0) {
        printf("Chamada da função excluir_veiculo com placa: %s\n", placa);
        excluir_veiculo(placa);
    } else {
        printf("Exclusão cancelada.\n");
    }
    limpa_buffer();
}


int excluir_veiculo(const char *placa) {
    Veiculo v;
    FILE *file = fopen("modulos/veiculos/veiculos.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para exclusão.\n");
        return 0;
    }

    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (strcmp(v.placa, placa) == 0 && v.status == 1) {
            v.status = 0;
            fseek(file, -sizeof(Veiculo), SEEK_CUR);
            fwrite(&v, sizeof(Veiculo), 1, file);
            fclose(file);
            printf("Registro com Placa %s excluído.\n", placa);
            return 1;
        }
    }

    fclose(file);
    printf("Veículo %s não encontrado ou já excluído.\n", placa);
    return 0;
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
    printf("|         9 - Disponíveis    0 - Voltar        |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");
    printf("\n");
    opc_relt_veiculo = validar_opcao(0, 9);
    return opc_relt_veiculo;
}

// RELATÓRIO VEÍCULO GERAL
void relatorio_geral_veiculos(void) {
    system("clear||cls");
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
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
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |          VEÍCULOS - VALOR            |   |\n");
    printf("------------------------------------------------\n");
    printf("|   | Digite o Valor: ");
    scanf("%f", &valor);
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

// RELATÓRIO VEÍCULO DISPONIBILIDADE
void relatorio_disponivel_veiculos(void) {
    system("clear||cls");
    limpa_buffer();
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
    printf("|                0 - Voltar                              |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_marcas = validar_opcao(0, 3);
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

// MENU CHECAR MARCA
void menu_checar_marca(void) {
    char id_marca[11];
    int opc_check_marca;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            CHECAR MARCA            |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_marca);
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    opc_check_marca = validar_opcao(0, 2);
    printf("----------------------------------------------\n");

    if (opc_check_marca == 1) {
        menu_alterar_marca();
    } else if (opc_check_marca == 2) {
        menu_excluir_marca();
    }
}

// MENU ALTERAR MARCA
void menu_alterar_marca(void) {
    int opc_altr_marca;
    
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            ALTERAR MARCA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("-> Escolha sua opção: ");
    scanf("%d", &opc_altr_marca);
    printf("---------------------------------------------\n");
}

// MENU EXCLUIR MARCA
void menu_excluir_marca(void) {
    char opc_exclr_marca;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |          EXCLUIR MARCA           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_marca);
    getchar();
    printf("----------------------------------------------\n");
}

// RELATÓRIO MARCA
void menu_relatorio_marca(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |          RELATÓRIO - MARCAS          |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
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
    printf("|                0 - Voltar                              |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_tipos = validar_opcao(0, 3);
    return opc_tipos;
}

// MENU CADASTRAR TIPO
void menu_cadastrar_tipo(void) {
    // VARIÁVEIS
    char nome[25];

    // FORM
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |           CADASTRAR TIPO           |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | Nome:  \n");
    printf("|   | ");
    scanf("%24s", nome);
    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Tipo Cadastrado com Sucesso! ");
    printf("\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU CHECAR TIPO
void menu_checar_tipo(void) {
    char id_tipo[11];
    int opc_check_tipo;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |             CHECAR TIPO            |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_tipo);
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    printf("----------------------------------------------\n");
    opc_check_tipo = validar_opcao(0, 2);


    if (opc_check_tipo == 1) {
        menu_alterar_tipo();
    } else if (opc_check_tipo == 2) {
        menu_excluir_tipo();
    }
}

// MENU ALTERAR TIPO
void menu_alterar_tipo(void) {
    int opc_altr_tipo;
    
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            ALTERAR TIPO            |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    scanf("%d", &opc_altr_tipo);
    printf("---------------------------------------------\n");
}

// MENU EXCLUIR TIPO
void menu_excluir_tipo(void) {
    char opc_exclr_tipo;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |            EXCLUIR TIPO            |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_tipo);
    getchar();
    printf("----------------------------------------------\n");
}

// RELATÓRIO TIPO
void menu_relatorio_tipo(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |           RELATÓRIO - TIPOS          |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
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
    printf("|                0 - Voltar                              |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    opc_combustiveis = validar_opcao(0, 3);
    return opc_combustiveis;
}

// MENU CADASTRAR COMBUSTÍVEL
void menu_cadastrar_combustivel(void) {
    // VARIÁVEIS
    char nome[25];

    // FORM
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |        CADASTRAR COMBUSTÍVEL       |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |\n");
    printf("|   | Nome:  \n");
    printf("|   | ");
    scanf("%24s", nome);
    printf("|   |\n");
    printf("---------------------------------------\n");
    printf("|   | Combustível Cadastrado com Sucesso! ");
    printf("\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
    getchar();
}

// MENU CHECAR COMBUSTÍVEL
void menu_checar_combustivel(void) {
    char id_combustivel[11];
    int opc_check_combustivel;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         CHECAR COMBUSTÍVEL         |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Digite o ID: ");
    scanf("%10s", id_combustivel);
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | O que você deseja fazer?\n");
    printf("_____------------------------------------_____\n");
    printf("|   | 1 - Alterar  2 - Excluir  0 - Sair |   |\n");
    printf("_____------------------------------------_____\n");
    printf("----------------------------------------------\n");
    opc_check_combustivel = validar_opcao(0, 2);

    if (opc_check_combustivel == 1) {
        menu_alterar_combustivel();
    } else if (opc_check_combustivel == 2) {
        menu_excluir_combustivel();
    }
}

// MENU ALTERAR COMBUSTÍVEL
void menu_alterar_combustivel(void) {
    int opc_altr_combustivel;
    
    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         ALTERAR COMBUSTÍVEL        |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    scanf("%d", &opc_altr_combustivel);
    printf("---------------------------------------------\n");
}

// MENU EXCLUIR COMBUSTÍVEL
void menu_excluir_combustivel(void) {
    char opc_exclr_combustivel;

    system("clear||cls");
    printf("_____------------------------------------_____\n");
    printf("|   |        == SIG-Rent-a-Car ==        |   |\n");
    printf("|   |   Sistema de Locação de Veículos   |   |\n");
    printf("----------------------------------------------\n");
    printf("|   |         EXCLUIR COMBUSTÍVEL        |   |\n");
    printf("----------------------------------------------\n");
    printf("|   | Nome: \n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("|   | Você tem certeza que deseja excluir?(S/N): ");
    scanf("%c", &opc_exclr_combustivel);
    getchar();
    printf("----------------------------------------------\n");
}

// RELATÓRIO COMBUSTÍVEL
void menu_relatorio_combustivel(void) {
    system("clear||cls");
    limpa_buffer();
    printf("_____--------------------------------------_____\n");
    printf("|   |         == SIG-Rent-a-Car ==         |   |\n");
    printf("|   |    Sistema de Locação de Veículos    |   |\n");
    printf("------------------------------------------------\n");
    printf("|   |       RELATÓRIO - COMBUSTÍVEIS       |   |\n");
    printf("------------------------------------------------\n");
    printf("|             ORDEM ALFABÉTICA [A-Z]           |\n");
    printf("------------------------------------------------\n");
    printf("Tecle <ENTER> para prosseguir...    ");
    limpa_buffer();
}

void menu_recuperar_veiculo(void) {
    char placa[8];

    printf("Digite o Placa da veiculo para recuperação: ");
    scanf("%s", placa);

    int resultado = recuperar_veiculo(placa);

    if (resultado == 1) {
        printf("A recuperação foi realizada com sucesso.\n");
    } else {
        printf("Falha na recuperação do Placa %s.\n", placa);
    }

    printf("Tecle <ENTER> para prosseguir... ");
    limpa_buffer();
    getchar();
}


int recuperar_veiculo(const char *placa) {
    Veiculo v;
    FILE *file = fopen("modulos/veiculos/veiculos.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para recuperação.\n");
        return 0;
    }

    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (strcmp(v.placa, placa) == 0 && v.status == 0) {
            v.status = 1; // Marca como ativo novamente
            fseek(file, -sizeof(Veiculo), SEEK_CUR);
            fwrite(&v, sizeof(Veiculo), 1, file);
            fclose(file);
            printf("Registro com Placa %s recuperado com sucesso.\n", placa);
            return 1;
        }
    }

    fclose(file);
    printf("Placa %s não encontrado ou já ativo.\n", placa);
    return 0;
}