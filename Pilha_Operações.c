.
#include <stdio.h>

void push(int valor);
int pop(void);
int size(void);
int stacktop(void);
int pilha[10];
int pos=0;  // topo da pilha
.
..
void push(int valor) {
  pilha[pos]=valor;
  /* Empilha um novo elemento no topo da pilha. Repare que não é verificada a capacidade máxima da pilha.*/
  pos++;  // Atualiza o topo da pilha
  return;
}

int pop() {
    /* Retorna o elemento do topo da ilha. Não é verificado o final da pilha. */
   return (pilha[--pos]);
}

int size() {
  return pos; /* retorna o topo da pilha */
}
..
int stacktop() /* retorna o elemento do topo da pilha sem desempilhar */
{
return pilha[pos];
}

int main(int argc, char ** argv ) {

    printf("\nColoca dados na pilha");
    push(1);
    push(2);
    push(3);

    printf("\nTamanho da pilha %d", size());

..
    printf("\nPegando dado da pilha: %d", pop());
    printf("\nPegando dado da pilha: %d", pop());
    printf("\nPegando dado da pilha: %d", pop());
    printf("\nTamanho da pilha %d", size());
    return 0;
}

Uma pilha em C pode ser declarada como uma estrutura contendo dois objetos: um vetor para armazenar os elementos da pilha e um inteiro para indicar a posição atual do topo da pilha.

/* programa_pilha_02.c */
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 100

/* Estrutura que irá conter a pilha de informações com o topo e o vetor de itens da pilha. */
struct pilha {
    int topo;
    int itens[TAMANHO_PILHA];
};

int empty(struct pilha *p) {
    if( p->topo == -1 ) {
        return 1;
    }
        return 0;
    }
}

/* Retorna um elemento do topo da pilha e atualiza o topo da pilha */
int pop(struct pilha *p) {..
    if( empty(p) ) {
        printf("\nPilha vazia");
        exit(1);
    }
    /* retorna o item do topo da pilha atual e diminui a posição da pilha */.
    return (p->itens[p->topo--]);
}

/* Inclui um elemento no topo da pilha */
void push(struct pilha *p, int e) {
    if( p->topo == (TAMANHO_PILHA - 1)) {
        printf("\nEstouro da pilha");
        exit(1);
    }
    /* após veriicar se não haveria estouro na capacidade da pilha,
    é criada uma nova posição na pilha e o elemento é armazenado */
    p->itens[++(p->topo)] = e;
    return;
}

/* Retorna o tamanho da pilha */
int size(struct pilha *p) {
    /* sempre lembrando que na linguagem C o índice de um vetor começa na posição 0 */
    return p->topo+1;
}

/* Retorna o elemento do topo da pilha*/
int stackpop(struct pilha *p) {
    return p->itens[p->topo];
}

/* Programa principal */
int main(void) {
    struct pilha x;
    x.topo = -1;
    push(&x,1);
    push(&x, 2);
    push(&x, 3);
    printf("\nTamanho da pilha %d", size(&x));
    printf("\n Elemento do topo da pilha %d", stackpop(&x));
..
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    return 0;
}