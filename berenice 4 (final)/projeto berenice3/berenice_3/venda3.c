#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"
// Vendidos vendidos[100] = { };
void realizar_venda()
{


    No* it;

    int q_item;
    int cod;



    char item;

    do
    {
        float subtotal = 0;


        if(lista.primeiro == NULL)
        {
            printf("Não há produtos cadastrados");
            return;
        }


        else
        {
            do
            {
                do
                {
                    exibir();
                    printf("\nDIGITE O CODIGO DO PRODUTO\t     |");
                    scanf("%d", &cod);
                    getchar();

                    it = busca(cod);

                    if (it == NULL)
                    {
                        printf("Código não encontrado! Tente novamente.");
                    }


                }
                while(it == NULL);

                do
                {

                    printf("DIGITE A QUANTIDADE DO ITEM\t     |");
                    scanf("%d", &q_item);
                    getchar();



                    if (q_item <= 0 || q_item > it->produtos.estoque)
                    {
                        printf("Quantidade invalida ou indisponivel! Tente novamente\n");

                    }

                }
                while (q_item <= 0 || q_item > it->produtos.estoque);

                it->produtos.estoque -= q_item;
                it->produtos.vendida += q_item;
                subtotal += q_item*it->produtos.preco;



                printf("\nSub-Total da Venda: R$ %.2f\n", subtotal);

                printf("Deseja adiconar mais produtos (S)\n");
                printf("Finalizar a venda   \t(N)\n");
                scanf("%c", &item);
                getchar();
            }
            while (item == 's' || item =='S');

            exibir();

            forma_pagamento(subtotal);
        }
        printf("Deseja realizar outra venda S/N? \n");
        scanf(" %c", &item);
    }
    while( item == 's' || item == 'S');

    return;
}


void forma_pagamento(float sub_total)
{

    int parcelas, opcao_pagamento;
    float valor_total, valor_pago, valor_desconto, valor_acrescimo, troco, valor_recebido,valor_parcela; //variaveis que possuem numeros decimais
    // printf("%.2f", sub_total);

    printf("\n Opcoes de pagamento:\n");
    printf("\n 1. A vista com desconto \n");
    printf("\n 2. A prazo \n");

    do
    {
        printf("\n Digite a opcao de pagamento desejada: \n ");
        scanf("%d", &opcao_pagamento);
        getchar();
        if (opcao_pagamento <=0 || opcao_pagamento >= 3)
        {
            printf("\n Opcao de pagamento invalida \n"); // caso a opcao selecionada for menor que 0 ou maior que 3, aparecera no display a seguinte mensagem dita anteriormente
        }
    }
    while(opcao_pagamento <=0 || opcao_pagamento >= 3);

    valor_total = sub_total;

    switch(opcao_pagamento)   // o calculo realizado na opcao avista, calcular o desconto
    {
    case 1: //opcao avista
        if (valor_total > 0 && valor_total <= 50.0 )
        {
            valor_desconto = valor_total * 0.05;// 100/5= 0.05 total de 5% de desconto;
        }
        else if (valor_total > 50 && valor_total< 100.0)
        {
            valor_desconto = valor_total * 0.1; // se for maior que 50 reias ou menor que 100 reais, o desconto sera de 10%
        }
        else
        {
            valor_desconto = valor_total * 0.18; // se for acima de 100 reais, sera 18 % de desconto
        }
        valor_pago = valor_total - valor_desconto; // formula do valor pago

        printf("\n Valor a ser pago: R$ %.2f\n", valor_pago); //mostra no display o valor a ser pago

        do
        {
            printf("\n Digite o valor recebido: \n ");
            scanf("%f", &valor_recebido);
            getchar();

            if(valor_recebido <= 0 || valor_recebido <= valor_pago)
            {
                printf("Valor insuficiente! Digite novamente. \n");
            }

        }
        while(valor_recebido <= 0 || valor_recebido <= valor_pago);
        printf("\n Valor Recebido: %.2f\n", valor_recebido);

        if ( valor_recebido >= valor_pago)  // IF PARA DIZER SE O VALOR DE TROCO ESTA CERTO
        {

            troco = (valor_recebido - valor_pago); //formula do troco

            printf("\n Troco: R$ %.2f \n", troco);

        }

        else   // ELSE PARA CASO O VALOR DADO SEJA MENOR PARA NAO HAVER PREJUIZO
        {

            printf("\n valor invalido \n");
        }


        break;
    case 2: //calculo da opcao a prazo, calculo dos acrescimos

        do
        {
            printf("\n Digite o numero de parcelas (ate 10): \n ");
            scanf("%d", &parcelas);
            getchar();

            if(parcelas <= 0)
            {
                printf("Entrada invalida!\n");
            }

        }
        while(parcelas <= 0);

        if (parcelas <= 3)
        {
            valor_acrescimo = valor_total * 0.05;//se for at  3 parcelas   para ter um acr scimo de 5% ou 5/100= 0.05
        }
        else
        {
            valor_acrescimo = valor_total * 0.08;// se for maior que 3 parcelas   para ter um acr scimo de 8% ou 8/100= 0.08
        }
        if (parcelas <=0 || parcelas >= 11)
        {
            printf("\n Opcao selecionada invalida \n"); // caso o numero de parcelas seja menor ou igual a 0 ou maior e igual 11, opcao sera invalida
            break;
        }

        valor_pago = valor_total + valor_acrescimo; //formula do acrescimo

        printf("Valor a ser pago: R$ %.2f\n", valor_pago);
        valor_parcela= valor_pago / parcelas;
        printf("\n Valor da parcela= %.2f \n",valor_parcela);
        break;
    default:
        exit(0);

    }
}
