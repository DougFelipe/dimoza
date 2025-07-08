# Makefile para o protótipo do compilador

# --- Variáveis de Configuração ---
CC      = gcc
FLEX    = flex
BISON   = bison
CFLAGS  = -Wall -g
TARGET  = compiler

# --- Arquivos Fonte ---
Y_SRC   = parser.y
Y_HDR   = parser.tab.h
Y_C     = parser.tab.c
LEX_SRC = scanner.l
LEX_C   = lex.yy.c

# Lista de todas as bibliotecas auxiliares
LIBSRC  = ./lib/record.c ./lib/symbol_table.c

# --- Regras ---
.PHONY: all clean

# Regra padrão: construir o alvo principal
all: $(TARGET)

# 1) Gera o parser (parser.tab.c e parser.tab.h) a partir do arquivo .y
$(Y_C) $(Y_HDR): $(Y_SRC)
	$(BISON) -d -o $(Y_C) $(Y_SRC) -Werror=conflicts-sr -Werror=conflicts-rr

# 2) Gera o scanner (lex.yy.c) a partir do arquivo .l
$(LEX_C): $(LEX_SRC) $(Y_HDR)
	$(FLEX) -o $(LEX_C) $(LEX_SRC)

# 3) Compila e linka todos os arquivos .c para criar o executável final
$(TARGET): $(Y_C) $(LEX_C) $(LIBSRC)
	$(CC) $(CFLAGS) $(Y_C) $(LEX_C) $(LIBSRC) -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET) $(Y_C) $(Y_HDR) $(LEX_C) y.output
