#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

void cadastrar()
{

    int quant, cod;
    char cad;

    do
    {
        printf("Quantidade de produtos a cadastrar: ");
        scanf("%i", &quant);
        getchar();

        if (quant <= 0)
        {
            printf("Entrada inválida! Tente novamente.\n");
        }
    }
    while (quant <= 0);



    for (int i = 0; i < quant; i++)
    {

        No * novo = (No *)malloc(sizeof(No)); //malloc do novo, do tipo no. aqui inicia o novo.
        No *it = NULL;

        novo->proximo = NULL; //define como nulo

        printf("Produto %d:\n", i + 1);

        do{
            printf("Código: ");
            scanf("%d", &cod);
            getchar();

            it = busca(cod);

            if(it != NULL || cod <= 0){
                printf("Codigo invalido ou ja existente!\n");
            }
            else{
                novo->produtos.codigo = cod;
            }
        }while(it != NULL || cod <= 0);


        printf("Nome: ");
        fgets(novo->produtos.nome, 25, stdin);
        novo->produtos.nome[strcspn(novo->produtos.nome, "\n")] = '\0';

        do{
            printf("Valor: ");
            scanf("%f", &(novo->produtos.preco));
            getchar();

            if(novo->produtos.preco <= 0){
                printf("Entrada invalida!\n");
            }

        }while(novo->produtos.preco <= 0);

        do{
            printf("Estoque: ");
            scanf("%i", &(novo->produtos.estoque));
            getchar();

            if(novo->produtos.estoque <0){
                printf("Entrada invalida!\n");
            }

        }while(novo->produtos.estoque < 0);

        No* atual = lista.primeiro;

        novo->produtos.vendida = 0;


        if (atual == NULL)
        {
            lista.primeiro = novo; //defina o primeiro nó da lista como o novo nó que foi fornecido.
        }
        else// se for diferente
        {
            if (novo->produtos.codigo < atual->produtos.codigo)//verificacao se e menor
            {
                novo->proximo = lista.primeiro;
                lista.primeiro = novo;
            }
            else
            {
                while (atual->proximo != NULL && novo->produtos.codigo > atual->proximo->produtos.codigo)//verificao se e maior
                {
                    atual = atual->proximo;
                }

                novo->proximo = atual->proximo;
                atual->proximo = novo;


            }
        }

    }
    printf("Produto cadastrado com sucesso! Aperte enter para voltar ao menu.");
    scanf("%c", &cad);

    return;
}

