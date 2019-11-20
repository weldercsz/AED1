#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

// Incrementar Funções de Operações Basicas Utilizando Estrutura de Pilha
// operações, Soma, Subtração,Multiplicação,Divisao.

struct Pilha {

    int topo;
    int capa;
    float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}


void push ( struct Pilha *p, float v){

    p->topo++;
    p->pElem [p->topo] = v;

}

float subtrair(struct Pilha *p){

  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x-y;
  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;

}

float multiplicar(struct Pilha *p){

  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];

  calc=x*y;

  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;
}

float Soma(struct Pilha *p){

  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x+y;
  p->topo--;
  p->pElem [p->topo]=calc;


  return calc;
}


float Dividir(struct Pilha *p)
{
  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x/y;
  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;
}

float decrementar(struct Pilha *p){

  int x;

  x=p->pElem [p->topo];
  x--;

  return x;
}


float  pop ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;

   return aux;

}

float monstrarpilha ( struct Pilha *p ){

   return p->pElem [p->topo];

}

int main(){

    struct Pilha p;

    int capacidade=4;
    float valor;
    int A=9,B=3,C=2,D=1,E=1;

    criarpilha (&p, capacidade);

    push(&p,A);
    printf("\nPUSH A: %.1f\n",monstrarpilha(&p));

    push(&p,B);
    printf("\nPUSH B: %.1f\n",monstrarpilha(&p));

    subtrair(&p);
    printf("\nSubtracao: %.1f\n",subtrair(&p));

    push(&p,C);
    printf("\nPUSH C: %.1f\n",monstrarpilha(&p));

    push(&p,D);
    printf("\nPUSH D: %.1f\n",monstrarpilha(&p));

    push(&p,E);
    printf("\nPUSH E: %.1f\n",monstrarpilha(&p));

    multiplicar(&p);
    printf("\nmultiplicacao: %.1f\n",multiplicar(&p));

    Soma(&p);
    printf("\nadicao: %.1f\n",Soma(&p));

    decrementar(&p);
    printf("\ndecrementar: %.1f\n",decrementar(&p));

    Dividir(&p);
    printf("\ndivisao: %.1f\n",Dividir(&p));

    printf("\nPOP F%.1f\n",pop(&p));



}

