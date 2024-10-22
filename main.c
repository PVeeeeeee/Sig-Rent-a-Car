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
#include "funcoes.h"

// FUNÇÃO MAIN - PRINCIPAL
int main(void) {
    int opc_principal, opc_pessoas, opc_veiculos, opc_locacoes;
    while (opc_principal != 0) {
        opc_principal = menu_principal();

        if (opc_principal == 1) {
            while (opc_pessoas != 0) {
                opc_pessoas = menu_pessoas();

                if (opc_pessoas == 1) {
                    menu_cadastrar_pessoa();
                } else if (opc_pessoas == 2) {
                    menu_checar_pessoa();
                }
            }
            
        }
    }
    
    return 0;
}