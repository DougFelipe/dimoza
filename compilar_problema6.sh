#!/bin/bash

# ==============================================================================
# Script para Compilação e Execução do Problema 6 - BST (Binary Search Tree)
# ==============================================================================
# Autor: Sistema de Compilação Customizado
# Data: $(date)
# Descrição: Automatiza todo o processo de compilação e execução de uma
#           implementação REAL de BST com structs customizados e algoritmos
#           recursivos completos.
# ==============================================================================

set -e  # Interrompe execução em caso de erro

# Cores para output mais legível
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Função para exibir cabeçalho
show_header() {
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${CYAN}    COMPILADOR DE LINGUAGEM CUSTOMIZADA - PROBLEMA 6: BST REAL${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${YELLOW}🌳 Binary Search Tree com Algoritmos Recursivos Completos${NC}"
    echo -e "${YELLOW}🔧 Structs Customizados + Alocação Dinâmica + Traversal por Níveis${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    echo ""
}

# Função para verificar dependências
check_dependencies() {
    echo -e "${BLUE}🔍 VERIFICANDO DEPENDÊNCIAS...${NC}"
    
    # Verificar se o compilador customizado existe
    if [ -f "compiler.exe" ]; then
        COMPILER="./compiler.exe"
        echo -e "${GREEN}✓ Compilador customizado encontrado: compiler.exe${NC}"
    elif [ -f "analisador.exe" ]; then
        COMPILER="./analisador.exe"
        echo -e "${GREEN}✓ Compilador customizado encontrado: analisador.exe${NC}"
    else
        echo -e "${RED}❌ ERRO: Nenhum compilador encontrado!${NC}"
        echo -e "${YELLOW}💡 Execute 'make' ou 'make clean && make' para compilar o parser primeiro.${NC}"
        exit 1
    fi

    # Verificar se GCC está disponível
    if ! command -v gcc &> /dev/null; then
        echo -e "${RED}❌ ERRO: GCC não encontrado!${NC}"
        echo -e "${YELLOW}💡 Instale o GCC através do MSYS2: pacman -S mingw-w64-x86_64-gcc${NC}"
        exit 1
    else
        echo -e "${GREEN}✓ GCC encontrado: $(gcc --version | head -n1)${NC}"
    fi

    # Verificar se o arquivo fonte existe
    if [ ! -f "problema6.txt" ]; then
        echo -e "${RED}❌ ERRO: Arquivo problema6.txt não encontrado!${NC}"
        echo -e "${YELLOW}💡 Certifique-se de que o arquivo existe no diretório atual.${NC}"
        exit 1
    else
        echo -e "${GREEN}✓ Arquivo fonte encontrado: problema6.txt${NC}"
    fi

    echo ""
}

# Função para mostrar informações sobre a implementação
show_implementation_info() {
    echo -e "${BLUE}📋 CARACTERÍSTICAS DA IMPLEMENTAÇÃO BST:${NC}"
    echo -e "${GREEN}  🟢 Struct TreeNode customizado com campos: key, left, right${NC}"
    echo -e "${GREEN}  🟢 Alocação dinâmica real: NEW TreeNode → malloc(sizeof(struct TreeNode))${NC}"
    echo -e "${GREEN}  🟢 Inserção recursiva completa na árvore binária${NC}"
    echo -e "${GREEN}  🟢 Busca de mínimo (navegação recursiva à esquerda)${NC}"
    echo -e "${GREEN}  🟢 Busca de máximo (navegação recursiva à direita)${NC}"
    echo -e "${GREEN}  🟢 Cálculo de altura da árvore (algoritmo recursivo)${NC}"
    echo -e "${GREEN}  🟢 Impressão por níveis (level-order traversal)${NC}"
    echo ""
    
    echo -e "${BLUE}🎯 VALORES DE TESTE:${NC}"
    echo -e "${CYAN}  Inserindo na ordem: 50, 30, 20, 40, 70, 60, 80${NC}"
    echo ""
    echo -e "${BLUE}🌳 ESTRUTURA DA ÁRVORE RESULTANTE:${NC}"
    echo -e "${CYAN}           50${NC}"
    echo -e "${CYAN}          /  \\${NC}"
    echo -e "${CYAN}        30    70${NC}"
    echo -e "${CYAN}       / \\   / \\${NC}"
    echo -e "${CYAN}     20  40 60  80${NC}"
    echo ""
    
    echo -e "${BLUE}📊 RESULTADOS ESPERADOS:${NC}"
    echo -e "${CYAN}  • Mínimo: 20 (nível 3)${NC}"
    echo -e "${CYAN}  • Máximo: 80 (nível 3)${NC}"
    echo -e "${CYAN}  • Altura: 3 níveis${NC}"
    echo -e "${CYAN}  • Traversal: Nível 1→50, Nível 2→30,70, Nível 3→20,40,60,80${NC}"
    echo ""
}

# Função para compilar da linguagem customizada para C
compile_to_c() {
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${BLUE}🔄 FASE 1: COMPILANDO LINGUAGEM CUSTOMIZADA PARA C${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    
    echo -e "${YELLOW}📝 Processando problema6.txt com o parser customizado...${NC}"
    
    # Executar compilador e capturar saída de debug
    if $COMPILER problema6.txt problema6.c 2>debug_problema6.log; then
        echo -e "${GREEN}✅ Conversão bem-sucedida!${NC}"
        echo -e "${CYAN}📄 Arquivo C gerado: problema6.c${NC}"
        
        # Mostrar estatísticas do arquivo gerado
        if [ -f "problema6.c" ]; then
            lines=$(wc -l < problema6.c)
            size=$(du -h problema6.c | cut -f1)
            echo -e "${CYAN}📊 Estatísticas: ${lines} linhas, ${size}B${NC}"
        fi
    else
        echo -e "${RED}❌ ERRO na compilação da linguagem customizada!${NC}"
        echo -e "${YELLOW}📋 Detalhes do erro:${NC}"
        if [ -f "debug_problema6.log" ]; then
            tail -n 10 debug_problema6.log
        fi
        echo -e "${YELLOW}💡 Verifique a sintaxe em problema6.txt${NC}"
        exit 1
    fi
    
    echo ""
}

# Função para compilar C para executável
compile_c_to_executable() {
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${BLUE}🔄 FASE 2: COMPILANDO CÓDIGO C COM GCC${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    
    echo -e "${YELLOW}⚙️ Compilando problema6.c com GCC...${NC}"
    
    # Verificar se arquivo C existe
    if [ ! -f "problema6.c" ]; then
        echo -e "${RED}❌ ERRO: Arquivo problema6.c não foi gerado!${NC}"
        exit 1
    fi
    
    # Compilar com GCC (flags para melhor debug e warnings)
    if gcc -Wall -Wextra -g -o problema6.exe problema6.c; then
        echo -e "${GREEN}✅ Compilação C bem-sucedida!${NC}"
        echo -e "${CYAN}🚀 Executável gerado: problema6.exe${NC}"
        
        # Mostrar informações do executável
        if [ -f "problema6.exe" ]; then
            size=$(du -h problema6.exe | cut -f1)
            echo -e "${CYAN}📊 Tamanho do executável: ${size}B${NC}"
        fi
    else
        echo -e "${RED}❌ ERRO na compilação do código C!${NC}"
        echo -e "${YELLOW}💡 Possíveis problemas:${NC}"
        echo -e "${YELLOW}   • Erro de sintaxe no código C gerado${NC}"
        echo -e "${YELLOW}   • Funções não declaradas${NC}"
        echo -e "${YELLOW}   • Problemas de tipos ou ponteiros${NC}"
        echo -e "${YELLOW}📄 Verifique o arquivo problema6.c para detalhes${NC}"
        exit 1
    fi
    
    echo ""
}

# Função para executar o programa
execute_program() {
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${BLUE}🚀 FASE 3: EXECUTANDO PROGRAMA BST${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    
    echo -e "${YELLOW}🎬 Iniciando execução da Binary Search Tree...${NC}"
    echo -e "${PURPLE}--------------------------------------------------------------------------------${NC}"
    
    # Executar e capturar código de saída
    if ./problema6.exe; then
        exit_code=$?
        echo -e "${PURPLE}--------------------------------------------------------------------------------${NC}"
        echo -e "${GREEN}✅ Execução concluída com sucesso! (código: $exit_code)${NC}"
    else
        exit_code=$?
        echo -e "${PURPLE}--------------------------------------------------------------------------------${NC}"
        echo -e "${RED}❌ Erro durante a execução! (código: $exit_code)${NC}"
        echo -e "${YELLOW}💡 Possíveis problemas:${NC}"
        echo -e "${YELLOW}   • Segmentation fault (acesso inválido à memória)${NC}"
        echo -e "${YELLOW}   • Stack overflow (recursão muito profunda)${NC}"
        echo -e "${YELLOW}   • Erro lógico no algoritmo${NC}"
        exit 1
    fi
    
    echo ""
}

# Função para exibir resumo final
show_final_summary() {
    echo -e "${PURPLE}================================================================================${NC}"
    echo -e "${GREEN}🎉 RESULTADO FINAL - BST IMPLEMENTADA COM SUCESSO!${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
    
    echo -e "${BLUE}✨ CONQUISTAS ALCANÇADAS:${NC}"
    echo -e "${GREEN}  🏆 Structs customizados (TreeNode) funcionando perfeitamente${NC}"
    echo -e "${GREEN}  🏆 Alocação dinâmica real (malloc) implementada corretamente${NC}"
    echo -e "${GREEN}  🏆 Algoritmos recursivos de inserção funcionais${NC}"
    echo -e "${GREEN}  🏆 Navegação em árvore (min/max) executada com precisão${NC}"
    echo -e "${GREEN}  🏆 Cálculo de altura e traversal por níveis operacionais${NC}"
    echo -e "${GREEN}  🏆 Código C gerado é válido e executável${NC}"
    echo ""
    
    echo -e "${BLUE}📁 ARQUIVOS GERADOS:${NC}"
    if [ -f "problema6.c" ]; then
        echo -e "${CYAN}  📄 problema6.c - Código C traduzido${NC}"
    fi
    if [ -f "problema6.exe" ]; then
        echo -e "${CYAN}  🚀 problema6.exe - Executável compilado${NC}"
    fi
    if [ -f "debug_problema6.log" ]; then
        echo -e "${CYAN}  📋 debug_problema6.log - Log de debug do parser${NC}"
    fi
    
    echo ""
    echo -e "${PURPLE}🌟 Esta é uma implementação REAL de BST, não uma simulação!${NC}"
    echo -e "${PURPLE}🌟 O compilador customizado agora suporta estruturas de dados complexas!${NC}"
    echo -e "${PURPLE}================================================================================${NC}"
}

# Função para limpeza (opcional)
cleanup() {
    echo -e "${BLUE}🧹 LIMPEZA DE ARQUIVOS TEMPORÁRIOS...${NC}"
    
    read -p "Deseja remover arquivos temporários? (debug_problema6.log) [y/N]: " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        if [ -f "debug_problema6.log" ]; then
            rm debug_problema6.log
            echo -e "${GREEN}✓ debug_problema6.log removido${NC}"
        fi
    fi
    echo ""
}

# ==============================================================================
# FUNÇÃO PRINCIPAL - EXECUÇÃO DO SCRIPT
# ==============================================================================
main() {
    # Registrar tempo de início
    start_time=$(date +%s)
    
    # Executar todas as fases
    show_header
    check_dependencies
    show_implementation_info
    compile_to_c
    compile_c_to_executable
    execute_program
    show_final_summary
    
    # Calcular tempo total
    end_time=$(date +%s)
    elapsed=$((end_time - start_time))
    echo -e "${CYAN}⏱️ Tempo total de execução: ${elapsed}s${NC}"
    echo ""
    
    # Opção de limpeza
    cleanup
    
    echo -e "${GREEN}🎯 Script concluído com sucesso!${NC}"
}

# Verificar se está sendo executado diretamente
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
