#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	int valor;
	struct no* prox;
}no;

typedef no pilha;

/*
Nesta Pilha, está adicionando no final. Ou seja, lá no último quando aponta pra NULL.
Como é uma Pilha, temos que retirar daí também.
*/
void empilhar(pilha** p, int numero){

	pilha* novo = (pilha*)malloc(sizeof(pilha));

	if(*p == NULL){ // A Pilha está vazia, é o primeiro elemento que vamos inserir nela.
		*p = novo;
		(*p)->valor = numero;
		(*p)->prox = NULL;

	}

	else{ // A Pilha não está vazia. Inserimos no final.
	
	pilha* percorre;

	percorre = *p;

		
		while(percorre->prox != NULL ){

			percorre = percorre -> prox;
		}

	percorre -> prox = novo;
	novo -> valor = numero;
	novo -> prox = NULL;
	

	}
	

}

/*
Vamos ter que retirar do final, já que o último que foi adicionando se encontra no final.
*/

void desempilhar(pilha** p){
	pilha* percorre;
	percorre = *p;
	
	if(*p == NULL) printf("A Pilha está vazia\n");
	

	else{//A Pilha tem mais de um elemento, então podemos desempilhar!
		
		if(percorre->prox == NULL) *p = NULL;
		else{

			while(percorre->prox->prox != NULL){
				percorre = percorre->prox;
			}

			percorre ->prox = NULL;

		}

	}
}

void imprimir(pilha* p){

	pilha* percorre;

	percorre = p;

	if(p == NULL) printf("A Pilha se encontra vazia!\n"); // Pilha Vazia
	else{
		while(percorre != NULL){
			
			printf("Elemento: %d \n", percorre->valor);

			percorre = percorre -> prox;

		}
	}
}

void esvaziarpilha(pilha **p){
	
	pilha* aux;
	aux = *p;

	while(aux != NULL){
		*p = aux->prox;
		free(aux);
		aux = *p;

	}


}


int main(){

	
	pilha* p = NULL;

	int elemento, opcao;

	while(opcao != 0){

	system("clear");

		printf("################### PILHA ####################\n");
		printf("\t\tEstudos sobre Funções da Pilha\n");
		printf("\tMatéria: Algoritimo e Estrutura de Dados I\n");

		printf("\n");
		printf("\t->>>> 0-Sair <<<<<--\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Esvaziar Pilha\n");
		printf("4 - Imprimir\n");
		

		scanf("%d", &opcao);


		switch(opcao){

			case 1: // Empilhando

				printf("Qual elemento você deseja empilhar?\n");
					scanf("%d", &elemento);

				empilhar(&p, elemento);

				printf("Vamos imprimir agora após ter empilhado\n");

				imprimir(p);

				getchar();
				getchar();


			break;



			case 2: // Desempilhando
				
				printf("Vamos desempilhar\n");

				desempilhar(&p);

				printf("\n");

				printf("Imprimindo agora após desempilhar\n");
				imprimir(p);


				getchar();
				getchar();
			break;


			case 3: // Esvaziando a Pilha
				

				printf("Esvaziando a pilha\n");

				esvaziarpilha(&p);

				printf("Imprimindo após ter esvaziado\n");

				imprimir(p);

				getchar();
				getchar();
			break;

			case 4: // Imprimindo
				
				printf("Imprimindo...\n");
				imprimir(p);

				getchar();
				getchar();

			break;


		}







}

return 0;
}
	
	
