#include "naipe.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

erro_t criar_naipe(arquivo_t *arquivo_naipe, naipe_t* naipe)
{
  naipe->simbolo = (char **)malloc(arquivo_naipe->n_linhas * sizeof(char *));
  erro_t erro = ok;
  if (naipe->simbolo == NULL)
  {
    PREP_ERRO(erro, erro_argumentos, "Impossivel alocar simbolos do naipe!");
    return erro;
  }

  for (int i = 0; i < arquivo_naipe->n_linhas; i++)
  {
    naipe->simbolo[i] = strdup(arquivo_naipe->dados[i]);
    if (naipe->simbolo[i] == NULL)
    {
      PREP_ERRO(erro, erro_tipo, "Simbolo de naipe nao pode ser nulo!");
      return erro;
    }
  }
  return erro;
}
