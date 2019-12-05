#include <stdio.h>
#include <string.h>
#include <math.h>

/*Declara��o do n� para a �rvore, composto de ponteiros
da direita e esquerda e de um campo para dado que no caso
� o campo char dado[30];
*/
struct no {
       
       char dado[30];
       struct no *direita;
       struct no *esquerda;
       
       };
       
struct no *raiz; //Ponteiro da raiz
struct no *alocar; //Ponteiro para fazer aloca��o

/*Rotina de busca
Insere o dado em string e ela retorna o ponteiro em hexa
para a regi�o da mem�ria para o qual o ponteiro est�
apontando.
*/
struct no * buscar(char *dado) {
       
      struct no *ponteiro;
      
      ponteiro = raiz;
       
      while (ponteiro) { 
            
      if (strcmp(dado, ponteiro->dado)==0) //Faz a compara��o de strings
            return ponteiro; //Retorna ponteiro se o encontrar
            
      if (strcmp(dado, ponteiro->dado)>0)
            ponteiro = ponteiro->direita;

      else
            ponteiro = ponteiro->esquerda; 
      
      }
      
      return NULL; //Retorna o ponteiro nulo
}

/*Rotina que faz a inser��o na �rvore bin�ria de busca
O Par�metro dado recebe um ponteiro para string 
A fun��o n�o retorna valor nem refer�ncia
*/
void inserir(char *dado) {
     
    alocar = (struct no *) malloc(sizeof(struct no)); //Faz aloca��o na mem�ria
        
    if (!alocar) { //Se n�o for poss�vel a aloca��o, sai do programa
       printf("Falta de mem�ria"); 
       exit(0);
    }
    
    strcpy(alocar->dado, dado); //Copia o dado para o novo n� alocado
     
     if (!raiz) { //Se n�o houver elemento ainda na �rvore, insere na raiz
         raiz = alocar;
     }
     
     else //se n�o...
     
     {
       //ponteiros para busca
       struct no *ponteiro; 
       struct no *ponteiroAnterior;
       ponteiro = raiz; //ponteiro inicia na raiz
       ponteiroAnterior = NULL; //anterior inicial em NULL
         
        while (ponteiro) { //Faz a busca do lugar ao qual deve ser inserido o n�
              
              ponteiroAnterior = ponteiro;
              
              if (strcmp(dado, ponteiro->dado)==0) {
                 printf("\nDado inserido j� existe!");
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
              //atribui o endere�o de aloca��o ao ponteiro da direita do n� anterior
            }  
        else  {
              ponteiroAnterior->esquerda = alocar;
              //atribui o endere�o de aloca��o ao ponteiro da esquerda do n� anterior
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
com algumas inser��es, um caminhamento e uma busca no final
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
