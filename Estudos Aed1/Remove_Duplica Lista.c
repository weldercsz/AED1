int Elemento* remove_duplicados(Elemento* agenda){
    Elemento* a;
    Elemento* p;
    Elemento* q;

    for(p = agenda; p != NULL; p = p -> prox ){
        a = NULL; //a cada varrimento a começa a NULL

        for(q = p -> prox; q != NULL; ){ //sem incremento
            if(0 == strcmp(p -> info.nome, q -> info.nome)){ //teste de igual
                if(a == NULL){ //remove do inicio
                    p -> prox = q -> prox;
                }
                else{ //ou do meio/fim
                    a -> prox = q -> prox;
                }

                Elemento* remover = q;
                q = q -> prox;
                free(remover);
            }
            else { //so atualiza o anterior quando não é igual
                a = q;
                q = q->prox;
            }
        }
    }

    return agenda;
}
