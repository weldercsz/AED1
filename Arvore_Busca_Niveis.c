#include<stdio.h>
#include<stdlib.h>

struct no{

int dado;

struct no *esq, *dir;

};

typedef struct no ARV;

int menu(){

    int opc;



printf("[0]-sair: \n");

printf("[1]-inserir: \n");

printf("[2]-pre ordem: \n");

printf("[3]-em ordem: \n");

printf("[4]- pos ordem: \n");

printf("[5]- quantidade: \n");

printf("[6]- maior elemento: \n");

printf("[7]- menor elemento: \n");

printf("[8]- remover maior elemento: \n");

printf("[9]- remover por valor: \n");

printf("[10]- mostrar no: \n");

printf("[11]- altura da arvore: \n");

printf("[12]- nivel do no: \n");

printf("Escolha uma opcao:\n");

scanf("%i",&opc);

return opc;

}

void inserir(ARV **r, int valor){

	if(*r==NULL){

			   ARV *novo;

			   novo=(ARV *)malloc(sizeof(ARV));

			   novo->dir=NULL;

			   novo->esq=NULL;

			   novo->dado=valor;

			   *r =novo;

}

else{

			   if(valor>(*r)->dado)

			   inserir(&((*r)->dir),valor);

			   else

			   inserir(&((*r)->esq),valor);

}

}

void pre_ordem(ARV **r){

	if(*r!=NULL){

	printf("%i \n",(*r)->dado);

	pre_ordem(&((*r)->esq));

	pre_ordem(&((*r)->dir));

}

}

void em_ordem(ARV **r){

	if(*r!=NULL){

	em_ordem(&((*r)->esq));

	printf("%i \n",(*r)->dado);

			 em_ordem(&((*r)->dir));

}

}

void pos_ordem(ARV **r){

	if(*r!=NULL){

	pos_ordem(&((*r)->esq));

	pos_ordem(&((*r)->dir));

	printf("%i \n",(*r)->dado);

}

}

//FORMA SEQUENCIAL

int *maior(ARV **r){

ARV *p;

    if(*r==NULL){

    return NULL;

}

else{

	for(p=(*r);p->dir!=NULL;p=p->dir);

	return &(p->dado);

}

}

int *menor(ARV **r){

    ARV *p;

    if(*r==NULL){

    return NULL;

}

else{

	if((*r)->esq==NULL)

				    return &((*r)->dado);

else

      return menor((&(*r)->esq));

}

}

int qtd_nos(ARV **r){

    if(*r==NULL)

    			 return 0;

else{

	return 1 + qtd_nos(&((*r)->esq)) + qtd_nos(&((*r)->dir));

}

}

//FORMA RECURSIVA

int remove_maior_elemento(ARV **r){

if (*r==NULL)

   return 0;

else{

	if((*r)->dir==NULL){

	ARV *p;

	p=*r;

	*r=p->esq;

	free(p);

return 1;

}

else{

return remove_maior_elemento(&((*r)->dir));

}

}

}

int remover_valor(ARV **r, int vlr){

    if(*r==NULL)

return 0;

else{

	if(vlr==(*r)->dado){

				if((*r)->esq==NULL){

				ARV *p;

				p=*r;

				*r=p->dir;

free(p);

return 1;

}

else{

	if((*r)->dir==NULL){

	ARV *p;

	p=*r;

	*r=p->esq;

free(p);

return 1;

}

else{

	(*r)->dado=*maior(&((*r)->esq));

         naior_elemento(&((*r)->esq));

return 1;

}

}

}

else{

	  if(vlr>(*r)->dado)

	  				return(remover_valor(&((*r)->dir),vlr));

else

return(remover_valor(&((*r)->esq),vlr));

}

}

}

void nos_folhas(ARV **r){

	if ((*r)==NULL){

	printf("Arvore vazia");

return ;

}

 	  if(((*r)->esq==NULL)&& ((*r)->dir==NULL)){

	  printf("%i \n ",(*r)->dado);

}

else{

	if((*r)->esq!=NULL){

					nos_folhas(&((*r)->esq));

}
            if((*r)->dir!=NULL) {

		  nos_folhas(&((*r)->dir));

}

}

}

int altura(ARV **r){

    if((*r)==NULL)

return -1;

else{

	if(altura(&((*r)->esq))>altura(&((*r)->dir)))

	    return 1+altura(&((*r)->esq));

else

        return 1+altura(&((*r)->dir));

}

}

int nivel_no(ARV**r, int niv){

  if((niv==0) && (*r!=NULL))

       printf("%i\n",(*r)-> dado);

else{

    if((*r)->esq!= NULL)

       nivel_no(&((*r)->esq),niv-1);

         if((*r)->dir!= NULL)

          nivel_no(&((*r)->dir),niv-1);

}

}

int main(){

    int opc,vlr;

    ARV *r=NULL;

    int *retorno;

    int *nivel;

while(opc=menu()){

switch(opc){

case 1:

printf("informe um valor:\n");

scanf("%i",&vlr);

inserir(&r, vlr);

break;

case 2:

pre_ordem(&r);

break;

case 3:

em_ordem(&r);

break;

case 4:

pos_ordem(&r);

break;

case 5:

printf("a qtd de elementos é: %i \n",qtd_nos(&r));

break;

case 6:

retorno=maior(&r);

          if(retorno==NULL)

               printf("arvore vazia.\n");

               printf("maior:%i \n",*retorno);

		   break;

		   case 7:

retorno=menor(&r);

      if(retorno==NULL)

           printf("arvore vazia.\n");

           printf("menor:%i \n",*retorno);

           break;

            case 8:

       if(remove_maior_elemento(&r))

	      printf("elemento removido. \n");

else

            printf("nao foi possivel remover");

            break;

            case 9:

            printf("valor:");

             scanf("%i",&vlr);

if(remover_valor(&r,vlr))

            printf("removido. \n");

else

            printf("nao encontrado ,\n");

             break;

              case 10:

nos_folhas(&r);

break;

case 11:

printf("a altura da arvore é: %i \n",altura(&r));

break;

case 12:

printf("Nivel da arvore para consulta: ");

scanf("%i", &nivel);

nivel_no(&r,nivel);

break;

}

system("pause");
return 0;
}

}
