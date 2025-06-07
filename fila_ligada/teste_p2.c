#include "fila.h"
#include <time.h>

int main(){
    t_fila *fila1 = constroi_fila();
    t_fila *fila2 = constroi_fila();
    int a;
    srand(time(0));
    for(int i=0; i < 10; i++){
        if(rand() % 4 < 3){
            enfileira(rand() % 10, fila1);
        }
        else{
            desenfileira(&a, fila1);
        }
        if(rand() % 4 < 3){
            enfileira(rand() % 10, fila2);
        }
        else{
            desenfileira(&a, fila2);
        }
    }
    printf("Fila 1\n");
    mostra_fila(fila1);
    printf("\n\\\\\\\\\\\\\n");
    printf("Fila 2\n");
    mostra_fila(fila2);
    printf("\n\\\\\\\\\\\\\n");

    t_fila *par= constroi_fila();
    t_fila *impar = constroi_fila();
    
    printf("Fila Original\n");
    mostra_fila(fila1);
    printf("\n\\\\\\\\\\\\\\\\\\\n");
    par_impar(fila1, par, impar);
    printf("par\n");
    mostra_fila(par);
    printf("\n\\\\\\\\\\\\\\\\\\\\\n");
    printf("impar\n");
    mostra_fila(impar);
    printf("\n\\\\\\\\\\\\\\\\\\\n");

    if(esvazia_menor(fila1, fila2)){
        mostra_fila(fila1);
        mostra_fila(fila2);
    }else printf("fila não esvaziada\n");


    return 0;
}