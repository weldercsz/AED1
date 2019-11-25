 //9-> Inserir um elemento n no final da lista.

#include <stdio.h>
#include <stdLib.h>
#include <math.h>

typedef struct no
{ 
	int info; 
	struct no *prox; 
} lista;

//como desejamos alterar o valor de dentro do Main e lá temos um ponteiro, 
//é necessário declarar um ponteiro para ponteiro
void insereFim(struct no **inicio, int info)
{
	lista *aux, *list = (*inicio);
	//se a lista estiver vazia inserir o elemento com o 'prox = NULL
	//insere como se fosse no inicio
	if((*inicio) == NULL)
	{
		if((aux = (struct no*) malloc(sizeof(struct no))) != NULL)
		{
			//atribui o valor de 'info' ao 'aux -> info' do no
			aux -> info = info;
			
			//atribui o valor de NULL ao prox do no
			aux -> prox = NULL;

			//se inicio for diferente de NULL o no atual deve recebé-lo
			if ((*inicio) != NULL)
				aux ->prox = (*inicio);

			//o inicio precisa ser atualizado
			(*inicio) = aux;
		}
	}
	else
		while(list!=NULL)
		{
			if(list->prox == NULL)
				if((aux =(struct no*)malloc(sizeof(struct no))) != NULL)
				{
					list->prox = aux;
					aux->info = info;
					aux->prox = NULL;
					break;
				}
			list = list->prox;
		}
}

//No Main deve conter um método que gere uma lista
//abaixo contém um exemplo para teste
int main()

{
	lista *inicio = NULL;

	insereFim(&inicio, 3);
	insereFim(&inicio, 5);
	insereFim(&inicio, 7);

return 0;
}
