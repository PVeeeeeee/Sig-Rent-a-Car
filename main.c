///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto Sistema de Locação de Veículos                   ///
///               Developed by Pedro Vitor, Elder Bruno and Felipe Erik     ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include "funcoes/funcoes.h"


// FUNÇÃO MAIN - PRINCIPAL
int main(void) {

    int opc_principal = -1, opc_pessoas = -1, opc_veiculos = -1, opc_locacoes = -1, opc_relt_pessoas = -1, opc_relt_veiculos = -1, opc_relt_locacoes = -1, opc_marcas = -1, opc_tipos = -1, opc_combustiveis = -1, opc_data_relatorio = -1;

    while (opc_principal != 0) {
        opc_principal = menu_principal();

        if (opc_principal == 1) {
            opc_pessoas = -1;
            while (opc_pessoas != 0) {
                opc_pessoas = menu_pessoas();

                if (opc_pessoas == 1) {
                    menu_cadastrar_pessoa();
                } else if (opc_pessoas == 2) {
                    menu_checar_pessoa();
                } else if (opc_pessoas == 3) {
                    opc_relt_pessoas = -1; 
                    while (opc_relt_pessoas != 0) {
                        opc_relt_pessoas = menu_relatorio_pessoa();

                        if (opc_relt_pessoas == 1) {
                            relatorio_clientes();
                        } else if (opc_relt_pessoas == 2) {
                            relatorio_funcionarios();
                        } else if (opc_relt_pessoas == 3) {
                            relatorio_geral_pessoas();
                        }
                    }
                } else if (opc_pessoas == 4) {
                    menu_recuperar_pessoa();
                }
            }

        } else if (opc_principal == 2) {
            opc_veiculos = -1; 
            while (opc_veiculos != 0) {
                opc_veiculos = menu_veiculos();

                if (opc_veiculos == 1) {
                    menu_cadastrar_veiculo();
                } else if (opc_veiculos == 2) {
                    menu_checar_veiculo();
                } else if (opc_veiculos == 3) {
                    opc_relt_veiculos = -1;
                    while (opc_relt_veiculos != 0) {
                        opc_relt_veiculos = menu_relatorio_veiculo();

                        if (opc_relt_veiculos == 1) {
                            relatorio_geral_veiculos();
                        } else if (opc_relt_veiculos == 2) {
                            relatorio_marca_veiculos();
                        } else if (opc_relt_veiculos == 3) {
                            relatorio_modelo_veiculos();
                        } else if (opc_relt_veiculos == 4) {
                            relatorio_ano_veiculos();
                        } else if (opc_relt_veiculos == 5) {
                            relatorio_combustivel_veiculos();
                        } else if (opc_relt_veiculos == 6) {
                            relatorio_tipo_veiculos();
                        } else if (opc_relt_veiculos == 7) {
                            relatorio_lugares_veiculos();
                        } else if (opc_relt_veiculos == 8) {
                            relatorio_valor_veiculos();
                        } else if (opc_relt_veiculos == 9) {
                            relatorio_disponivel_veiculos();
                        }
                    }
                } else if (opc_veiculos == 4) {
                    opc_marcas = -1; 
                    while (opc_marcas != 0) {
                        opc_marcas = menu_marcas();

                        if (opc_marcas == 1) {
                            menu_cadastrar_marca();
                        } else if (opc_marcas == 2) {
                            menu_checar_marca();
                        } else if (opc_marcas == 3) {
                            menu_relatorio_marca();
                        }
                    }
                } else if (opc_veiculos == 5) {
                    opc_tipos = -1;
                    while (opc_tipos != 0) {
                        opc_tipos = menu_tipos();

                        if (opc_tipos == 1) {
                            menu_cadastrar_tipo();
                        } else if (opc_tipos == 2) {
                            menu_checar_tipo();
                        } else if (opc_tipos == 3) {
                            menu_relatorio_tipo();
                        }
                    }
                } else if (opc_veiculos == 6) {
                    opc_combustiveis = -1; 
                    while (opc_combustiveis != 0) {
                        opc_combustiveis = menu_combustiveis();

                        if (opc_combustiveis == 1) {
                            menu_cadastrar_combustivel();
                        } else if (opc_combustiveis == 2) {
                            menu_checar_combustivel();
                        } else if (opc_combustiveis == 3) {
                            menu_relatorio_combustivel();
                        }
                    }
                } else if (opc_veiculos == 7) {
                    menu_recuperar_veiculo();
                }
            }
        } else if (opc_principal == 3) {
            opc_locacoes = -1; 
            while (opc_locacoes != 0) {
                opc_locacoes = menu_locacoes();

                if (opc_locacoes == 1) {
                    menu_cadastrar_locacao();
                } else if (opc_locacoes == 2) {
                    menu_checar_locacao();
                } else if (opc_locacoes == 3) {
                    opc_relt_locacoes = -1;
                    while (opc_relt_locacoes != 0) {
                        opc_relt_locacoes = menu_relatorio_locacao();

                        if (opc_relt_locacoes == 1) {
                            relatorio_geral_locacoes();
                        } else if (opc_relt_locacoes == 2) {
                            relatorio_veiculo_locacoes();
                        }
                    }
                }  else if (opc_locacoes == 4) {
                    menu_recuperar_locacao();
                }
            }
        
        } else if (opc_principal == 4) {
            menu_sobre();
        }
    }

    return 0;
}