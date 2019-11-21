#include<stdio.h>
#include<stdlib.h>

/* Duas Pilhas Implementação Estática 

Utilazaremos um Unico arranjo de elementos predefinidos
colocaremos "uma pilha" em cada extremediade do arrajno
Controlar aonde  a poição do elemento que está no Topo de cada
uma das "Pilhas"


temos um arranjo ´redefinido
temos um campo para indicar a posição do elemento que está 


*/


#define MAX 50;
 typedef int TIPO CHAVE;

 typedef struct{

     TIPOCHAVE chave;

 }Registro;

 typedef struct{

     Registro A[MAX];
     int topo1;
     int topo2;
 }PILHADUPLA;


 void inicializarPilhaDupla(PILHADUPLA*p){
     
     p->topo1 =-1;
     p->topo2=MAX;

 }

bool exibirumaPilha(PILHADUPLA*P,int pilha){

    if (pilha<1||pilha>2) return false;
    printf("Pilha %i:\"",pilha);
    int i;
    if(pilha==1) 
    for(i=p->topo;i>=0;i--)
    else  {

       for (i=p->topo2;i<MAX;i++)
         printf("%i",p->A[i].chave);
    }
printf("\"\n");    
return true;

}

bool inserirElementoPilha(PILHADUPLA* p,REGISTRO rog ,int pilha){
    if(pilha<1||pilha>2) return false;
    if(p->+1 == p->topo2) return false;

    if (pilha==1){
        p->topo1 = p->topo+1;
        p->A[p->topo1]=reg;
    } else {

        p->topo2 =p->topo2-1;
        p->A[p->topo2] =reg ;

    }


}

bool excluirElementoPilha(PILHADUPLA* P,REGISTRO* reg,int pilha){

f(pilha<1||pilha2) return false;

if(p->topo==1{
    if(p->topo1==-1) return false;
        *reg= p->A[p->topo1];
        p->topo1=p->topo1 -1;
} else{
    if(p->topo2==MAX) retunr false;
        *reg=p->A[p->topo2];
        p->topo2=p->topo2+1;

}

}

void reinicializarPilha(PILHADUPLA* P){

    P-> topo1 =-1;
    p-> topo2 =MAX;

}

void reinicializarPilha2(PILHADUPLA*p){

    inicializarPilhaDupla(p);
}