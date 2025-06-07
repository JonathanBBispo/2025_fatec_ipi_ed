#include "fila.h"

t_fila * constroi_fila (){
    t_fila * pf = (t_fila *) malloc (sizeof(t_fila));
    pf->primeiro = NULL;
    pf->ultimo = NULL;
    return pf;
}

int fila_vazia (t_fila *pf){
    return pf->primeiro == NULL;
}

int enfileira (int i, t_fila *pf){
    t_no * novo = constroi_no(i);
    if(novo ==NULL){ //alocação de memória falhou
        return 0;
    }
    if(fila_vazia(pf)){
        pf->primeiro = novo;
    }
    else{
        pf->ultimo->prox = novo;    
    }
    pf->ultimo = novo;
    return 1;
}

int desenfileira (int *i, t_fila *pf){
    if(fila_vazia(pf)) return 0;
    *i = pf->primeiro->info;
    t_no * aux = pf->primeiro;
    pf->primeiro = pf->primeiro->prox;
    if(pf->primeiro == NULL){  //esvaziou a fila
        pf->ultimo = NULL;
    }
    free(aux);
    return 1;
}

void mostra_fila (t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!\n");
    }
    else{
        t_no * aux = pf->primeiro;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

void exibe_primeiro(t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!\n");
    }
    else{
        printf("%d\n", pf->primeiro->info);
    }
}

int devolve_primeiro(t_fila *pf){
    if(fila_vazia(pf)){
        return -1;
    }
    return pf->primeiro->info;
}

void exibe_ultimo(t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!\n");
    }
    else{
        printf("%d\n", pf->ultimo->info);
    }
}

int devolve_ultimo(t_fila *pf){
    if(fila_vazia(pf)){
        return -1;
    }
    return pf->ultimo->info;
}

int par_impar(t_fila *pf, t_fila *par, t_fila *impar){
    if(fila_vazia(pf)) return 0;

    t_no * aux = pf->primeiro;
    while(aux != NULL){
        if(aux->info % 2 == 0) enfileira(aux->info, par);
        else enfileira(aux->info, impar);
        aux = aux->prox;
    }

    return 1;
}

int esvazia_menor(t_fila *pf1, t_fila *pf2){
    if(fila_vazia(pf1) || fila_vazia(pf2)) return 0;

    int i1 = 0, i2 = 0;
    
    t_no * aux = pf1->primeiro;
    while(aux != NULL){
        i1++;
        aux = aux->prox;
    }
    aux = pf2->primeiro;
    while(aux != NULL){
        i2++;
        aux = aux->prox;
    }

    int valor;
    if(i1 > i2){
        while(desenfileira(&valor, pf2))
            enfileira(valor, pf1);
    }
    else{
        while(desenfileira(&valor, pf1))
            enfileira(valor, pf2);
    }
    return 1;
}