#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct pilha{
       int dados;
       struct pilha *proximo;
};

void push(struct pilha **topo,int valor, int *sinal);
void mostra_pilha(struct pilha **ppilha);
int pop(struct pilha **topo, int *sinal);


// PROGRAMA PRINCIPAL;
int main(){
    int num,ok;
    struct pilha *pilha1=NULL;
    struct pilha *pilhaaux=NULL;
    
    // Construindo PILHA 
    printf("\nPara encerrar digite 0");
    do{
         printf("\nInforme numeros para PILHA1: ");
         scanf("%d", &num);
         if(num != 0){
                push(&pilha1,num,&ok);
                if(ok==0){
                     printf("\nErro de alocacao! ");
                }
         }
    }while (num!=0);
    
    mostra_pilha(&pilha1);
    getch();
    
    pop(&pilha1,&ok);
    mostra_pilha(&pilha1);
    getch();
    
}
//Pilha ________________________________________________________________________

void push(struct pilha **topo,int valor, int *sinal){
     struct pilha *n;
     n = (struct pilha *) malloc (sizeof(struct pilha));
     if (n == NULL){
           *sinal=0;
     }else{
           n->dados=valor;
           n->proximo=*topo;
           *topo=n;
           *sinal=1;
     }
}

//Desempilha ___________________________________________________________________

int pop(struct pilha **topo, int *sinal){
    struct pilha *n,*aux;
    int valor;
    
    aux=*topo;
    if(aux == NULL){
            *sinal=0;
    }else{
            valor=aux->dados;
            n=aux;
            aux=n->proximo;
            free(n);
            *topo=aux;
            *sinal=1;
            return valor;
    }
} 

//Mostra Pilha _________________________________________________________________

void mostra_pilha(struct pilha **p1){
     struct pilha *aux;
     
     aux=*p1;
     while(aux != NULL){
               printf("\n\nValores Pilha - %i\n",aux->dados);
               aux=aux->proximo;
     }
}

//Retira Impares__ONDE ESTA ACONTECENDO O ERRO__________________________________________

void retira_impares(struct pilha *pilha1,struct pilha **pilhaaux){
     
     while(pilha1 != NULL){
                   if(pilha1->dados % 2 == 0){
                               push(*pilhaaux,pop(pilha1);
                   }else{
                              printf("\n IMPAR - %i",pilha1->dados);
                   }
     }while(pilhaaux != NULL){
                   push(pilha1,pop(*pilhaaux));
     }
}
  
