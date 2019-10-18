#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main( ){

char **nomes,nova[20];
int n,i,j;
 
printf("Informe quando nomes deseja inserir: ");
scanf("%d", &n);
 
nomes = (char**)malloc(sizeof(char*)*n);
 
printf("Informe os nomes: ");

for(i = 0; i < n; i++){
 
nomes[i] = (char*)malloc(sizeof(char)*20);
 
}
 
for(i = 1; i < n; i++){
scanf("%s", nova);
j = i - 1;

    while(j >= 0 && strcmp(nova,nomes[j])<0){

        strcpy(nomes[j+1],nomes[j]);

            j--;
 
}
        strcpy(nomes[j+1],nova);

}
 
 
for(i = 0; i < n; i++){
 
    printf("%s\n", nomes[i]);
 
}
free(nomes);
 
    return 0;
}