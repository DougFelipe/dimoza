#!/bin/bash

# Este script para a execução se qualquer comando falhar (set -e)
set -e

# --- ETAPA 1: Compilar o compilador ---
echo "Compilando..."
make

# --- ETAPA 2: Preparar os diretórios de teste ---
echo "Preparando diretórios de teste..."
mkdir -p tests/problema1
mkdir -p tests/problema2
mkdir -p tests/problema3
mkdir -p tests/problema4
mkdir -p tests/problema5
mkdir -p tests/problema6

# --- ETAPA 3: Executar os testes ---

# Teste do problema 1
echo ""
echo "Gerando e compilando problema1..."
./compiler problema1.txt tests/problema1/saida1.c
gcc -w -I. tests/problema1/saida1.c -o tests/problema1/teste1.exe
echo "Executando problema1:"
./tests/problema1/teste1.exe

# Teste do problema 2
echo ""
echo "Gerando e compilando problema2..."
./compiler problema2.txt tests/problema2/saida2.c
gcc -w -I. tests/problema2/saida2.c -o tests/problema2/teste2.exe
echo "Executando problema2 com entrada2.txt:"
./tests/problema2/teste2.exe < entrada2.txt

# Teste do problema 3 (Matrix)
echo ""
echo "Gerando e compilando problema3..."
./compiler problema3.txt tests/problema3/saida3.c
gcc -w -I. tests/problema3/saida3.c lib/matrix.c -o tests/problema3/teste3.exe
echo "Executando problema3:"
./tests/problema3/teste3.exe

# Teste do problema 4 (Rational)
echo ""
echo "Gerando e compilando problema4..."
./compiler problema4.txt tests/problema4/saida4.c
gcc -w -I. tests/problema4/saida4.c lib/rational.c -o tests/problema4/teste4.exe
echo "Executando problema4:"
./tests/problema4/teste4.exe

# Teste do problema 5 (MDC com Referência)
echo ""
echo "Gerando e compilando problema5..."
./compiler problema5.txt tests/problema5/saida5.c
gcc -w -I. tests/problema5/saida5.c lib/mdc.c -o tests/problema5/teste5.exe
echo "Executando problema5:"
./tests/problema5/teste5.exe

# Teste do problema 6 (BST)
echo ""
echo "Gerando e compilando problema6..."
./compiler problema6.txt tests/problema6/saida6.c
gcc -w -I. tests/problema6/saida6.c lib/bst.c -o tests/problema6/teste6.exe
echo "Executando problema6:"
./tests/problema6/teste6.exe

echo ""
echo "Todos os testes executados com sucesso!"
