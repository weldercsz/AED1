


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	char nome[30];
	int posicao;
	struct lista *proximo;
};

void push (struct lista **lista1,int *atual){

	struct lista *novonodo = (struct lista*) malloc(sizeof(struct lista)); ;

	scanf(" %[^\n]",novonodo->nome);
	novonodo->posicao = *atual;
	novonodo->proximo = *lista1;
	*lista1=novonodo;
	*atual= *atual + 1;
	printf("%d\n",*atual);
	
}

void pop (struct lista *lista1,int *atual){
	struct lista *ord1,*ord2;
	
	char compara[30];
	scanf(" %[^\n]",compara);
	
	ord1=lista1;
	ord2=lista1->proximo;
	
	while(ord2!=NULL && strcmp(ord2->nome,compara)!=0){
			ord1=ord2;
			ord2=ord2->proximo;}
			
			
			 if(ord2!=NULL && ord2->posicao != *atual-1){
			ord1->proximo = ord2->proximo;
			free (ord2);}
			}
			
			

			



void printa(struct lista *listando)  
{  
    while (listando != NULL)  
    {  
        printf("Nome: %s \tPosicao: %d\n",listando->nome,listando->posicao);  
        listando = listando->proximo;  
    }  
}  


int main(int argc, char **argv)
{
	struct lista *lista1;
	lista1=NULL;
	int *atual;
    *atual=0;
	
	push(&lista1,atual);
	push(&lista1,atual);
	push(&lista1,atual);
	


	printa(lista1);
	pop(lista1,atual);
	printa(lista1);
	pop(lista1,atual);
	printa(lista1);
	
	return 0;
}


