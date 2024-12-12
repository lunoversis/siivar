#ifndef _CHAVE_H
#define _CHAVE_H

#include <string.h>
#include <malloc.h>

typedef enum {
    tipo_chave_indef,       // indefinido
    tipo_chave_texto,       // A..Z, a..z
    tipo_chave_numero,      // 0..9
    tipo_chave_simbolo,     // depende do naipe
    tipo_chave_operador,    // +, -, *, /, ^
    tipo_chave_especial     // \n, \0, ' '
} tipos_chave_e;

typedef struct {
    tipos_chave_e   tipo;
    char*           valor;
} chave_t;

//  Funcao que cria uma matriz dinamica de chaves
chave_t*    obter_chaves(char* entrada, int* n_chaves);

//  Subrotina que liberta a memoria alocada em uma matriz
void        liberar_chaves(chave_t* ch);

#endif