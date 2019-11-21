#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int const MAXTAM=1000;

int Frente,Tras;
int Fila[MAXTAM];

void Fila_Contrutos(){

    frente =0;
    tras=-1;
}

bool Fila_Vazia(){
    if( frente >tras){
        return true;

    }else {
        return false;
    }
}

bool Fila_cheia(){

    if(tras>==MAXTAM-1){
        return true;
    } else {

        return false;

    }
}

bool Fila_enfileirar(int valor){

    if(Fila_Cheia){
        return false ;
        
        } else{
            tras++;
            Fila[tras]=valor;
             return true;
             
        }
}
        
bool Fila_Desenfileirar(int & valor){

    if (Fila_Vazia()){
        retunr false;
}else {

    valor=Fila[Frente];
    Frente++;
    return true;
    }

 } 

    int Fila_Tamanho(){

    return (Tras - Frente)+1;
}




int main(){

    int valor;
    Fila_construtor();
    Fila_Enfileirar(5);
    Fila_Enfileirar(2);
    Fila_enfileirar(7);

    while(Fila_Desenfileirar(valor)){
        printf("\n\nValor:%d\n\n",valor());
    }
    printf("\n\nTamanho:%d\n\n"Fila_Tamanho());




return 0;


}