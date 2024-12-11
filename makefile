# Definindo o compilador e as flags
CC = gcc
CFLAGS = -Wall -g

# Diretórios
SRC_DIR = .
OBJ_DIR = build

# Nome do projeto (que será o nome do executável)
EXEC = Sig-Rent-a-Car

# Arquivos fonte
SRC = modulos/menu/menu.c modulos/pessoas/pessoas.c modulos/veiculos/veiculos.c modulos/locacoes/locacoes.c main.c funcoes/funcoes.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra principal para criar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Regra para compilar os arquivos .c em .o dentro do diretório build
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criação do diretório build se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza dos arquivos gerados
clean:
	@if exist Sig-Rent-a-Car.exe del /q Sig-Rent-a-Car.exe


# Regra para rodar o programa (opcional)
run: $(EXEC)
	./$(EXEC)