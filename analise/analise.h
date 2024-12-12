#ifndef _ANALISE_H
#define _ANALISE_H

#include <string.h>

typedef enum {
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

#endif