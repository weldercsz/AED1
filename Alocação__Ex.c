#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char *nome;
    unsigned int tam = 50;
    
    //Em C n�o vai casting antes do malloc, e voc� quer alocar
    //caracteres (sizeof(char)), n�o ponteiros para caracteres
    //(sizeof(char *):
    nome = malloc(tam * sizeof(char));  
    
    
    printf("Qual o seu nome: ");
    //gets() � uma fun��o obsoleta que foi abandonada por n�o
    //ser segura, logo use fgets no lugar:
    fgets(nome, tam, stdin);
    //fgets() � segura pois permite limitar o n�mero de 
    //caracteres capturados, assim evitando que estoure o
    //tamanho da mem�ria alocada se o usu�rio digitar mais
    //de tam=50 caracteres.
    
    puts(nome);
    
    return 0;
}
