#include <stdlib.h>
#include <stdio.h>


int main ( ){

int *p,i;

p= (int*)calloc(1500,sizeof(int));

for(i=0;i<1500;i++){

    printf("%d",p[i]);
}    
for(i=0;i<1500;i++){

   p[i]=i;
}   
for(i=0;i<10;i++){

  printf("%d",p[i]);

}  
for(i=1490;i<1500;i++){

  printf("%d",p[i]);
}  

free(p);
    return 0;
}
