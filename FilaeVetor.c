#include<stdio.h>
#include<stdlib.h>

#define N 4 // numero maximo de elementos
struct fila{
	
	int n; // numero de elementos na fila
	int ini; // posicao do proximo elemento a ser retirado da fila
	int tipoElemFila ;
};

Fila * fila_cria(void){
	
Fila * f = (Fila *)malloc(sizeof(Fila));

	if (f == NULL) {
	    printf("sem memoria\n"); exit(1);
 }
 
  f->n = 0; // inicializa fila como vazia
  f->ini = 0; // escolhe uma posição inicial

return f;
}
int fila_vazia(Fila * f){

return f->n == 0;

}
void fila_insere(Fila * f, tipoElemFila v){
	
 	int fim;
 	
	if (f->n == N) {
	   printf("sem memoria\n"); exit(1);
 }
	fim = (f->ini + f->n) % N; // insere elemento na proxima posicao livre
	f->vet[fim] = v;
	f->n++;
}
float fila_retira(Fila* f){
 	 tipoElemFila v;

	 if (fila_vazia(f)) {
   	 printf("Fila vazia.\n"); exit(1);
   }
   
// retira elemento do inicio
   v = f->vet[f->ini];
   f->ini = (f->ini + 1) % N;
   f->n--;
   
   return v;
}
void fila_imprime(Fila * f){
	
 	int i;
	int ini, fim, n;
	
	if (fila_vazia(f)){
	   printf("Fila vazia\n");
	   
return;
}

 	  ini = f->ini;
	  n = f->n;
	  fim = (ini + n - 1) % N;
	  
	  printf("Inicio[%d]->",ini);

for (i=ini; i!=fim; i=(i+1)%N)
        printf("%7.2f ", f->vet[i]);
        printf("%7.2f ", f->vet[i]);
        printf("<-[%d]Fim\n",fim);
        
}

