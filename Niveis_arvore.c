#include <stdio.h> 
#include <stdLib.h>

typedef struct arvore 
{
    int info;
    struct arvore *esq,*dir;
};

void insere(struct arvore **inicio, int info);

//Soma o no atual com o maior da esquerda ou direita
int altura(struct arvore *inicio)
{
    if(inicio)
    {
        if(altura(inicio->esq) > altura(inicio->dir))
            return 1 + altura(inicio->esq);
	else
            return 1 + altura(inicio->dir);
    }
    else
       return 0;
}

int main()
{
    struct arvore *oi = NULL;
    insere(&oi, 3);
    insere(&oi, 5);
    insere(&oi, 1);
    insere(&oi, 3);

    int test = altura(oi);

 return 0; 
}
