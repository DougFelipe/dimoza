#!/bin/bash

# Script para compilar e executar o Problema 1 - Avaliação de Expressão Aritmética

echo "=== COMPILAÇÃO E EXECUÇÃO DO PROBLEMA 1 ==="
echo "Problema: Avaliação da expressão x*x - y + c"
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
if [ ! -f "problema1.txt" ]; then
    echo "ERRO: Arquivo problema1.txt não encontrado!"
    exit 1
fi

# Mostrar as variáveis que serão usadas
echo "Variáveis utilizadas no programa:"
echo "x = 3.0 (Float)"
echo "y = 2.5 (Float)"
echo "c = 10 (Int)"
echo ""
echo "Expressão a ser avaliada: x*x - y + c"
echo "Substituindo: 3.0*3.0 - 2.5 + 10"
echo "Resultado esperado: 9.0 - 2.5 + 10 = 16.5"
echo ""

# Compilar da linguagem customizada para C
echo "Compilando problema1.txt..."
$COMPILER problema1.txt problema1.c

if [ $? -ne 0 ]; then
    echo "ERRO na compilação da linguagem customizada!"
    exit 1
fi

# Compilar o código C gerado
echo "Compilando código C gerado..."
gcc -o problema1.exe problema1.c

if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida!"
    echo ""
    
    echo "=== EXECUÇÃO DO PROGRAMA ==="
    echo "Executando a avaliação da expressão..."
    echo ""
    
    # Executar o programa
    ./problema1.exe
    
    echo ""
    echo "=== EXECUÇÃO CONCLUÍDA ==="
    echo ""
    echo "RESUMO: O programa demonstrou:"
    echo "- Declaração e inicialização de variáveis (Float e Int)"
    echo "- Avaliação de expressão aritmética complexa"
    echo "- Conversão automática de tipos (Int para Float)"
    echo "- Operações de multiplicação, subtração e adição"
    echo "- Impressão do resultado final"
    echo ""
    echo "O resultado deve ser 16.5 (ou 16.500000 em formato float)"
else
    echo "ERRO na compilação do código C!"
    echo ""
    echo "Possíveis causas:"
    echo "1. Parser não foi recompilado após as modificações"
    echo "2. Erro de sintaxe no código gerado"
    echo ""
    echo "Para resolver:"
    echo "1. Recompile o parser usando: make clean && make"
    echo "2. Verifique se o código C gerado está correto"
fi
