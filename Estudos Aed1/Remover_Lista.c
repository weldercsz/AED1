#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct TLista
{
    struct TLista *prox;
    char nome[30];
    char end[40];
    int idade;
}TLista;

typedef TLista *PLista;

PLista inicializa()
{
    return NULL;
}
PLista remover(PLista p)
{
    PLista ant = NULL;
    PLista aux = p;
    char name[60], name2[60];
    getchar();
    strcpy(name2, aux->nome);
    strlwr(name2);
    printf("\nEntre com o nome que deseja remover: ");
    gets(name);
    strlwr(name);
    while(aux!=NULL && strcmp(name, name2) !=0)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL || p == NULL)
    {
        return p;
    }
    else if(ant == NULL)
    {
        p = aux->prox;
    }
    else if(aux->prox == NULL)
    {
        ant->prox = NULL;
    }
    else
    {
        ant->prox = aux->prox;
    }
    printf("\n      Nome removido com sucesso!\n\n");
    free(aux);
    return p;
}


