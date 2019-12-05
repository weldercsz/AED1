#include <stdio.h>
#include <stdlib.h> 
#include <math.h>


typedef struct node
{
 int chave;
 struct node *filhoDir;
 struct node *filhoEsq;
 /**
  * balanco := altura da sub-�rvore direita - altura da sub-�rvore esquerda
  * Para um n� estar regulado, balan�o deve estar entre -1 e 1.
  **/
 int balanco;
} noh;


/**
* Tratamento do caso em que a �rvore da esquerda
* ficou duas unidades maior que a da direita
**/
void caso1(noh** raiz, int *alterou)
{
 noh* u;
 noh* v;

 u = malloc(sizeof(noh));
 u = (*raiz)->filhoEsq;

 if(u->balanco == -1)
 {
   printf("caso 1.1\n");
   (*raiz)->filhoEsq = u->filhoDir;
   u->filhoDir = *raiz;
   (*raiz)->balanco = 0;
   (*raiz) = u;
 }
 else
 {
   printf("caso 1.2\n");
   v = u->filhoDir;
   u->filhoDir = v->filhoEsq;
   v->filhoEsq = u;
   (*raiz)->filhoEsq = v->filhoDir;
   v->filhoDir = (*raiz);
   if(v->balanco == -1)
     (*raiz)->balanco = 1;
   else
     (*raiz)->balanco = 0;
   if(v->balanco == 1)
     u->balanco = -1;
   else
     u->balanco = 0;
   (*raiz) = v;
 }
 (*raiz)->balanco = 0;
 (*alterou) = 0;
}


/**
* Tratamento do caso em que a �rvore da direita
* ficou duas unidades maior que a da esquerda
**/
void caso2(noh** raiz, int *alterou)
{
 noh* u;
 noh* v;

 u = malloc(sizeof(noh));
 u = (*raiz)->filhoDir;

 if(u->balanco == 1)
 {
   printf("caso 2.1\n");
   (*raiz)->filhoDir = u->filhoEsq;
   u->filhoEsq = *raiz;
   (*raiz)->balanco = 0;
   (*raiz) = u;
 }
 else
 {
   printf("caso 2.2\n");
   v = u->filhoEsq;
   u->filhoEsq = v->filhoDir;
   v->filhoDir = u;
   (*raiz)->filhoDir = v->filhoEsq;
   v->filhoEsq = (*raiz);
   if(v->balanco == 1)
     (*raiz)->balanco = -1;
   else
     (*raiz)->balanco = 0;
   if(v->balanco == -1)
     u->balanco = 1;
   else
     u->balanco = 0;
   (*raiz) = v;
 }
 (*raiz)->balanco = 0;
 *alterou = 0;
}

/**
* Fun��o de inser��o
**/
void insereNumaAVL(int x, noh **raiz , int *alterou)
{
 /* se a �rvore est� vazia.. */
 if(*raiz == NULL )
 {
   /* inicializa a �rvore */
   *raiz = (noh*) malloc(sizeof(noh));
   (*raiz)->filhoEsq = NULL;
   (*raiz)->filhoDir = NULL;
   (*raiz)->chave = x;
   (*raiz)->balanco = 0;
   *alterou = 1;
 }
 else /* ent�o a �rvore j� tem elementos */
 {
   /* se devemos inserir na esquerda... */
   if(x < (*raiz)->chave)
   {
     /* insere na esquerda */
     insereNumaAVL (x, &((*raiz)->filhoEsq), alterou);
     /* se houve altera��o de altura */
     if(*alterou)
     {
       if((*raiz)->balanco == 1)
       {
         (*raiz)->balanco = 0;
         alterou = 0;
       }
       else
       {
         if((*raiz)->balanco == 0)
           (*raiz)->balanco = -1;
         else if((*raiz)->balanco == -1) /* se desregulou o n�... */
           caso1(raiz, alterou); /* fazemos a regulagem */
         else
           fprintf(stderr, "erro inesperado\n");
       }
     }
   }
   /* agora an�logo pro lado direito */
   else if(x > (*raiz)->chave)
   {
     insereNumaAVL(x, &((*raiz)->filhoDir), alterou);
     if(*alterou)
     {
       if ((*raiz)->balanco == -1)
       {
         alterou = 0;
         (*raiz)->balanco = 0;
       }
       else
       {
         if((*raiz)->balanco == 0)
           (*raiz)->balanco = 1;
         else if ((*raiz)->balanco == 1)
           caso2(raiz, alterou);
         else
           fprintf(stderr, "erro inesperado\n");
       }
     }
   }
   /* Caso contr�rio, x == (*raiz)->chave, ou seja, o
    elemento x j� est� na �rvore. Ent�o, n�o se faz nada. */
 }
}


int main(void)
{
 int h;
 noh* raiz = NULL;

 printf("inserindo o H\n");
 insereNumaAVL('H', &raiz, &h);
 /* imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o G\n");
 insereNumaAVL('G', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o E\n");
 insereNumaAVL('E', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o I\n");
 insereNumaAVL('I', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o J\n");
 insereNumaAVL('J', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o R\n");
 insereNumaAVL('R', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o B\n");
 insereNumaAVL('B', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o N\n");
 insereNumaAVL('N', &raiz, &h);
 /*  imprimeArvoreBinaria(*raiz);*/

 printf("inserindo o M\n");
 insereNumaAVL('M', &raiz, &h);
 /*imprimeArvoreBinaria(*raiz);*/

 
 return 0;
}
