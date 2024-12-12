#ifndef _TRADUTOR_H
#define _TRADUTOR_H

#include "../chave/chave.c"

typedef struct {
    chave_t* chaves_l;
} tradutor_t;

tradutor_t criar_tradutor();

#endif //_TRADUTOR_H