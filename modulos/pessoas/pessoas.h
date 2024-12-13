#ifndef PESSOAS_H
#define PESSOAS_H

typedef struct {
    char nome[51];   
    char cpf[12];        
    char data_nasc[11];  
    char telefone[12];   
    char email[26];     
    char funcao[10];   
} Pessoa;


int menu_pessoas(void);
void menu_cadastrar_pessoa(void);
void menu_checar_pessoa(void);
void menu_alterar_pessoa(const char *cpf);
void menu_excluir_pessoa(const char *cpf);
void relatorio_clientes(void);
void relatorio_funcionarios(void);
void relatorio_geral_pessoas(void);

#endif