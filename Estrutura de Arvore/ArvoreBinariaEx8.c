#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int i; /* chave */
  struct no *esq, *dir;
} No;


No *arv(int i, No* esq, No* dir) {
  No* n = (No*) malloc (sizeof (No));
  n->i = i;
  n->esq = esq;
  n->dir = dir;
  return n;
}



No* exemplo() {
  return arv(25,
	     arv(15, arv(5,NULL,NULL), NULL),
	     arv(30, arv(26,NULL,NULL), arv(35,NULL,NULL)));
}


void inorder(No* p) {
  if (p != NULL) {
    inorder (p->esq);
    printf("%d ", p->i);    
    inorder (p->dir);    
  }
}

void escreve(No* p) {
  inorder(p);
  printf("\n");
}

/* Retorna 1 se a chave for encontrada */

int busca (No* p, int chave) {
  if (p == NULL)
    return 0;
  if (p->i == chave)
    return 1;
  if (p->i > chave)
    return busca(p->esq, chave);
  return busca(p->dir, chave);
}

/* Retorna 1 se a chave for encontrada */

int n_rec_busca(No* p, int chave) {
  while (p != NULL) {
    if (p->i == chave)
      return 1;
    if (p->i > chave)
      p = p->esq;
    else
      p = p->dir;
  }
  return 0;
}

/* Retorna 0 se a chave for repetida */

int  insere(No** ap_p, int chave) {
  if (*ap_p == NULL) {
    *ap_p = (No*) malloc(sizeof(No));
    (*ap_p)->i = chave;
    (*ap_p)->esq = (*ap_p)->dir = NULL;
    return 1;
  }
  if ((*ap_p)->i == chave)
    return 0;
  if ((*ap_p)->i > chave)
    return insere (&(*ap_p)->esq, chave);
  return insere (&(*ap_p)->dir, chave);
}

/* Retorna 0 se a chave for repetida */
/* Parte sem Recurção */
int  n_rec_insere(No** ap_p, int chave) {
 while (*ap_p != NULL) {
   if ((*ap_p)->i == chave)
     return 0;
   if ((*ap_p)->i > chave)
     ap_p = &(*ap_p)->esq;
   else
     ap_p = &(*ap_p)->dir;
 }
 *ap_p = (No*) malloc(sizeof(No));
 (*ap_p)->i = chave;
 (*ap_p)->esq = (*ap_p)->dir = NULL;
 return 1;
}

/* Retorna 0 se a chave não for encontrada */

int remove_arv(No** ap_p, int chave) {
  while (*ap_p != NULL && (*ap_p)->i != chave) {
   if ((*ap_p)->i > chave)
     ap_p = &(*ap_p)->esq;
   else
     ap_p = &(*ap_p)->dir;
 }  
  if (*ap_p == NULL)
    return 0;
  if ((*ap_p)->esq == NULL && (*ap_p)->dir == NULL) {
    free(*ap_p);
    *ap_p = NULL;
  }
  if ((*ap_p)->esq == NULL && (*ap_p)->dir != NULL) {
    No *r = *ap_p;
    *ap_p = (*ap_p)->dir;   
    free(r);
  }
  if ((*ap_p)->esq != NULL && (*ap_p)->dir == NULL) {
    No *r = *ap_p;
    *ap_p = (*ap_p)->esq;   
    free(r);
  }  
  No **ap_s = &(*ap_p)->dir;
  No *r = *ap_p;

  while ((*ap_s)->esq != NULL)
    ap_s = &(*ap_s)->esq;
  No* s = *ap_s;

  *ap_s = (*ap_s)->dir;
  s->esq = r->esq;
  s->dir = r->dir;

  *ap_p = s;
  free(r);

  return 1;
}

/* Verifica se p é uma árvore de busca */

int verifica_busca(No* p)  {
  return 0;
}


int main() {
  No *arv = exemplo();
  escreve(arv);
  int i = remove_arv(&arv, 32);
  escreve(arv);
  return 0;
}
