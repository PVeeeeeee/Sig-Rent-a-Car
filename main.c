///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto Sistema de Locação de Veículos                   ///
///               Developed by Pedro Vitor and Elder Bruno                  ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// ATIVANDO FUNÇÕES
void menu_principal(void);
void menu_sobre(void);

    // PESSOAS
void menu_pessoas(void);
void menu_cadastrar_pessoa(void);
void menu_checar_pessoa(void);
void menu_alterar_pessoa(void);
void menu_excluir_pessoa(void);

    // VEÍCULOS
void menu_veiculos(void);
void menu_cadastrar_veiculo(void);
void menu_checar_veiculo(void);
void menu_alterar_veiculo(void);
void menu_excluir_veiculo(void);

    // LOCAÇÕES
void menu_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_checar_locacao(void);
void menu_alterar_locacao(void);
void menu_excluir_locacao(void);

// FUNÇÃO MAIN - PRINCIPAL
int main(void) {
    menu_principal();
    return 0;
}