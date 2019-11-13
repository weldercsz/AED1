#include<stdio.h>
#include<stdlib.h>






/*Lista encadeada Circular ------------Programação Descomplicada----------
Este exercicio contém uma serie de testes e modificações para meu aprendizado por 
esse motivo contém erros, mas o compartilhei como parametro de como se faz uma Lista
encadeada Circular
*/



    //DEFINIÇAO DE PONTEIROS
    struct no{
           char nome[50];
           int idade;
          struct no *prox;
          }; 
    //CRIAÇÃO DE PONTEIROS       
    struct no *pra_mim = NULL ,*novo,*aux,*ant;

    //INSERE 
    int Insere (char *nome, int idade){
        int cont;
        novo = new no();
         if (novo != NULL) {

           novo->idade = idade;
           strcpy(novo->nome,nome);

           if (pra_mim == NULL){
               pra_mim = novo ;
               novo->prox=pra mim;
               pra_mim->prox=novo;

           }else{

             aux = pra_mim;
             while(aux->prox != pra_mim){
                  aux = aux ->prox; 
              }
                                 novo->prox=pra mim;
                                 aux->prox=novo;
             } 
         } 
    }
        //IMPRIME
        int imprime_circular(){

          if(aux==NULL){
                           printf("Lista vazia!\r\n");
                           printf("\n");}
          else{
          aux = pra_mim;
          do{
          printf("-----------------------------");
          printf("\nNOME: %s\n",aux->nome);
          printf("\nIDADE: %d\n",aux->idade);
          printf("-----------------------------");
          aux=aux->prox;
          }while (aux!=pra_mim);
             }   
             
        }

        //ORDENA
        void ordenar(){
        int a = 0;
        no *p1;
        p1=(no*)malloc(sizeof(no)); 
        while (a<20){
              aux = pra_mim;
              do{
                   if (aux->idade <= aux->prox->idade){
                                 aux = aux->prox;
                                 }
                   if (aux->prox!=pra_mim){
                   if (aux->idade > aux->prox->idade){
                                p1->idade=aux->prox->idade;
                                aux->prox->idade=aux->idade;
                                aux->idade=p1->idade;
                                aux=aux->prox;
                                }
                   }
                   }while (aux->prox!= pra_mim);
                   a++;
                   }
              }

        //DELETA
        void deleta(char *nome1){
          aux=pra_mim;
          ant=aux;
          if (aux==NULL){
              printf("Lista vazia!\r\n");
              printf("\n");}
              else{
                   while(aux->prox != pra_mim){
                        if(strcmp(nome1,aux->nome)){
                            if(aux == pra_mim){
                               pra_mim = aux->prox;
                               }
                    else{
                        ant->prox = aux->prox;
                    }
                    free(aux);
                    aux=ant;

                }
                ant=aux;
                aux=aux->prox;
             }
         }
    }                 


    int main () {
        int x,k;
        no *p_l;
        char nome[50],nomedel[50];
        int idade;
        for (;{
           system("cls");
           printf("\n01-Inserir");
           printf("\n02-Exibir");
           printf("\n03-Ordenar");
           printf("\n04-Deletar");
           printf("\n05-Exit");
           printf("\n O que voce deseja fazer? : ");
           scanf("%d",&x);
           switch(x){
                case 1 : printf("\nQual e o nome?\t");
                         scanf("%s",&nome);
                         printf("\nQual e a idade?\t");
                         scanf("%d",&idade);
                         Insere(nome,idade);
                         system("PAUSE");
                         break;
                case 2 : imprime_circular();
                         system("PAUSE");
                         break;
                case 3 : ordenar();
                         system("PAUSE");
                         break;
                case 4 : printf("\nQuem voce deseja deletar?\n");
                         scanf("%s",&nomedel);
                         deleta(nomedel);
                         system("PAUSE");
                         break;         
                case 5 : exit(0);
                default: printf("opção Errada");
                         scanf("%d",&k);
                     }
        }                
        }