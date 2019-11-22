#include <stdio.h>
#include <stdlib.h>
    
    #define TAM 5
    
    struct fila {
       char itens[TAM];
       int inicio;
       int fim;
    };
    
    void insere(struct fila *f, int el) {
         if (f->fim == TAM -1)
            f->fim = 0;
         else 
             f->fim = f->fim + 1;
         
         if (f->fim == f->inicio) {
            printf("\nEstouro na fila.\n");
            system("pause");
            exit(1);
         }
         else 
            f->itens[f->fim]= el;
     }

     int empty(struct fila *f) {
         if (f->fim == f->inicio)
            return 1;
         else return 0;
      }

      int remove(struct fila *f) {
          if (empty(f) == true) {
             printf("\nUnderflow na fila. \n");
             system("pause");
             exit(1);
          }
          else {
              if (f->inicio == TAM -1)
                   f->inicio = 0;
              else 
                   f->inicio = f->inicio + 1;
              return f->itens[f->inicio];
          } 
      }
      
int main() {
 
   int op, el;
struct fila f;
f.inicio = f.fim = TAM - 1;
do { printf("\n1-Inserir \n2-Remover \n3-Encerrar");
scanf("%d", &op);
if(op ==1) {
printf("\nNumero?");
scanf("%d", &el);
insere(&f, el); }
if (op ==2) {
int aux =remove(&f);
printf("\nRemovido: %d", aux);
}
} while (op !=3);
}