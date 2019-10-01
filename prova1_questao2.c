#include <stdio.h>
#include <stdlib.h>

void imparPar(void *pN, unsigned int t);

int main( )
{
	void *buffer;
	unsigned int t = 6;
	int i;
	
	buffer = malloc(sizeof(int) * t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", (int *)(buffer + (sizeof(int) * i)));
	}
	
	imparPar(buffer, t);

	for (i = 0; i < t; i++)
	{
		printf("%d ", *(int *)(buffer + (sizeof(int) * i)));
	}
	
	free(buffer);
	
	return 0;
}
void imparPar(void *pN, unsigned int t)
{
	int *i, *j, *aux;

	i = (int *)malloc(sizeof(int));
	j = (int *)malloc(sizeof(int));
	aux = (int *)malloc(sizeof(int));
	
	for ((*i) = 0; (*i) < t; (*i)++)
	{
		if (*(int *)(pN + (sizeof(int) * (*i))) % 2 == 0)
		{
			for ((*j) = (*i) + 1; (*j) < t; (*j)++)
			{
				if (*(int *)(pN + (sizeof(int) * (*j))) % 2 != 0)
				{
					*aux = *(int *)(pN + (sizeof(int) * (*i)));
					*(int *)(pN + (sizeof(int) * (*i))) = *(int *)(pN + (sizeof(int) * (*j)));
					*(int *)(pN + (sizeof(int) * (*j))) = *aux;
					(*j) = t;
				}
			}
		}
	}
	
	free(i);
	free(j);
	free(aux);
}
