#ifndef LOCACOES_H
#include <stdbool.h>
#define LOCACOES_H

typedef struct {
    char cpf_cliente[12];       
    char cpf_funcionario[12];   
    char placa_veiculo[8];      
    char data_inic[11];         
    char data_final[11];        
    float valor_final;         
    bool situacao;
    int status;          
} Locacao;

int menu_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_checar_locacao(void);
void menu_alterar_locacao(void);
void menu_excluir_locacao(void);
void relatorio_geral_locacoes(void);
void relatorio_locacoes_recentes(void);
void relatorio_locacoes_antigas(void);
void relatorio_locacoes_data(void);
void relatorio_veiculo_locacoes(void);

#endif