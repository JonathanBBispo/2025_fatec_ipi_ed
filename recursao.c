#include <stdio.h>


long fat_iterativo (int n) { // iterativo para verificar limite do inteiro
    long f = 1;
    // for (int i = 2; i <= n; i++)
    //     f = f * i;
    while (n > 1)
        f = f * n--;
    return f;
}


long fat_recursivo(int n){
    if (n <= 1) return 1;
    return n * fat_recursivo(n - 1);
}


long fibonacci(int n) {
    if (n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}


void exibe_1_a_n_rec (int i, int n) {
    printf("%d ", i);
    if (i < n) exibe_1_a_n_rec (i+1, n);
}


void exibe_1_a_n_rec2 (int i, int n) {
    if (i < n) exibe_1_a_n_rec2 (i+1, n);
    printf("%d ", i);
}


void exibe_1_a_n_rec3 (int n) {
    printf("%d ", n);
    if (n > 1) exibe_1_a_n_rec3 (n - 1);
}


void exibe_1_a_n_rec4 (int n) {
    if (n > 1) exibe_1_a_n_rec4 (n - 1);
    printf("%d ", n);
}


int main () {
    for(int i = 0; i <= 13; i++) {
        printf("fatorial de %d: %.0ld\n", i, fat_iterativo(i));
    }
    for(int i = 0; i <= 13; i++) {
        printf("fatorial de %d: %.0ld\n", i, fat_recursivo(i));
    }
    for(int i = 0; i <= 13; i++)
        printf("fibonacci em %d = %0.ld\n", i, fibonacci(i));


    printf("\n");
    exibe_1_a_n_rec(1, 5);
    printf("\n");
    exibe_1_a_n_rec2(1, 5);
    printf("\n");
    exibe_1_a_n_rec3(5);
    printf("\n");
    exibe_1_a_n_rec4(5);
    return 0;
}
