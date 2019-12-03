#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 
// Tamanho da tela em colunas (para impressão da árvore)
#define TELA 64
 

 
/* Estrutura de um nó */
struct no
{
    int chave;
    int nivel;      // Para impressão em gráfico
    int pos;        // Para impressão em gráfico
    struct no *p;
    struct no *e;
    struct no *d;
};
 
// Imprime a árvore graficamente
// A posição de cada elemento será relativa ao seu nível na árvore
// Por isso usa a equação (TELA / 2^(nivel + 2)) para determinar o quanto
// o elemento deve variar para cada lado
void imprime_graf(struct no *raiz){
      
    int nivel_ant = 0;      // Indica o nível do nó impresso anteriormente
    int pos_filho;          // Usado para calcular a posição do filho do nó atual
    int linha_pos = 0;      // Calcula quantas casas já foram movimentadas em uma linha
 
    // Inicializa o nível e a posição da raíz e insere na fila
    raiz->nivel = 0;
    raiz->pos = TELA / 2;
    
 
    // Enquanto houver elementos na fila, imprime!
    while (!fila.empty())
    {
        // Pega o primeiro elemento da fila
        struct no *temp = fila.front();
        fila.pop_front();
 
        // Se o nível deste novo elemento for maior que o do anterior, significa
        // que ele deve ficar na linha abaixo. Atualiza o nível e a posição
        // atual da linha
        if (temp->nivel > nivel_ant)
        {
            printf("\n");
            nivel_ant = temp->nivel;
            linha_pos = 0;
        }
 
        // Insere espaços até a posição de um provável filho que esse nó possa
        // ter à esquerda
        pos_filho = temp->pos - (TELA / pow(2, temp->nivel + 2));
        for (int i = linha_pos; i < pos_filho; i++)
            linha_pos += printf(" ");
 
        // Verifica se o elemento tem filho à esquerda. Se tiver, insere traços.
        // Caso contrário, insere espaços
        if (temp->e != NULL) linha_pos += printf("|");
        for (int i = linha_pos; i < temp->pos; i++)
            temp->e != NULL ? linha_pos += printf("-") : linha_pos += printf(" ");
 
        // Imprime o elemento atual e atualiza a posição na linha.
        linha_pos += printf("%d", temp->chave);
 
        // Verifica se o elemento tem filho à direita. Se tiver, posiciona no
        // local onde o filho será impresso abaixo e insere traços.
        if (temp->d != NULL)
        {
            pos_filho = temp->pos + (TELA / pow(2, temp->nivel + 2));
            for (int i = linha_pos; i < pos_filho; i++)
                linha_pos += printf("-");
            linha_pos += printf("|");
        }
 
        // Insere os filhos deste elemento na fila, armazenando suas posições.
        if (temp->e != NULL)
        {
            temp->e->nivel = temp->nivel + 1;
            temp->e->pos = temp->pos - (TELA / pow(2, temp->e->nivel + 1));
            fila.push_back(temp->e);
        }
 
        if (temp->d != NULL)
        {
            temp->d->nivel = temp->nivel + 1;
            temp->d->pos = temp->pos + (TELA / pow(2, temp->d->nivel + 1));
            fila.push_back(temp->d);
        }
    }
 
    printf("\n\n");
}
 
/* Cria um nó */
struct no *criar(int chave)
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));
    novo->chave = chave;
    novo->p = novo->e = novo->d = NULL;
}
 
/* Rotaciona nó para direita */
void girar_direita(struct no **raiz)
{
    struct no *temp             = *raiz;
    struct no *temp_esquerda    = (*raiz)->e;
    temp->e                     = temp_esquerda->d;
    temp_esquerda->d            = temp;
    temp_esquerda->p            = temp->p;
    temp->p                     = temp_esquerda;
    *raiz                       = temp_esquerda;
}
 
/* Rotaciona nó para esquerda */
void girar_esquerda(struct no **raiz)
{
    struct no *temp            = *raiz;
    struct no *temp_direita    = (*raiz)->d;
    temp->d                    = temp_direita->e;
    temp_direita->e            = temp;
    temp_direita->p            = temp->p;
    temp->p                    = temp_direita;
    *raiz                      = temp_direita;
}
 
/* Calcula a altura de uma árvore */
int altura(struct no *raiz)
{
    if(raiz == NULL)
        return 0;
 
    int e = altura(raiz->e);
    int d = altura(raiz->d);
    int m;
 
    if (e > d)
        m = e;
    else
        m = d;
 
    return m + 1;
}
 
 
/* Calcula o fator de balanceamento de um nó */
int balanceamento(struct no *raiz)
{
    return altura(raiz->d) - altura(raiz->e);
}
 
/*Percorre a árvore pelo método da pós-ordem em busca de nós desbalanceados */
void verificar_balanceamento(struct no **raiz)
{
    if ((*raiz) == NULL)
        return;
 
    verificar_balanceamento(&(*raiz)->e);
    verificar_balanceamento(&(*raiz)->d);
 
    if(balanceamento((*raiz)) == 2)
    {
        //Rotação a esquerda
        if(balanceamento((*raiz)->d) == -1)
            girar_direita(&(*raiz)->d);
        girar_esquerda(&(*raiz));
    }
    else if(balanceamento((*raiz)) == -2)
    {
        //Rotação a direita
        if(balanceamento((*raiz)->e) == 1)
            girar_esquerda(&(*raiz)->e);
        girar_direita(&(*raiz));
    }
}
 
/* Adiciona elemento na árvore */
struct no *adicionar(struct no *raiz, int chave)
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));
    if (raiz == NULL)
    {
        novo = criar(chave);
        return novo;
    }
 
    if (chave < raiz->chave)
    {
        novo = adicionar(raiz->e, chave);
        raiz->e = novo;
        novo->p = raiz;
    }
    else
    {
        novo = adicionar(raiz->d, chave);
        raiz->d = novo;
        novo->p = raiz;
    }
 
    verificar_balanceamento(&raiz);
 
    return raiz;
}
 
/* Busca um nó na árvore */
struct no *buscar(struct no *raiz, int chave)
{
    if(raiz == NULL)
        return NULL;
    if(raiz->chave == chave)
        return raiz;
 
    if(chave > raiz->chave)
        return buscar(raiz->d,chave);
    else
        return buscar(raiz->e,chave);
}
 
/* Imprime a árvore em ordem */
void emordem(struct no *raiz)
{
    if (raiz == NULL)
        return;
 
    emordem(raiz->e);
    printf("%d ",raiz->chave);
    emordem(raiz->d);
}
 
/* Imprime a árvore em pré-ordem */
void preordem(struct no *raiz)
{
    if (raiz == NULL)
        return;
 
    printf("%d ",raiz->chave);
    preordem(raiz->e);
    preordem(raiz->d);
}
 
/* Imprime a árvore em pós-ordem */
void posordem(struct no *raiz)
{
    if (raiz == NULL)
        return;
 
    posordem(raiz->e);
    posordem(raiz->d);
    printf("%d ",raiz->chave);
}
 
/* Retorna o mínimo de uma árvore */
struct no *minimo(struct no *raiz)
{
    if (raiz == NULL)
        return NULL;
 
    if (raiz->e == NULL)
        return raiz;
 
    return minimo(raiz->e);
}
 
/* Retorna o máximo de uma árvore */
struct no *maximo(struct no *raiz)
{
    if (raiz == NULL)
        return NULL;
 
    if (raiz->d == NULL)
        return raiz;
 
    return maximo(raiz->d);
}
 
/* Retorna o antecessor de um nó */
struct no *antecessor(struct no *raiz)
{
    if(raiz->e == NULL)
    {
        while(raiz->p != NULL && raiz->p->chave > raiz->chave  )
            raiz = raiz->p;
 
        return raiz->p;
    }
    return maximo(raiz->e);
}
 
/* Retorna o sucessor de um nó */
struct no *sucessor(struct no *raiz)
{
    if(raiz->d == NULL)
    {
        while(raiz->p != NULL && raiz->p->chave < raiz->chave  )
            raiz = raiz->p;
        return raiz->p;
    }
 
    return minimo(raiz->d);
 
}
 
/* Remove um nó da árvore e retorna a nova árvore */
struct no* remover(struct no *arvore, int chave)
{
    if(arvore == NULL)
        return NULL;
 
    struct no *raiz = buscar(arvore, chave);
 
    if (raiz == NULL)
        return arvore;
 
    // Remover NO sem Filhos
    if (raiz->e == NULL && raiz->d == NULL)
    {
        if(raiz->p != NULL)
        {
            if(raiz->p->chave >= raiz->chave)
                raiz->p->e = NULL;
            else
                raiz->p->d = NULL;
            free(raiz);
        }
        else
        {
            free(raiz);
            return NULL;
        }
        if (raiz == arvore)
            return NULL;
    }
    else
    {
        // Remover NO com 2 Filhos
        if (raiz->e && raiz->d != NULL)
        {
            struct no *ant = antecessor(raiz);
            raiz->chave = ant->chave;
            ant = remover(ant, ant->chave);
        }
        // Remover NO com 1 Filho
        else
        {
            // Reconectar Filho a Esquerda
            if(raiz->e != NULL)
            {
                if (raiz->p != NULL)
                {
                    if(raiz->p->chave > raiz->chave)    // Caso o pai seja maior
                        raiz->p->e = raiz->e;
                    else                                // Caso o pai seja menor
                        raiz->p->d = raiz->e;
                }
                raiz->e->p = raiz->p;
            }
            // Reconectar Filho a Direita
            else
            {
                if (raiz->p != NULL)
                {
                    if(raiz->p->chave < raiz->chave)    // Caso o pai seja menor
                        raiz->p->d = raiz->d;
                    else                                // Caso o pai seja maior
                        raiz->p->e = raiz->d;
                }
                raiz->d->p = raiz->p;
 
                free(raiz);
            }
        }
    }
 
    return arvore;
}
 
/* Função principal */
int main(void)
{
    struct no *arvore = NULL;
    int opt, chave;
 
    do
    {
        printf("==============================\n");
        printf("OPCOES:\n\n");
        printf("\t[1] Adicionar\n");
        printf("\t[2] Listar\n");
        printf("\t[3] Remover\n");
        printf("\t[0] Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &opt);
 
        switch(opt)
        {
        case 1:
            printf("\n\nDigite as chaves separadas por espacos, na ordem que deseja inserir, e pressione CTRL+D para finalizar: ");
            while (scanf("%d", &chave) != EOF)
                arvore = adicionar(arvore, chave);
            break;
 
        case 2:
            printf("==============================\n");
            printf("IMPRESSAO DA ARVORE:\n\n");
            printf("Em ordem:\n");
            emordem(arvore);
            printf("\n\n");
            printf("Pre ordem:\n");
            preordem(arvore);
            printf("\n\n");
            printf("Pos ordem:\n");
            posordem(arvore);
            printf("\n\n");
            printf("Grafico:\n");
            imprime_graf(arvore);
            break;
 
        case 3:
            printf("==============================\n");
            printf("Digite a chave a ser removida: ");
            scanf("%d", &chave);
            arvore = remover(arvore, chave);
            break;
 
        case 0:
            return 0;
 
        default:
            printf("Opcao invalida!\n\n");
        }
    } while(1);
 
    return 0;
}
