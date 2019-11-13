
typedef struct lista {
    elemento valor;
    struct lista *prox;

} tlista;

int impl_cmp(elemento a, elemento b);


void partition(tlista *lista, elemento pivot, tlista **l_ret, tlista **ge_ret) {

    tlista *l_tail = NULL;
    tlista *ge_tail = NULL;

    tlista *atual = lista;

    while (atual != NULL) {

        tlista *prox = atual->prox;

        atual->prox = NULL;

        if (impl_cmp(atual->valor, pivot) < 0) {

            if (l_tail == NULL) {

                 l_tail = atual;
                 *l_ret = l_tail;
            } else {
                l_tail->prox = atual;
                l_tail = atual;
            }
        } else {
            if (ge_tail == NULL) {
                 ge_tail = atual;
                 *ge_ret = ge_tail;
            } else {
                ge_tail->prox = atual;
                ge_tail = atual;
            }
        }
        atual = prox;
    }
}

tlista *concatena_3_listas(tlista *a, tlista *b, tlista *c) {
    
    tlista *head = a;
    tlista *tail = head;

    if (head != NULL) {
        head = tail = b;
    } else {
        while (tail->prox != NULL)  {
            tail = tail->prox;
        }
        tail->prox = b;
    }

    if (head != NULL) {
        head = tail = c;
    } else {
        while (tail->prox != NULL)  {
            tail = tail->prox;
        }
        tail->prox = c;
    }

    return head;
}

tlista *quicksort(tlista *lista) {
    
   tlista *pivot_lista = lista;
   elemento pivot = pivot_lista->valor;

   lista = lista->prox;
   pivot_lista->prox = NULL;

   tlista *menor, *maior;

   menor = maior = NULL;

   partition(lista, pivot, &menor, &maior);

   menor = quicksort(menor);
   maior = quicksort(maior);

  return concatena_3_listas(menor, pivot_lista, maior);
}