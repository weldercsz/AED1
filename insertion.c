#include <stdio.h>
#include <stdlib.h>
int *insertion(int v[], int n);
int *selection(int v[], int n);
int *shellSort(int v[], int n);

int main()
{
  int *v, n, i;
  printf("Informe o numero de elementos: ");
  scanf("%d", &n);
  v = (int *)malloc(sizeof(int) * n);
  printf("Elementos: ");
  for (i = 0; i < n; i++)
  {
    *(v + i) = rand() % 100;
    printf("%d ", *(v + i));
  }
  printf("\n\n");
  v = shellSort(v, n);
  for (i = 0; i < n; i++)
  {
    printf("%d ", *(v + i));
  }
  free(v);
  return 0;
}
int *insertion(int v[], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > temp)
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
  }
  return v;
}
int *selection(int v[], int n)
{
  int i, j, temp, min;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (v[j] < v[min])
      {
        min = j;
      }
    }
    temp = v[i];
    v[i] = v[min];
    v[min] = temp;
  }

  return v;
}
int *shellSort(int vet[], int size)
{
  int i, j, value;
  int gap = 1;
  while (gap < size)
  {
    gap = 3 * gap + 1;
  }
  while (gap > 1)
  {
    gap /= 3;
    for (i = gap; i < size; i++)
    {
      value = vet[i];
      j = i - gap;
      while (j >= 0 && value < vet[j])
      {
        vet[j + gap] = vet[j];
        j -= gap;
      }
      vet[j + gap] = value;
    }
  }
  return vet;
}
