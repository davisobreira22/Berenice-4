#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#include "berenice.h"

void ler()
{

    system("cls");

    ProdutosC produto;
    No* atual;
    FILE *arq = fopen("produtos.txt", "r+");

    if(lista.primeiro != NULL) //
    {
        while(lista.primeiro != NULL) {

            atual = lista.primeiro->proximo;

            free (lista.primeiro);

            lista.primeiro = atual;
        }
    }
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else
    {
        printf("--------------------------------------------------------\n");
        printf("|                       LER                            |\n");
        printf("--------------------------------------------------------\n");
        printf("%-10s %-24s %-8s %-6s %-6s\n", "Código", "Produto", "Valor", "Est.", "Vend.");


        while (fscanf(arq, "%d", &produto.codigo)== 1){


            fgetc(arq);

            fgets(produto.nome, 25, arq);
            produto.nome[strcspn(produto.nome, "\n")] = '\0';

            fscanf(arq, "%f", &produto.preco);
            fgetc(arq);
            fscanf(arq, "%d", &produto.estoque);
            fgetc(arq);
            fscanf(arq, "%d", &produto.vendida);
            fgetc(arq);

        No * novo = (No *)malloc(sizeof(No)); //malloc do novo, do tipo no. aqui inicia o novo.
        novo->produtos =  produto;
        novo->proximo = lista.primeiro;
        lista.primeiro = novo; //define como nulo

            printf("%-10d %-24s %-8.2f %-6d %-6d\n",
                   novo->produtos.codigo,
                   novo->produtos.nome,
                    novo->produtos.preco,
                    novo->produtos.estoque,
                    novo->produtos.vendida);
        }
    }
    fclose(arq);
}
