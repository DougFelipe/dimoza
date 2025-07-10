#!/bin/bash

# =======================================================================
# Script para compilar e executar o Problema 2 - Versão Interativa
# Classificação de números em intervalos: [0-25], [26-50], [51-75], [76-100]
# =======================================================================

echo "================================================================="
echo "         COMPILAÇÃO E EXECUÇÃO DO PROBLEMA 2 - DIMOZA"
echo "================================================================="
echo ""
echo "Descrição: Programa interativo que classifica números em intervalos"
echo "- Lê números do usuário até que um número negativo seja inserido"
echo "- Classifica cada número em um dos intervalos definidos"
echo "- Exibe feedback imediato sobre a classificação"
echo "- Apresenta relatório final com estatísticas"
echo ""

# Verificar se o compilador existe
if [ -f "compiler.exe" ]; then
    echo "✓ Compilador encontrado: compiler.exe"
    COMPILER="./compiler.exe"
elif [ -f "analisador.exe" ]; then
    echo "✓ Compilador encontrado: analisador.exe"
    COMPILER="./analisador.exe"
elif [ -f "compiler" ]; then
    echo "✓ Compilador encontrado: compiler"
    COMPILER="./compiler"
else
    echo "❌ ERRO: Nenhum compilador encontrado!"
    echo "   Compile primeiro com: make"
    exit 1
fi

# Verificar se o arquivo fonte existe
if [ ! -f "problema2.txt" ]; then
    echo "❌ ERRO: Arquivo problema2.txt não encontrado!"
    exit 1
fi

echo "✓ Arquivo fonte encontrado: problema2.txt"
echo ""

# Etapa 1: Gerar código C
echo "📝 ETAPA 1: Gerando código C a partir do código Dimoza..."
$COMPILER problema2.txt problema2.c

if [ $? -ne 0 ]; then
    echo "❌ Erro na geração de código C!"
    exit 1
fi

echo "✓ Código C gerado com sucesso: problema2.c"

# Etapa 2: Compilar para executável
echo ""
echo "🔧 ETAPA 2: Compilando código C para executável..."
gcc -w -o problema2.exe problema2.c

if [ $? -ne 0 ]; then
    echo "❌ Erro na compilação do código C!"
    exit 1
fi

echo "✓ Executável criado com sucesso: problema2.exe"
echo ""

# Etapa 3: Execução em modo interativo
echo "================================================================="
echo "                    EXECUÇÃO INTERATIVA"
echo "================================================================="
echo ""
echo "🎮 INSTRUÇÕES DE USO:"
echo "• O programa solicitará números para classificação"
echo "• Digite números positivos (0 a 1000+)"
echo "• Para encerrar, digite qualquer número negativo"
echo "• O programa mostrará em qual intervalo cada número se encaixa"
echo ""
echo "📊 INTERVALOS MONITORADOS:"
echo "├─ [0-25]     : Números de 0 a 25"
echo "├─ [26-50]    : Números de 26 a 50"  
echo "├─ [51-75]    : Números de 51 a 75"
echo "└─ [76-100]   : Números de 76 a 100"
echo ""
echo "⚡ INICIANDO PROGRAMA INTERATIVO..."
echo ""

# Executar apenas em modo interativo
./problema2.exe

echo ""
echo "================================================================="
echo "                 PROGRAMA FINALIZADO COM SUCESSO"
echo "================================================================="
echo ""
echo "📊 Arquivos gerados:"
echo "├─ problema2.c     : Código C intermediário"
echo "└─ problema2.exe   : Executável final"
echo ""
echo "🎯 Para executar novamente: ./problema2.exe"
echo "🔄 Para recompilar: $0"
echo ""
