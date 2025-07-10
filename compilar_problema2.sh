#!/bin/bash

# Script para compilar e executar o Problema 2
# Contagem de números em intervalos específicos

echo "=== COMPILAÇÃO E EXECUÇÃO DO PROBLEMA 2 ==="

# Verificar se o compilador existe
if [ -f "compiler.exe" ]; then
    echo "Usando compiler.exe"
    COMPILER="./compiler.exe"
elif [ -f "analisador.exe" ]; then
    echo "Usando analisador.exe"
    COMPILER="./analisador.exe"
else
    echo "ERRO: Nenhum compilador encontrado (compiler.exe ou analisador.exe)"
    exit 1
fi

# Verificar se o arquivo fonte existe
if [ ! -f "problema2.txt" ]; then
    echo "ERRO: Arquivo problema2.txt não encontrado!"
    exit 1
fi

echo "Gerando código C a partir de problema2.txt..."
$COMPILER problema2.txt problema2.c

# Verificar se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro na geração de código C!"
    exit 1
fi

echo "Código C gerado com sucesso em problema2.c"

# Compilar o código C gerado
echo "Compilando código C para executável..."
gcc -o problema2.exe problema2.c

if [ $? -ne 0 ]; then
    echo "Erro na compilação do código C!"
    exit 1
fi

echo "Executável criado: problema2.exe"

# Executar o programa
echo ""
echo "=== EXECUÇÃO DO PROGRAMA ==="
echo ""
echo "O programa lê números e os conta em intervalos:"
echo "- [0, 25]: números de 0 a 25"
echo "- [26, 50]: números de 26 a 50"  
echo "- [51, 75]: números de 51 a 75"
echo "- [76, 100]: números de 76 a 100"
echo "Digite números (um por linha) e -1 para terminar."
echo ""

# Verificar se existe arquivo de entrada
if [ -f "entrada_problema2.txt" ]; then
    echo "Usando entrada automática do arquivo entrada_problema2.txt:"
    cat entrada_problema2.txt
    echo ""
    echo "Executando com entrada automática..."
    ./problema2.exe < entrada_problema2.txt
    
    echo ""
    echo "=== EXECUÇÃO INTERATIVA ==="
    echo "Agora você pode testar interativamente (digite -1 para sair):"
    ./problema2.exe
else
    echo "Arquivo entrada_problema2.txt não encontrado. Executando modo interativo:"
    ./problema2.exe
fi

echo ""
echo "=== PROGRAMA CONCLUÍDO ==="
