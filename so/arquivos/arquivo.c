#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

arquivo_t ler_arquivo(char* nome)
{
    FILE *arq_ptr;               // Ponteiro para o arquivo
    arquivo_t arquivo;           // Estrutura para armazenar os dados do arquivo
    int n_linhas = 0;            // Contador de linhas
    char buffer[TAMANHO_BUFFER]; // Buffer temporário para leitura de uma linha

    // Inicialização do ponteiro de dados como NULL
    arquivo.dados = NULL;

    // Abra o arquivo no modo leitura
    arq_ptr = fopen(nome, "r");

    // Verifique se o arquivo foi aberto corretamente
    if (arq_ptr == NULL) {
        printf("Arquivo não pode ser aberto!\n");
        exit(EXIT_FAILURE);
    }

    // Leia o arquivo linha por linha
    while (fgets(buffer, TAMANHO_BUFFER, arq_ptr) != NULL) {
        n_linhas++;

        // Realoca o array de ponteiros para armazenar mais uma linha
        arquivo.dados = (char**)realloc(arquivo.dados, n_linhas * sizeof(char*));

        if (arquivo.dados == NULL) {
            printf("Erro ao alocar memória!\n");
            fclose(arq_ptr);
            exit(EXIT_FAILURE);
        }

        // Aloca espaço para armazenar a linha atual
        arquivo.dados[n_linhas - 1] = strdup(buffer);

        if (arquivo.dados[n_linhas - 1] == NULL) {
            printf("Erro ao alocar memória para linha!\n");
            fclose(arq_ptr);
            exit(EXIT_FAILURE);
        }
    }

    // Feche o arquivo
    fclose(arq_ptr);

    // Atualize o número de linhas na estrutura
    arquivo.n_linhas = n_linhas;

    return arquivo;
}

// Função para liberar a memória alocada
void liberar_arquivo(arquivo_t* arquivo)
{
    for (int i = 0; i < arquivo->n_linhas; i++) {
        free(arquivo->dados[i]); // Libera cada linha
    }
    free(arquivo->dados); // Libera o array de ponteiros
}
