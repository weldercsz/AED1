#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cidade{
char *nome;
int x;
int y;
};

typedef struct cidade cidade;
int main ( ){

int n,i,j;
float **matriz;
cidade *vetor_cidades;

printf("Informe quantas cidades deseja armazenar: ");
scanf("%d",&n);
vetor_cidades=(cidade*)malloc(sizeof(cidade)*n);

printf("Informe os nomes e as posicoes X e Y das cidades: ");

for(i=0;i<n;i++){

    vetor_cidades[i].nome=(char*)malloc(sizeof(char)*15);

    scanf("%s",vetor_cidades[i].nome);
    scanf("%d",&vetor_cidades[i].x);
    scanf("%d",&vetor_cidades[i].y);
}

matriz = (float**)malloc(sizeof(float*)*n);
for(i=0;i<n;i++){

   matriz[i] = (float*)malloc(sizeof(float)*n); 
}

for(i=0;i<n;i++){

    for(j=0;j<n;j++){

        if(i!=j){

        matriz[i][j]=sqrt(((vetor_cidades[j].x-vetor_cidades[i].x)*(vetor_cidades[j].x-vetor_cidades[i].x))+((vetor_cidades[j].y-vetor_cidades[i].y)*(vetor_cidades[j].y-vetor_cidades[i].y)));
        printf("Distancia entre as cidades %d e %d : %.2f\n",i,j,matriz[i][j]);

        }
    }
}
printf("Informe o numero de duas cidades: ");
scanf("%d %d",&i,&j);

printf("A distancia e : %.2f",matriz[i][j]);
for(i=0;i<n;i++){

free(matriz[i]);
free(vetor_cidades[i].nome);

}

free(matriz);
free(vetor_cidades);

    return 0;
}