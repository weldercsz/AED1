// Nao se preocupem com isso
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

#define TESTCASE1 "011101010111011010101001011101101000101100\0"
#define RESULT1 "ESTRUTURA"
#define TESTCASE2 "0001100000111001010\0"
#define RESULT2 "DADOS"
#define TESTCASE3 "1000011110010111010001010000001001100\0"
#define RESULT3 "AVALIACAO"
#define TESTCASE4 "0011000010110110010111010\0"
#define RESULT4 "FINAL"
#define TESTCASE5 "10100110011010111010101110110101011\0"
#define RESULT5 "SEMESTRE"
#define TESTCASE6 "\0"
#define RESULT6 ""

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nodo da Arvore
struct Nodo
{
    char c;
    struct Nodo *zero;
    struct Nodo *um;
};

// Arvore
struct HuffTree
{
    struct Nodo *raiz;
};

typedef struct Nodo Nodo;
typedef struct HuffTree HuffTree;

// Cria uma arvore de Huffman
HuffTree *criarArvore()
{
    return (HuffTree *)malloc(sizeof(HuffTree));
}

// Inicializa arvore de Huffman
void initArvore(HuffTree *arvore)
{
    arvore->raiz = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->c = '-';
    arvore->raiz->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->c = '-';
    arvore->raiz->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->c = '-';
    arvore->raiz->zero->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->zero->c = '-';
    arvore->raiz->zero->zero->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->zero->zero->c = 'C';
    arvore->raiz->zero->zero->zero->zero->zero = NULL;
    arvore->raiz->zero->zero->zero->zero->um = NULL;
    arvore->raiz->zero->zero->zero->um->c = 'D';
    arvore->raiz->zero->zero->zero->um->zero = NULL;
    arvore->raiz->zero->zero->zero->um->um = NULL;
    arvore->raiz->zero->zero->um->c = '-';
    arvore->raiz->zero->zero->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->zero->c = 'I';
    arvore->raiz->zero->zero->um->zero->zero = NULL;
    arvore->raiz->zero->zero->um->zero->um = NULL;
    arvore->raiz->zero->zero->um->um->c = '-';
    arvore->raiz->zero->zero->um->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->um->um->c = 'V';
    arvore->raiz->zero->zero->um->um->um->zero = NULL;
    arvore->raiz->zero->zero->um->um->um->um = NULL;
    arvore->raiz->zero->zero->um->um->zero->c = '-';
    arvore->raiz->zero->zero->um->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->zero->um->um->zero->zero->c = 'F';
    arvore->raiz->zero->zero->um->um->zero->zero->zero = NULL;
    arvore->raiz->zero->zero->um->um->zero->zero->um = NULL;
    arvore->raiz->zero->zero->um->um->zero->um->c = 'M';
    arvore->raiz->zero->zero->um->um->zero->um->zero = NULL;
    arvore->raiz->zero->zero->um->um->zero->um->um = NULL;
    arvore->raiz->zero->um->c = '-';
    arvore->raiz->zero->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->um->um->c = 'E';
    arvore->raiz->zero->um->um->zero = NULL;
    arvore->raiz->zero->um->um->um = NULL;
    arvore->raiz->zero->um->zero->c = '-';
    arvore->raiz->zero->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->zero->um->zero->zero->c = 'U';
    arvore->raiz->zero->um->zero->zero->zero = NULL;
    arvore->raiz->zero->um->zero->zero->um = NULL;
    arvore->raiz->zero->um->zero->um->c = 'R';
    arvore->raiz->zero->um->zero->um->zero = NULL;
    arvore->raiz->zero->um->zero->um->um = NULL;
    arvore->raiz->um->c = '-';
    arvore->raiz->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->c = '-';
    arvore->raiz->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->zero->c = 'A';
    arvore->raiz->um->zero->zero->zero = NULL;
    arvore->raiz->um->zero->zero->um = NULL;
    arvore->raiz->um->zero->um->c = '-';
    arvore->raiz->um->zero->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->zero->c = 'S';
    arvore->raiz->um->zero->um->zero->zero = NULL;
    arvore->raiz->um->zero->um->zero->um = NULL;
    arvore->raiz->um->zero->um->um->c = '-';
    arvore->raiz->um->zero->um->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->c = '-';
    arvore->raiz->um->zero->um->um->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->um->c = 'G';
    arvore->raiz->um->zero->um->um->um->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->zero->c = '-';
    arvore->raiz->um->zero->um->um->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->zero->zero->c = 'Z';
    arvore->raiz->um->zero->um->um->um->zero->zero->zero = NULL;
    arvore->raiz->um->zero->um->um->um->zero->zero->um = NULL;
    arvore->raiz->um->zero->um->um->um->zero->um->c = '-';
    arvore->raiz->um->zero->um->um->um->zero->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->zero->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->um->zero->um->zero->c = 'L';
    arvore->raiz->um->zero->um->um->um->zero->um->zero->zero = NULL;
    arvore->raiz->um->zero->um->um->um->zero->um->zero->um = NULL;
    arvore->raiz->um->zero->um->um->um->zero->um->um->c = 'T';
    arvore->raiz->um->zero->um->um->um->zero->um->um->zero = NULL;
    arvore->raiz->um->zero->um->um->um->zero->um->um->um = NULL;
    arvore->raiz->um->zero->um->um->zero->c = '-';
    arvore->raiz->um->zero->um->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->zero->um->um->zero->zero->c = 'Q';
    arvore->raiz->um->zero->um->um->zero->zero->zero = NULL;
    arvore->raiz->um->zero->um->um->zero->zero->um = NULL;
    arvore->raiz->um->zero->um->um->zero->um->c = 'P';
    arvore->raiz->um->zero->um->um->zero->um->zero = NULL;
    arvore->raiz->um->zero->um->um->zero->um->um = NULL;
    arvore->raiz->um->um->c = '-';
    arvore->raiz->um->um->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->um->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->um->um->c = ' ';
    arvore->raiz->um->um->um->zero = NULL;
    arvore->raiz->um->um->um->um = NULL;
    arvore->raiz->um->um->zero->c = '-';
    arvore->raiz->um->um->zero->zero = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->um->zero->um = (Nodo *)malloc(sizeof(Nodo));
    arvore->raiz->um->um->zero->zero->c = 'O';
    arvore->raiz->um->um->zero->zero->zero = NULL;
    arvore->raiz->um->um->zero->zero->um = NULL;
    arvore->raiz->um->um->zero->um->c = 'N';
    arvore->raiz->um->um->zero->um->zero = NULL;
    arvore->raiz->um->um->zero->um->um = NULL;
}

// Decodifica uma sequencia de entrada de acordo com a arvore de Huffman passada como argumento
char *decodificar(Nodo *raiz, char *entrada){
    char *resultado;
    Nodo *busca;
    int i = 0, j = 0, c = 0;
    resultado = (char *)malloc(sizeof(char) * c);
    busca = raiz;

    do
    {
        if (entrada[i] == '1'){
        
            busca = busca->um;

        }
        else if(entrada[i] == '0'){
        
            busca = busca->zero;

        }
        if (busca->c != '-'){

            c++;
            resultado = realloc(resultado,(char )(sizeof(char) * c));
            resultado[j] = busca->c;
            j++;
            busca = raiz;

        }
    i++;
    }while(entrada[i] != '\0');

    return resultado;
}

int main()
{
    HuffTree *tree = criarArvore();
    initArvore(tree);

    char *resultado;

    printf("---Testes de Validacao---\n");
    printf("1. ");
    resultado = decodificar(tree->raiz, TESTCASE1);
    if (strcmp(RESULT1, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT1);
    }
    free(resultado);

    printf("2. ");
    resultado = decodificar(tree->raiz, TESTCASE2);
    if (strcmp(RESULT2, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT2);
    }
    free(resultado);

    printf("3. ");
    resultado = decodificar(tree->raiz, TESTCASE3);
    if (strcmp(RESULT3, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT3);
    }
    free(resultado);

    printf("4. ");
    resultado = decodificar(tree->raiz, TESTCASE4);
    if (strcmp(RESULT4, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT4);
    }
    free(resultado);

    printf("5. ");
    resultado = decodificar(tree->raiz, TESTCASE5);
    if (strcmp(RESULT5, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT5);
    }
    free(resultado);

    printf("6. ");
    resultado = decodificar(tree->raiz, TESTCASE6);
    if (strcmp(RESULT6, resultado) == 0)
    {
        printf(GREEN " PASS!\n" RESET);
    }
    else
    {
        printf(RED "FAIL. %s != %s\n" RESET, resultado, RESULT6);
    }
    free(resultado);

    return 0;
}
