
#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE; // Tipo de ID de cada n� da lista

// Estrutura de dados que representa cada n� da lista
typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX* prox;
}NO, *PONT;

typedef struct{
	PONT cab; // N� cabe�a
}LISTA;

void inicializar(LISTA *L){
	// N� cabe�a n�o deixa a lista ficar vazia, tamb�m pode ser usado como sentinela
	L->cab = (PONT) malloc( sizeof(NO) );
	L->cab->prox = L->cab; // Come�a apontando para o pr�prio n�, pois � circular
}

// Como neste m�todo n�o ir� alterar a lista, pode ser passado uma c�pia dela e n�o necess�riamente um ponteiro para ela
PONT buscaSequencial(TIPOCHAVE ch, LISTA L, PONT* ant){
	*ant = L.cab; // Sendo uma c�pia pode-se usar o ponto (.) no lugar de seta (->), o ant guarda o ponteiro para o n� encontrado
	PONT pos = L.cab->prox;
	L.cab->chave = ch; // Grava o valor no n� cabe�a para ser utilizado como sentinela, ser� o �ltimo a ser comparado
	while(pos->chave != ch){ 
		*ant = pos; // Guarda o ponteiro para o n�
		pos = pos->prox; // Vai para o pr�ximo n�
	}
	if( pos != L.cab ) // Se o n� n�o � o n� cabe�a � pq encontrou
		return pos; // Retorna o n�
	else
		return NULL; // Sen�o n�o encontrou retorna NULL
}

bool excluir(TIPOCHAVE ch, LISTA *L){
	PONT aux, ant;
	aux = buscaSequencial(ch, *L, &ant); // Busca o valor para excluir, o ant � passado como endere�o de mem�ria, assim a fun��o busca altera ele, guardando o valor anterior
	if( aux == NULL ) return false; // N�o encontrou
	ant->prox = aux->prox; // N� anterior aponta para o pr�ximo, no caso o pr�ximo que o n� a ser exclu�do est� apontando
	free(aux); // Libera a mem�ria
	return true;
}

void inserir(TIPOCHAVE ch, LISTA *L){
	PONT ant = L->cab; // O ant guarda o ponteiro para o n� anterior
	PONT pos = L->cab->prox; // O pos guarda o ponteiro para o atual

	while(pos->chave < ch && pos != L->cab){
		ant = pos; // Guarda o ponteiro para o n� atual, que ser� o anterior
		pos = pos->prox; // Vai para o pr�ximo n�
	}
	// Quando encontrou a posi��o correta na ordem crescente
	PONT novo_no = (PONT) malloc( sizeof(NO) ); // Cria um novo n�
	novo_no->chave = ch; // Coloca a chave no n�
	novo_no->prox  = pos; // Aponta para o pr�ximo n�
	ant->prox = novo_no; // N� anterior aponta para o novo n�
}

PONT mostrarLista(LISTA L){
	PONT pos = L.cab->prox; // Pos recebe o primeiro elemento depois do n� cabe�a
	while(pos != L.cab){ // Se n�o for o n� cabe�a, a lista n�o est� vazia
		printf("[ %d ]->", pos->chave); // Mostra o valor do n�
		pos = pos->prox; // Vai para o pr�ximo n�
	}printf("\n");
}

int main(){
	
	LISTA lista;
	inicializar(&lista);

	inserir(4, &lista);
	inserir(6, &lista);
	inserir(2, &lista);
	inserir(3, &lista);
	inserir(1, &lista);
	inserir(5, &lista);

	mostrarLista(lista);

	excluir(2, &lista);
	excluir(4, &lista);
	excluir(6, &lista);

	mostrarLista(lista);

	// Exemplo de busca na lista
	PONT aux;
	int valor = 2;
	if( buscaSequencial(valor, lista, &aux) != NULL )
		printf("Valor %d encontrado.\n", valor );
	else
		printf("Valor %d n�o encontrado.\n", valor);

	return 0;
}

