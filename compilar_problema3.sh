#!/bin/bash

# Script para compilar e executar o problema 3 (Operações com Matrizes)

echo "=== COMPILANDO PROBLEMA 3: OPERACOES COM MATRIZES ==="

# Limpar arquivos antigos
rm -f problema3_exec.exe problema3.c

# Compilar usando o compilador customizado
echo "Compilando problema3.txt..."
./compiler.exe problema3.txt problema3.c

# Verificar se a compilação foi bem-sucedida
if [ ! -f "problema3.c" ]; then
    echo "ERRO: Compilação falhou - arquivo problema3.c não foi gerado"
    exit 1
fi

echo "Arquivo problema3.c gerado com sucesso!"

# Compilar o código C gerado
echo "Compilando o código C gerado..."
gcc -o problema3_exec.exe problema3.c lib/*.c

# Verificar se a compilação C foi bem-sucedida
if [ ! -f "problema3_exec.exe" ]; then
    echo "ERRO: Compilação C falhou - executável não foi gerado"
    exit 1
fi

echo "Executável problema3_exec.exe gerado com sucesso!"

# Executar o programa
echo ""
echo "=== EXECUTANDO PROBLEMA 3 ==="
echo ""

# Executar com entrada fornecida
./problema3_exec.exe < entrada_problema3.txt

echo ""
echo "=== EXECUCAO CONCLUIDA ==="
