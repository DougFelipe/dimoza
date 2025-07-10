#!/bin/bash

# Script para compilar e executar o Problema 3 (Operações com Matrizes)


echo "===================================================================="
echo "         COMPILADOR DIMOZA - PROBLEMA 3: OPERAÇÕES COM MATRIZES"
echo "===================================================================="
echo ""

# Verificar se os arquivos necessários existem
echo "🔍 Verificando arquivos necessários..."

if [ ! -f "problema3.txt" ]; then
    echo "❌ ERRO: Arquivo 'problema3.txt' não encontrado!"
    echo "   Por favor, certifique-se de que o arquivo existe no diretório atual."
    exit 1
fi

if [ ! -f "compiler.exe" ]; then
    echo "❌ ERRO: Compilador 'compiler.exe' não encontrado!"
    echo "   Por favor, compile o compilador Dimoza antes de executar este script."
    exit 1
fi

if [ ! -d "lib" ]; then
    echo "❌ ERRO: Diretório 'lib' não encontrado!"
    echo "   As bibliotecas do compilador são necessárias para a compilação."
    exit 1
fi

echo "✅ Todos os arquivos necessários foram encontrados."
echo ""

# Limpar arquivos de compilação anteriores
echo "🧹 Limpando arquivos de compilação anteriores..."
rm -f problema3.exe problema3.c
echo "✅ Limpeza concluída."
echo ""

# Etapa 1: Compilar código Dimoza para C
echo "⚙️  ETAPA 1: Compilando código Dimoza para C..."
echo "   Arquivo fonte: problema3.txt"
echo "   Arquivo destino: problema3.c"
echo ""

./compiler.exe problema3.txt problema3.c

# Verificar se a compilação Dimoza foi bem-sucedida
if [ ! -f "problema3.c" ]; then
    echo "❌ ERRO: Falha na compilação Dimoza!"
    echo "   O arquivo 'problema3.c' não foi gerado."
    echo "   Verifique se há erros de sintaxe no arquivo 'problema3.txt'."
    exit 1
fi

echo "✅ Compilação Dimoza bem-sucedida! Arquivo 'problema3.c' gerado."
echo ""

# Etapa 2: Compilar código C para executável
echo "⚙️  ETAPA 2: Compilando código C para executável..."
echo "   Compilando com GCC e bibliotecas do projeto..."
echo ""

gcc -o problema3.exe problema3.c lib/*.c 2>gcc_erro.log

# Verificar se a compilação C foi bem-sucedida
if [ ! -f "problema3.exe" ]; then
    echo "❌ ERRO: Falha na compilação C!"
    echo "   O executável 'problema3.exe' não foi gerado."
    if [ -f "gcc_erro.log" ] && [ -s "gcc_erro.log" ]; then
        echo "   Detalhes do erro:"
        cat gcc_erro.log
    fi
    exit 1
fi

echo "✅ Compilação C bem-sucedida! Executável 'problema3.exe' gerado."
echo ""

# Executar o programa em modo interativo
echo "===================================================================="
echo "                     EXECUTANDO PROBLEMA 3"
echo "===================================================================="
echo ""
echo "──────────────────────────────────────────────────────────────────"
echo "                    INSTRUÇÕES DE EXECUÇÃO"
echo "──────────────────────────────────────────────────────────────────"
echo ""
echo "📋 COMO USAR O PROGRAMA:"
echo "   1. Digite as dimensões das matrizes A e B (valores de 1 a 3)"
echo "   2. Insira os elementos de cada matriz linha por linha"
echo "   3. O programa calculará automaticamente:"
echo "      • Soma das matrizes (se compatíveis)"
echo "      • Multiplicação das matrizes (se compatíveis)"
echo ""

./problema3.exe

echo ""
echo "===================================================================="
echo "                      EXECUÇÃO CONCLUÍDA"
echo "===================================================================="
echo ""
echo "✅ Problema 3 executado com sucesso!"
echo "📁 Arquivos gerados:"
echo "   • problema3.c (código C intermediário)"
echo "   • problema3.exe (executável final)"
echo ""
