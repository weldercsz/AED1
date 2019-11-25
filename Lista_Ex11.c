//11.  Excluir o primeiro elemento da lista.

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

void removeInicio(struct no **list)
{
	struct no *remove = *list;
	(*list) = (*list)->prox;
	free(remove);
}

//No Main deve conter um método que gere uma lista
//abaixo contém um exemplo para teste
int main()
{
	lista *list1 = NULL;

	insereInicio(&list1, 3);
	insereInicio(&list1, 7);
	insereInicio(&list1, 9);

	removeInicio(&list1);
	
return 0;
}
