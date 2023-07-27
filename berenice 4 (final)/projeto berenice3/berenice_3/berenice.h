 #ifndef BERENICE_H_INCLUDED
#define BERENICE_H_INCLUDED

typedef struct
{
    int  codigo;
    char nome[25];
    float preco;
    int estoque;
    int vendida;
    int quantidade;
    int acrescentar;

} ProdutosC;

// Struct do nó da lista
typedef struct No {
    ProdutosC produtos;
    struct No* proximo;
}No;
typedef struct Lista{

struct No* primeiro;
struct No* ultimo;
}Lista;

extern ProdutosC produtos;

extern int tmn_produtos;

extern Lista lista;


void exibir(); //exibir os produtos
void cadastrar(); //cadastro
void excluir(); // funcao excluir
void salvar(); //funcao salvar
void ler(); //funcao ler
void realizar_venda(); //realizar a venda
void forma_pagamento(float sub_total); //forma de pagamento
void atualizar();//
No* busca(int cod);

#endif // BERENICE_H_INCLUDED
