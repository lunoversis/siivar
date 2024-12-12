#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chave.h"

chave_t* obter_chaves(char* entrada, int* n_chaves) 
{
    // Variável auxiliar para armazenar a chave atual
    chave_t c_atual;   

    // Inicializando a matriz de saída
    chave_t* saida = NULL;

    // Inicializações
    c_atual.tipo = tipo_chave_indef;
    c_atual.valor = (char*) malloc(1); // Inicialmente uma string vazia
    c_atual.valor[0] = '\0';

    *n_chaves = 0;

    // Percorrendo o texto de entrada
    for (int i = 0; i <= strlen(entrada); i++) 
    {
        // Caractere atual (ou delimitador final quando `\0`)
        char c = entrada[i];

        // Verifica se é um delimitador
        if (c == ' ' || c == '\n' || c == '\0') 
        {
            // Verifica se há algo em c_atual.valor para armazenar
            if (strlen(c_atual.valor) > 0) 
            {
                // Incrementa o contador de chaves
                (*n_chaves)++;
                saida = (chave_t*)realloc(saida, (*n_chaves) * sizeof(chave_t));

                // Armazena a chave atual na saída
                saida[*n_chaves - 1].tipo = c_atual.tipo;
                saida[*n_chaves - 1].valor = strdup(c_atual.valor);

                // Reseta `c_atual`
                c_atual.tipo = tipo_chave_indef;
                free(c_atual.valor);
                c_atual.valor = (char*)malloc(1);
                c_atual.valor[0] = '\0';
            }
        } 
        else 
        {
            // Atualiza o tipo da chave
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
            {
                c_atual.tipo = tipo_chave_texto;
            } 
            else if (c >= '0' && c <= '9') 
            {
                c_atual.tipo = tipo_chave_numero;
            } 
            else if (c == '+' || c == '-' || c == '*' || c == '/') 
            {
                c_atual.tipo = tipo_chave_operador;
            }

            // Concatena o caractere ao valor atual
            size_t len = strlen(c_atual.valor);
            c_atual.valor = (char*)realloc(c_atual.valor, len + 2);
            c_atual.valor[len] = c;
            c_atual.valor[len + 1] = '\0';
        }
    }

    // Libera memória temporária usada por c_atual
    free(c_atual.valor);

    return saida;
}

void liberar_chaves(chave_t* ch, int n_chaves) 
{
    // Libera a memória de cada chave
    for (int i = 0; i < n_chaves; i++) 
    {
        free(ch[i].valor);
    }

    // Libera a matriz de chaves
    free(ch);
}
