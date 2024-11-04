// ASSINATURAS DAS FUNÇÕES

// ATIVANDO FUNÇÕES
int menu_principal(void);
void menu_sobre(void);
void limpa_buffer(void);

// Declarações de funções de validação
int validar_opcao(int limite_inferior, int limite_superior);

    // PESSOAS
int menu_pessoas(void);
void menu_cadastrar_pessoa(void);
void menu_checar_pessoa(void);
void menu_alterar_pessoa(void);
void menu_excluir_pessoa(void);
int menu_relatorio_pessoa(void);
void relatorio_clientes(void);
void relatorio_funcionarios(void);
void relatorio_geral_pessoas(void);

    // VEÍCULOS
int menu_veiculos(void);
void menu_cadastrar_veiculo(void);
void menu_checar_veiculo(void);
void menu_alterar_veiculo(void);
void menu_excluir_veiculo(void);

    // RELATÓRIOS VEÍCULOS
int menu_relatorio_veiculo(void);
void relatorio_geral_veiculos(void);
void relatorio_marca_veiculos(void);
void relatorio_modelo_veiculos(void);
void relatorio_ano_veiculos(void);
void relatorio_combustivel_veiculos(void);
void relatorio_tipo_veiculos(void);
void relatorio_lugares_veiculos(void);
void relatorio_valor_veiculos(void);
void relatorio_disponivel_veiculos(void);

    // MARCAS
int menu_marcas(void);
void menu_cadastrar_marca(void);
void menu_checar_marca(void);
void menu_alterar_marca(void);
void menu_excluir_marca(void);
void menu_relatorio_marca(void);

    // TIPOS
int menu_tipos(void);
void menu_cadastrar_tipo(void);
void menu_checar_tipo(void);
void menu_alterar_tipo(void);
void menu_excluir_tipo(void);
void menu_relatorio_tipo(void);

    // COMBUSTÍVEIS
int menu_combustiveis(void);
void menu_cadastrar_combustivel(void);
void menu_checar_combustivel(void);
void menu_alterar_combustivel(void);
void menu_excluir_combustivel(void);
void menu_relatorio_combustivel(void);

    // LOCAÇÕES
int menu_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_checar_locacao(void);
void menu_alterar_locacao(void);
void menu_excluir_locacao(void);

    // RELATÓRIOS LOCAÇÕES
int menu_relatorio_locacao(void);
void relatorio_geral_locacoes(void);
int relatorio_data_locacoes(void);
void relatorio_locacoes_recentes(void);
void relatorio_locacoes_antigas(void);
void relatorio_locacoes_data(void);
void relatorio_veiculo_locacoes(void);
