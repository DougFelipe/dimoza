#!/bin/bash

# Script para compilar e executar o Problema 4 - Números Racionais (Versão Super Simplificada)

echo "=== COMPILAÇÃO E EXECUÇÃO DO PROBLEMA 4 - NÚMEROS RACIONAIS ==="

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

# Verificar se o arquivo de entrada existe
if [ ! -f "entrada_problema4.txt" ]; then
    echo "ERRO: Arquivo entrada_problema4.txt não encontrado!"
    exit 1
fi

# Mostrar entrada que será usada
echo "Entrada utilizada (arquivo entrada_problema4.txt):"
echo "4 números inteiros representando dois números racionais:"
echo ""
echo "Conteúdo da entrada:"
cat entrada_problema4.txt | tr '\n' ' '
echo ""
echo ""
echo "Interpretação da entrada:"
echo "Primeiro número racional: $(sed -n '1p' entrada_problema4.txt)/$(sed -n '2p' entrada_problema4.txt)"
echo "Segundo número racional: $(sed -n '3p' entrada_problema4.txt)/$(sed -n '4p' entrada_problema4.txt)"
echo ""

# Compilar da linguagem customizada para C
echo "Compilando problema4.txt..."
$COMPILER problema4.txt problema4.c

if [ $? -ne 0 ]; then
    echo "ERRO na compilação da linguagem customizada!"
    exit 1
fi

# Compilar o código C gerado
echo "Compilando código C gerado..."
gcc -o problema4.exe problema4.c

if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida!"
    echo ""
    
    echo "=== EXECUÇÃO DO PROGRAMA ==="

    
    # Executar o programa com a entrada
    ./problema4.exe < entrada_problema4.txt
    
    echo ""
    echo "=== EXECUÇÃO CONCLUÍDA ==="
    echo ""
    echo "RESUMO DA IMPLEMENTAÇÃO:"
    echo "✓ A) Criação de rational_t a partir de inteiros"
    echo "✓ B) Comparação de igualdade usando produto cruzado"
    echo "✓ C) Todas as operações: soma, negação, subtração, multiplicação, inverso e divisão"
    echo "✓ Tratamento de erros (denominador zero, divisão por zero)"
    echo "✓ Simplificação  (denominador sempre positivo)"
else
    echo "ERRO na compilação do código C!"
    echo ""
    echo "Se este erro persistir, pode ser um problema fundamental no parser"
    echo "com passagem de parâmetros por referência."
fi
