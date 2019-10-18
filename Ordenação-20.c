
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
void quick(char *s, int esquerda, int direita);
int main()
{
    char *palavra;
 
    palavra = (char *)malloc(sizeof(char) * 20);
    printf("Informe a palavra: ");
    scanf("%s", palavra);
    quick(palavra, 0, strlen(palavra)-1);
    printf("\nPalavra: %s", palavra);
 
    return 0;
}
void quick(char *s, int esquerda, int direita)
{
    int i, j;
    char temp, pivo;
    i = esquerda;
    j = direita;
 
   pivo = s[(esquerda + direita) / 2];
    do
    {
        while (s[i] > pivo)
            i++;
 
        while (s[j] < pivo)
            j--;
 
        if (i <= j)
        {
 
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
 
    } while (i <= j);
 
    if (esquerda < j)
    {
        quick(s, esquerda, j);
    }
    if (i < direita)
    {
        quick(s, i, direita);
    }
}
 