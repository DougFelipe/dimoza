#!/bin/bash

# Script para compilar e executar o Problema 5 (MDC Recursivo)


echo "===================================================================="
echo "         COMPILADOR DIMOZA - PROBLEMA 5: MDC RECURSIVO"
echo "===================================================================="
echo ""

# Verificar se os arquivos necessários existem
echo "🔍 Verificando arquivos necessários..."

if [ ! -f "problema5.txt" ]; then
    echo "❌ ERRO: Arquivo 'problema5.txt' não encontrado!"
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
rm -f problema5.exe problema5.c
echo "✅ Limpeza concluída."
echo ""

# Etapa 1: Compilar código Dimoza para C
echo "⚙️  ETAPA 1: Compilando código Dimoza para C..."
echo "   Arquivo fonte: problema5.txt"
echo "   Arquivo destino: problema5.c"
echo ""

./compiler.exe problema5.txt problema5.c

# Verificar se a compilação Dimoza foi bem-sucedida
if [ ! -f "problema5.c" ]; then
    echo "❌ ERRO: Falha na compilação Dimoza!"
    echo "   O arquivo 'problema5.c' não foi gerado."
    echo "   Verifique se há erros de sintaxe no arquivo 'problema5.txt'."
    exit 1
fi

echo "✅ Compilação Dimoza bem-sucedida! Arquivo 'problema5.c' gerado."
echo ""

# Etapa 2: Compilar código C para executável
echo "⚙️  ETAPA 2: Compilando código C para executável..."
echo "   Compilando com GCC e bibliotecas do projeto..."
echo ""

gcc -o problema5.exe problema5.c lib/*.c 2>gcc_erro.log

# Verificar se a compilação C foi bem-sucedida
if [ ! -f "problema5.exe" ]; then
    echo "❌ ERRO: Falha na compilação C!"
    echo "   O executável 'problema5.exe' não foi gerado."
    if [ -f "gcc_erro.log" ] && [ -s "gcc_erro.log" ]; then
        echo "   Detalhes do erro:"
        cat gcc_erro.log
    fi
    exit 1
fi

echo "✅ Compilação C bem-sucedida! Executável 'problema5.exe' gerado."
echo ""

# Executar o programa em modo interativo
echo "===================================================================="
echo "                     EXECUTANDO PROBLEMA 5"
echo "===================================================================="
echo "──────────────────────────────────────────────────────────────────"
echo "                    INSTRUÇÕES DE EXECUÇÃO"
echo "──────────────────────────────────────────────────────────────────"
echo ""
echo "📋 COMO USAR O PROGRAMA:"
echo "   1. Digite o primeiro número natural positivo (n > 0)"
echo "   2. Digite o segundo número natural positivo (m > 0)"
echo "   3. O programa executará automaticamente:"
echo "      • Validação dos números inseridos"
echo "      • Cálculo do MDC usando recursão"
echo "      • Rastreamento passo a passo das chamadas"

echo ""
echo "    DICAS IMPORTANTES:"
echo "   • Use apenas números naturais positivos (> 0)"
echo "   • O algoritmo funciona independente da ordem dos números"
echo "   • Observe as chamadas recursivas sendo executadas"

echo "▶️  Iniciando execução em modo interativo..."
echo ""

./problema5.exe

echo ""
echo "===================================================================="
echo "                      EXECUÇÃO CONCLUÍDA"
echo "===================================================================="
echo ""
echo "✅ Problema 5 executado com sucesso!"
echo "📁 Arquivos gerados:"
echo "   • problema5.c (código C intermediário)"
echo "   • problema5.exe (executável final)"
echo ""
