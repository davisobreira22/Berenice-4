#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"

void salvar()
{
    ProdutosC produtos;
    No* atual = lista.primeiro;
    No* it;

    FILE *arquivo;

    // Salvar os dados no arquivo
    arquivo = fopen("produtos.txt", "w");


    if(atual == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }
    else
    {

        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        //fprintf(arquivo, "%d\n", atual);

        for(it = lista.primeiro; it != NULL; it = it->proximo)

        {

            fprintf(arquivo, "%d\n%s\n%.2f\n%d\n%d\n",
                    it->produtos.codigo,
                    it->produtos.nome,
                    it->produtos.preco,
                    it->produtos.estoque,
                    it->produtos.vendida);
        }
        fclose(arquivo);
    }
}
