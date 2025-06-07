#include <stdio.h>
#include "C:\Users\Pichau\Documents\Ens_Fatec\Ativ\3sem_ESD\lista_ligada\no.h"

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
} t_fila;

t_fila * constroi_fila ();
int fila_vazia (t_fila *);
int enfileira (int, t_fila *);
int desenfileira (int *, t_fila *);
void mostra_fila (t_fila *);
void exibe_primeiro(t_fila *);
int devolve_primeiro(t_fila *);
void exibe_ultimo(t_fila *);
int devolve_ultimo(t_fila *);
int par_impar(t_fila *pf, t_fila *par, t_fila *impar);
int esvazia_menor(t_fila *, t_fila *);
