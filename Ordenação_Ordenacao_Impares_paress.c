#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble(int *v, int n);
int main()
{
    int *v, n, i, j, temp, pares = 0;
    int *par, *imp;
 
    printf("Informe o numero de elementos: ");
    scanf("%d", &n);
    srand(time(NULL));
    v = (int *)malloc(sizeof(int) * n);
 
    for (i = 0; i < n; i++)
    {
        *(v + i) = rand() % 100;
    }
 
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 != 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (v[j] % 2 == 0)
                {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                    j = n;
                    pares++;
                }
            }
        }
    }
    par = (int *)malloc(sizeof(int) * pares);
    imp = (int *)malloc(sizeof(int) * (n - pares));
 
    for (i = 0; i < pares; i++)
    {
        par[i] = v[i];
    }
    for (i = 0; i < n - pares; i++)
    {
        imp[i] = v[pares + i];
    }
    bubble(par, pares);
    bubble(imp, n - pares);
    for (i = 0; i < pares; i++)
    {
        v[i] = par[i];
    }
    j = 0;
    for (i = pares; i < n; i++)
    {
        v[i] = imp[j];
        j++;
    }
 
    for (i = 0; i < n; i++)
    {
 
        printf("%d ", v[i]);
    }


    free(v);
 
    return 0;
}
void bubble(int *v, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}