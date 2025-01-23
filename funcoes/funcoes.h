#include <stdbool.h>
#include "../modulos/pessoas/pessoas.h"
// ASSINATURAS DAS FUNÇÕES



// ATIVANDO FUNÇÕES
int menu_principal(void);
void menu_sobre(void);
void limpa_buffer(void);

// validação
int validar_opcao(int, int);
int validar_nome(const char*);
int validar_cpf(const char*);
int validar_data(const char*);
int validar_telefone(const char*);
int validar_email(const char*);
int validar_chassi(const char*i);
int validar_placa(const char*);
int validar_texto(const char*, int);
bool validar_inteiro(int*, int, int);
bool validar_float(float*, float, float);
int validar_funcao(Pessoa*, const char*, int);
int validar_cliente(Pessoa*, const char*);
int validar_funcionario(Pessoa*, const char*);
int verificar_existencia_chassi(const char*);
int verificar_existencia_placa(const char*);
void salvar_entidade(void*, size_t, const char*);