#include <stdio.h>
#include <stdlib.h>

//Questão -6

int main (){
    int vet[6], ex, i, j, temp;

    for(i=0;i<6;i++){

    printf("Insira um número para o vetor: ");
    scanf("%d", &vet[i]);

    }

    printf("Insira um número extra: ");
    scanf("%d", &ex);

    for(i=0; i<6; i++){

        if(ex > vet[i]){

            realloc(vet, sizeof(int)*1);
            temp=vet[i];
            vet[i]=ex;
            
        }

    }


    return 0;
}