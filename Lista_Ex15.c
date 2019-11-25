//15 ->Imprimir apenas o �ltimo elemento da lista.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>
typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

void imprimeUltimo(struct no *list)
{
	printf("\n\nImprime o ultimo\n");

	//Percorre a lista
	while(list != NULL)
	{
		//Depois do ultimo elemento temos NULL, ent�o basta verificar
		//se o pr�ximo � igual NULL
		if(list->prox == NULL)
			printf("Ultimo = %d\n", list->info);
        	list = list->prox;
	}
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
			//atribui o valor de NULL ao prox do no
			aux -> prox = NULL;

			//se inicio for diferente de NULL o no atual deve receb�-lo
			if (inicio != NULL)
				aux ->prox = inicio;

			//o inicio precisa ser atualizado
			inicio = aux;
		}
	imprimeUltimo(inicio);
	
return 0;

}
