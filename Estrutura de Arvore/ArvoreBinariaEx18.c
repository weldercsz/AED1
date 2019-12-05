#include <stdio.h>
#include <time.h>

struct Arvore
{
int matricula;
char nome[100];
char curso[100];
struct Arvore *esq, *dir;
};

typedef struct Arvore *pArvore;

//variavel para a raiz da arvore
pArvore raiz = NULL;



//essa funcao ira fazer de forma recursiva a inclusao
void Inserir(pArvore *p, int x)
{
// procura se a arvore esta vazia
if((*p) == NULL){
	
*p = (pArvore)malloc(sizeof(struct Arvore));
(*p)->esq=NULL;
(*p)->dir=NULL;
(*p)->matricula=x;
}
else
{
if(x <((*p)->matricula))
//função recursiva se o numero for menor do que o numero da raiz
Inserir(&((*p)->esq), x);
else
//função recursiva se o numero for maior do que o numero da raiz
Inserir(&((*p)->dir), x);
}
}




int Remover(pArvore *p, int x)
{
if(*p == NULL)
//verifica se a arvore esta vazia
return 1;
else {
pArvore aux = *p;
if((*p)->matricula == x) //achou o elemento
{//apenas o subno da direita
if((*p)->esq ==NULL){
*p = (*p)->dir;
free(aux);
}
else
//apenas quando tem o subno da esquerda
if((*p)->dir==NULL){
*p = (*p)->esq;
free(aux);
}else{
//quando possui dois subnos, chama a função maior
aux = maior(&((*p)->dir));
free(aux);
}
}else{
if(x < (*p)->matricula)
return Remover(&((*p)->esq), x);
else
return Remover(&((*p)->dir), x);
}
return 0; //retorna 0 caso tenha tido sucesso ao remover o elemento
}

}

pArvore Maior(pArvore *p){
pArvore aux = *p;
if(aux->esq==NULL){
*p = (*p)->dir;
return aux;
}
else{
return maior(&((*p)->esq));
}
}

void randomiza(pArvore *p, int x)
{
int i;
srand(time(NULL));
if(*p == NULL)
return 1;
else{
i = rand() % 100;
return 0;}

}



//Procura um elemento na arvore

pArvore Buscar(pArvore p, int x){
if(p==NULL)return 0;
else{
if(p->matricula == x) return p->matricula;
else{
if(x < p->matricula)
return Buscar(p->esq, x);
else
return Buscar(p->dir, x);
}
}
}

int imprime_insere(pArvore *p, int x)
{
int i;
if(*p == NULL)
return 1;
else{
printf("%d\n", *p);
return 0;
}
}

int main(void){

char opcao;
int x, aux;
clock_t inicio,fim;
double time_insere=0,time_remove=0,time_Busca=0;

do{
printf("==============================\n");
printf("||===== Arvore Binaria =====||\n");
printf("||==========================||\n");
printf("||=== O que deseja fazer? ==||\n");
printf("||= (1) Inserir um novo no =||\n");
printf("||= (2) Remover um no ======||\n");
printf("||= (3) Buscar um no =======||\n");
printf("==============================\n");
scanf("%d",&opcao);
if(opcao<1||opcao>3);{
exit(1);
}
switch(opcao){

case 1:
randomiza(&raiz, x);
inicio=clock();
Inserir(&raiz, x);
fim=clock();
time_insere = ((double)(fim-inicio))/CLK_TCK;
imprime_insere(&raiz, x);
break;

case 2:
randomiza(&raiz, x);
inicio=clock();
Remover(&raiz, x);
fim=clock();
time_remove = ((double)(fim-inicio))/CLK_TCK;

case 3:
randomiza(&raiz, x);
inicio=clock();
Busca(&raiz, x);
fim=clock();
time_Busca = ((double)(fim-inicio))/CLK_TCK;


}
}while(opcao>0||opcao<3);
return 0;
}
