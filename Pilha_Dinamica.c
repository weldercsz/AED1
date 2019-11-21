#include <stdio.h>
#include <stdlib.h>


struct Aluno
{
    int ra;
    char nome[50];
};

struct Item
{
    Aluno aluno;
    Item *proximo;
};


void Inicializar(Item **topo)
{
   *topo = NULL;
}

bool EstaVazia(Item **topo)
{
   if(*topo == NULL)  
      return true;  
   else  
      return false;  
}

void Empilhar(Item **topo, Aluno elemento)
{
    Item *novo;
    novo = (Item *)malloc(sizeof(Item));  
    novo->aluno = elemento;
    novo->proximo = *topo; // -> próximo recebe o elemento que estava no topo.
    *topo = novo;
}

Aluno Desempilhar(Item **topo)
{
   Aluno result;
   Item *auxiliar;
  
   if(EstaVazia(topo))
   {
        printf("\n stack underflow! \n");
        exit(1);
   }
   else // -> Elemento retirado do topo
   {
       result = (*topo)->aluno;
        auxiliar = *topo;
        *topo = (*topo)->proximo;
        free(auxiliar);
        return result;
   }  
}

void MostrarPilha(Item *topo)
{
    int i = 0;
    Item *item;
  
    printf("\n\n Listando...\n\n");
    printf("---------------------------------\n");

    if (EstaVazia(&topo))
    {
        printf ("A Pilha esta vazia!\n");
    }
    else
    {      
        item = topo;

        while(item != NULL)
        {
            i++;
            printf("[%i] -> %i - %s\n", i, item->aluno.ra, item->aluno.nome);
            item = item->proximo;
        }
    }

    printf("---------------------------------\n");
}


void Menu()
{
    printf( "Digite a sua escolha: \n"
        "    1 empilhar elemento \n"
        "    2 desempilhar \n"
        "    3 para finalizar \n"
        "? ");
}


void main()
{   
    Item *topo = NULL;
    int opcao;
    Aluno aluno;

    Menu();
    scanf("%i", &opcao);

    while (opcao != 3)
    {

        switch (opcao)
        {
            case 1:
                printf( "Digite um RA: ");
                scanf("\n%i", &aluno.ra);

                printf( "Digite um Nome: ");
                scanf("\n%s", &aluno.nome);

                Empilhar(&topo, aluno);
                MostrarPilha(topo);

                break;
            case 2:
                Desempilhar(&topo);
                MostrarPilha(topo);

                break;

            default:
                printf( "Escolha invalida.\n\n");
                Menu();
                break;
        }

        scanf("%i", &opcao);   
    }

    system("pause");
}