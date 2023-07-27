#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

void excluir()
{

    int codigo;
    No* atual = lista.primeiro;
    No* anterior = NULL;


    if (atual == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }
    else
    {
        exibir();

        printf("Digite o código do produto a ser excluído: ");
        scanf("%d", &codigo);




        while (atual != NULL)   //se atual nao apontar para nulo, ocorrera um loop
        {
            if (atual->produtos.codigo == codigo)
            {
                if (anterior == NULL)   //Se o ponteiro anterior for NULL, significa que o nó a ser removido é o primeiro da fila
                {
                    lista.primeiro = atual->proximo;
                }
                else
                {
                    anterior->proximo = atual->proximo;
//se for falso, atualizamos o ponteiro anterior -> proximo para apontar para o nó seguinte ao nó atual ( atual->proximo). assim "pula" o nó atual na fila, removendo-o.
                }
                free(atual); //libera memomoria
                printf("Pessoa removida com sucesso!\n");
                return;
            }

//Caso a pessoa não seja encontrada no nó atual, atualiza os ponteiros anterior e atual para avançar para o próximo nó da fila
            anterior = atual;
            atual = atual->proximo;
        }
        printf("Pessoa com o codigo informado nao encontrada \n");
    }
    return;
}
