#ifndef VEICULOS_H
#define VEICULOS_H

typedef struct {
    char chassi[18];  
    char placa[8];           
    char marca[15];  
    char modelo[25];
    char cor[15];
    char tipo[12];
    char combustivel[15];
    int ano;
    int lugares;
    float valor;
    bool disponibilidade;
    int status;
} Veiculo;

static const char *marcas[] = {"Toyota", "Honda", "Ford", "Chevrolet", "BMW"};
static const char *tipos[] = {"Hatchback", "Sedan", "SUV", "Picape", "Conversível"};
static const char *cores[] = {"Preto", "Branco", "Prata", "Vermelho", "Azul"};
static const char *combustiveis[] = {"Gasolina", "Álcool", "Flex", "Diesel", "Elétrico"};

// Declarações das funções do módulo veiculos.c
void salvar_veiculos(void *data, size_t size, const char *fileName);
void carregar_veiculos(void *data, size_t size, const char *fileName);
int menu_veiculos(void);
void exibir_veiculo(const Veiculo *v);
void menu_cadastrar_veiculo(void);
void menu_checar_veiculo(void);
void menu_alterar_veiculo(const char *placa);
void menu_excluir_veiculo(const char *placa);

// Funções de relatório
int menu_relatorio_veiculo(void);
void relatorio_geral_veiculos(void);
void relatorio_marca_veiculos(void);
void relatorio_modelo_veiculos(void);
void relatorio_ano_veiculos(void);
void relatorio_combustivel_veiculos(void);
void relatorio_tipo_veiculos(void);
void relatorio_lugares_veiculos(void);
void relatorio_valor_veiculos(void);
void relatorio_disponivel_veiculos(void);

// Funções de gestão de marcas
int menu_marcas(void);
void menu_cadastrar_marca(void);
void menu_checar_marca(void);
void menu_alterar_marca(void);
void menu_excluir_marca(void);
void menu_relatorio_marca(void);

// Funções de gestão de tipos
int menu_tipos(void);
void menu_cadastrar_tipo(void);
void menu_checar_tipo(void);
void menu_alterar_tipo(void);
void menu_excluir_tipo(void);
void menu_relatorio_tipo(void);

// Funções de gestão de combustíveis
int menu_combustiveis(void);
void menu_cadastrar_combustivel(void);
void menu_checar_combustivel(void);
void menu_alterar_combustivel(void);
void menu_excluir_combustivel(void);
void menu_relatorio_combustivel(void);

#endif