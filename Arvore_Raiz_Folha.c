#include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #define TAM 6
    
    /* 
    Funcao para inicializar com zero os elmentos da matrix que representa o 
    Grafo. A matriz com 6 linhas e 6 colunas representa um Grafo que possui 6
    vertices ou nos. 
    */
    void iniciarGrafo(int mat[][TAM]) {
         int i, j;
         for (i=0; i<TAM; i++)
             for (j=0; j<TAM; j++)
                 mat[i][j] = 0;
    }
    
    /*
    Funcao para estabelecer ligacao entre um vertice/no e outro vertice/no do Grafo. 
    a Funcao recebe a matric que representa o Grafo, a cidade origem e a cidade destino e
    grava 1 no elemento da matriz correpondente a ligacao entre a cidade origem e a cidade destino,
    estabelecendo desta forma o vinculo entre a cidade origem e a cidade destino.
    */
    void join(int mat[][TAM], int cidade1, int cidade2) {
         mat[cidade1][cidade2]=1;
    }
    
    /*
    Funcao verificar se um vertice/no do Grafo está ligado ao vertice/no adjacente. A funcao
    verifica se o elemento da matriz apontado pela cidade origem e cidade destino possui valor 1 o que
    representa que a cidade origem e a cidade destino estao ligadas e sao adjacentes.
    */
    int adjacente(int mat[][TAM], int cidade1, int cidade2) {
        if (mat[cidade1][cidade2])
           return 1;
        else 
           return 0;
    }
    
    /* 
    Verifica existe caminho entre a cidade origem e a cidade destino. Caso a cidade origem seja
    adjacente a cidade destino entao retorna 1. Caso contrario, busca um caminho entre a cidade origem 
    e a cidade destino, percorrendo o Grafo a partir o vertice adjacente ao vertice que representa 
    a cidade origem. Caso nenhum caminho seja encontrado entre a cidade destino e algum vertice adjacente
    a cidade origem entao retorna 0.
    */
    int procuraCaminho(int mat[][TAM], int cidade1, int cidade2, int k) {
        
        if (k ==1) {
           if (adjacente(mat, cidade1, cidade2))
              return 1;
           else 
              return 0;
         }
         for (int c=0; c<TAM; ++c)
           if (adjacente(mat, cidade1, c) && procuraCaminho(mat, c, cidade2, k-1))
              return 1;
              
          return 0;
    }
    
    int main() {
        int matriz[TAM][TAM];
        int cidade1, cidade2, k, temCaminho;
        char resp='S', caminho[30]="\0";
        
        /* Inicializa a matriz que representa o Grafo, atribuindo 0 para todos os elementos e
        desta forma caracterizando que inicialmente o Grafo nao possui nenhum vertice ligado a outro
        vertice */
        iniciarGrafo(matriz);
    
       /* Enquando o usuario responder S solicita a digitacao da cidade origem e cidade destino e 
       liga a cidade origem com a cidade destino, estabelecento uma ligacao entre as cidades */
        while (toupper(resp) == 'S') {
              
           /* Recebe a cidade origem. Enquanto o usuario digitar cidade origem invalida fica
           aguardando a digitacao. Cidade origem valida é de 1 a 6*/
           do {
               printf("Digite origem: ");
               scanf("%i", &cidade1);
           } while (cidade1 <1 || cidade1 >TAM);
           
           /* Recebe a cidade destino.*/
           do {
                printf("Digite destino: ");
                scanf("%i", &cidade2);
           } while (cidade2 <1 || cidade2 >TAM);    
    
            /* Estabelece uma ligacao entre a cidade origem e a cidade destino*/
            join(matriz, cidade1-1, cidade2-1);
    
            printf("Realizar outro join? ");
            fflush(stdin);
            scanf("%c", &resp);
            
        }//fim while  
        resp='S' ; 
        while (toupper(resp) == 'S') {
              printf("Digite cidade A: ");
              scanf("%i", &cidade1);
    
              printf("Digite cidade B: ");
              scanf("%i", &cidade2);
    
              printf("Digite tamanho do caminho: ");
              scanf("%i", &k);
    
              temCaminho = procuraCaminho(matriz, cidade1-1, cidade2-1, k);
        
              if (temCaminho ==1)
                     printf("Existe caminho de comprimento %i entre as cidades %i e% i", k, cidade1, cidade2);
            
            else
                printf("Nao existe caminho de comprimento %i entre as cidades %i e% i", k, cidade1, cidade2);
    
         system("pause");
         
           printf("Realizar outra pesquisa? ");
           fflush(stdin);
           scanf("%c", &resp);
          }
         
         return 0;
        
    }