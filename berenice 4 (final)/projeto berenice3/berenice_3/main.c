#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"


Lista lista;

int main(int argc, char *argv[])
{

    lista.primeiro = NULL;// inicializacao DA LISTA
    setlocale(LC_ALL, "Portuguese"); //  permite a inser��o de acentos e caract�res especiais em portugu�s

    int opMenu; // op��o do menu principal
    char menu;// opcao que reinicia o loop do menu ou sai do programa

    do
    {

        // Limpa a tela
        system("cls");
        //printf("%i", sizeof(produtos));
        printf("--------------------------------------------------------\n");
        printf("                   PADARIA DA BERENICE                  | \n");
        printf("--------------------------------------------------------\n");
        printf("-> Produtos                 )))                        1|\n");
        printf("                           (((                         *| \n");
        printf("-> Vendas                +-----+                       2|\n");
        printf("                         |     |]                      *|\n");
        printf("-> Sair                  `-----'                       3|\n");
        printf("--------------------------------------------------------\n");
        printf("Selecione uma op��o                                   ");
        scanf("%i", &opMenu);
        getchar();

        if(opMenu > 0 && opMenu < 4)  // verifica se o c�digo digitado est� dentro do intervalo [1,3]
        {

            switch(opMenu)
            {
            case 1:
                subMenuProduto();
                menu = '\n'; // reinicia o loop quando o programa retorna da fun��o
                break;

            case 2:
                 subMenuVendas();
                menu = '\n'; // reinicia o loop quando o programa retorna da fun��o
                break;

            case 3:
                menu = 1;
                break;
            }
        }

        else
        {
            //caso a opcao selecionada pelo usu�rio n�o estiver dentro do intervalo [1,4]
            printf("\nOP��O INV�LIDA!\t\t\t\n");
            printf("PRESSIONE ENTER PARA VOLTAR AO MENU                   |"); //reinicia o loop ou sai do programa
            scanf("%c", &menu);
        }
    }
    while(menu == '\n');  // enquanto o usu�rio pressionar enter o menu inicial ser� exibido para que ele tente um novo c�digo



    return 0;
}
