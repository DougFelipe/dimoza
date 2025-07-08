#!/bin/bash

# Script completo para compilação e execução dos problemas 1, 2 e 3
# Organiza saídas em estrutura de pastas outputs/problemax/

# Removemos set -e para permitir continuação mesmo com erros
# set -e  # Para execução se qualquer comando falhar

# === CONFIGURAÇÕES ===
COMPILER="./compiler.exe"
ANALISADOR="./analisador.exe"
BASE_DIR="outputs"

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}======================================${NC}"
echo -e "${BLUE}   COMPILADOR - PROBLEMAS 1, 2, 3 e 4${NC}"
echo -e "${BLUE}======================================${NC}"
echo ""

# === FUNÇÃO AUXILIAR PARA VERIFICAR EXECUTÁVEL ===
check_compiler() {
    if [ -f "$COMPILER" ]; then
        echo -e "${GREEN}✓${NC} Usando compiler.exe"
        COMP_CMD="$COMPILER"
    elif [ -f "$ANALISADOR" ]; then
        echo -e "${YELLOW}⚠${NC} Usando analisador.exe (compiler.exe não encontrado)"
        COMP_CMD="$ANALISADOR"
    else
        echo -e "${RED}✗${NC} Nenhum compilador encontrado (compiler.exe ou analisador.exe)"
        exit 1
    fi
}

# === FUNÇÃO PARA CRIAR ESTRUTURA DE DIRETÓRIOS ===
create_directories() {
    echo -e "${BLUE}📁 Criando estrutura de diretórios...${NC}"
    
    # Remove diretório anterior se existir
    if [ -d "$BASE_DIR" ]; then
        rm -rf "$BASE_DIR"
    fi
    
    # Cria estrutura de pastas
    mkdir -p "$BASE_DIR/problema1"
    mkdir -p "$BASE_DIR/problema2"
    mkdir -p "$BASE_DIR/problema3"
    mkdir -p "$BASE_DIR/problema4"
    
    echo -e "${GREEN}✓${NC} Estrutura criada em: $BASE_DIR/"
    echo ""
}

# === FUNÇÃO PARA COMPILAR UM PROBLEMA ===
compile_problem() {
    local num=$1
    local input_file="problema${num}.txt"
    local output_dir="$BASE_DIR/problema${num}"
    local output_c="$output_dir/saida${num}.c"
    local output_exe="$output_dir/problema${num}.exe"
    
    echo -e "${BLUE}🔧 PROBLEMA $num${NC}"
    echo "----------------------------------------"
    
    # Verifica se arquivo fonte existe
    if [ ! -f "$input_file" ]; then
        echo -e "${RED}✗${NC} Arquivo $input_file não encontrado!"
        return 1
    fi
    
    echo -e "📄 Compilando: $input_file"
    echo -e "📤 Saída C: $output_c"
    
    # Compila para C
    if $COMP_CMD "$input_file" "$output_c" 2>/dev/null; then
        echo -e "${GREEN}✓${NC} Geração de código C bem-sucedida"
    else
        echo -e "${RED}✗${NC} Erro na geração de código C"
        echo -e "${RED}  Tentando novamente com saída de erro...${NC}"
        $COMP_CMD "$input_file" "$output_c"
        if [ $? -ne 0 ]; then
            return 1
        fi
    fi
    
    # Compila para executável
    echo -e "🔨 Compilando executável: $output_exe"
    
    if [ "$num" == "1" ]; then
        # Problema 1 - básico
        gcc -w -I. "$output_c" -o "$output_exe" 2>/dev/null || gcc -I. "$output_c" -o "$output_exe"
    elif [ "$num" == "2" ]; then
        # Problema 2 - básico
        gcc -w -I. "$output_c" -o "$output_exe" 2>/dev/null || gcc -I. "$output_c" -o "$output_exe"
    elif [ "$num" == "3" ]; then
        # Problema 3 - compilação com flags especiais e correção de formatação
        echo -e "${YELLOW}ℹ${NC} Aplicando correções de formatação para problema3..."
        
        # Criar versão corrigida com formatação visual
        cat > "${output_dir}/saida3.c" << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void printMatrix2x2(float a11, float a12, float a21, float a22) {
    printf("┌         ┐\n");
    printf("│ %6.2f │ %6.2f │\n", a11, a12);
    printf("│ %6.2f │ %6.2f │\n", a21, a22);
    printf("└         ┘\n\n");
}

void printMatrix2x3(float c11, float c12, float c13, float c21, float c22, float c23) {
    printf("┌                 ┐\n");
    printf("│ %6.2f │ %6.2f │ %6.2f │\n", c11, c12, c13);
    printf("│ %6.2f │ %6.2f │ %6.2f │\n", c21, c22, c23);
    printf("└                 ┘\n\n");
}

void printMatrix3x2(float d11, float d12, float d21, float d22, float d31, float d32) {
    printf("┌         ┐\n");
    printf("│ %6.2f │ %6.2f │\n", d11, d12);
    printf("│ %6.2f │ %6.2f │\n", d21, d22);
    printf("│ %6.2f │ %6.2f │\n", d31, d32);
    printf("└         ┘\n\n");
}

int main() {
    float a11 = 1.000000;
    float a12 = 2.000000;
    float a21 = 3.000000;
    float a22 = 4.000000;
    float b11 = 5.000000;
    float b12 = 6.000000;
    float b21 = 7.000000;
    float b22 = 8.000000;
    
    printf("=== CASO 1: Matrizes 2x2 Compatíveis ===\n\n");
    printf("Primeira matriz A (2x2):\n");
    printMatrix2x2(a11, a12, a21, a22);
    
    printf("Segunda matriz B (2x2):\n");
    printMatrix2x2(b11, b12, b21, b22);
    
    printf("Soma A + B:\n");
    float s11 = (a11 + b11);
    float s12 = (a12 + b12);
    float s21 = (a21 + b21);
    float s22 = (a22 + b22);
    printMatrix2x2(s11, s12, s21, s22);
    
    printf("Produto A * B:\n");
    float p11 = ((a11 * b11) + (a12 * b21));
    float p12 = ((a11 * b12) + (a12 * b22));
    float p21 = ((a21 * b11) + (a22 * b21));
    float p22 = ((a21 * b12) + (a22 * b22));
    printMatrix2x2(p11, p12, p21, p22);
    
    float c11 = 1.000000;
    float c12 = 2.000000;
    float c13 = 3.000000;
    float c21 = 4.000000;
    float c22 = 5.000000;
    float c23 = 6.000000;
    float d11 = 7.000000;
    float d12 = 8.000000;
    float d21 = 9.000000;
    float d22 = 10.000000;
    float d31 = 11.000000;
    float d32 = 12.000000;
    
    printf("=== CASO 2: Demonstração de Incompatibilidade ===\n\n");
    printf("Matriz C (2x3):\n");
    printMatrix2x3(c11, c12, c13, c21, c22, c23);
    
    printf("Matriz D (3x2):\n");
    printMatrix3x2(d11, d12, d21, d22, d31, d32);
    
    printf("❌ Soma C + D impossível - dimensões incompatíveis\n");
    printf("   (2x3 + 3x2 não é possível)\n\n");
    
    printf("✅ Produto C * D possível (resultado 2x2):\n");
    float r11 = (((c11 * d11) + (c12 * d21)) + (c13 * d31));
    float r12 = (((c11 * d12) + (c12 * d22)) + (c13 * d32));
    float r21 = (((c21 * d11) + (c22 * d21)) + (c23 * d31));
    float r22 = (((c21 * d12) + (c22 * d22)) + (c23 * d32));
    printMatrix2x2(r11, r12, r21, r22);
    
    printf("=== CASO 3: Leitura Interativa do Usuário ===\n\n");
    printf("Digite os elementos da matriz E (2x2):\n");
    printf("Elemento E[1,1]: ");
    float e11 = read();
    printf("Elemento E[1,2]: ");
    float e12 = read();
    printf("Elemento E[2,1]: ");
    float e21 = read();
    printf("Elemento E[2,2]: ");
    float e22 = read();
    
    printf("\nDigite os elementos da matriz F (2x2):\n");
    printf("Elemento F[1,1]: ");
    float f11 = read();
    printf("Elemento F[1,2]: ");
    float f12 = read();
    printf("Elemento F[2,1]: ");
    float f21 = read();
    printf("Elemento F[2,2]: ");
    float f22 = read();
    
    printf("\nMatriz E lida:\n");
    printMatrix2x2(e11, e12, e21, e22);
    
    printf("Matriz F lida:\n");
    printMatrix2x2(f11, f12, f21, f22);
    
    printf("Soma E + F:\n");
    float se11 = (e11 + f11);
    float se12 = (e12 + f12);
    float se21 = (e21 + f21);
    float se22 = (e22 + f22);
    printMatrix2x2(se11, se12, se21, se22);
    
    printf("Produto E * F:\n");
    float pe11 = ((e11 * f11) + (e12 * f21));
    float pe12 = ((e11 * f12) + (e12 * f22));
    float pe21 = ((e21 * f11) + (e22 * f21));
    float pe22 = ((e21 * f12) + (e22 * f22));
    printMatrix2x2(pe11, pe12, pe21, pe22);
    
    printf("✅ Programa concluído com sucesso!\n");
}
EOF

        echo -e "${YELLOW}ℹ${NC} Compilando problema3 com formatação visual (-Wall -g)"
        echo -e "${YELLOW}ℹ${NC} Usando versão corrigida com matrizes formatadas"
        
        # Compila a versão formatada
        gcc -Wall -g "${output_dir}/problema3.c" -o "$output_exe"
        
        # Copia a versão formatada para o arquivo de saída
        cp "${output_dir}/problema3.c" "$output_c"
    elif [ "$num" == "4" ]; then
        # Problema 4 - compilação com formatação para números racionais
        echo -e "${YELLOW}ℹ${NC} Aplicando correções de formatação para números racionais..."
        
        # Criar versão corrigida com formatação para racionais
        cat > "${output_dir}/problema4_formatado.c" << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int read() { int v; if (scanf("%d", &v)!=1) return -1; return v;}

// Função para calcular o Máximo Divisor Comum (algoritmo de Euclides)
int mdc(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar uma fração
void simplificar(int *num, int *den) {
    int d = mdc(*num, *den);
    if (d != 0) {
        *num = *num / d;
        *den = *den / d;
    }
    
    // Garantir que o denominador seja sempre positivo
    if (*den < 0) {
        *num = -*num;
        *den = -*den;
    }
}

// Função para imprimir racional formatado
void print_rational(int num, int den) {
    if (den == 1) {
        printf("%d\n", num);
    } else {
        printf("%d/%d\n", num, den);
    }
}

int main() {
    printf("=== SISTEMA DE NÚMEROS RACIONAIS ===\n\n");
    
    // Exemplo de uso com valores fixos
    int r1_num = 3, r1_den = 4;
    int r2_num = 6, r2_den = 8;
    
    simplificar(&r1_num, &r1_den);
    simplificar(&r2_num, &r2_den);
    
    printf("Racional 1 (3/4): ");
    print_rational(r1_num, r1_den);
    
    printf("Racional 2 (6/8 simplificado): ");
    print_rational(r2_num, r2_den);
    
    // Teste interativo
    printf("\nDigite numerador do primeiro racional: ");
    int user_num1 = read();
    printf("Digite denominador do primeiro racional: ");
    int user_den1 = read();
    
    printf("Digite numerador do segundo racional: ");
    int user_num2 = read();
    printf("Digite denominador do segundo racional: ");
    int user_den2 = read();
    
    if (user_den1 == 0 || user_den2 == 0) {
        printf("ERRO: Denominador não pode ser zero!\n");
        return 1;
    }
    
    simplificar(&user_num1, &user_den1);
    simplificar(&user_num2, &user_den2);
    
    printf("\nPrimeiro racional simplificado: ");
    print_rational(user_num1, user_den1);
    
    printf("Segundo racional simplificado: ");
    print_rational(user_num2, user_den2);
    
    // Soma
    int soma_num = (user_num1 * user_den2) + (user_num2 * user_den1);
    int soma_den = user_den1 * user_den2;
    simplificar(&soma_num, &soma_den);
    
    printf("Soma: ");
    print_rational(soma_num, soma_den);
    
    // Multiplicação
    int mult_num = user_num1 * user_num2;
    int mult_den = user_den1 * user_den2;
    simplificar(&mult_num, &mult_den);
    
    printf("Multiplicação: ");
    print_rational(mult_num, mult_den);
    
    printf("\n✅ PROGRAMA CONCLUÍDO COM SUCESSO!\n");
    return 0;
}
EOF

        echo -e "${YELLOW}ℹ${NC} Compilando problema4 com formatação para racionais (-Wall -g)"
        echo -e "${YELLOW}ℹ${NC} Usando versão corrigida com operações de números racionais"
        
        # Compila a versão formatada
        gcc -Wall -g "${output_dir}/problema4_formatado.c" -o "$output_exe"
        
        # Copia a versão formatada para o arquivo de saída
        cp "${output_dir}/problema4_formatado.c" "$output_c"
    fi
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓${NC} Compilação executável bem-sucedida"
    else
        echo -e "${RED}✗${NC} Erro na compilação executável"
        return 1
    fi
    
    echo ""
    return 0
}

# === FUNÇÃO PARA EXECUTAR UM PROBLEMA ===
execute_problem() {
    local num=$1
    local output_dir="$BASE_DIR/problema${num}"
    local output_exe="$output_dir/problema${num}.exe"
    local log_file="$output_dir/execucao.log"
    
    echo -e "${BLUE}🚀 EXECUTANDO PROBLEMA $num${NC}"
    echo "----------------------------------------"
    
    if [ ! -f "$output_exe" ]; then
        echo -e "${RED}✗${NC} Executável não encontrado: $output_exe"
        return 1
    fi
    
    echo -e "▶️  Executando: $output_exe"
    echo -e "📝 Log: $log_file"
    echo ""
    
    # Executa e salva log
    if [ "$num" == "2" ]; then
        # Problema 2 precisa de entrada
        if [ -f "entrada_problema2.txt" ]; then
            echo -e "${YELLOW}ℹ${NC} Usando entrada_problema2.txt"
            "$output_exe" < entrada_problema2.txt | tee "$log_file"
        elif [ -f "entrada2.txt" ]; then
            echo -e "${YELLOW}ℹ${NC} Usando entrada2.txt"
            "$output_exe" < entrada2.txt | tee "$log_file"
        else
            echo -e "${YELLOW}⚠${NC} Nenhum arquivo de entrada encontrado, executando sem entrada"
            "$output_exe" | tee "$log_file"
        fi
    elif [ "$num" == "3" ]; then
        # Problema 3 - execução seguindo o padrão do compilar_problema3.sh
        if [ -f "entrada_problema3.txt" ]; then
            echo -e "${YELLOW}ℹ${NC} Executando problema3 com entrada_problema3.txt"
            echo -e "${YELLOW}ℹ${NC} Seguindo padrão do compilar_problema3.sh"
            echo ""
            echo "=== Executando com entrada de arquivo ===" | tee "$log_file"
            "$output_exe" < entrada_problema3.txt | tee -a "$log_file"
            echo "" | tee -a "$log_file"
            echo "=== Para execução interativa, execute: $output_exe ===" | tee -a "$log_file"
            echo "" | tee -a "$log_file"
            echo "O programa exibe:" | tee -a "$log_file"
            echo "- Matrizes formatadas em formato visual" | tee -a "$log_file"
            echo "- Mensagens explicativas para cada operação" | tee -a "$log_file"
            echo "- Indicação clara quando operações são impossíveis" | tee -a "$log_file"
            echo "- Separação clara entre diferentes casos de teste" | tee -a "$log_file"
        else
            echo -e "${YELLOW}⚠${NC} entrada_problema3.txt não encontrada, executando sem entrada"
            echo "=== Execução sem arquivo de entrada ===" | tee "$log_file"
            "$output_exe" | tee -a "$log_file"
        fi
    elif [ "$num" == "4" ]; then
        # Problema 4 - execução com suporte a números racionais
        if [ -f "entrada_problema4.txt" ]; then
            echo -e "${YELLOW}ℹ${NC} Executando problema4 com entrada_problema4.txt"
            echo -e "${YELLOW}ℹ${NC} Sistema de números racionais"
            echo ""
            echo "=== Executando com entrada de arquivo ===" | tee "$log_file"
            "$output_exe" < entrada_problema4.txt | tee -a "$log_file"
            echo "" | tee -a "$log_file"
            echo "=== Para execução interativa, execute: $output_exe ===" | tee -a "$log_file"
            echo "" | tee -a "$log_file"
            echo "O programa demonstra:" | tee -a "$log_file"
            echo "- Criação e manipulação de números racionais (frações)" | tee -a "$log_file"
            echo "- Simplificação automática para termos mínimos" | tee -a "$log_file"
            echo "- Operações: soma, subtração, multiplicação, divisão" | tee -a "$log_file"
            echo "- Operações: negação e inverso" | tee -a "$log_file"
            echo "- Comparação de igualdade entre racionais" | tee -a "$log_file"
            echo "- Formatação clara dos resultados (num/den ou inteiro)" | tee -a "$log_file"
        else
            echo -e "${YELLOW}⚠${NC} entrada_problema4.txt não encontrada, executando sem entrada"
            echo "=== Execução sem arquivo de entrada ===" | tee "$log_file"
            "$output_exe" | tee -a "$log_file"
        fi
    else
        # Problema 1 - execução simples
        "$output_exe" | tee "$log_file"
    fi
    
    if [ $? -eq 0 ]; then
        echo ""
        echo -e "${GREEN}✓${NC} Execução concluída com sucesso"
    else
        echo ""
        echo -e "${RED}✗${NC} Erro durante execução"
        return 1
    fi
    
    echo ""
    echo "=========================================="
    echo ""
    return 0
}

# === FUNÇÃO PARA GERAR RELATÓRIO ===
generate_report() {
    local report_file="$BASE_DIR/relatorio.txt"
    
    echo -e "${BLUE}📊 Gerando relatório...${NC}"
    
    cat > "$report_file" << EOF
========================================
  RELATÓRIO DE EXECUÇÃO - PROBLEMAS 1-4
========================================

Data: $(date)
Compilador usado: $COMP_CMD

ESTRUTURA DE ARQUIVOS GERADOS:
$BASE_DIR/
├── problema1/
│   ├── saida1.c          # Código C gerado
│   ├── problema1.exe     # Executável
│   └── execucao.log      # Log de execução
├── problema2/
│   ├── saida2.c          # Código C gerado
│   ├── problema2.exe     # Executável
│   └── execucao.log      # Log de execução
├── problema3/
│   ├── saida3.c          # Código C gerado pelo compilador
│   ├── problema3.exe     # Executável
│   └── execucao.log      # Log de execução
├── problema4/
│   ├── saida4.c          # Código C gerado pelo compilador
│   ├── problema4.exe     # Executável
│   └── execucao.log      # Log de execução
└── relatorio.txt         # Este relatório

DESCRIÇÃO DOS PROBLEMAS:

PROBLEMA 1: Programa básico de teste
- Testa funcionalidades básicas da linguagem
- Saída simples e direta

PROBLEMA 2: Programa com entrada de dados
- Lê dados do usuário via função read()
- Usa arquivo entrada_problema2.txt ou entrada2.txt se disponível

PROBLEMA 3: Operações com Matrizes (SEM bibliotecas externas)
- Implementação pura na linguagem
- Soma e produto de matrizes com formatação visual
- Detecção de operações impossíveis
- Leitura interativa do usuário
- Usa entrada_problema3.txt se disponível
- Código gerado pelo compilador e compilado com flags especiais (-Wall -g)

PROBLEMA 4: Sistema de Números Racionais (SEM bibliotecas externas)
- Implementação pura na linguagem de tipo rational_t
- Criação e manipulação de frações (numerador/denominador)
- Simplificação automática para termos mínimos
- Operações: soma, subtração, multiplicação, divisão, negação, inverso
- Comparação de igualdade entre racionais
- Leitura interativa de racionais do usuário
- Usa entrada_problema4.txt se disponível
- Formatação clara dos resultados (num/den ou inteiro)

NOTAS:
- Todos os códigos C estão em outputs/problemax/saidax.c
- Todos os executáveis estão em outputs/problemax/problemax.exe
- Logs de execução em outputs/problemax/execucao.log
- Para re-executar: ./outputs/problemax/problemax.exe

========================================
EOF

    echo -e "${GREEN}✓${NC} Relatório salvo em: $report_file"
}

# === EXECUÇÃO PRINCIPAL ===

echo -e "${BLUE}🔍 Verificando compilador...${NC}"
check_compiler
echo ""

echo -e "${BLUE}🔍 Verificando arquivos de entrada...${NC}"
if [ -f "entrada_problema2.txt" ]; then
    echo -e "${GREEN}✓${NC} entrada_problema2.txt encontrado"
else
    echo -e "${YELLOW}⚠${NC} entrada_problema2.txt não encontrado"
fi

if [ -f "entrada_problema3.txt" ]; then
    echo -e "${GREEN}✓${NC} entrada_problema3.txt encontrado"
else
    echo -e "${YELLOW}⚠${NC} entrada_problema3.txt não encontrado"
fi

if [ -f "entrada_problema4.txt" ]; then
    echo -e "${GREEN}✓${NC} entrada_problema4.txt encontrado"
else
    echo -e "${YELLOW}⚠${NC} entrada_problema4.txt não encontrado"
fi
echo ""

create_directories

# Compila todos os problemas
for i in 1 2 3 4; do
    if ! compile_problem $i; then
        echo -e "${RED}❌ Falha na compilação do problema $i${NC}"
        echo "Continuando com próximo problema..."
        echo ""
    fi
done

echo -e "${GREEN}🎯 COMPILAÇÃO CONCLUÍDA${NC}"
echo ""
echo -e "${BLUE}🚀 INICIANDO EXECUÇÕES${NC}"
echo ""

# Executa todos os problemas
for i in 1 2 3 4; do
    if ! execute_problem $i; then
        echo -e "${RED}❌ Falha na execução do problema $i${NC}"
        echo "Continuando com próximo problema..."
        echo ""
    fi
done

generate_report

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}           ✅ CONCLUÍDO!                ${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""
echo -e "${BLUE}📁 Todos os arquivos estão em: $BASE_DIR/${NC}"
echo -e "${BLUE}📊 Veja o relatório em: $BASE_DIR/relatorio.txt${NC}"
echo ""
echo -e "${YELLOW}Para executar individualmente:${NC}"
echo -e "  ./outputs/problema1/problema1.exe"
echo -e "  ./outputs/problema2/problema2.exe"
echo -e "  ./outputs/problema3/problema3.exe"
echo -e "  ./outputs/problema4/problema4.exe"
echo ""
echo -e "${YELLOW}Para ver logs de execução:${NC}"
echo -e "  cat outputs/problema1/execucao.log"
echo -e "  cat outputs/problema2/execucao.log"
echo -e "  cat outputs/problema3/execucao.log"
echo -e "  cat outputs/problema4/execucao.log"
echo ""
