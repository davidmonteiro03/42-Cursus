#!/bin/bash

# Diretórios com os arquivos de mapa
VALID_DIR="maps/valid"
INVALID_DIR="maps/invalid"

# Arquivo de log para registrar as falhas
LOG_FILE="valgrind_failures.log"

# Limpa o arquivo de log anterior, se existir
> "$LOG_FILE"

# Inicializa os contadores
correct_count=0
wrong_count=0

# Definição de cores
RED='\e[31m'
GREEN='\e[32m'
NC='\e[0m' # No Color

# Função para executar valgrind e verificar falhas
run_valgrind() {
    local map_file=$1
    local log_file=$2
    local expected_status=$3
    
    # echo "Executando valgrind no arquivo: $map_file"
    ./cub3D "$map_file" &> "$log_file"
    local actual_status=$?
    
    if [ $actual_status -ne $expected_status ]; then
        echo -e "$map_file: \e[31m✗\e[0m" # Red X
        echo "==== Falha no arquivo: $map_file ====" >> "$LOG_FILE"
        echo "Esperado: $expected_status, Obtido: $actual_status" >> "$LOG_FILE"
        cat "$log_file" >> "$LOG_FILE"
        echo -e "\n\n" >> "$LOG_FILE"
        ((wrong_count++))
    else
        echo -e "$map_file: \e[32m✔\e[0m" # Green checkmark
        rm "$log_file"
        ((correct_count++))
    fi
}

# Executa valgrind em todos os arquivos inválidos
for map_file in "$INVALID_DIR"/*.cub; do
    run_valgrind "$map_file" "valgrind_log_invalid.txt" 1
done

# Executa valgrind em todos os arquivos válidos
for map_file in "$VALID_DIR"/*.cub; do
    run_valgrind "$map_file" "valgrind_log_valid.txt" 0
done

total_count=$((correct_count + wrong_count))

# Exibe os resultados finais
echo ""
echo -e "${GREEN}Execução completa.${NC}"
echo ""
echo -e "${NC}Total de mapas testados: $total_count${NC}"
echo -e "${NC}Resultado: ${GREEN}$correct_count/${NC}$total_count${NC}"
echo -e "${NC}Total de errados: ${RED}$wrong_count${NC}"