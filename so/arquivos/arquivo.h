#ifndef _ARQUIVO_H
#define _ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_BUFFER 1024

typedef struct {
    char**  dados;  
    int     n_linhas;   
    int     n_caracteres;
} arquivo_t;

arquivo_t ler_arquivo(char* nome);

#endif