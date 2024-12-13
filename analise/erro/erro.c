#include "erro.h"

#include <stdio.h>
#include <stdlib.h>

void escrever_erro(erro_t erro)
{
  if(erro.tipo == erro_nenhum)
  {
    return;
  }
  printf("ERRO: ");
  switch(erro.tipo)
  {
  case erro_sintaxe:
    printf("Sintaxe invalida!");
    break;
  case erro_a_fazer:
    printf("\'A Fazer\' (Nao implementado)");
    break;
  case erro_tipo:
    printf("Tipo invalido!")
    break;
  case erro_argumentos:
    printf("Argumento invalido!");
  case erro_generico:
    break;
  case erro_nenhum:
    break;
  default:
    break;
  }
  putchar('\n');
}

