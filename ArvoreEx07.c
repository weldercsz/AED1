#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct registro_st{         // sequência de objetos do mesmo tipo
    char login[50];
    char nome[50];
    float valor;
    struct registro *prox;
} registro;

typedef struct nodo_st{
    registro *dado;
    struct nodo_st *dir;
    struct nodo_st *esq;
} nodo;

typedef struct Lista_st{
    nodo *cabeca;
    nodo *cauda;
    int tamanho;
} lista;

void insere_Arvore(nodo* raiz, struct registro_st registro){
    if(raiz == NULL)
        {
        return 0;
        }
    nodo* novo = (nodo*)malloc(sizeof(nodo));
    if(novo == NULL){
        return 0;
    }
    novo->dado->valor;
    novo->dir = NULL;
    novo->esq= NULL;
        if(*raiz = NULL){
        	
            *raiz = novo;
        }
    else{
    nodo* atual = *raiz;
    nodo* ant = NULL;
    }

        while(atual != NULL)
            {
            ant = atual;
            if (valor1 == atual->dado->valor){
                            free(novo);
                            return 0;
            }

        if(valor1 > atual->dado->valor)
                                    {
                    atual = atual->dir
    }
        else{
                    atual = atual->esq;
        }
        if(valor1 > ant->dado->valor)
                                    {
        ant->dir = novo;
        }
        else{
        ant->esq = novo;
        }
        if(valor > ant->dado->valor){
            ant->dir = novo;
        }
        else{
        ant->esq = novo;
        }
        }
            }
        return 1;
}


int main(){
    nodo *arvore = NULL;

    registro *reg = malloc(sizeof(registro));
    strcpy(reg->nome, "O nome aqui");
    strcpy(reg->login, "O inicio aqui");
    reg->valor = 10;


    insere_Arvore(&arvore, reg); 
