#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define FALSE   0      // constante falsa
#define TRUE   !FALSE  // constante verdadeira


/***********************************************/ 
/* Definicao dos Registros                                                 */
/***********************************************/ 
typedef struct {             // registro para uma pessoa
       int  matr;
       char nome[30];
} INFORMACAO;

typedef struct arvore {
       INFORMACAO info;      // dados do registro
       struct arvore* subd;  // ponteiro para o nodo da direita
       struct arvore* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 



/***********************************************/ 
/* Definicao das Funces                                                     */
/***********************************************/
void    entrada_dados ( ARVORE* aux ); // leitura dos dados de entrada
void    imprime_ARVORE( ARVORE* aux ); // visualizacao da lista em tela
void    cria_ARVORE   ( ARVORE** r );  // inicializa arvore com NULL
void    insere        ( ARVORE** r );  // inclui um novo registro na arvore
int     busca         ( int matricula, ARVORE** a, ARVORE** p ); // procura na arvore por uma matricula
void    sucessor      ( ARVORE* p, ARVORE** q, ARVORE** b );
void    antecessor    ( ARVORE* p, ARVORE** q, ARVORE** b );
void    remove        ( ARVORE** r );  // exclui um regitro por matricula



/***********************************************/ 
/* Programa Principal                                                        */
/***********************************************/
int main( void )
{
    char op;   // opcao do menu                               
    ARVORE* r; // declaracao da ARVORE // variavel do tipo ARVORE = ARVORE de ponteiros

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de cadastro academico - Menu                " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [2] Insere                                           " );
         printf( "\n [3] Remove                                           " );
         printf( "\n [4] Imprime                                          " );         
         printf( "\n [5] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de opcao do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;

           case '2':  // rotina inclui nodo no final da ARVORE
                   insere( &r );    
                   break;

           case '3':  // rotina exclui nodo da ARVORE
                   remove( &r );
                   break;

           case '4':  // rotina exclui nodo da ARVORE
                   imprime_ARVORE( r );
                   break;                   

           case '5': // t?rmino do programa                                                 
                   exit( 1 ); 
                   break;

           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )

        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela

        printf( "\n" );
     } // fim do while( 1 )

 return 0;
} // fim do programa principal



/************************************************/ 
/* entrada_dados                                                              */
/* objetivo: rotina para ler dados                                          */
/* entrada : nodo (ponteiro para o novo espaco)                     */
/ * sa?da   : nodo com dados                                               */
/************************************************/
void entrada_dados( ARVORE* aux )
{ 
//    printf( "\n\n Matricula: %d", aux->info.matr );
    printf( "\n\n Matricula: ");
    fflush( stdin );
    scanf("%d", aux->info.matr);
    printf( "\n Digite o nome: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );

    aux->subd = NULL;    // n?o aponta
    aux->sube = NULL;    // n?o aponta

}

/*************************************************/
/* imprime_ARVORE                                                              */
/* objetivo: rotina para imprimir dados                                     */
/* entrada : ARVORE                                                            */
/* sa?da   : nenhuma                                                           */
7*************************************************/ 
void imprime_ARVORE( ARVORE* aux )
{    

    if( aux != NULL ){ // verifica se a raiz e diferente de vazio
        printf( "\n Nome.....: %d", aux->info.matr );
        getchar();
        printf( "\n >> sube" );
        imprime_ARVORE( aux->sube );
        printf( "\n >> subd" );
        imprime_ARVORE( aux->subd );
    }
    else
       printf("\n Arvore vazia!");
}

/************************************************/
/* cria_ARVORE                                                                 */
/* objetivo: rotina para inicializar a ARVORE                            */
/* entrada : nenhuma                                                         */
/* sa?da   : NULL (inicializa ARVORE)                                     */
/************************************************/ 
void cria_ARVORE( ARVORE** r )
{
    *r = NULL; // arvore criada, raiz nao aponta
}

/*************************************************/ 
/* insere                                                                            */
/* objetivo: rotina para inserir no fim da ARVORE                       */
/* entrada : ARVORE                                                            */
/* sa?da   : ARVORE com mais um registro                                */
/*************************************************/ 
void insere( ARVORE** r )
{
    ARVORE* p;    // ponteiro auxiliar
    ARVORE* a;    // ponteiro auxiliar para anterior
    int matricula, achou; // matricula = dado de entrada; achou = informa se matricula ja existe na estrutura

      p = *r;
      if (p == NULL) {   
        ARVORE *matricula = (ARVORE *) malloc(sizeof(ARVORE));   
        entrada_dados(matricula);
        // (p)->sube = NULL;   
        // (p)->subd = NULL;
        p->info.matr = achou;

      }   
      if (p->info.matr < ) {   


      }   
      else{   
        if (p->info.matr > ) {               


        }   
  } 
}

/************************************************/ 
/* busca                                                                          */
/* objetivo: achar nodo                                                      */
/* entrada : ARVORE e matricula a ser excluida                       */
/* sa?da   : posicao ou NULL (n?o encontrou)                         */
/************************************************/ 
int busca( int matricula, ARVORE** a, ARVORE** p )
{
   int achou = FALSE; // achou = indica se encontrou a matricula na estrutura

   a = NULL;

} 


/***************************************************/ 
/* remove                                                                              */
/* objetivo: rotina para excluir nodo da ARVORE                            */
/* entrada : ARVORE                                                                */
/* sa?da   : ARVORE                                                                 */
/***************************************************/ 
void remove( ARVORE** r )
{
    ARVORE* p;    // ponteiro auxiliar
    ARVORE* q;    // ponteiro auxiliar
    ARVORE* b;    // ponteiro auxiliar
    ARVORE* a;    // ponteiro auxiliar para anterior
    int matricula, achou; // matricula = dado de entrada; achou = informa se matricula ja existe na estrutura

}


/***************************************************/
/* sucessor                                                                            */
/* objetivo: rotina para descobrir nodos filhos                               */
/* entrada : ARVORE, ponteiros auxiliares q e b                             */
/* saida   : ponteiros auxiliares q e b                                           */
/***************************************************/ 
void sucessor( ARVORE* p, ARVORE** q, ARVORE** b )
{
 *b= p;
 *q= p->subd;
 while( (*q)->sube != NULL )
        {
           *b= *q;
           *q= (*q)->sube;
        }
}



/***************************************************/
/* antecessor                                                                         */
/* objetivo: rotina para descobrir nodos filhos                               */
/* entrada : ARVORE, ponteiros auxiliares q e b                             */
/* sa?da   : ponteiros auxiliares q e b                                          */
/***************************************************/ 
void antecessor( ARVORE* p, ARVORE** q, ARVORE** b )
{
 *b= p;
 *q= p->sube;
 while( (*q)->subd != NULL )
        {
           *b= *q;
           *q= (*q)->subd;
        }
}
