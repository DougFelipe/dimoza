#!/bin/bash


echo "===================================================================="
echo "         COMPILADOR DIMOZA - PROBLEMA 6: ÁRVORE BINÁRIA DE BUSCA"
echo "===================================================================="
echo ""

# Verificar se os arquivos necessários existem
echo "🔍 Verificando arquivos necessários..."

if [ ! -f "problema6.txt" ]; then
    echo "❌ ERRO: Arquivo 'problema6.txt' não encontrado!"
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
rm -f problema6.exe problema6.c
echo "✅ Limpeza concluída."
echo ""

# Etapa 1: Compilar código Dimoza para C
echo "⚙️  ETAPA 1: Compilando código Dimoza para C..."
echo "   Arquivo fonte: problema6.txt"
echo "   Arquivo destino: problema6.c"
echo ""

./compiler.exe problema6.txt problema6.c

# Verificar se a compilação Dimoza foi bem-sucedida
if [ ! -f "problema6.c" ]; then
    echo "❌ ERRO: Falha na compilação Dimoza!"
    echo "   O arquivo 'problema6.c' não foi gerado."
    echo "   Verifique se há erros de sintaxe no arquivo 'problema6.txt'."
    exit 1
fi

echo "✅ Compilação Dimoza bem-sucedida! Arquivo 'problema6.c' gerado."
echo ""

# Etapa 2: Compilar código C para executável
echo "⚙️  ETAPA 2: Compilando código C para executável..."
echo "   Compilando com GCC e bibliotecas do projeto..."
echo ""

gcc -o problema6.exe problema6.c lib/*.c 2>gcc_erro.log

# Verificar se a compilação C foi bem-sucedida
if [ ! -f "problema6.exe" ]; then
    echo "❌ ERRO: Falha na compilação C!"
    echo "   O executável 'problema6.exe' não foi gerado."
    if [ -f "gcc_erro.log" ] && [ -s "gcc_erro.log" ]; then
        echo "   Detalhes do erro:"
        cat gcc_erro.log
    fi
    exit 1
fi

echo "✅ Compilação C bem-sucedida! Executável 'problema6.exe' gerado."
echo ""

# Executar o programa em modo interativo
echo "===================================================================="
echo "                     EXECUTANDO PROBLEMA 6"
echo "===================================================================="
echo ""
echo "──────────────────────────────────────────────────────────────────"
echo "                    INSTRUÇÕES DE EXECUÇÃO"
echo "──────────────────────────────────────────────────────────────────"
echo ""
echo "📋 COMO USAR O PROGRAMA:"
echo "   1. Digite a quantidade de valores a inserir na BST"
echo "   2. Insira os valores inteiros um por linha"
echo "   3. O programa executará automaticamente:"
echo "      • Operação A: Construção da BST com inserção recursiva"
echo "      • Operação B: Busca da chave mínima (extremo esquerdo)"
echo "      • Operação C: Busca da chave máxima (extremo direito)"
echo "      • Operação D: Visualização da árvore por níveis"
echo "   4. Observe a estrutura hierárquica resultante"
echo ""
echo "💡 DICAS IMPORTANTES:"
echo "   • Use números inteiros (positivos ou negativos)"
echo "   • A ordem de inserção afeta a forma da árvore"
echo "   • BST mantém propriedade: esquerda ≤ nó ≤ direita"
echo ""
echo "▶️  Iniciando execução em modo interativo..."
echo ""

./problema6.exe

echo ""
echo "===================================================================="
echo "                      EXECUÇÃO CONCLUÍDA"
echo "===================================================================="
echo ""
echo "✅ Problema 6 executado com sucesso!"
echo "📁 Arquivos gerados:"
echo "   • problema6.c (código C intermediário)"
echo "   • problema6.exe (executável final)"
echo ""
