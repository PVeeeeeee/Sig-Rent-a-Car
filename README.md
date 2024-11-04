# ⏳ Sig-Rent-a-Car 🚗
Sig Rent-a-Car - Sistema para Locações de Veículos

## 🧑‍💻 Desenvolvedores
Esse projeto foi desenvolvido por:
- Pedro Vitor
- Elder Bruno
- Felipe Erik

## 📋 Sobre
Projeto para avaliação da disciplina <b>DCT1106 | PROGRAMAÇÃO</b> do curso de Sistemas de Informação, da Universidade Federal do Rio Grande do Norte (UFRN). Programa feito na linguagem de programação C, capaz de gerenciar os processos para locações de veículos.

## 💻 Como Usar o Sig-Rent-a-Car

### Pré-requisitos

Certifique-se de que você tenha os seguintes itens instalados:

- [Git](https://git-scm.com/downloads)
- Um compilador C (como GCC, Clang, ou qualquer outro que você preferir).

### Clonando o Repositório

1. Abra o terminal (ou o prompt de comando).
2. Navegue até o diretório onde você deseja clonar o projeto.
3. Execute o seguinte comando:

   ```bash
   git clone https://github.com/PVeeeeeee/Sig-Rent-a-Car.git
   ```

### Compilando o Projeto

1. Navegue até o diretório do projeto clonado:

   ```bash
   cd Sig-Rent-a-Car
   ```

2. Compile os arquivos do projeto. Se você seguiu a estrutura de pastas, use o seguinte comando para compilar todos os arquivos:

   ```bash
   gcc -c modulos/menu/menu.c -o build/menu.o
   gcc -c modulos/pessoas/pessoas.c -o build/pessoas.o
   gcc -c modulos/veiculos/veiculos.c -o build/veiculos.o
   gcc -c modulos/locacoes/locacoes.c -o build/locacoes.o
   gcc -c main.c -o build/main.o
   gcc -c funcoes.c -o build/funcoes.o
   ```

3. Em seguida, vincule todos os arquivos `.o` para criar o executável:

   ```bash
   gcc -o programa build/main.o build/menu.o build/pessoas.o build/veiculos.o build/locacoes.o build/funcoes.o
   ```

### Executando o Programa

Após a compilação, você pode executar o programa usando o seguinte comando:

```bash
./programa
```


## ⚒️ Ferramentas
- C
- VsCode

  
