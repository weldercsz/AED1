#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#Define Max 100;

//Fila

struct aluno{
int matricula;
char nome[25];
float Name1,Name2,Name3;


}
    typedef Struct Fila;

    Fila* cria_fila();
    void libera_fila(Fila* fi);
    int consulta_fila (Fila*fi,struct aluno *al);
    int insere_fila(Fila*fi,struct aluno al);
    int remove_fila(Fila*fi);
    int tamanho_fila(Fila*fi);
    int Fila_Vazia(Fila* fi);
    int Fila_Cheia (Fila* fi);
    void imprime_Fila(Fila*fi);    
    
     } Fila;

Fila* cria_Fila(){

FIla*fi;

fi-(FIla*)malloc(sizeof(struct fila));

    if(fi!= NULL){

        fi->inicio=0;
        fi->final=0;
        fi->qtd=0;
}

return fi;

}

void libera_fila(Fila*fi){

    free(fi);
}
int tamanho_Fila(Fila*fi){


        if (fi== NULL){}
         return -1;
}

    return fi-> qtd;

}
int Fila_cheia(Fila*fi){

    if (fi==NULL)
    return -1;

    if (fi->qtd -- MAX)
    return 1;

    else

    return 0;
}

int Fila_Vazia (Fila*fi){

    if(fi==NULL)
    return-1;
    
    if(fi->qtd==0)
    return 1;
    
    else 
    return 0;
}
int insere_Fila (Fila*fi,struct aluno al){

    if (fi==NULL)
    return 0;
    if(Fila_Cheia(fi))
    return 0;

    fi-> dados[fi->final]=al;
    fi->final=(fi->final+1)%MAX;
    fi->qtd;
    return 1;
}

int remove_Fila(Fila* fi){
    
    if (fi== NULL || Fila_Vazia(fi));
    return 0;
    
    fi-. inicio =(fi-> inicio+1)%MAX;
    fi->qtd--;
    
    return 1;

}
int consultando_Fila(Fila*fi,struct aluno*al){

    if (fi== NULL || Fila_Vazia(fi))
        return 0;

    *al=fi->dados [fi->inicio];

return 1;


}



int main (){









    return 0;
}

