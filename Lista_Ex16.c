//16.  Imprimir apenas o n-�simo elemento da lista.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>

typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

void imprimeNesio(int posicao, struct no *list)
{
	printf("\n\nImprime N-esimo\n");
	int count = 0;
	
	//percorre a lista
	while(list != NULL)
	{
		//se o proximo for NULL significa que a posicao n�o existe
		if (list->prox == NULL)
		{
			printf("ERRO - Posicao nao existente\n");
			break;
		}
		if (posicao == count)
		{
			printf("N-esimo = %d\n", list->info);
			break;
		}
		else
			count++;
		list = list->prox;
	}
}

//No Main deve conter um m�todo que gere uma lista
//abaixo cont�m um exemplo para teste
int main()
{
	lista *inicio = NULL, *aux;

	int nno=0, posicao,i;
	printf("Digite o tamanho da lista: ");
	scanf("%d", &nno);
	printf("Digite a posicao: ");
	scanf("%d", &posicao);

	//esse for criar� uma lista sequencial decrescente, 
	//base no m�todo de inser��o no in�cio
	for (i =0; i<nno; i++)
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

	imprimeNesio(posicao,inicio);
	
return 0;
}
