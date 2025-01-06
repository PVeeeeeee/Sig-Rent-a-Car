CC = gcc
CFLAGS = -Wall -g

EXEC = Sig-Rent-a-Car

SRC = modulos/menu/menu.c modulos/pessoas/pessoas.c modulos/veiculos/veiculos.c modulos/locacoes/locacoes.c main.c funcoes/funcoes.c

OBJ = $(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

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
else
	@rm -f Sig-Rent-a-Car
	@rm -f *.o
	@rm -f modulos/menu/*.o
	@rm -f modulos/pessoas/*.o
	@rm -f modulos/veiculos/*.o
	@rm -f modulos/locacoes/*.o
	@rm -f funcoes/*.o
	@rm -f *.dat
	@rm -f modulos/pessoas/*.dat
	@rm -f modulos/veiculos/*.dat
	@rm -f modulos/locacoes/*.dat
endif

run: $(EXEC)
	./$(EXEC)
