#!/bin/bash

# Script para compilar e executar o problema 6 (Árvore Binária de Busca)

echo "=== COMPILANDO PROBLEMA 6: ARVORE BINARIA DE BUSCA ==="

# Define os nomes dos arquivos
SRC_FILE="problema6.txt"
C_FILE="problema6.c"
EXEC_FILE="problema6.exe"
COMPILER="./compiler.exe"

# Limpar arquivos antigos para garantir uma compilação limpa
rm -f ${EXEC_FILE} ${C_FILE}

# 1. Usar o seu compilador para traduzir o código-fonte para C
echo "Compilando ${SRC_FILE} com o seu compilador..."
${COMPILER} ${SRC_FILE} ${C_FILE}

# Verificar se o arquivo C foi gerado
if [ ! -f "${C_FILE}" ]; then
    echo "ERRO: Falha na compilação. O arquivo ${C_FILE} não foi gerado."
    exit 1
fi

echo "Arquivo ${C_FILE} gerado com sucesso!"

# 2. Usar o GCC para compilar o código C gerado e criar o executável
echo "Compilando o código C gerado (${C_FILE}) com o GCC..."
# A flag -mconsole é importante para ambientes MinGW/Cygwin no Windows.
# A flag -o especifica o nome do arquivo de saída.
# CORREÇÃO: Adicionado lib/*.c para linkar com as bibliotecas de apoio (symbol_table, etc.)
gcc -mconsole ${C_FILE} lib/*.c -o ${EXEC_FILE}

# Verificar se o executável foi criado
if [ ! -f "${EXEC_FILE}" ]; then
    echo "ERRO: Falha na compilação com GCC. O executável não foi gerado."
    exit 1
fi

echo "Executável ${EXEC_FILE} gerado com sucesso!"

# 3. Executar o programa final
echo ""
echo "=== EXECUTANDO PROBLEMA 6 ==="
echo ""

./${EXEC_FILE}

echo ""
echo "=== EXECUCAO CONCLUIDA ==="
