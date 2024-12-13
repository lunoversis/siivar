#ifndef _ERRO_H
#define _ERRO_H

// tipos de erros
typedef enum {
  erro_nenhum    = 0,
  erro_tradutor,
  erro_argumentos,
  erro_tipo,
  erro_generico,
  erro_sintaxe,
  erro_a_fazer
} erro_tipo_e;

// Estrutura para lidar com erros
typedef struct {
  erro_tipo_e tipo;
  char* mensagem;
} erro_t;

#define CRIAR_ERRO(n, t, msg) erro_t(n) = { (t), (msg) }
#define PREP_ERRO(n, t, msg)  erro_t(n) = { (t), (msg) }

// "Nao ha erros, continue..."
erro_t ok = { erro_nenhum, NULL };

const char* caractere_vazio = "\r";
const char* caractere_delim = ":\n";

void escrever_erro(erro_t erro);

#endif //_ERRO_H_
