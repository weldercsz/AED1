#include <stdio.h>
#include <stdlib.h>

int main(){
    
int v, *p, **pp, ***ppp;
v = 10;
p = &v;
pp = &p;
ppp= &pp;

scanf("%d" ,**pp);
printf("%d" ,***ppp);
printf("%d", v);

    return 0;
}