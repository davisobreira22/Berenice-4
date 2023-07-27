#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

void atualizar()
{
    No* atual = lista.primeiro;
    No *it;
    int cod, op, novo_estoque;
    float novo_preco;
    char atualizar;

    if(atual == NULL)
    {
        printf("Lista de produtos vazia!");
        return;
    }

    exibir();

    do
    {
        do
        {
            printf("Digite o c�digo do produto: ");
            scanf("%d", &cod);
            getchar();

            // Verificar se o c�digo existe
            for (it = lista.primeiro; it != NULL; it = it->proximo)
            {
                if (cod == it->produtos.codigo)
                {
                    break;
                }
            }

            if (it == NULL)
            {
                printf("C�digo n�o encontrado ou lista vazia.\n\n");
            }
            else
            {
                atual = it;

                printf("produto selecionado: \n %-10d %-24s %-8.2f %-6d %-6d\n", //mostra o produto selecionado
                       atual->produtos.codigo,
                       atual->produtos.nome,
                       atual->produtos.preco,
                       atual->produtos.estoque,
                       atual->produtos.vendida);

                do
                {
                    printf("\nDeseja atualizar o PRE�O (1) ou o ESTOQUE (2): ");
                    scanf("%i", &op);
                    getchar();

                    if (op == 1)
                    {
                        printf("Digite o novo pre�o: ");
                        scanf("%f", &novo_preco);
                        getchar();

                        if (novo_preco > 0)
                        {
                            printf("%-10d %-24s %-8.2f %-6d %-6d\n",
                                   atual->produtos.codigo,
                                   atual->produtos.nome,
                                   atual->produtos.preco,
                                   atual->produtos.estoque,
                                   atual->produtos.vendida);

                            atual->produtos.preco = novo_preco;

                            printf("%-10d %-24s %-8.2f %-6d %-6d\n",
                                   atual->produtos.codigo,
                                   atual->produtos.nome,
                                   atual->produtos.preco,
                                   atual->produtos.estoque,
                                   atual->produtos.vendida);

                            printf("\nPre�o Unit�rio de '%s' atualizado com sucesso!", atual->produtos.nome);
                        }
                        else
                        {
                            printf("Valor inv�lido! Tente novamente");
                            op = 0;
                        }
                    }
                    else if (op == 2)
                    {
                        printf("Digite o novo estoque: ");
                        scanf("%i", &novo_estoque);
                        getchar();

                        if (novo_estoque >= 0)
                        {
                            printf("%-10d %-24s %-8.2f %-6d %-6d\n",
                                   atual->produtos.codigo,
                                   atual->produtos.nome,
                                   atual->produtos.preco,
                                   atual->produtos.estoque,
                                   atual->produtos.vendida);

                            atual->produtos.estoque = novo_estoque;

                            printf("%-10d%-24s %-8.2f %-6d %-6d\n",
                                   atual->produtos.codigo,
                                   atual->produtos.nome,
                                   atual->produtos.preco,
                                   atual->produtos.estoque,
                                   atual->produtos.vendida);

                            printf("\nEstoque de '%s' atualizado com sucesso!", atual->produtos.nome);
                        }
                        else
                        {
                            printf("Valor inv�lido! Tente novamente");
                            op = 0;
                        }

                    }
                    else
                    {
                        printf("Valor inv�lido! Tente novamente\n");
                    }
                }
                while (op < 1 || op > 2);
            }
        }
        while(it == NULL);

        printf("\nDeseja atualizar mais produtos? S/N");
        scanf("%c", &atualizar);

    }
    while (atualizar == 's' || atualizar == 'S');

}
