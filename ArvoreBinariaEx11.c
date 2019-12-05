#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
 int info;
 struct nodo *esq;
 struct nodo *dir;
} NO;

typedef NO *ARV;
int EMPTY (ARV a){

 return (a == NULL);}
// Para inserir um novo elemento 'b' na arvore 'a'

ARV insere (ARV a, int b){
 ARV nova;
   if (EMPTY(a))
   
 {
        nova = (ARV) malloc (sizeof(NO));
   	   nova->esq = NULL;
 	   nova->dir = NULL;
 	   nova->info = b;
 	   printf("Insercao do numero %d na AB realizada!", b);
 
 return nova;
 }
 else{
 	  if ( b > a->info )
	    a->dir = insere(a->dir, b);
 	    
		else
 	        a->esq = insere(a->esq, b); /* Repeticoes sao inseridas na esquerda! */

 return a;
 
 }
}
int main(){

 ARV a=NULL;
 int opcao=0;
 int num;

 while (opcao != 2){
 	
 	   system("cls");
 	   printf("\n\n----------------MENU PRINCIPAL----------------");
 	   printf("\n\n 1 - Inserir Novo Numero na AB");
 	   printf("\n 2 - Encerrar");
 	   printf("\n\n Opcao Escolhida: ");
 	   scanf("%d",&opcao);

 switch(opcao){
 
  case 1: system("cls");
  
  printf("\nNovo Numero: ");
  scanf("%d",&num);
  
  a = insere(a,num);
  system("pause>>null");
 
  break;
 }
 }
  return 0;
 }
