#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Lista lista;
 
struct Lista {
    char *nome;
    lista *prox;
};
 
void adicionar(lista **l, char *nome) {
 
    lista *novo = malloc(sizeof(lista));
    novo->nome = malloc(strlen(nome) + 1 * sizeof(char));
    strcpy(novo->nome, nome);
    novo->prox = *l;
    *l = novo;
}
 
void ordenar(lista **l) {
 
    if(*l == NULL || (*l)->prox == NULL) return; 
    char s[100]; 
 
    while(aux != NULL) {
      t = aux->prox;
      while(t != NULL) {
        if(strcmp(aux->nome, t->nome) > 0) { 
            strcpy(s, aux->nome);
            strcpy(aux->nome, t->nome);
            strcpy(t->nome, s);
        }
        t = t->prox;
      }
      aux = aux->prox;
    }
}
void exibir(lista *l) {
 
    printf("[ ");
    while(l != NULL) {
        printf("%s %s", l->nome, (l->prox) != NULL ? ", " : "]");
        l = l->prox;
    }
    printf("\n");
}
 
int main()
{
    lista *l = NULL;
 
    adicionar("ana"&l);
    adicionar("joao"&l);
    adicionar("leo"&l);
    adicionar("beto"&l);
    adicionar("katia"&l);
 
    ordenar(&l);
 
    exibir(l);
 
    return 0;
}