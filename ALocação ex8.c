#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2);
int main()
{
    int *V1, *V2, *V3, N1, N2, i;

    printf("Informe o tamanho do v1: ");
    scanf("%d", &N1);

    printf("Informe o tamanho do v2: ");
    scanf("%d", &N2);

    v1 = (int *)malloc(sizeof(int) * N1);
    v2 = (int *)malloc(sizeof(int) * N2);

    printf("Digite os elementos do v1: ");
    for (i = 0; i < N1; i++)
    {
        scanf("%d", &V1[i]);
    }
    printf("Digite os elementos do v2: ");
    for (i = 0; i < N2; i++)
    {
        scanf("%d", &V2[i]);
    }
    v3 = uniao(V1, N1, V2, N2);
    printf("V3: ");
    for (i = 0; i < (N1 + N2); i++)
    {
        printf("%d ", V3[i]);
    }
    free(V1);
    free(V2);
    free(V3);

    return 0;
}
int *uniao(int *v1, int n1, int *v2, int n2)
{
    int *v3, i, j = 0;

    v3 = (int *)malloc(sizeof(int) * (n1 + n2));
    for (i = 0; i < (n1 + n2); i++)
    {
        if (i < n1)
        {
            v3[i] = v1[i];
        }
        else
        {
            v3[i] = v2[j];
            j++;
        }
    }

    return v3;
}
