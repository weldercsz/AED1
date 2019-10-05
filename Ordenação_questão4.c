#include <stdlib.h>
#include <stdio.h>
#include <math.h>

 /*Questão numero -4  Escreva um algoritmo que receba valores em um vetor 
e imprimaORDENADOse o vetorestiver em ordem crescente */

int main(){
	
int vet[10];//vetor de 10 posições
int t, ordem, auxiliar;

//Lendo o Vetor

for (t = 1; t <= 10; t++){
	
printf("Digite um numero:");
scanf("%d",&vet[t]);

}
/* Ordenação do Vetor */
ordem=10;

while (ordem>1){
	
for (t=1;t<=10; t++){
	if (vet[t]>vet[t+1]){
		
		auxiliar=vet[t];
		vet[t]=vet[t+1];
		vet[t+1]=auxiliar;
}
}
ordem=ordem-1;
}
//Impressão do Vetor Ordenado

printf("Vetor em ordem crescente: \n");

{
printf(" %d,",vet[t]);
}

return 0;
}
