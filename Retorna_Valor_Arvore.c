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
    /* Como a fun�ao � recursiva, em alguem momento receber� um in�cio igual a NULL,
       ou caso a �rvore esteja vazia. */
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
        /* Se o info atual for MAIOR que o valor a ser inserido, ent�o esse 
           valor ser� inserido do lado ESQUERDO. */
        if ((*inicio)->info > info)
	    insere(&((*inicio)->esq), info);
	else
	    /* Se o info atual for MENOR que o valor a ser inserido, ent�o esse 
               valor ser� inserido do lado DIREITO. */
	    if((*inicio)->info < info)
	        insere(&((*inicio)->dir), info);
		/* Caso ele seja igual, isso significa que j� pertece a �rvore.*/
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
