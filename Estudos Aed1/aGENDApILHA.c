void fpvazia(){
	
	struct pilha *prox;
	aux=malloc(sizeof(struct pilha*));
	topo = aux;
	fundo =topo;
	fundo->prox=NULL;
}

void cadastra(pilha prox,char na){
	aux=((prox*)malloc(sizeof(prox));
printf("Voce selecionou cadastra:\n\n");
/*struct pilha *aux;*/
aux->name=na;
/*aux->name=prox->topo;*/
aux->px=prox->topo;
prox->topo=aux
/*topo = aux;*/
/*char x[30];
char op;*/
fpvazia();
/*while(op !='n'){*/
    	printf("Digite o nome:\n\n");
    	scanf("%c",&x);
    	/*printf ("Continuar com o cadastro ?(s/n)");
    	op = getch();*/
    	tamanho++;
    	numero++;



char opc;
printf("Voce deseja continuar o progama? (s/n):\n\n");
scanf("%c",&opc);

if(opc == 's'){
menu();
}/*else{
     print("O progama sera finalizado");
     }*/

}
/*void knota(pilha *prox,char x){
	printf("Voce selecionou cadastra nota:\n\n ");
	/*char x[30];*/
	/*int flag =0;
	struct pilha *aux;
aux->prox = topo;
aux-> nota;
topo = aux;
while(aux->prox !=NULL){

    	printf("Digite o nome do aluno a ser cadastrado a nota:\n\n");
    	scanf("%c",&x);
    	if(aux->name==x){
    	printf("Aluno encontrado:");
    	printf("digite a nota do aluno");
    	scanf("%d",&nota);
    	flag =1;
    	aux->prox=NULL;
    	}else{
          	aux=aux->prox;
          	}
    	printf ("Continuar com o cadastro ?(s/n)");
    	op = getch();
    	}
    	if(flag==0){
                	printf("Nao a aluno com esse nome:");
                	}


menu();
}

void mediana(){
printf("Voce selecionou tirar media:\n\n ");
menu();
}

void listar(){
	int con=0;
printf("Voce selecionou listar:\n\n");
struct pilha *aux;
aux = topo;
while(aux->prox !=NULL){

    	printf("aluno(s) sem nota:",aux->name,numero);
    	con++;

     if(con=0){
    	printf("Todos os alunos posuen notas:");
    	}                  

char opc;
printf("Voce deseja continuar o progama? (s/n):\n\n");
scanf("%c",&opc);

if(opc == 's'){
menu();
}

}
}
void excluir(){
     printf("Voce selecionou Excluir aluno:\n\n ");
	char x[30];
	int flag =0;
	struct pilha *aux;
aux->prox = topo;
aux-> nota;
topo = aux;
while(aux->prox !=NULL){

    	printf("Digite o nome do aluno a ser exluido :\n\n");
    	scanf("%c",&x);
    	if(aux->name==x){
    	printf("Aluno encontrado:\n\n");
                  	if (name->nota==NULL){
                  	printf("aluno sera excluido:\n\n");
                  	topo =topo->prox;
                  	}else{
                        	printf("aluno tem nota e nao sera exluido:\n\n");
                        	}
    	flag =1;
    	aux->prox=NULL;
    	}else{
          	aux=aux->prox;
          	}
    	printf ("Continuar com o cadastro ?(s/n)");
    	op = getch();
    	}
    	if(flag==0){
                	printf("Nao a aluno com esse nome:");
                	}


printf("Voce selecionou excluir aluno:\n\n");
menu();
}

void exnota(){
printf("Voce selecionou excluir nota:\n\n");
menu();
}

void sair(){

exit(1);
}
*/


int main (void){

menu();

system("pause");
return 0;
}

void menu(){
	system("cls");
int opc;

printf("Escolha uma opcao:\n\n");
printf("1 - cadastrar:\n\n");
printf("2 - cadastrar nota do aluno:\n\n");
printf("3 - Calcular media do aluno:\n\n");
printf("4 - listar alunos sem nota:\n\n");
printf("5 - Excluir aluno:\n\n");
printf("6 - Excluir nota:\n\n");
printf("7 - sair:\n\n");

printf ("Opcao:\n\n");
scanf("%d",&opc);
getchar();

switch (opc){
           case 1:
           cadastra();

           break;

           case 2:
           knota();

           break;

           case 3:
           mediana();

           break;

           case 4:
           listar();

           break;

           case 5:
           excluir();

           break;

           case 6:
           exnota();

           break;

           case 7:
           sair();

           break;

           default:
           printf("Opcao invalida tente novamente\n\n");
           break;

           system("pause");
           menu();

   }

}
typedef struct pilha pilha;
pilha* pl = NULL;

int inseririnicio (pilha** pl, char* name, ...)
{
   pilha* pnew;

   pnew = (pilha*) malloc(sizeof(pilha));
   if(pnew == NULL)
       return 0;

   pnew->name = name;
   //..
   pnew->prox = *pl;
   *pl = pnew;
   return 1;
}

int inserirfinal (pilha** pl, char* name, ...)
{
   if(*pl == NULL)
   {
       return inseririnicio(pl, name, ...);
   }
   else
   {
       pilha* pnew,* aux = *pl;

       pnew = (pilha*) malloc(sizeof(pilha));
       if(pnew == NULL)
           return 0;

       pnew->name = name;
       //..
       pnew->prox = *pl;

       while(aux->prox != NULL)
           aux = aux->prox;

       aux->prox = pnew;
   }
   return 1;
}

