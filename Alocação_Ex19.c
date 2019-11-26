#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
 int main ()
 {

     // funcao q calcula as medias
     // tem que receber um aluno como parametro...
     // nao estou conseguindo passar um aluno como parametro da funcao    

/*    float calc_media(aluno *x , n_notas) 
        {
           float result;
           float somatorio;
           int j;

           for(j=0; j< n_notas; j++){
             somatorio += (x)->notas+j ;
              printf("\n nota %d lida",j );
                }       
           result = somatorio/n_notas;
           printf("Media: %6.2f \n",result);

           return result;
        }

*/    

  typedef struct  { // typedef=definir tipo, struct= novo tipo, listas de tipo
                  char curso[20];
                  int matricula;
                  int idade;
                  int *coDdisciplinas;    
                  int *notas;
                  }aluno ;
 aluno *alunos;  // um ponteiro que aponta para o dado
 int i,j,n,temp;
 int n_notas;//numero de notas a serem lidas de cada aluno

    FILE *fp;

   if (!(fp = fopen("notas.txt","w+"))) 
        {
                printf("Erro! Impossível abrir o arquivo!\n");
                system("pause");
                exit(1);
        }


 alunos = (aluno*)malloc(1*sizeof(aluno));  // malloc= alocador de memoria; retorna o end. da memoria a alocada; dado* ponteiro do tipo dado
 printf( "Entre com a quantidade de alunos a serem processados:"  );
 scanf("\n%d",&n);

 alunos=(aluno*)realloc(alunos,n*sizeof(aluno));

 for(i=0; i<=n-1; i++)
 {
   printf("\nAluno %d :",i+1);
   printf("\n Matricula :");
   fprintf(fp,"\n Matricula :");
   scanf("%d",&(alunos+i)->matricula);
   fprintf(fp,"\n%d",(alunos+i)->matricula);
   printf(" \nCurso :");
   fprintf(fp,"\n Curso :");
   scanf("%s",&(alunos+i)->curso);
   fprintf(fp,"\n%s",(alunos+i)->curso);
   printf(" \nNumero de notas a seren lidas:");
   scanf("%d",&n_notas);
   (*(alunos+i)).notas = (int*)malloc(n_notas*sizeof(int));
   (*(alunos+i)).coDdisciplinas = (int*)malloc(n_notas*sizeof(int));

    for(j=0; j< n_notas; j++){
           printf("   \nNota %d :",j+1);
           fprintf(fp,"  \n Nota %d:",j+1);
           printf("\n   Cod_disciplina :"); 
           fprintf(fp,"\n   Cod_disciplina :"); 
           scanf("%d",&(alunos+i)->coDdisciplinas+j); 
           fprintf(fp,"\n%d",(alunos+i)->coDdisciplinas+j);
           printf("   \nPontos na disciplina  : ");  
           fprintf(fp," \n  Pontos na disciplina  : ");  
           scanf("%d",&(alunos+i)->notas+j);    
           fprintf(fp,"%s\n",&(alunos+i)->notas+j);
    }


//   calc_media((alunos+i), &n_notas)
 }
 free(alunos);
 getch();
}
