#!/bin/bash

# Script para compilar e executar o Problema 4 com strings

echo "=== COMPILAÇÃO DO PROBLEMA 4 ==="
echo ""

# Verificar se o compilador existe
if [ -f "compiler.exe" ]; then
    COMPILER="./compiler.exe"
elif [ -f "analisador.exe" ]; then
    COMPILER="./analisador.exe"
else
    echo "ERRO: Nenhum compilador encontrado!"
    exit 1
fi

# Verificar se o arquivo fonte existe
if [ ! -f "problema4.txt" ]; then
    echo "ERRO: Arquivo problema4.txt não encontrado!"
    exit 1
fi

# Compilar da linguagem customizada para C
echo "Compilando problema4.txt..."
$COMPILER problema4.txt problema4.c

if [ $? -ne 0 ]; then
    echo "ERRO na compilação da linguagem customizada!"
    exit 1
fi

# Compilar o código C gerado
echo "Compilando código C..."
gcc -o problema4.exe problema4.c

if [ $? -ne 0 ]; then
    echo "ERRO na compilação do código C!"
    exit 1
fi

echo "Compilação bem-sucedida!"
echo ""

# Executar com entrada automática se disponível
if [ -f "entrada_problema4.txt" ]; then
    echo "Usando entrada automática do arquivo entrada_problema4.txt:"
    echo "Conteúdo da entrada:"
    cat entrada_problema4.txt
    echo ""
    echo "=== EXECUÇÃO DO PROGRAMA ==="
    ./problema4.exe < entrada_problema4.txt
else
    echo "=== EXECUÇÃO INTERATIVA ==="
    echo "O programa solicitará que você digite 4 números:"
    echo "1. Numerador do primeiro número racional"
    echo "2. Denominador do primeiro número racional" 
    echo "3. Numerador do segundo número racional"
    echo "4. Denominador do segundo número racional"
    echo ""
    ./problema4.exe
fi

echo ""
echo "=== EXECUÇÃO CONCLUÍDA ==="
