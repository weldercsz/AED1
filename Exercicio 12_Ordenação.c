#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct produto
{
    int codigo;
    char nome[10];
    int quantidade;
    float valor;
};
typedef struct produto produto;

int main()
{
    int n, i, imaior, imenor;
    float maior = -1.0, menor = 10000000.0;
    produto *lista_produtos;
    printf("Informe o numero de produtos: ");
    scanf("%d", &n);
    lista_produtos = (produto *)malloc(sizeof(produto) * n);
    for (i = 0; i < n; i++)
    {
        printf("Produto %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &lista_produtos[i].codigo);
        printf("Nome: ");
        scanf("%s", lista_produtos[i].nome);
        printf("Quantidade: ");
        scanf("%d", &lista_produtos[i].quantidade);
        printf("Valor: ");
        scanf("%f", &lista_produtos[i].valor);
    }
    for (i = 0; i < n; i++)
    {
        if (lista_produtos[i].valor > maior)
        {
            maior = lista_produtos[i].valor;
            imaior = i;
        }
        if (lista_produtos[i].valor < menor)
        {
            menor = lista_produtos[i].valor;
            imenor = i;
        }
    }
    printf("Produto de maior preco e %s\n", lista_produtos[imaior].nome);
    printf("Produto de menor preco e %s\n", lista_produtos[imenor].nome);
    free(lista_produtos);
    return 0;
}
