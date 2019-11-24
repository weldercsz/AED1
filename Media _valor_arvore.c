#include <stdio.h> 
#include <stdLib.h>

typedef struct arvore 
{
    int info;
    struct arvore *esq,*dir;
};

void insere(struct arvore **inicio, int info);int qtdNos(struct arvore *inicio);int somaNos(struct arvore *inicio);

//Divide a soma dos Nos pela quantidade de Nos.
int mediaNos()
{
    return somaNos(oi)/ qtdNos(oi);
}

int main()
{
    struct arvore *oi = NULL;
    insere(&oi, 3);
    insere(&oi, 5);
    insere(&oi, 1);
    insere(&oi, 3);

    int test = mediaNos();

    system("pause");
}
