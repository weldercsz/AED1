#include <stdio.h>
#include <string.h>
#include <math.h>

/*Declaração do nó para a árvore, composto de ponteiros
da direita e esquerda e de um campo para dado que no caso
é o campo char dado[30];
*/
struct no {
       
       char dado[30];
       struct no *direita;
       struct no *esquerda;
       
       };
       
struct no *raiz; //Ponteiro da raiz
struct no *alocar; //Ponteiro para fazer alocação

/*Rotina de busca
Insere o dado em string e ela retorna o ponteiro em hexa
para a região da memória para o qual o ponteiro está
apontando.
*/
struct no * buscar(char *dado) {
       
      struct no *ponteiro;
      
      ponteiro = raiz;
       
      while (ponteiro) { 
            
      if (strcmp(dado, ponteiro->dado)==0) //Faz a comparação de strings
            return ponteiro; //Retorna ponteiro se o encontrar
            
      if (strcmp(dado, ponteiro->dado)>0)
            ponteiro = ponteiro->direita;

      else
            ponteiro = ponteiro->esquerda; 
      
      }
      
      return NULL; //Retorna o ponteiro nulo
}

/*Rotina que faz a inserção na árvore binária de busca
O Parâmetro dado recebe um ponteiro para string 
A função não retorna valor nem referência
*/
void inserir(char *dado) {
     
    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocação na memória
        
    if (!alocar) { //Se não for possível a alocação, sai do programa
       printf("Falta de memória"); 
       exit(0);
    }
    
    strcpy(alocar->dado, dado); //Copia o dado para o novo nó alocado
     
     if (!raiz) { //Se não houver elemento ainda na árvore, insere na raiz
         raiz = alocar;
     }
     
     else //se não...
     
     {
       //ponteiros para busca
       struct no *ponteiro; 
       struct no *ponteiroAnterior;
       ponteiro = raiz; //ponteiro inicia na raiz
       ponteiroAnterior = NULL; //anterior inicial em NULL
         
        while (ponteiro) { //Faz a busca do lugar ao qual deve ser inserido o nó
              
              ponteiroAnterior = ponteiro;
              
              if (strcmp(dado, ponteiro->dado)==0) {
                 printf("\nDado inserido já existe!");
                 return;
                 }
              
              if (strcmp(dado, ponteiro->dado)>0){
                 ponteiro = ponteiro->direita;
              }
              else {
                 ponteiro = ponteiro->esquerda; 
                   }
           }

        if  (strcmp(dado, ponteiroAnterior->dado)>0) {
              ponteiroAnterior->direita = alocar; 
              //atribui o endereço de alocação ao ponteiro da direita do nó anterior
            }  
        else  {
              ponteiroAnterior->esquerda = alocar;
              //atribui o endereço de alocação ao ponteiro da esquerda do nó anterior
              }
     }
}

/*Faz o caminhamento em ordem recursivamente*/
void caminharEmOrdem(struct no *ponteiro) {
     if (ponteiro) {
           caminharEmOrdem(ponteiro->esquerda);
           printf("\n%s", ponteiro->dado);
           caminharEmOrdem(ponteiro->direita);
          }
     }

/*Rotina principal
com algumas inserções, um caminhamento e uma busca no final
*/       
int main() {
    char dado[30];
    printf("\nInserir: ");
    gets(dado);
    inserir(dado);
    printf("\nInserir: ");
    gets(dado);
    inserir(dado);
    printf("\nInserir: ");
    gets(dado);
    inserir(dado);
    printf("\nInserir: ");
    gets(dado);
    inserir(dado);
    caminharEmOrdem(raiz);
    printf("\nInserir para buscar: ");
    gets(dado);
    printf("%p", buscar(dado));
  
    getchar();
}
