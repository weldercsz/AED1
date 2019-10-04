#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int *insertion(int *v, int n);
int *criar_vetor(int *v, int n);
void imprimir_vetor(int *v, int n);

int main(){

int N,*vet;
printf("Informe o numero de elementos: ");
scanf("%d", &N);

v = criaR_vetor(vet,N);
insertion(vet,N);
imprimir_vetor(vet,N);

free(vet);

    return 0;
}

int *criaR_vetor(int *v, int n){
int i;

v = (int*)malloc(sizeof(int)*n);

printf("Informe os elementos: ");

for (i = 0; i < n; i++){
  scanf("%d", &v[i]);
}
    return v;
}
void imprimir_vetor(int *v, int n){
int i;

printf("Vetor: ");

for (i = 0; i < n; i++){
  printf("%d ", v[i]);
}
}

int *insertion(int v[], int n){
int i,j,temp;

for(i = 1; i < n; i++){
temp = v[i];
j = i - 1;

while(j>=0 && v[j] > temp){
v[j+1]= v[j];
j--;
}

v[j+1] = temp;
}

}
