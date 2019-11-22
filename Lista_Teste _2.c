// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#define TESTCASE1 "<..><.<..>>\0"
#define RESULT1 3
#define TESTCASE2 "<<<..<......<<<<....>\0"
#define RESULT2 1
#define TESTCASE3 "....<...<.\0"
#define RESULT3 0
#define TESTCASE4 "\0"
#define RESULT4 0
#define TESTCASE5 "<><><><<>><<\0"
#define RESULT5 5
#define TESTCASE6 "...<<<...<...><.<...<....<...>>.>.<....>..>.....>.....>.>...<<<...<...><.<...<...<....>>.>.<....>..>.....>.....>.>...<<<...<...><.<...<.....<..>>.>.<....>..>.....>.....>.>\0"
#define RESULT6 27
#define TESTCASE7 "....<...<...<.<<..><<...<.<\0"
#define RESULT7 1
#define TESTCASE8 ">...>..>..........>>.......>..>.>\0"
#define RESULT8 0
#define TESTCASE9 "..<..>....<..>....<..>....<..>....<..>....<..>....<..>..\0"
#define RESULT9 7
#define TESTCASE10 "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\0"
#define RESULT10 43

#include <stdio.h>
#include <stdlib.h>

// Nodo da Pilha
struct Nodo {
    struct Nodo * prox;
    char c;
};

// Pilha
struct Pilha {
    struct Nodo * topo;
};

typedef struct Pilha Pilha;
typedef struct Nodo Nodo;

// Retorna 1 se a pilha estiver vazia, 0 caso contrario
int isEmpty(Pilha * pilha) {
    if (pilha->topo)
        return 0;
    return 1;
}

// Insere elemento no topo da pilha
void push(Pilha * pilha, char elemento) {
    // SEU CODIGO AQUI
    Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
    novo->c=elemento;
    novo->prox=pilha->topo;
    pilha->topo=novo;

}

// Remove elemento do topo da pilha, se a pilha nao estiver vazia
void pop(Pilha * pilha) {
    if (!isEmpty(pilha)) {
        Nodo * remover = pilha->topo;
        pilha->topo = remover->prox;
        free(remover);
    }
}

// Retorna valor do topo da pilha, se a pilha nao estiver vazia
Nodo * top(Pilha * pilha) {
    if (isEmpty(pilha))
        return NULL;
    return pilha->topo;
}

// Remove todos os elementos da pilha
void clear(Pilha * pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

// Retorna o numero de diamantes em uma string de entrada
int qttDiamantes(Pilha *p, char * entrada) {
    // SEU CODIGO AQUI

return 0;
}

int main() {
    // INICIALIZAR PILHA AQUI
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));
    int resultado;

    printf("---Testes de Validacao---\n");
    printf("1. ");
    resultado = qttDiamantes(p, TESTCASE1);
    if (resultado == RESULT1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT1 );
    }
    clear(p);

    printf("2. ");
    resultado = qttDiamantes(p, TESTCASE2);
    if (resultado == RESULT2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT2);
    }
    clear(p);

    printf("3. ");
    resultado = qttDiamantes(p, TESTCASE3);
    if (resultado == RESULT3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT3);
    }
    clear(p);

    printf("4. ");
    resultado = qttDiamantes(p, TESTCASE4);
    if (resultado == RESULT4) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT4);
    }
    clear(p);

    printf("5. ");
    resultado = qttDiamantes(p, TESTCASE5);
    if (resultado == RESULT5) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT5);
    }
    clear(p);

    printf("6. ");
    resultado = qttDiamantes(p, TESTCASE6);
    if (resultado == RESULT6) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT6);
    }
    clear(p);

    printf("7. ");
    resultado = qttDiamantes(p, TESTCASE7);
    if (resultado == RESULT7) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT7);
    }
    clear(p);

    printf("8. ");
    resultado = qttDiamantes(p, TESTCASE8);
    if (resultado == RESULT8) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT8);
    }
    clear(p);

    printf("9. ");
    resultado = qttDiamantes(p, TESTCASE9);
    if (resultado == RESULT9) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT9);
    }
    clear(p);

    printf("10. ");
    resultado = qttDiamantes(p, TESTCASE10);
    if (resultado == RESULT10) {
        printf(GREEN "PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT10);
    }
    clear(p);

    return 0;
}
