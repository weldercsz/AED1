#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char *nome;
    unsigned int tam = 50;
    
    //Em C não vai casting antes do malloc, e você quer alocar
    //caracteres (sizeof(char)), não ponteiros para caracteres
    //(sizeof(char *):
    nome = malloc(tam * sizeof(char));  
    
    
    printf("Qual o seu nome: ");
    //gets() é uma função obsoleta que foi abandonada por não
    //ser segura, logo use fgets no lugar:
    fgets(nome, tam, stdin);
    //fgets() é segura pois permite limitar o número de 
    //caracteres capturados, assim evitando que estoure o
    //tamanho da memória alocada se o usuário digitar mais
    //de tam=50 caracteres.
    
    puts(nome);
    
    return 0;
}
