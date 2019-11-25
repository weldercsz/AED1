//14.  Imprimir apenas o primeiro elemento da lista.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>

typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

void imprimePrimeiro(struct no *list)
{
	printf("\n\nImprime o primeiro\n");
	printf("Primeiro = %d\n", list->info);
}

//No Main deve conter um método que gere uma lista
//abaixo contém um exemplo para teste
int main()
{
	lista *inicio = NULL, *aux;

	int nno=0,i;
	printf("Digite o tamanho da lista: ");
	scanf("%d", &nno);

	//esse for criará uma lista sequencial decrescente, 
	//base no método de inserção no início
	for (i =0; i<nno; i++)
		if((aux = (struct no*) malloc(sizeof(struct no))) != NULL)
		{	
			//atribui o valor de NULL ao prox do no
			aux -> prox = NULL;

			//se inicio for diferente de NULL o no atual deve recebé-lo
			if (inicio != NULL)
				aux ->prox = inicio;

			//o inicio precisa ser atualizado
			inicio = aux;
		}
	imprimePrimeiro(inicio);
	
	return 0;
}
