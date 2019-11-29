// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Insertionsort (int data[], int n) { 
	int tmp,i,j;
	for (j=1; j<n; j++) { 
		i =j - 1;
		tmp = data[j]; 
		while ( (i>=0) && (tmp < data[i]) ) { 
			data[i+1] = data[i];
			 i--; 
		}//while

		data[i+1] = tmp; 
	}//for
 }//Insertionsort


// mediana : recebe um vetor desordenado e seu tamanho e retorna o valor da mediana dos valor. Assuma que o tamanho eh sempre impar.
int mediana(int * vetor, int tamanho) {
	int *p, i;
	
	p= malloc(tamanho * sizeof(int));
	
	for(i=0 ; i<tamanho ; i++){
		p[i]=vetor[i];
		}
		
	Insertionsort (vetor, tamanho);
	 
    
    free(p);
    return vetor[tamanho / 2];
}

// numNotificacoes : recebe um vetor, seu tamanho e o tamanho do intervalo. 
// Retorna o numero de notificacoes que o cliente ira receber segundo o criterio estabelecido na especificacao do problema
int numNotificacoes(int * vetor, int tamanho, int intervalo) {
    int *vetIntervalo, *Mediana, resultado = 0;
    
    vetIntervalo= malloc(intervalo * sizeof(int));
      
		int i,j, testes, dobro;
		
		testes = tamanho - intervalo + 1;
		
		Mediana= malloc(testes * sizeof(int));
		
		int dias =0;
		
		for(j=0 ; j< testes; j++){
			for(i=0 ; i<intervalo ; i++){
				vetIntervalo[i]= vetor[i + dias];
			}
		
			Mediana[j] = mediana(vetIntervalo, intervalo); // Foi utilizado o insertion sort na mediana, pois é de fácil implementação e também é melhor que um bublesort por exemplo.
			dias= dias + 1;
		}
		
		for (i=0; i< testes ; i++){
			dobro = 2* Mediana[i];
			
			if(dobro <= Mediana[i+1]){
				resultado= resultado + 1;
				}
			}
			resultado= resultado +1;
			
			free(vetIntervalo);
			free(Mediana);

    return resultado;
}

int main() {
    int tamanho, intervalo, resultado;
    int * vetor;

    printf("---Testes de Validacao---\n");
    printf("1. ");

    tamanho = 9;
    intervalo = 5;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 2;
    vetor[1] = 3;
    vetor[2] = 4;
    vetor[3] = 2;
    vetor[4] = 3;
    vetor[5] = 6;
    vetor[6] = 8;
    vetor[7] = 4;
    vetor[8] = 5;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 2\n" RESET, resultado);
    }
    free(vetor);

    printf("2. ");

    tamanho = 5;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 4;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 0) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 0\n" RESET, resultado);
    }
    free(vetor);

    printf("3. ");

    tamanho = 12;
    intervalo = 7;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 17;
    vetor[1] = 23;
    vetor[2] = 44;
    vetor[3] = 11;
    vetor[4] = 3;
    vetor[5] = 17;
    vetor[6] = 31;
    vetor[7] = 55;
    vetor[8] = 12;
    vetor[9] = 91;
    vetor[10] = 47;
    vetor[11] = 19;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);

    printf("4. ");

    tamanho = 27;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = (i * 4) + 1;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 1\n" RESET, resultado);
    }
    free(vetor);

    printf("5. ");

    tamanho = 12;
    intervalo = 1;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = i * i;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);
    
    printf("resultado : %d", resultado);

    return 0;
}
