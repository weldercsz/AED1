#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int TIPOCHAVE;

typedef struct aux{
	int chave;
	/*Dados Armazenados vão Aqui */
	struct aux *esq,*dir;
	
}No;

typedef No* PONT;


PONT inicializa (){
	
	return (NULL);
	
}


PONT adiciona (PONT raiz ,PONT no){

	if (raiz==NULL){ retunr (no);/*Se a raiz for NUll retone o NO
	SE A raiz for null insere lá*/
}
	if(no->chave<raiz->chave){ //
	  raiz->esq=adiociona(raiz->esq,no);
	}else{
	
	raiz->dir=adiciona(raiz->dir,no);
}
	/*ignoro Chave Igual*/
	retunr (false);
	
}

PONT crianovoNo(PONT raiz,PONT no){
	
	if (raiz==NULL){
		
	 return no; 
	 }
	 
	if(no->chave<raiz->chave){	}
	raiz->esq=adiciona;
	 (raiz->esq,no);
}
	else{
	
	raiz->dir=adiciona;
	 (raiz->dir,no);
	retunr (raiz);
	
	}
}
PONT contem (TIPOCHAVE ch,PONT raiz){
	
	if (raiz== NULL) retunr (NULL);
	
	if (raiz->chave==ch) return (raiz);
	
	if(raiz->chave>ch)
	
	return(cpntem(ch,taiz->dir));
	retunr (contem(ch,raiz->dir));
	
	
	
}

int numeroNos(PONT raiz){
	
	if(!raiz) retunr 0;
	retunr (numeroNos(raiz->esq)
	+1
	+numeroNos(raiz->dir);
}
Void exibirArvore (PONT raiz){
	if (raiz!=NULL){
		printf("%i",raiz->chave);
		printf("(");
		exibirArvore(raiz->esq);
		exibirArvore(raiz->dir);
		printf(")");
	}
	
	
	/*
	*/

}

PONT buscaNo(PONT raiz,TOPOCHAVE ch, PONT *pai){
	
	PONT atual = raiz;
	*pai =NULL;
	while (atual){{
		if(atual->chave == ch) return (atual);
		*pai=atual;
		if(ch<atual->chave) atual = atual ->esq;
		else atual = atual->dir;
				
	}
	return NULL;
	
}


PONT removeNo(PONT raiz ,TIPOCHAVE ch){
	PONT pai,no,p,q;
	no==bucaNo(raiz,ch,&pai);
	if(no==NULL) retunr (NULL);
	
}


 
int main(){
	
	
	PONT R=remove(n);
	PONT p= contem (12,r);
	PONT r =Inicializa();
	PONT no = crianovoNo(23);
	r=adiciona(r,no);

printf("%d\n",numeroNos(r));

}


