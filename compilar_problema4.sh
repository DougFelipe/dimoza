#!/bin/bash

# Script para compilar e executar o Problema 4 (Números Racionais)

echo "===================================================================="
echo "         COMPILADOR DIMOZA - PROBLEMA 4: NÚMEROS RACIONAIS"
echo "===================================================================="
echo ""

# Verificar se os arquivos necessários existem
echo "🔍 Verificando arquivos necessários..."

if [ ! -f "problema4.txt" ]; then
    echo "❌ ERRO: Arquivo 'problema4.txt' não encontrado!"
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
rm -f problema4.exe problema4.c
echo "✅ Limpeza concluída."
echo ""

# Etapa 1: Compilar código Dimoza para C
echo "⚙️  ETAPA 1: Compilando código Dimoza para C..."
echo "   Arquivo fonte: problema4.txt"
echo "   Arquivo destino: problema4.c"
echo ""

./compiler.exe problema4.txt problema4.c

# Verificar se a compilação Dimoza foi bem-sucedida
if [ ! -f "problema4.c" ]; then
    echo "❌ ERRO: Falha na compilação Dimoza!"
    echo "   O arquivo 'problema4.c' não foi gerado."
    echo "   Verifique se há erros de sintaxe no arquivo 'problema4.txt'."
    exit 1
fi

echo "✅ Compilação Dimoza bem-sucedida! Arquivo 'problema4.c' gerado."
echo ""

# Etapa 2: Compilar código C para executável
echo "⚙️  ETAPA 2: Compilando código C para executável..."
echo "   Compilando com GCC e bibliotecas do projeto..."
echo ""

gcc -o problema4.exe problema4.c lib/*.c 2>gcc_erro.log

# Verificar se a compilação C foi bem-sucedida
if [ ! -f "problema4.exe" ]; then
    echo "❌ ERRO: Falha na compilação C!"
    echo "   O executável 'problema4.exe' não foi gerado."
    if [ -f "gcc_erro.log" ] && [ -s "gcc_erro.log" ]; then
        echo "   Detalhes do erro:"
        cat gcc_erro.log
    fi
    exit 1
fi

echo "✅ Compilação C bem-sucedida! Executável 'problema4.exe' gerado."
echo ""

# Executar o programa em modo interativo
echo "===================================================================="
echo "                     EXECUTANDO PROBLEMA 4"
echo "===================================================================="
echo "──────────────────────────────────────────────────────────────────"
echo "                    INSTRUÇÕES DE EXECUÇÃO"
echo "──────────────────────────────────────────────────────────────────"
echo ""
echo "📋 COMO USAR O PROGRAMA:"
echo "   1. Digite o numerador do primeiro número racional"
echo "   2. Digite o denominador do primeiro número racional (≠ 0)"
echo "   3. Digite o numerador do segundo número racional"
echo "   4. Digite o denominador do segundo número racional (≠ 0)"
echo "   5. O programa executará automaticamente todas as operações:"
echo "      • Criação e normalização dos racionais"
echo "      • Comparação de igualdade"
echo "      • Todas as operações aritméticas"
echo "   6. Visualize os resultados formatados"
echo ""
echo "💡 DICAS IMPORTANTES:"
echo "   • Denominadores nunca podem ser zero"
echo "   • Use números inteiros (positivos ou negativos)"
echo "   • O programa normaliza automaticamente (denominador positivo)"
echo "   • Pressione Enter após cada entrada"
echo ""

echo ""

./problema4.exe

echo ""
echo "===================================================================="
echo "                      EXECUÇÃO CONCLUÍDA"
echo "===================================================================="
echo ""
echo "✅ Problema 4 executado com sucesso!"
echo "📁 Arquivos gerados:"
echo "   • problema4.c (código C intermediário)"
echo "   • problema4.exe (executável final)"
echo ""
