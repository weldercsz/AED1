#include <stdio.h> 
#include <stdLib.h>
#include <math.h>


typedef struct arvore 
{
    int info;
    struct arvore *esq,*dir;
};

void insere(struct arvore **inicio, int info)
{
    struct arvore *aux;
    /* Como a funçao é recursiva, em alguem momento receberá um início igual a NULL,
       ou caso a árvore esteja vazia. */
    if (!*inicio)
    {
        if((aux = (struct arvore*) malloc(sizeof(struct arvore))) != NULL)
        {
            aux -> info = info;
	    aux -> dir = NULL;
	    aux -> esq = NULL;
	    *inicio = aux;
        }
        else
            printf("Nao foi possivel alocar memoria");
    }
    else
    {
        /* Se o info atual for MAIOR que o valor a ser inserido, então esse 
           valor será inserido do lado ESQUERDO. */
        if ((*inicio)->info > info)
	    insere(&((*inicio)->esq), info);
	else
	    /* Se o info atual for MENOR que o valor a ser inserido, então esse 
               valor será inserido do lado DIREITO. */
	    if((*inicio)->info < info)
	        insere(&((*inicio)->dir), info);
		/* Caso ele seja igual, isso significa que já pertece a árvore.*/
	    else
		printf("%d ja pertence a arvore \n", info);
    }    
}

int main()
{
    struct arvore *oi = NULL;
    insere(&oi, 3);
    insere(&oi, 5);
    insere(&oi, 1);
    insere(&oi, 3);

   return 0;
}
