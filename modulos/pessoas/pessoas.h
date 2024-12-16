#ifndef PESSOAS_H
#define PESSOAS_H

typedef struct {
    char nome[51];   
    char cpf[12];        
    char data_nasc[11];  
    char telefone[12];   
    char email[26];     
    int funcao; 
    int status;  
} Pessoa;

void salvar_pessoa(Pessoa *pessoa);
int carregar_pessoa(Pessoa *data, const char *fileName, const char *cpf);
int menu_pessoas(void);
int promover_cliente_funcionario(const char *cpf);
void menu_cadastrar_pessoa(void);
void menu_checar_pessoa(void);
void menu_alterar_pessoa(const char *cpf);
void menu_excluir_pessoa(const char *cpf);
void relatorio_clientes(void);
void relatorio_funcionarios(void);
void relatorio_geral_pessoas(void);

#endif