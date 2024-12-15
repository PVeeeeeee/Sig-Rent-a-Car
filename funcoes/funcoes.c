#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"
#include <time.h>
#include "../modulos/pessoas/pessoas.h"
#include "../modulos/veiculos/veiculos.h"

// LIMPA BUFFER
void limpa_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
}


//VALIDACOES
int validar_opcao(int limite_inferior, int limite_superior) {
    int opcao;

    while (1) {
        printf("-> Escolha sua opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); 
        } else if (opcao < limite_inferior || opcao > limite_superior) {
            printf("Opção fora do intervalo permitido (%d - %d). Tente novamente.\n", limite_inferior, limite_superior);
        } else {
            break;
        }
    }
    return opcao;
}


// Verifica se o nome tem até 50 caracteres e é alfabético
int validar_nome(const char *nome) {
    if (strlen(nome) == 0 || strlen(nome) > 50) return 0;
    for (int i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') return 0;
    }
    return 1;
}

// Validação de CPF feito pelo cahtgpt
int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11 || strspn(cpf, "0123456789") != 11) return 0;

    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 ||
        strcmp(cpf, "22222222222") == 0 || strcmp(cpf, "33333333333") == 0 ||
        strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 ||
        strcmp(cpf, "88888888888") == 0 || strcmp(cpf, "99999999999") == 0) {
        return 0;
    }

    int digito1 = 0, digito2 = 0;

    for (int i = 0; i < 9; i++) {
        digito1 += (cpf[i] - '0') * (10 - i);
    }
    digito1 = (digito1 * 10) % 11;
    if (digito1 >= 10) digito1 = 0;

    for (int i = 0; i < 10; i++) {
        digito2 += (cpf[i] - '0') * (11 - i);
    }
    digito2 = (digito2 * 10) % 11;
    if (digito2 >= 10) digito2 = 0;

    return digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0');
}

// Validação de Data feito pelo cahtgpt
int validar_data(const char *data) {
    if (strlen(data) != 8 || strspn(data, "0123456789") != 8) return 0;

    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[2] - '0') * 10 + (data[3] - '0');
    int ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + (data[7] - '0');

    int dias_mes[] = {31, (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return mes >= 1 && mes <= 12 && dia >= 1 && dia <= dias_mes[mes - 1];
}

// Verifica se o telefone tem 11 dígitos e apenas números
int validar_telefone(const char *telefone) {
    if (strlen(telefone) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i])) return 0;
    }
    return 1;
}

// Verifica se o e-mail é válido
int validar_email(const char *email) {
    int len = strlen(email);
    if (len == 0 || len > 25) return 0;
    int has_at = 0;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') has_at = 1;
    }
    return has_at;
}



int validar_texto(const char *texto, int max_len) {
    if (strlen(texto) == 0 || strlen(texto) > max_len) 
        return 0;
    
    for (int i = 0; i < strlen(texto); i++) {
        if (isdigit(texto[i])) 
            return 0; 
    }
    
    return 1;
}

// Função para validar se o valor é inteiro dentro do intervalo
bool validar_inteiro(int *valor, int minimo, int maximo) {
    if (*valor >= minimo && *valor <= maximo) {
        limpa_buffer(); 
        return true;
    }
    limpa_buffer(); 
    return false;
}

// Função para validar se o valor é float dentro do intervalo
bool validar_float(float *valor, float minimo, float maximo) {
    if (*valor >= minimo && *valor <= maximo) {
        limpa_buffer(); 
        return true;
    }
    limpa_buffer(); 
    return false;
}

// Validação de Chassi feito pelo chatgpt
int validar_chassi(const char *chassi) {
    if (strlen(chassi) != 17) return 0;
    for (int i = 0; i < 17; i++) {
        if (!isalnum(chassi[i]) || (chassi[i] >= 'G' && chassi[i] <= 'Z')) {
            return 0;
        }
    }
    return 1;
}

// Validação de Placa feito pelo chatgpt
int validar_placa(const char *placa) {
    if (strlen(placa) != 7) return 0;
    if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2])) return 0; // Primeiros três devem ser letras
    if (!isdigit(placa[3])) return 0;
    if (!isalnum(placa[4]) || !isalnum(placa[5]) || !isalnum(placa[6])) return 0; // Últimos três devem ser alfanuméricos
    return 1;
}


int validar_cliente(const char *cpf) {
    Pessoa pessoa;
    char caminho[50] = "modulos/pessoas/pessoas.dat";

    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        return 0;
    }

    while (fread(&pessoa, sizeof(Pessoa), 1, file)) {
        if (strcmp(pessoa.cpf, cpf) == 0 && pessoa.funcao == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int validar_funcionario(const char *cpf) {
    Pessoa pessoa;
    char caminho[50] = "modulos/pessoas/pessoas.dat";

    FILE *file = fopen(caminho, "rb");
    if (file == NULL) {
        return 0;
    }

    while (fread(&pessoa, sizeof(Pessoa), 1, file)) {
        if (strcmp(pessoa.cpf, cpf) == 0 && pessoa.funcao == 1) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


int verificar_existencia_chassi(const char *chassi) {
    FILE *arquivo = fopen("modulos/veiculos/veiculos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return 0;
    }

    Veiculo veiculo;
    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo)) {
        if (strcmp(veiculo.chassi, chassi) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0; 
}

int verificar_existencia_placa(const char *placa) {
    FILE *arquivo = fopen("modulos/veiculos/veiculos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return 0; 
    }

    Veiculo veiculo;
    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo)) {
        if (strcmp(veiculo.placa, placa) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}