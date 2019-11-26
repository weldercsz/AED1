#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* uniao(int* v1, int n, int* v2, int m, int *p){
    int h=0,g,i,j,k,q,w=0,cont=0;
    int v3[n+m];
    for(i=0;i<n;i++){     /*coloca numeros de v1 em v3*/
        v3[i]=v1[i];
        if(v1[i]==0){w=1;}/*se tiver zero em v1*/
    }
    for(j=0;j<m;j++){     /*coloca numeros de v2 em v3*/
        v3[i]=v2[j];
        if(v2[j]==0){w=1;} /*se tiver zero em v2*/
        i++;
    }
    for(j=0;j<i-1;j++){   /*verifica numeros repetidos*/
        for(k=0;k<i-1;k++){
            if(k!=j){
                if(v3[j]==v3[k]){
                    v3[j]=0;   /*deleta numeros repetidos*/
                }
            }
        }
    }
    for(j=0;j<i-1;j++){   /*coloca em ordem crescente*/
        for(k=j+1;k<i;k++){
            if(v3[j]>v3[k]){
                q=v3[j];
                v3[j]=v3[k];
                v3[k]=q;
            }
        }
    }
    for(k=0;k<i;k++){
        if(v3[k]!=0){h++;} /*ver o tamanho de uniao*/
    }
    g=0;
    if(w==1){h++;}
    int x = h;
    int *uniao;
    uniao = (int*)malloc(x*sizeof(int));
    if(w==1){uniao[0]=0;g=1;}
    h=g;
    for(k=g;k<i;k++){
        if(v3[k]!=0){
            uniao[h]=v3[k];
            h++;
        }
    }
    if(w==1){printf("valor de uniao 0\n");}
    for(k=g;k<h;k++){
        if(uniao[k]!=0){
          printf("valor de uniao %d \n",uniao[k]);
        }
    }
    printf("\n");
    *p = x;
    return *p;
}
int main(void){
    int n, m;
    printf("Digite a Quantidade De Numeros em N: ");
    scanf("%d" , &n);
    printf("\n");
    printf("Digite a Quantidade De Numeros em M: ");
    scanf("%d",&m);
    int i, j;
    int v1[n], v2[m];
    for(i=0;i<n;++i){
        printf("%d - Elemento em v1 --> : ",i+1);
        scanf("%d", &v1[i]);
    }
    printf("\n");
    for(j=0;j<m;++j){
        printf("%d - Elemento em v2 --> : ", j+1);
        scanf("%d", &v2[j]);
    }
    int p;
    int* unir = uniao(v1,n,v2,m,p);
    printf("\n A uniao tera tamanho de %d", unir);
    getch();
    return 0;
}
