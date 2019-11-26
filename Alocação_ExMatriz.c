#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
int ***vetor,
*nodos;
int grafos,
num = 0;

scanf("%i", &grafos);

if((**vetor = (int*) malloc(sizeof(int*) * grafos)) /* erro aqui */ 
&& (nodos = (int*) malloc(sizeof(int)  * grafos)))
{		
	while(num <= grafos)
	{
		scanf("%i", nodos[num]);
		
		if(*vetor[num] = (int*) malloc(sizeof(int*) * nodos[num]))
		{
			int i;
			
			for(i = 0;i<nodos[num];i++)
			{
				if(vetor[num][i] = (int*) malloc(sizeof(int) * nodos[num]));
				else
				{
					printf("Erro na alocacao de memoria.\n");
					exit(-1);
				}
			}
		}
		
		else{
			printf("Erro na alocacao de memoria.\n");
			exit(-1);
		}
}
}
else
	printf("Erro na alocacao de memoria.\n");
	exit(-1);
}
