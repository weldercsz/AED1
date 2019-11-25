//13.  Excluir o k-ésimo elemento da lista.

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
void insereInicio(struct no **inicio, int info)
{
	lista *aux;
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

void remove(int posicao, struct no **lista)
{
	struct no *aux, *remove = NULL;
	aux = *list;
	int count = 1;
	if(posicao==1)
	{
		(*list) = (*list)->prox;
		free(aux);
	}
	else
	{
		while(aux != NULL && count < posicao)
		{
			if ((posicao-1) == count)
			{
				remove = aux->prox;
				aux->prox = (aux->prox)->prox;
				free(remove);
				break;
			}
			else
				count++;
			aux = aux->prox;
		}
		if (aux==NULL)
			printf("ERRO - Posicao nao existente\n");
	}
}

//No Main deve conter um método que gere uma lista
//abaixo contém um exemplo para teste
int main()
{
	lista *list1 = NULL;

	insereInicio(&list1, 3);
	insereInicio(&list1, 7);
	insereInicio(&list1, 9);

	remove(2, &list1);

return 0;
}
