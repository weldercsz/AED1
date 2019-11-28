#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista2{
    char cidades[51];
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* lst2_cria (void){
    return NULL;
}

Lista2* lst2_insere (Lista2* l, char v[] ){
    Lista2* novo=(Lista2*)malloc(sizeof(Lista2));
    strcpy(novo->cidades, v);
    novo->prox=l;
    novo->ant=NULL;
    if (l!=NULL) l->ant=novo;
    return novo;
}

Lista2* lst2_busca (Lista2*l, char v[]){
    Lista2* p;
    for (p=l; p!=NULL; p=p->prox)
        if (strcmp (p->cidades,v)==0)
            return p;
    return NULL;
}

Lista2* lst2_retira (Lista2* l, char v[]){
    Lista2* p;
    p= lst2_busca(l,v);
    if (p==NULL){
        printf("Cidade nao encontada.\n");
        return l;
    }
    else printf("Cidade retirada.\n");
    if (l==p) l=p->prox;
    else p->ant->prox=p->prox;
    if (p->prox!=NULL)
        p->prox->ant=p->ant;
    free(p);
    return l;
}

int lst2_vazia(Lista2* l){
    if (l==NULL)return 1;
    else return 0;
}

void lst2_imprime (Lista2* l){
    Lista2*p=l;
    if(lst2_vazia(l))
        printf("\n\nA lista esta vazia.\n\n");
    else{
    while(p->prox != NULL)
        p = p->prox;
    while(p != NULL){
        printf("%s\n", p->cidades);
        p = p->ant;
    }
    }
}

void lst2_libera (Lista2* l){
    Lista2* p=l;
    while (p!=NULL) {
        Lista2* t=p->prox;
        free(p);
        p=t;
    }
}

int main()
{
    int n;char cidade[51];
    Lista2* l;
    printf("\n\t\t>-------------------- MENU --------------------<\n\n");
    printf("\n0)Encerrar\n1)Criar lista\n2)Inserir cidade\n3)Retirar cidade\n4)Imprimir lista\n5)Verificar se a lista esta vazia\n6)Liberar lista\n");
    printf("\n\t\t>----------------------------------------------<\n");
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        switch(n)
        {
            case 1:
                l=lst2_cria();
                printf("Lista criada.\n");
                break;
            case 2:
                printf("Digite a cidade que deseja inserir\n");
                scanf(" %[^\n]s", cidade);
                l=lst2_insere(l, cidade);
                break;
            case 3:
                printf("Digite a cidade que deseja retirar\n");
                scanf("%s", cidade);
                l=lst2_retira(l, cidade);
                break;
            case 4:
                lst2_imprime(l);
                break;
            case 5:
                if(lst2_vazia(l))
                    printf("A lista esta vazia.\n");
                else printf("A lista nao esta vazia.\n");
                break;
            case 6:
                lst2_libera(l);
                printf("Lista liberada\n");
                break;
            default:
                printf("\nDigite uma das opções validas.\n");
                break;
        }
    }
    return 0;
}
/*
//troque esse por
while (p!=NULL) {
        Lista2* t=p->prox;
        free(p);
        p=t;
    }

//esse
while(p != NULL){
   free(p);
   p = p->prox;
}

//veja que o loop só começa e continua se p for diferente 
//de NULL
*/
