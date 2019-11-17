#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila {
   char eventos[250];
};
int inicio = 0, fim = 0;

void Inserir(Fila *a);
void Listar(Fila *a);
void Remover(void);

int main()
{
   Fila agenda[100];
   int opc;

   for(;;){
       printf("(1) Inserir\n(2) Listar\n(3) Remover\n(4) Sair\n");
       scanf("%d%*c", &opc);
       switch(opc){
           case 1 :
               Inserir(agenda);
               break;
           case 2 :
               Listar(agenda);
               break;
           case 3 :


               break;
           case 4 :
               exit(0);
       }
   }
}

void Inserir(Fila *a){
   int opc;
   char s[250];

   do{
       system("cls");
       printf("Insira o evento: ");
       gets(s);
       strcpy((a[inicio].eventos),s);
       inicio++;
       printf("\n(1) Inserir outro\n(2) Voltar ao menu\n");
       scanf("%d%*c", &opc);
   }while(opc != 2);    
}

void Listar(Fila *a){
   int i;
   for(i=0; i<inicio; i++){
       printf("%s\n", a[fim].eventos );
       fim++;
   }
}
