#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cabecalho;

typedef struct {
   unsigned long int codigo;
   char nome[50];
   char endereco[150];
   char telefone[15];
   char email[50];
} contato_t;

/* Variaveis Globais */
contato_t *lista;
unsigned long int numero_de_contatos, codigo_max, i;

/* Declaracao das funcoes */
void limpar_tela (void);
void ler_arquivo (void);
void menu (void);
void procurar_contato (void);
int comparar_nomes (char*, char*);
void adicionar_contato (void);
void inserir_por_nome (contato_t);
void editar_contato (void);
void remover_contato (void);
void apaga_contato (long int);
void listar_nomes (void);
void sair (void);


void swap(contato_t listas[], int ind_um, int ind_dois)
 
{
   contato_t aux;
   
   aux = listas[ind_um];
   listas[ind_um] = listas[ind_dois];
   listas[ind_dois] = aux;
}


int partition(contato_t listas[], int esq, int dir)
{
   int prim = esq-1;
   int ult = dir;

   while (1){
   
      while (comparar_nomes(listas[++prim].nome, listas[dir].nome) < 0)
      ;
      while (comparar_nomes(listas[dir].nome, listas[--ult].nome) < 0)
         if (ult == esq)
            break;
      if (prim >= ult)
               break;
      swap(listas, prim, ult);
   }
   swap(listas, prim, dir);
   return prim;
}


void quicksort(contato_t listas[], int esq, int dir)
{
   int meio;
   if (dir > esq){
      meio = partition(listas, esq, dir);
      quicksort(listas, esq, meio - 1);
      quicksort(listas, meio + 1, dir);
   }
}

int busca_binaria(char chave[])
{
   int limiteInf, limiteSup, metade;

   limiteInf = 0;
   limiteSup = numero_de_contatos;

   while (limiteInf <= limiteSup) {
      metade = (limiteInf + limiteSup)/2;
      if ( comparar_nomes(chave, lista[metade].nome) == 0 )
         return metade;           // retorna somente o indice metade!!!
      if ( comparar_nomes( chave , lista[metade].nome) == -1 )
         limiteSup = metade - 1;
      else
         limiteInf = metade + 1;
   }
    
   return -1;
}

int busca_iguais(int metade, char chave[])
{
   int limiteInf,limiteSup;


   limiteInf = metade; //faz isso pra caso soh existir apenas 1, tanto 
   limiteSup = metade; //o superior quanto o inferior serem o termo encontrado
    
     
   while (limiteInf > 0){ //acha as chaves iguais abaixo
      limiteInf = limiteInf - 1;
      if (comparar_nomes( chave , lista[limiteInf].nome ) == 0 ){}
      else {
         limiteInf = limiteInf + 1;
         break;
      }
   }
   while (limiteSup < (numero_de_contatos-1)){ //acha as chaves iguais acima
      limiteSup = limiteSup + 1;
      if ( comparar_nomes( chave , lista[limiteSup].nome) == 0){}
      else {
         limiteSup = limiteSup - 1;
         break;
      }
   }
   if (limiteInf == limiteSup){ //se forem iguais eh pq so existe 1 q eh a metade
      printf ("%4ld - %s\n", lista[metade].codigo, lista[metade].nome);
      return 1;
   }
   else{
      for ( ;limiteInf <= limiteSup; limiteInf++){ //imprime do menor ao maior do vetor
      printf ("%4ld - %s\n", lista[limiteInf].codigo, lista[limiteInf].nome); 
      }
      return 2;
   } 
}

void limpar_tela ()
{
   system ("clear");
}

void ler_arquivo()
{
   FILE *arquivo;
   numero_de_contatos = codigo_max = 0;
   arquivo = fopen("dados", "a"); /* Cria o arquivo caso ele nao exista */
   fclose(arquivo);
   arquivo = fopen("dados", "r");
   fscanf (arquivo, "%ld %ld\n\n", &numero_de_contatos, &codigo_max);

   lista = malloc(numero_de_contatos * sizeof(contato_t) );

   for (i = 0; i < numero_de_contatos; i++){
      fscanf(arquivo, "%ld\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n\n", &lista[i].codigo, lista[i].nome, lista[i].endereco, lista[i].telefone, lista[i].email);
   }
   fclose(arquivo);
}

void menu ()
{
   char opcao[10];
   
   while (1){
      printf ("Escolha uma opcao:\n[P]rocurar por um Contato\n[A]dicionar um Contato\n[E]ditar um Contato\n[R]emover um contato\n[L]istar Nomes\n[S]air\n\n");
      printf (">> ");
      gets(opcao);
      switch (opcao[0]){
         case 'p':
         case 'P':
            procurar_contato();
            break;
         case 'a':
         case 'A':
            adicionar_contato();
            break;
         case 'e':
         case 'E':
            editar_contato();
            break;
         case 'r':
         case 'R':
            remover_contato();
            break;
         case 'l':
         case 'L':
            listar_nomes();
            break;
         case 's':
         case 'S':
            sair();
         default:
            limpar_tela();
            printf("Opcao invalida!!!\n\n");
      }
   }
}

void procurar_contato()
{
   char nome_procurado[50];
   long int posicao, codigo_view, count = 0;
   int metade;
   posicao = -1;

   limpar_tela ();

   printf ("Qual nome deseja procurar?\n>> ");
   gets(nome_procurado);
   limpar_tela ();
   
   metade = busca_binaria(nome_procurado);
   if (metade == -1){
      printf ("\nO contato procurado nao existe.\n\n");
      return;
   }
   count = busca_iguais(metade,nome_procurado);
   
   if (count > 1){
      do{
         printf ("\nDigite o codigo do contato que deseja obter mais detalhes:\n>> ");
         scanf ("%ld", &codigo_view);
         limpar_tela ();
         for (i = 0; i < numero_de_contatos; i++)
            if (codigo_view == lista[i].codigo){
               posicao = i;
               break;
            }
         if (posicao == -1){
            printf ("Codigo inexistente.\n");
         }
      }while(posicao == -1);
      printf ("\nNome: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n\n", lista[posicao].nome, lista[posicao].endereco, lista[posicao].telefone, lista[posicao].email);
      gets (nome_procurado);
   }
   else
   printf ("\nNome: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n\n", lista[metade].nome, lista[metade].endereco, lista[metade].telefone, lista[metade].email);
   return;
}


int comparar_nomes (char *nome1, char *nome2)
{
   int c;
   
   for (c=0; c < strlen(nome1); c++) {
      if (toupper(nome1[c]) < toupper(nome2[c])) {
         return -1;
      }
      else if (toupper(nome1[c]) > toupper(nome2[c])) {
         return 1;
      }
   }
   return 0;
}



void adicionar_contato ()
{
   contato_t novo;
   codigo_max++;
   numero_de_contatos++;
   novo.codigo = codigo_max;
   limpar_tela ();
   printf ("Nome: ");
   gets (novo.nome);
   printf ("Endereco: ");
   gets (novo.endereco);
   printf ("Telefone: ");
   gets (novo.telefone);
   printf ("E-mail: ");
   gets (novo.email);
   lista = realloc(lista, numero_de_contatos * sizeof(contato_t));
   inserir_por_nome(novo);
}

void inserir_por_nome(contato_t novo)
{
   unsigned long int posicao = (numero_de_contatos-1);
   
   lista[posicao] = novo;
   quicksort(lista,0,posicao);
   limpar_tela ();
   puts("Contato inserido com sucesso!\n");
   return;
}


void editar_contato ()
{
   long int codigo_edit, posicao;
   char aux[50];
   posicao = -1;
   
   limpar_tela();
   puts ("Cod. | Nome");
   for (i = 0; i < numero_de_contatos; i++){
      printf ("%4ld - %s\n", lista[i].codigo, lista[i].nome);
   }
   printf ("\nTotal de contatos: %ld\n\n", numero_de_contatos);
   do{
      printf("Insira o codigo do contato a ser editado ou digite zero(0) para voltar: ");
      scanf("%ld", &codigo_edit);
      if( codigo_edit == 0){
         return;
      }
      for(i = 0; i < numero_de_contatos; i++)
         if(codigo_edit == lista[i].codigo){
            posicao = i;
            break;
         }
      if(posicao == -1){
         printf("Codigo inexistente.\n");
      }
   }while( posicao == -1);
   printf("\nNome: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n\n", lista[posicao].nome, lista[posicao].endereco, lista[posicao].telefone, lista[posicao].email);
   puts("Digite os novos dados para altera-los ou pressione\nENTER para manter os dados originais:\n");
   gets(aux);
   printf("Nome: ");
   gets(aux);
   if(strlen(aux) > 0){
      strcpy(lista[posicao].nome, aux);
   }
   printf("Endereco: ");
   gets(aux);
   if(strlen(aux) > 0){
      strcpy(lista[posicao].endereco, aux);
   }
   printf("Telefone: ");
   gets(aux);
   if(strlen(aux) > 0){
      strcpy(lista[posicao].telefone, aux);
   }
   printf("E-mail: ");
   gets(aux);
   if(strlen(aux) > 0){
      strcpy(lista[posicao].email, aux);
   }
   limpar_tela();
   puts("Dados alterados com sucesso.\n");
   quicksort(lista,0, (numero_de_contatos-1) );
   return;
}

void remover_contato ()
{
   long int codigo_remove, posicao;
   char opcao[100];
   posicao = (-1);
   
   limpar_tela ();
   
   if (numero_de_contatos == 0){
      puts ("Nao existem contatos para serem removidos.\n");
      return;
   }
   puts ("Cod. | Nome");
   for (i = 0; i < numero_de_contatos; i++){
      printf ("%4ld - %s\n", lista[i].codigo, lista[i].nome);
   }
   printf ("\nTotal de contatos: %ld\n\n", numero_de_contatos);
   do{
      printf ("Insira o codigo do contato a ser removido: ");
      scanf ("%ld", &codigo_remove);
      for (i = 0; i < numero_de_contatos; i++)
         if (codigo_remove == lista[i].codigo){
            posicao = i;
            break;
         }
      if (posicao == (-1)){
         printf ("\aCodigo inexistente.\n");
      }
   }while(posicao == -1);
   
   invalido:
   printf ("\nDeseja mesmo remover o seguinte contato?\n\nNome: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n\n[S]im\n[N]ao\n\n>> ", lista[posicao].nome, lista[posicao].endereco, lista[posicao].telefone, lista[posicao].email);
   
   gets (opcao);
   switch (opcao[0]){
      case 's':
      case 'S':
         apaga_contato (posicao);
         limpar_tela ();
         puts ("Contato removido com sucesso.\n");
         break;
      case 'n':
      case 'N':
         limpar_tela ();
         break;
      default:
         limpar_tela ();
         goto invalido;
   }
   return;
}

void apaga_contato (long int posicao)
{
   for (i = posicao; i < (numero_de_contatos - 1); i++){
      lista[i] = lista[i+1];
   }
   numero_de_contatos--;
   lista = realloc (lista, numero_de_contatos * sizeof (contato_t));
}

void listar_nomes ()
{
   long int posicao, codigo_view;
   char opcao[1];
   posicao = -1;
   
   limpar_tela();
   puts ("Cod. | Nome");
   for (i = 0; i < numero_de_contatos; i++){
      printf ("%4ld - %s\n", lista[i].codigo, lista[i].nome);
   }
   printf ("\nTotal de contatos: %ld\n\n", numero_de_contatos);
   if (numero_de_contatos > 0){
      printf ("Digite o codigo do contato que deseja obter mais detalhes:\n>> ");
      do{
         scanf ("%ld", &codigo_view);
         for(i = 0; i < numero_de_contatos; i++)
            if (codigo_view == lista[i].codigo){
               posicao = i;
               break;
            }
         if (posicao == -1){
            printf ("Codigo inexistente. Digite um codigo acima.\n>> ");
         }
      }while(posicao == -1);
      limpar_tela();
      printf ("Nome: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n\n", lista[posicao].nome, lista[posicao].endereco, lista[posicao].telefone, lista[posicao].email);
      gets(opcao);
   }
   return;
}

void sair ()
{
   FILE *arquivo;
   arquivo = fopen ("dados", "w");
   fprintf (arquivo, "%ld %ld\n\n", numero_de_contatos, codigo_max);
   for (i = 0; i < numero_de_contatos; i++){
      fprintf (arquivo, "%ld\n%s\n%s\n%s\n%s\n\n", lista[i].codigo, lista[i].nome, lista[i].endereco, lista[i].telefone, lista[i].email);
   }
   fclose (arquivo);
   free (lista);
   limpar_tela ();
   exit(0);
}

int main()
{
   limpar_tela ();
   ler_arquivo ();
   puts (cabecalho);
   menu ();
   return 0;
}
