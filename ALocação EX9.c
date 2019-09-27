#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ler_aposta(int *aposta, int n);
void sorteia_valores(int *sorteio, int n);
int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);

int main(void)
{
    int nas, nis, quantidade_acertos = 0, i;
    int *aposta, *sorteio, *acertos;
    ns = 20;
    printf("QUANTIDADE , numeros deseja apostar: ");
    scanf("%d", &nas);
    while (nas < 0 || nas > 20)
    {
        printf("Nao e possivel apostar mais que 20 numeros, por favor informe quantos numeros deseja apostar: ");
        scanf("%d", &nas);
    }

    Aposta = (int *)malloc(nas * sizeof(int));
    sorteio = (int *)malloc(nis * sizeof(int));
    lerrr_aposta(aposta, nas);
    sorteia_valores(sorteio, nis);
    acertos = compara_aposta(aposta, sorteio, &quantidade_acertos, nas, nis);
    printf("Voce acertou %d numeros: ", quantidade_acertos);
    for (i = 0; i < quantidade_acertos; i++)
    {
        printf("%d ", acertos[i]);
    }
    return 0;
}
void lerrr_aposta(int *aposta, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        do
        {
            scanf("%d", &aposta[i]);
        } while (aposta[i] <= 0 || aposta[i] >= 100);
    }
}
void sorteia_valores(int *sorteio, int n)
{
    int i;
    printf("Foram sorteados os numeros : ");
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        sorteio[i] = rand() % 100;
        printf("%d ", sorteio[i]);
    }
    printf("\n");
}
int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
    int *acertos;
    int i, j, k = 0;
    acertos = (int *)malloc(sizeof(int));
    for (i = 0; i < na; i++)
    {
        for (j = 0; j < ns; j++)
        {
            if (aposta[i] == sorteio[j])
            {
                acertos[k] = aposta[i];
                k++;
                (*qtdacertos)++;
                acertos = (int *)realloc(acertos, (k + 1) * sizeof(int));
            }
        }
    }
    return acertos;
}
