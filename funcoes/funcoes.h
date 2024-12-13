#include <stdbool.h>
// ASSINATURAS DAS FUNÇÕES



// ATIVANDO FUNÇÕES
int menu_principal(void);
void menu_sobre(void);
void limpa_buffer(void);

// validação
int validar_opcao(int limite_inferior, int limite_superior);
int validar_nome(const char *nome);
int validar_cpf(const char *cpf);
int validar_data(const char *data);
int validar_telefone(const char *telefone);
int validar_email(const char *email);
int validar_chassi(const char *chassi);
int validar_placa(const char *placa);
int validar_texto(const char *texto, int max_len);
bool validar_inteiro(int *valor, int minimo, int maximo);
bool validar_float(float *valor, float minimo, float maximo);