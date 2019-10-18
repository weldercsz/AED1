 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    char **nomes;
    int n, i, j, min;
    char temp[20];
    
    printf("Quantas palavras deseja ler: ");
    scanf("%d", &n);
    
    printf("Informe as palavras: ");
    nomes = (char **)malloc(sizeof(char *) * n);
    
    for (i = 0; i < n; i++){

        nomes[i] = (char *)malloc(sizeof(char) * 20);
        scanf("%s", nomes[i]);
    }
    for (i = 0; i < n - 1; i++){

        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (strlen(nomes[j]) < strlen(nomes[min])){

 
                min = j;
            }
        }

        strcpy(temp, nomes[i]);
        strcpy(nomes[i], nomes[min]);
        strcpy(nomes[min], temp);
    }
 
    printf("Apos ordenar por tamanho\n");
    
    for (i = 0; i < n; i++){

 
        printf("%s\n", nomes[i]);
    }
 free(nomes);
 
    return 0;
}
 
 