#!/bin/bash

# Script de teste completo para critérios de avaliação
# Uso: ./teste_criterios_completo.sh

echo "====================================================================="
echo "    TESTES COMPLETOS PARA CRITÉRIOS DE AVALIAÇÃO ACADÊMICA"
echo "====================================================================="
echo

# Verifica se o compilador existe
if [ ! -f "./compiler" ]; then
    echo "ERRO: Compilador não encontrado. Execute 'make' primeiro."
    exit 1
fi

COMPILER="./compiler"
total_tests=0
passed_tests=0

# Função para executar um teste
run_test() {
    local test_name="$1"
    local test_file="$2"
    local should_fail="$3"
    local description="$4"
    
    echo "🔍 Teste: $test_name"
    echo "   Descrição: $description"
    ((total_tests++))
    
    if [ ! -f "$test_file" ]; then
        echo "   ❌ ERRO: Arquivo $test_file não encontrado"
        return 1
    fi
    
    local output_file="saida_${test_name}.c"
    
    echo "   📝 Compilando $test_file..."
    $COMPILER "$test_file" "$output_file" 2>&1
    local compile_result=$?
    
    if [ $compile_result -eq 0 ]; then
        if [ "$should_fail" = "true" ]; then
            echo "   ❌ FALHA: Teste deveria falhar mas passou"
            return 1
        else
            echo "   ✅ Compilação bem-sucedida"
            if [ -f "$output_file" ]; then
                echo "   📄 Código C gerado: $output_file"
                ((passed_tests++))
                echo "   🎉 PASSOU"
            else
                echo "   ❌ Arquivo C não foi gerado"
                return 1
            fi
        fi
    else
        if [ "$should_fail" = "true" ]; then
            echo "   ✅ Falhou como esperado"
            ((passed_tests++))
            echo "   🎉 PASSOU"
        else
            echo "   ❌ Falha inesperada na compilação"
            return 1
        fi
    fi
    
    echo
    return 0
}

echo "====================================================================="
echo " 1. ESTRUTURA SINTÁTICA"
echo "====================================================================="

run_test "erro_lexico" "teste_erro_lexico.txt" "true" \
    "Detecção de caracteres inválidos (@)"

run_test "erro_sintatico" "teste_erro_sintatico.txt" "true" \
    "Detecção de expressões incompletas"

run_test "derivacao_regras" "teste_derivacao_regras.txt" "false" \
    "Derivação completa das regras sintáticas"

run_test "conflitos_precedencia" "teste_conflitos_precedencia.txt" "false" \
    "Resolução de conflitos shift-reduce com precedência"

echo "====================================================================="
echo " 2. VARIÁVEIS"
echo "====================================================================="

run_test "variavel_omitida" "teste_variavel_omitida.txt" "true" \
    "Detecção de variáveis não declaradas"

run_test "variavel_duplicada_mesmo_escopo" "teste_variavel_duplicada_mesmo_escopo.txt" "true" \
    "Detecção de variáveis duplicadas no mesmo escopo"

run_test "variavel_escopos_distintos" "teste_variavel_escopos_distintos.txt" "false" \
    "Variáveis com mesmo nome em escopos distintos (funções)"

run_test "variavel_escopos_aninhados" "teste_variavel_escopos_aninhados.txt" "false" \
    "Variáveis com mesmo nome em escopos aninhados (shadowing)"

echo "====================================================================="
echo " 3. EXPRESSÕES"
echo "====================================================================="

run_test "coercoes_permitidas" "teste_coercoes_permitidas.txt" "false" \
    "Coerções permitidas entre tipos compatíveis"

run_test "tipos_incompativeis" "teste_tipos_incompativeis.txt" "true" \
    "Detecção de operações com tipos incompatíveis"

echo "====================================================================="
echo " 4. PASSAGEM DE PARÂMETROS"
echo "====================================================================="

run_test "passagem_parametros" "teste_passagem_parametros.txt" "false" \
    "Passagem por valor vs. referência"

echo "====================================================================="
echo " RELATÓRIO FINAL"
echo "====================================================================="

echo "📊 Total de testes: $total_tests"
echo "✅ Testes aprovados: $passed_tests"
echo "❌ Testes falharam: $((total_tests - passed_tests))"

if [ $passed_tests -eq $total_tests ]; then
    echo "🎉 TODOS OS CRITÉRIOS DE AVALIAÇÃO FORAM ATENDIDOS!"
    echo "🏆 Taxa de sucesso: 100%"
else
    echo "⚠️  Alguns critérios precisam de atenção."
    echo "📈 Taxa de sucesso: $((passed_tests * 100 / total_tests))%"
fi

echo "====================================================================="
