#include<stdio.h>
#include<stdlib.h>

struct lista{
	   int info;
	   struct lista*prox;
};
typedef lista Lista;


Lista* cria(void){

	   return NULL;

}

Lista* insere(Lista*l,int i){

	   Lista* novo=(Lista*)malloc(sizeof(Lista));
	   novo->info=i;
	   novo->prox=l;
	   return novo;
}



Lista* insere_pos(Lista *l, int valor, int pos){

	  int cont=1; 
	  Lista*p=l;
	  Lista* novo=(Lista*)malloc(sizeof(Lista));
	  while (cont!=pos){	 
          	p=p->prox;
			cont++;
	  }

	  novo->info=valor;
	  novo->prox=p->prox;
	  return novo;

}

void imprime(Lista* l){

	   while (l!=NULL){
			 printf("%d",l);

			 l->prox;

	   }
}

			 
int main(){

	int i,pos,valor;
	Lista*l;
	l=cria();

	for (i=0;i<7;i++)

		l=insere(l,i);

	imprime(l);
	
	printf("\nDigite a posição que você quer inserir e o seu valor\n");
	scanf("%d %d",&pos,&valor);

	l=insere_pos(l,valor,pos);
	imprime(l);
}



