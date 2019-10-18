#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  int main( ) {

char s[20];
int i,j;
char temp;

printf("Informe seu nome: ");
scanf("%s", s);

for(i = 0; i < strlen(s)-1; i++){
    for(j = 0; j < strlen(s)-i-1; j++){
        if(s[j]>s[j+1]){
            temp = s[j];
            s[j]= s[j+1];
            s[j+1] = temp;
}
}
}
 printf("Palavra ordenada: %s", s);

    return 0;
}
  