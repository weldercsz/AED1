#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int *valores_entre(int *v, int n, int min, int max, int *qtd);
int main()
{
    int *vetor_minimo_maximo, *v;
    int n = 10, q = 0, mi, ma, i;

    v = (int *)malloc(sizeof(int) * 10);
    for (i = 0; i < n; i++){

        v[i] = 10 + i;
        printf("%d ", v[i]);
    }

    printf("Informe os valor minimo e maximo: \n");
    scanf("%d %d", &mi, &ma);
    vetor_minimo_maximo = valores_entre(v, n, mi, ma, &q);
    if (vetor_minimo_maximo != NULL){

        for (i = 0; i < q; i++)

        {
            printf("%d ", vetor_minimo_maximo[i]);
        }
    }
    else
    {
        printf("Nenhum numero do vetor entre os valores minimo e maximo!\n");
    }


    free(v);
    free(vetor_minimo_maxim);

    return 0;
}
int *valores_entre(int *v, int n, int mi, int ma, int *qtd)
{
    int i, *vetor, j = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] > mi && v[i] < ma)
        {
            (*qtd)++;
        }
    }
    if ((*qtd) > 0)
    {
        vetor = (int *)malloc(sizeof(int) * (*qtd));
        for (i = 0; i < n; i++)
        {
            if (v[i] > mi && v[i] < ma)
            {
                vetor[j] = v[i];
                j++;
            }
        }

        return vetor;
    }
    else{

        return NULL;
    }
}
