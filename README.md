# ⏳ Sig-Rent-a-Car 🚗
Sig Rent-a-Car - Sistema para Locações de Veículos

## 🧑‍💻 Desenvolvedores
Esse projeto foi desenvolvido por:
- Pedro Vitor
- Elder Bruno
- Felipe Erik
- Mosiah Adam

## 📋 Sobre
Projeto para avaliação da disciplina <b>DCT1106 | PROGRAMAÇÃO</b> do curso de Sistemas de Informação, da Universidade Federal do Rio Grande do Norte (UFRN). Programa feito na linguagem de programação C, capaz de gerenciar os processos para locações de veículos.


## 💻 Como Usar o Sig-Rent-a-Car

### Pré-requisitos

- [Git](https://git-scm.com/downloads)
- Compilador C (como GCC ou Clang).

### Clonando o Repositório

1. Abra o terminal.
2. Navegue até o diretório onde deseja clonar o projeto.
3. Execute:

   ```bash
   git clone https://github.com/PVeeeeeee/Sig-Rent-a-Car.git
   ```

### Compilando o Projeto

#### Usando Make:

1. Navegue até o diretório do projeto:

   ```bash
   cd Sig-Rent-a-Car
   ```

2. Execute:

   ```bash
   make run
   ```

#### Sem Make (Manual):

1. Navegue até o diretório do projeto:

   ```bash
   cd Sig-Rent-a-Car
   ```

2. Compile os arquivos do projeto:

   ```bash
   gcc -c modulos/menu/menu.c -o build/menu.o
   gcc -c modulos/pessoas/pessoas.c -o build/pessoas.o
   gcc -c modulos/veiculos/veiculos.c -o build/veiculos.o
   gcc -c modulos/locacoes/locacoes.c -o build/locacoes.o
   gcc -c main.c -o build/main.o
   gcc -c funcoes/funcoes.c -o build/funcoes.o
   ```

3. Em seguida, vincule todos os arquivos .o para criar o executável:
   
   ```bash
   gcc -o Sig-Rent-a-Car main.c modulos/menu/menu.c modulos/pessoas/pessoas.c modulos/veiculos/veiculos.c modulos/locacoes/locacoes.c funcoes/funcoes.c
   ```

### Executando o Programa

Após a compilação, execute:

   ```bash
   ./Sig-Rent-a-Car
   ```


## ⚒️ Ferramentas
- C
- VsCode
- Make

  
