#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[20];
    int telefone;
    int cpf;
    float peso;
    char endereco[37];
};

struct No
{
    struct aluno info;
    struct No *esquerda;
    struct No *direita;
};

typedef struct No No;
typedef struct aluno Aluno;
void criarArvore(No **pRaiz);
void listar(No *pRaiz);
void insere(No **pRaiz, Aluno aux);
void buscar(No *pRaiz, Aluno aux);
void remover(No **pRaiz, Aluno aux);
void antecessor(No *p, No **pp);


int main()
{
    int op;
    Aluno aux;
    No *raiz;
    criarArvore(&raiz);

    for (;;){
        printf("1)Inserir\n");
        printf("2)Listar\n");
        printf("3)Buscar\n");
        printf("4)Excluir\n");
        printf("5)Sair\n");
        scanf("%d", &op);
       
        switch (op)
        {
        case 1:

            printf("Informe o nome: ");
            scanf("%s", aux.nome);

            printf("Informe o telefone: ");
            scanf("%d", &aux.telefone);
           
            printf("informe o Cpf");
            scanf("%d",&aux.cpf);
           
            printf ("informe o peso");
            scanf("%f",&aux.peso);
          
            printf("informe o endereço");
            scanf("%s", aux.endereco);

              insere(&raiz,aux);
            break;

        case 2:
            
            listar(raiz,aux);
            break;

        case 3:
            
            printf("Informe o nome que deseja buscar: ");
            scanf("%s", aux.nome);
            buscar(raiz, aux);
            break;
        
        case 4:
        
            printf("Informe o nome que deseja excluir: ");
            scanf("%s", aux.nome);
            remover(&raiz, aux);
            break;
        
        case 5:
            exit(0);
            break;
        
        default:
            printf("ERROO!! invalida\n");
            break;
        }
    }
    return 0;
}


void criarArvore(No **pRaiz)

{
    *pRaiz = NULL;
}

void insere(No **pRaiz, Aluno aux)
{
    if (*pRaiz == NULL)
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->info = aux;
    }
    else
    {
        if (strcmp(aux.nome, ((*pRaiz)->info.nome)) < 0)
        {
            insere(&((*pRaiz)->esquerda), aux);
        }
        else
        {
            insere(&((*pRaiz)->direita), aux);
        }
    }
}

void listar(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        listar(pRaiz->esquerda);
        printf("Nome: %s\n", pRaiz->info.nome);
        printf("Telefone: %d\n", pRaiz->info.telefone);
        listar(pRaiz->direita);
    }
}

void buscar(No *pRaiz, Aluno aux)
{

    if (pRaiz != NULL)
    {

        if (strcmp(aux.nome, pRaiz->info.nome) < 0)
        {
            buscar(pRaiz->esquerda, aux);
        }
        else if (strcmp(aux.nome, pRaiz->info.nome) > 0)
        {
            buscar(pRaiz->direita, aux);
        }
        else
        {
            printf("Nome: %s\n", pRaiz->info.nome);
            printf("Telefone: %d\n", pRaiz->info.telefone);
        }
    }
    else
    {
        printf("Sem dados!\n");
    }
}

void remover(No **pRaiz, Aluno aux)

{
    No *auxiliar;

    if (*pRaiz == NULL)
        return;

    if(strcmp(aux.nome,  (*pRaiz)->info.nome)<0)
    {
        remover(&(*pRaiz)->esquerda,aux);
        return;
    }

    if (strcmp(aux.nome,  (*pRaiz)->info.nome)>0)
    {    remover(&(*pRaiz)->direita,aux);
         return;
    }

    if((*pRaiz)->direita == NULL)
    {
        auxiliar = *pRaiz;
        *pRaiz = (*pRaiz)->esquerda;
        free(auxiliar);
        return;
    }

    if ((*pRaiz)->esquerda != NULL)
    {
        antecessor(*pRaiz, &(*pRaiz)->esquerda);
        return;
    }

    auxiliar = *pRaiz;
    *pRaiz = (*pRaiz)->direita;
    free(auxiliar);
}

void antecessor(No *p, No **pp)
{
    No *aux;

    if ((*pp)->direita != NULL)
    {    
        antecessor(p, &(*pp)->direita);
        return;
    }

    p->info = (*pp)->info;
    aux = *pp;
    *pp = (*pp)->esquerda;
    free(aux);
}