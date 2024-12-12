# Definindo o compilador e as flags
CC = gcc
CFLAGS = -Wall -g

# Nome do projeto (que será o nome do executável)
EXEC = Sig-Rent-a-Car

# Arquivos fonte
SRC = modulos/menu/menu.c modulos/pessoas/pessoas.c modulos/veiculos/veiculos.c modulos/locacoes/locacoes.c main.c funcoes/funcoes.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra principal para criar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Limpeza dos arquivos gerados
clean:
	@if exist Sig-Rent-a-Car.exe del /q Sig-Rent-a-Car.exe
	@if exist *.o del /q *.o
	@if exist modulos\menu\*.o del /q modulos\menu\*.o
	@if exist modulos\pessoas\*.o del /q modulos\pessoas\*.o
	@if exist modulos\veiculos\*.o del /q modulos\veiculos\*.o
	@if exist modulos\locacoes\*.o del /q modulos\locacoes\*.o
	@if exist funcoes\*.o del /q funcoes\*.o
	@if exist *.dat del /q *.dat
	@if exist modulos\pessoas\*.dat del /q modulos\pessoas\*.dat
	@if exist modulos\veiculos\*.dat del /q modulos\veiculos\*.dat
	@if exist modulos\locacoes\*.dat del /q modulos\locacoes\*.dat

# Regra para rodar o programa (opcional)
run: $(EXEC)
	./$(EXEC)
