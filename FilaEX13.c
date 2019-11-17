#include <stdio.h>
#include<stdlib.h>
#include<math.h>
/*
O programa deve conter um menu com as seguintes opções:
1 – Exibir estoque;
2 – Dar entrada no estoque;
3 – Remover item do estoque.


*/
struct loja{
        char nota_fiscal[100];
        int quant;
        struct loja *prox;
};

typedef struct loja estoque;

int cont = 0;

estoque *estrut;

menu(){
       int caso;
       system("cls");
       printf("[1] Adicionar NF\n");
       printf("[2] Mostrar Estoque\n");
       printf("[3] Remover NF\n");
       printf("[0] Sair\n");
       scanf("%d",&caso);
       system("cls");
       switch(caso){
         case 1: inserir();
                 break;
         case 2: imprimir();
                 break;
         case 3: remover();
                 break;
         case 0: (1); 
                 break;
         default: 
             printf("Opcao invalida!\n");
             getch();
             menu();         
       }
       
}
inserir(){
        char nota_fiscal[100];
        int quant;

        fflush(stdin);
        printf("Digite o numero da Nota Fiscal: ");
        gets(nota_fiscal);
        printf("Digite a quantidade do produto: ");
        scanf("%d",&quant);
        printf("%d",strlen(estrut->nota_fiscal));
        getchar();
        if (strlen(estrut->nota_fiscal) == 0){
           strcpy(estrut->nota_fiscal,nota_fiscal);
           estrut->quant = quant;
        }else{
          estoque *novo;
          
          novo = (estoque*) malloc(sizeof(estoque));
          strcpy(novo->nota_fiscal,nota_fiscal);
          novo->quant = quant;
          novo->prox = NULL;
          
          estoque *atual;

          atual = estrut;
          
          while (atual->prox != NULL)
                atual = atual->prox;      
          
          atual->prox = novo;
          
        }
        cont++;
        menu();
}
imprimir(){
       estoque *mostrar;  
       mostrar = estrut;
       if(cont == 0){
       printf("Sem Dados");
       }
       else{
       do{
          printf("Nota Fiscal: %s\n", mostrar->nota_fiscal);
          printf("Quantidade: %d\n\n", mostrar->quant);
          mostrar = mostrar->prox;

          if (mostrar ==NULL)
             break;
          
       } while (1==1);
       }
       getch();
       menu();
       
}
remover(){
       if (estrut->prox==NULL){
         strcpy(estrut->nota_fiscal,"");
         estrut->quant = NULL;
       }else{
         estoque *atual, *anterior;
         atual = estrut;
         while(atual->prox != NULL){
           anterior = atual;
           atual    = atual->prox;
         }
         anterior->prox = NULL;
         free(atual);
       }
       if(cont == 0){
               printf("Sem Dados");
               }else{
       printf("Ultimo registro removido!");
       cont--;
       }
       getch();
       menu();
}
 int main(){
       estrut = (estoque*) malloc(sizeof(estoque));
       strcpy(estrut->nota_fiscal,"");
       estrut->prox=NULL;
       menu();
}


