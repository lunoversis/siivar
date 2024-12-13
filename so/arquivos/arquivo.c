#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

fpos_t tamanho_arquivo(arquivo_t* arquivo)
{
    if(!arquivo) return 0;
    fpos_t original = 0;
    if(fgetpos(arquivo->cabecalho, &original) != 0)
    {
        printf("fgetpos() falhou!: %i\n", errno);
        return 0;
    }
    fseek(arquivo->cabecalho, 0, SEEK_SET);
    fpos_t saida = fseek(arquivo->cabecalho, 0, SEEK_END);
    ftell(arquivo->cabecalho);
    if(fsetpos(arquivo->cabecalho, &original) != 0)
    {
        printf("fsetpos() falhou!: %i\n", errno);
    }
    return original;
}

arquivo_t ler_arquivo(char* nome)
{ 
    arquivo_t arquivo;           // Estrutura para armazenar os dados do arquivo
    int n_linhas = 0;            // Contador de linhas
    char buffer[TAMANHO_BUFFER]; // Buffer temporário para leitura de uma linha

    // Inicialização do ponteiro de dados como NULL
    arquivo.dados = NULL;

    // Abra o arquivo no modo leitura
    arquivo.cabecalho = fopen(nome, "r");

    // Verifique se o arquivo foi aberto corretamente
    if (arquivo.cabecalho == NULL) {
        printf("Arquivo não pode ser aberto!\n");
        exit(EXIT_FAILURE);
    }

    // Leia o arquivo linha por linha
    while (fgets(buffer, TAMANHO_BUFFER, arquivo.cabecalho) != NULL) {
        n_linhas++;

        // Realoca o array de ponteiros para armazenar mais uma linha
        arquivo.dados = (char**)realloc(arquivo.dados, n_linhas * sizeof(char*));

        if (arquivo.dados == NULL) {
            printf("Erro ao alocar memória!\n");
            fclose(arquivo.cabecalho);
            exit(EXIT_FAILURE);
        }

        // Aloca espaço para armazenar a linha atual
        arquivo.dados[n_linhas - 1] = strdup(buffer);

        if (arquivo.dados[n_linhas - 1] == NULL) {
            printf("Erro ao alocar memória para linha!\n");
            fclose(arquivo.cabecalho);
            exit(EXIT_FAILURE);
        }
    }

    // Feche o arquivo
    fclose(arquivo.cabecalho);

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
