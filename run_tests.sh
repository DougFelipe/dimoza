#!/bin/bash

# Script unificado para executar todos os testes de avaliação
# Uso: ./run_tests.sh

echo "=== EXECUÇÃO DE TODOS OS TESTES DE AVALIAÇÃO ==="
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
    
    echo "Teste: $test_name"
    ((total_tests++))
    
    if [ ! -f "$test_file" ]; then
        echo "  ERRO: Arquivo $test_file não encontrado"
        return 1
    fi
    
    local output_file="saida_${test_name}.c"
    
    $COMPILER "$test_file" "$output_file" 2>/dev/null
    local compile_result=$?
    
    if [ $compile_result -eq 0 ]; then
        if [ "$should_fail" = "true" ]; then
            echo "  FALHOU (deveria ter falhado)"
            return 1
        else
            echo "  PASSOU"
            ((passed_tests++))
        fi
    else
        if [ "$should_fail" = "true" ]; then
            echo "  PASSOU"
            ((passed_tests++))
        else
            echo "  FALHOU"
            return 1
        fi
    fi
    
    return 0
}

echo "=== 1. ESTRUTURA SINTÁTICA ==="
run_test "erro_lexico" "testes/teste_erro_lexico.txt" "true"
run_test "erro_sintatico" "testes/teste_erro_sintatico.txt" "true"
run_test "derivacao_regras" "testes/teste_derivacao_regras.txt" "false"
run_test "conflitos_precedencia" "testes/teste_conflitos_precedencia.txt" "false"
run_test "precedencia" "testes/teste_precedencia.txt" "false"

echo
echo "=== 2. VARIÁVEIS ==="
run_test "variavel_omitida" "testes/teste_variavel_omitida.txt" "true"
run_test "variavel_duplicada_mesmo_escopo" "testes/teste_variavel_duplicada_mesmo_escopo.txt" "true"
run_test "variavel_escopos_distintos" "testes/teste_variavel_escopos_distintos.txt" "false"
run_test "variavel_escopos_aninhados" "testes/teste_variavel_escopos_aninhados.txt" "false"
run_test "estruturas_controle" "testes/teste_estruturas_controle.txt" "false"

echo
echo "=== 3. EXPRESSÕES ==="
run_test "coercoes_permitidas" "testes/teste_coercoes_permitidas.txt" "false"
run_test "tipos_incompativeis" "testes/teste_tipos_incompativeis.txt" "true"
run_test "tipos_especializados" "testes/teste_tipos_especializados.txt" "false"

echo
echo "=== 4. PASSAGEM DE PARÂMETROS ==="
run_test "passagem_parametros" "testes/teste_passagem_parametros.txt" "false"
run_test "referencia" "testes/teste_referencia.txt" "false"

echo
echo "=== TESTES ADICIONAIS ==="
run_test "id_error" "testes/teste_id_error.txt" "true"
run_test "string_error" "testes/teste_string_error.txt" "true"

echo
echo "=== RELATÓRIO FINAL ==="
echo "Total de testes: $total_tests"
echo "Testes aprovados: $passed_tests"
echo "Testes falharam: $((total_tests - passed_tests))"

if [ $passed_tests -eq $total_tests ]; then
    echo "RESULTADO: TODOS OS TESTES PASSARAM!"
    echo "Taxa de sucesso: 100%"
    exit 0
else
    echo "RESULTADO: Alguns testes falharam"
    echo "Taxa de sucesso: $((passed_tests * 100 / total_tests))%"
    exit 1
fi
