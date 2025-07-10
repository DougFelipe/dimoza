#!/bin/bash

# =======================================================================
# Script para compilar e executar o Problema 1 - Versão Interativa
# Avaliação da expressão aritmética: x² - y + c
# =======================================================================

echo "================================================================="
echo "         COMPILAÇÃO E EXECUÇÃO DO PROBLEMA 1 - DIMOZA"
echo "================================================================="
echo ""
echo "Descrição: Programa interativo para cálculo de expressão aritmética"
echo "- Solicita valores de x (Float), y (Float) e c (Int) do usuário"
echo "- Calcula a expressão: x² - y + c"
echo "- Exibe os valores recebidos e o resultado final"
echo "- Interface amigável com feedback detalhado"
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
if [ ! -f "problema1.txt" ]; then
    echo "❌ ERRO: Arquivo problema1.txt não encontrado!"
    exit 1
fi

echo "✓ Arquivo fonte encontrado: problema1.txt"
echo ""

# Etapa 1: Gerar código C
echo "📝 ETAPA 1: Gerando código C a partir do código Dimoza..."
$COMPILER problema1.txt problema1.c

if [ $? -ne 0 ]; then
    echo "❌ Erro na geração de código C!"
    exit 1
fi

echo "✓ Código C gerado com sucesso: problema1.c"

# Etapa 2: Compilar para executável
echo ""
echo "🔧 ETAPA 2: Compilando código C para executável..."
gcc -w -o problema1.exe problema1.c

if [ $? -ne 0 ]; then
    echo "❌ Erro na compilação do código C!"
    exit 1
fi

echo "✓ Executável criado com sucesso: problema1.exe"
echo ""

# Etapa 3: Execução em modo interativo
echo "================================================================="
echo "                    EXECUÇÃO INTERATIVA"
echo "================================================================="
echo ""
echo "🎮 INSTRUÇÕES DE USO:"
echo "• O programa solicitará 3 valores:"
echo "  - x (número decimal, ex: 3.0, 2.5, 10.7)"
echo "  - y (número decimal, ex: 1.5, 4.2, 0.8)"
echo "  - c (número inteiro, ex: 5, -2, 10)"
echo ""
echo "📊 EXPRESSÃO CALCULADA:"
echo "  resultado = x² - y + c"
echo "  (onde x² significa x multiplicado por x)"
echo ""
echo "💡 EXEMPLO:"
echo "  x = 3.0, y = 2.5, c = 10"
echo "  resultado = 3.0² - 2.5 + 10 = 9.0 - 2.5 + 10 = 16.5"
echo ""
echo "⚡ INICIANDO PROGRAMA INTERATIVO..."
echo ""

# Executar apenas em modo interativo
./problema1.exe

echo ""
echo "================================================================="
echo "                 PROGRAMA FINALIZADO COM SUCESSO"
echo "================================================================="
echo ""
echo "📊 Arquivos gerados:"
echo "├─ problema1.c     : Código C intermediário"
echo "└─ problema1.exe   : Executável final"
echo ""
echo "🎯 Para executar novamente: ./problema1.exe"
echo "🔄 Para recompilar: $0"
echo ""
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
