#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"




No* busca(int cod)
{

    No* it;

    for (it = lista.primeiro; it != NULL; it = it->proximo)
    {
        if (cod == it->produtos.codigo)
        {
            break;
        }
    }

    return it;
}
