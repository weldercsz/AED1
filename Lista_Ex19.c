//19->Fa�a uma fun��o que fa�a a c�pia de uma lista.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>

typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

void insereInicio(struct no **inicio, int info)
{
	lista *aux;
	if((aux = (struct no*) malloc(sizeof(struct no))) != NULL)
	{
		//atribui o valor de 'info' ao 'aux -> info' do no
		aux -> info = info;
			
		//atribui o valor de NULL ao prox do no
		aux -> prox = NULL;

		//se inicio for diferente de NULL o no atual deve receb�-lo
		if ((*inicio) != NULL)
			aux ->prox = (*inicio);

		//o inicio precisa ser atualizado
		(*inicio) = aux;
	}
}

void insereFim(struct no **inicio, int info)
{
	lista *aux, *list = (*inicio);
	//se a lista estiver vazia inserir o elemento com o 'prox = NULL)
	if((*inicio) == NULL)
		insereInicio(inicio, info);
	else
		while(list!=NULL)
		{
			if(list->prox == NULL)
				if((aux = (struct no*) malloc(sizeof(struct no))) != NULL)
				{
					list->prox = aux;
					aux->info = info;
					aux->prox = NULL;
					break;
				}
			list = list->prox;
		}
}

//para copiar uma lista � o mesmo principio de ir inserindo no fim da lista
void copy(struct no *lista1)
{
	lista *inicio = NULL;
	while(lista1!=NULL)
	{
		//OBS.: M�todo insereFim
		insereFim(&inicio, lista1->info);
		lista1 = lista1->prox;
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
	for (i =0; i<nno; i++)
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

	copy(inicio);
return 0;
}
