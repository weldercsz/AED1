// Porgramação Descomplicada !!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct agenda {
    char matricula[20];
    char nome[30];
    struct agenda *prox;
    struct tel *t;
    struct mail *m;

};
struct tel{
       char telefone[20];
       struct tel *prox;
};
struct mail{
       char email[30];
       struct mail *prox;
};


struct agenda* criaAgenda (){
     return NULL;
}
struct tel* criaTel(){
     return NULL;
}
struct mail*criaMail(){
       return NULL;
}
void insereTel(struct tel **t,char tel[]){
     struct tel *p,*q;

      p=(struct tel*)malloc(sizeof(struct tel));
      strcpy(p->telefone,tel);
      p->prox=*t;
      *t=p;

}

void insereMail(struct mail **m,char mail[]){
     struct mail *p;
      p=(struct mail*)malloc(sizeof(struct mail));

      strcpy(p->email,mail);
      p->prox=*m;
      *m=p;
}

void inserePessoa (struct agenda **L, struct tel *T,struct mail *M, char n[], char end[]){
     struct agenda *p;

     p=(struct agenda*)malloc(sizeof(struct agenda));

     strcpy(p->matricula,n); strcpy(p->nome,end);
     p->prox=*L;
     p->t=T;
     p->m=M;
     *L=p;


}

struct agenda* localiza(struct agenda *L,char n[]){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     int cont=0;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while(p!=NULL){
        if (strcmp(p->matricula,n)!=0)
            p=p->prox;
          else{
                  printf("\n\n Matricula -> %s",p->matricula);
                  printf("\n Nome -> %s",p->nome);
                  while(auxt!=NULL){
                     printf("\n Telefone -> %s",auxt->telefone);
                     auxt =auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n Email -> %s",auxm->email);
                     auxm=auxm->prox;
                  }

           return p;
           }


     }
     return NULL;
}

void listarTodos(struct agenda *L){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while (p!=NULL){
             printf("\n\nmatricula -> %s",p->matricula);
             printf("\n\nnome -> %s",p->nome);
             while(auxt!=NULL){
                     printf("\n\nTelefone -> %s",auxt->telefone);
                     auxt =auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n\nEmail -> %s",auxm->email);
                     auxm=auxm->prox;
                  }
           p=p->prox;
           printf("\n\n=================\n\n");
     }
}

void TotalTelefones(struct agenda *L){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     int contador;
     p=L;
     auxt=p->t;
     auxm=p->m;

    while(auxt!=NULL){
        contador ++;
        auxt =auxt->prox;
    }

    printf("\nTotal de telefones: %d", contador);

}

void TotalAlunos(struct agenda *L){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     int contador;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while (p!=NULL){
           contador ++;

           p=p->prox;
           //printf("\n\n=================\n\n");
     }
     printf("\nTotal de alunos: %d", contador);
}


void SalvarTXT(struct agenda *L){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     p=L;
     auxt=p->t;
     auxm=p->m;

    FILE *arquivo_texto;  //Criando a File   
    arquivo_texto = fopen ("agenda_eletronica.txt", "w+");  //Abrindo txt e escrevendo nele

    if (arquivo_texto == NULL) {  
        printf("Erro ao abrir o arquivo.\n");  //Caso de algum erro
        exit(1);             
    }

    while (p!=NULL){ //Correr toda lista das structs     
        fprintf(arquivo_texto, "Matricula -> %s\n Nome -> %s\n", p->matricula, p->nome); //Inserindo dados da Struct de dados
             while(auxt!=NULL){
                     fprintf(arquivo_texto, "Telefone -> %s\n", auxt->telefone); //Inserindo dados da Struct de telefones
                     auxt =auxt->prox; //Pula pro proximo registro
                  }
                  while (auxm!=NULL){
                     fprintf(arquivo_texto, "Email -> %s\n", auxm->email); //Inserindo dados da Struct de email
                     auxm=auxm->prox; //Pula pro proximo registro
                  }
           p=p->prox;
           fprintf(arquivo_texto, "=================\n");
           //printf("\n\n=================\n\n");
     }

     fclose(arquivo_texto); //fecha o arquivo
}

void listaLetra(struct agenda *L,char n){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while (p!=NULL){
           if(p->matricula[0]!=n)
              p=p->prox;
           else{
             printf("\n\nmatricula -> %s",p->matricula);
             printf("\n\nnome -> %s",p->nome);
             while(auxt!=NULL){
                     printf("\n\nTelefone -> %s",auxt->telefone);
                     auxt=auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n\nEmail -> %s",auxm->email);
                     auxm=auxm->prox;
                  }
             p=p->prox;
             printf("\n\n======================\n\n");
             }
     }
}

void alterarDados(struct agenda *L,char n[]){
     int cont=0;
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     auxt=p->t;
     auxm=p->m;
     p=localiza(L,n);
        if(p==NULL)
        printf("\nmatricula não encontrado");
        else{
                printf("\n\nDigite o novo nome:");
                scanf("%s",&p->nome);

                while (auxt!=NULL){
                      printf("\n\n Digite o novo telefone:");
                      scanf("%s",&auxt->telefone);
                      auxt=auxt->prox;
                }
               while (auxm!=NULL){
                     printf("\n\n Digite o novo email:");
                     scanf("%s",&auxm->email);
                     auxm=auxm->prox;
               }
    }
}

struct agenda* removermatricula(struct agenda *L,char n[]){
    struct agenda *p, *q;
    p=localiza(L,n);
    if (p==NULL)
        printf("\n\n Matricula nao encontrada !");
    else{
        q=L;
        if(q==p){
            L=p->prox;
            free(p);
        }else{
        while (q->prox!=p)
            q=q->prox;

         q->prox=p->prox;
         free(p);
        }
        printf("\n\n Aluno removido com sucesso !");
    }
    return L;
}
void LimpaLista(struct agenda *L){
    struct agenda *p, *q;
    p=L;
    q=L;
    if (p==NULL)
        printf("\n\n Lista vazia");
    else{
        q=L;
        if(q==p){
            L=p->prox;
            free(p);
        }else{
        while (q->prox!=p)
            q=q->prox;

         q->prox=p->prox;
         free(p);
        }
        printf("\n\n Lista limpa !");
    }
    //return L;
}
main(){
       struct agenda *Lista;
       struct tel *Tel;
       struct mail *Mail;
       int op;
       char matricula[20], nome[30], telefone[20], email[20];
       char no;

       Lista=criaAgenda();
       Tel=criaTel();
       Mail=criaMail();

       do{
          system("cls");
          printf("\nEstrutura de Dados - Trabalho Pratico I - Gabriel de Souza\n");
          printf("\n[1] - Cadastra Aluno --Falta arrumar bug dos tel");
          printf("\n[2] - Pesquisa Aluno (Matricula)");
          printf("\n[3] - Remove Aluno");
          printf("\n[4] - Total de alunos");
          printf("\n[5] - Total de telefones");
          printf("\n[6] - Limpar Lista");
          printf("\n[7] - Salva em Disco");
          printf("\n[8] - Carrega lista");
          printf("\n\nDigite -> ");     
          fflush(stdin);
          scanf("%d",&op);

      switch (op){
             case 1: printf("\nMatricula -> ");
                     fflush(stdin);
                     scanf("%s",matricula);
                     printf("\nNome -> ");
                     fflush(stdin);
                     scanf("%s",nome);

                     do{
                        printf("\nTelefone -> ");
                        fflush(stdin);
                        scanf("%s",telefone);
                        insereTel(&Tel,telefone);
                        printf("\nPossui mais telefones -> [1] Sim [2] Nao\n");
                        scanf("%d",&op);
                     }while(op!=2);

                     do{
                           printf("\nEmail -> ");
                           fflush(stdin);
                           scanf("%s", email);
                           insereMail(&Mail,email);
                           printf("\nPossui mais emails? [1] Sim [2] Nao\n");
                           scanf("%d",&op);
                      }while(op!=2);

                     inserePessoa(&Lista,Tel,Mail,matricula,nome);
              break;

              case 2: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                      printf("\n Digite um matricula -> ");
                      fflush(stdin);
                      scanf("%s",matricula);
                    if(localiza(Lista,matricula)==NULL)
                      printf("\n Matricula não encontrado na agenda");
                      }
                      getch();
                    break;
              case 3: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                        printf("\nDigite a matricula do aluno que deseja remover -> ");
                        scanf("%s",matricula);
                        Lista=removermatricula(Lista,matricula);
                        getch();
                      }

              case 4: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      TotalAlunos(Lista);
                      getch();
                      break;
              case 5: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      TotalTelefones(Lista);
                      getch();
                      break;
              case 6: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      LimpaLista(Lista);
                      getch();
                      break;
              case 7: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      SalvarTXT(Lista);
                      getch();
                      break;
              case 8: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      listarTodos(Lista);
                      getch();
                      break;
      }
      }while (op!=0);
}
