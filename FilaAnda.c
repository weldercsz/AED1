#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PU_QtdElementos;
int PU_Fila[10];

void remover( int*PA_Valor )
{
   if ( PU_QtdElementos > 0 )
   {
      *PA_Valor = PU_Fila[0]; // Carrega o valor de retorno

      // Laço para fazer a fila andar
     
      int LO_Contador;
      for( LO_Contador = 0; LO_Contador < PU_QtdElementos; LO_Contador++)
      {
         PU_Fila[LO_Contador] = PU_Fila[LO_Contador+1];
      }
   }
}

void insere(int PA_Valor )
{
   if ( PU_QtdElementos < 10 )
   {
      PU_Fila[PU_QtdElementos] = PA_Valor;
      PU_QtdElementos++;
   }
   else
   {
      // Caso houver estouro da pilha remove o primeiro valor da fila altomaticamente e adiciona o último
     
      int LO_Temp = 0;                  // Valor que irá para o lixo
      remover( &LO_Temp );              // Remove
      PU_Fila[PU_QtdElementos] = PA_Valor; // Adiciona no último valor possível da pilha
   }
}

int main(int argc, char *argv[])
{
   PU_QtdElementos = 0;

   // Crie aqui uma opção para entrada e verificação das funções acima
   
   
   return 0;
}
