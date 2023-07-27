#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"

void exibir()
{
    No *it;

    No* atual = lista.primeiro;



    if (atual == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }
    else
    {
        system("cls");
        printf("--------------------------------------------------------\n");
        printf("                       BERENICE                         \n");
        printf("--------------------------------------------------------\n");
        printf("%-8s %-25s %-8s %-6s %-6s\n", "Código", "Produto", "Valor", "Est.", "Vend.");

        for (it = lista.primeiro; it != NULL; it = it->proximo)
        {
            printf("%-8d %-25s %-8.2f %-6d %-6d\n",
                   it->produtos.codigo,
                   it->produtos.nome,
                   it->produtos.preco,
                   it->produtos.estoque,
                   it->produtos.vendida);
        }
    }

    return;
}
