#include <stdio.h>
#include "analise/chave/chave.c"
#include "so/arquivos/arquivo.c"

int main(int argc, char**argv) 
{
    int tamanho;
    arquivo_t arquivo = ler_arquivo("teste.sivar");
    for(int i = 0; i < arquivo.n_linhas; i++)
    {
        chave_t* ch =   obter_chaves(arquivo.dados[i], &tamanho);
        for(int j = 0; j < tamanho; j++)
        {
            printf("%s %d\n", ch[j].valor, ch[j].tipo);
        }
        liberar_chaves(ch, tamanho);
    }
    liberar_arquivo(&arquivo);
    return 0;
}