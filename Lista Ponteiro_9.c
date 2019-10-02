#include <stdio.h>
#include <stdlib.h>


void min_max(int *vet, int *Min, int *Max);

int main(){
	
	
	
    int *v, min, max, n = 10, i;
    
    v = (int *)malloc(sizeof(int) * n);
    
    printf("Vetor: ");
    srand(time(NULL));
    for (i = 0; i < n; i++){
    	
        v[i] = rand() % 120;
        
        printf("%d ", v[i]);
        
    }
    printf("\n");
    
    min_max(v, &min, &max);
    
    printf("Menor valor do vetor: %d", min);
    printf("Maior valor do vetor: %d", max);
    
    return 0;
}
void min_max(int *vet, int *Min, int *Max)
{
    int i;
    
    *Min = vet[0];
    *Max = vet[0];
    
    for (i = 0; i < 10; i++){
    	
    	   	  if (vet[i] > *Max){
    	   	  	
            *Max = vet[i];
        }
           if (vet[i] < *Min){
           	
            *Min = vet[i];
        }
    }
}
