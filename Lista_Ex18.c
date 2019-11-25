//18->Retornar a soma dos valores dos n�s. O valor deve ser impresso pela fun��o main.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>

typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

int somaElementos(struct no *list)
{
	int x=0;
	//Percorre a lista
	while(list!=NULL)
	{
		//soma os elementos contidos em list-> com x
		x+=list->info;
		list=list->prox;
	}
	return x;
}

//No Main deve conter um m�todo que gere uma lista
//abaixo cont�m um exemplo para teste
int main()
{
	lista *inicio = NULL, *aux;

	int nno=0,i;
	printf("Digite o tamanho da lista: ");
	scanf("%d", &nno);

	//esse for criar� uma lista sequencial decrescente, 
	//base no m�todo de inser��o no in�cio
	for ( i =0; i<nno; i++)
		if((aux = (struct no*) malloc(sizeof(struct no))) != NULL)
		{
			//atribui o valor de 'i' ao 'info' do no
			aux -> info = i;
			
			//atribui o valor de NULL ao prox do no
			aux -> prox = NULL;

			//se inicio for diferente de NULL o no atual deve receb�-lo
			if (inicio != NULL)
				aux ->prox = inicio;

			//o inicio precisa ser atualizado
			inicio = aux;
		}
	
	printf("Quantidade de nos: %d", somaElementos(inicio));
	removeUltimo(inicio);
	
	return 0;
}
