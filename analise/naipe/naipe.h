#ifndef _NAIPE_H
#define _NAIPE_H

#include "../../so/arquivos/arquivo.h"
#include "../erro/erro.h"

#define N_SIMBOLOS 14

// IDs de simbolos
typedef enum {
  ID_SIMBOLO_DECL       = 0x00000000,         
  ID_SIMBOLO_DECLPROC,
  ID_SIMBOLO_DECLMOD,      
  ID_SIMBOLO_TIPOINT8,     
  ID_SIMBOLO_TIPOINT16,    
  ID_SIMBOLO_TIPOINT32,    
  ID_SIMBOLO_TIPONAT8,     
  ID_SIMBOLO_TIPONAT16,    
  ID_SIMBOLO_TIPONAT32,    
  ID_SIMBOLO_TIPOGENINT,   
  ID_SIMBOLO_TIPOGENNAT,   
  ID_SIMBOLO_TIPOTEXTO,    
  ID_SIMBOLO_TIPOLOGICO,    
  ID_SIMBOLO_RESFIM,
  ID_SIMBOLO_DECLOPERADOR
} ID_SIMBOLO_E;

typedef struct {
  char**   simbolo;
} naipe_t;

erro_t criar_naipe(arquivo_t* arquivo_naipe, naipe_t* naipe);

#endif 
