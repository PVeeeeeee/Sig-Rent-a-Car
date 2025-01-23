#ifndef LOCACOES_H
#define LOCACOES_H
#include <stdbool.h>

typedef struct Locacao Locacao;

struct Locacao {
    char cpf_cliente[12];
    char cpf_funcionario[12];
    char placa_veiculo[8];
    char data_inic[11];
    char data_final[11];
    float valor_final;
    bool situacao;
    int status;
    Locacao *next;
};

int menu_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_checar_locacao(void);
void menu_alterar_locacao(const char *cpf_cliente);
void menu_excluir_locacao(const char *cpf_cliente);
void relatorio_geral_locacoes(void);
void relatorio_veiculo_locacoes(void);

Locacao* get_lista_locacoes();
void limpar_lista_locacoes(Locacao*);
int atualizar_lista_locacoes(Locacao*);
Locacao* get_lista_locacoes_por_veiculo(const char*);

#endif