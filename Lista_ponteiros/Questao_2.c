#include<stdio.h>
#include<stdlib.h>

int main() {

    int vet[5] = {1,2,3,4,5};
    int *p;

    p = vet;

    printf("\na. O endereco guardado em vet e o endereco guardado em p.\n");
    printf("\tR: Endereco guardado em vet: %p\n\t   Endereco guardado em p: %p\n\n", &vet, p); // p == &*p

    printf("b. Todos os valores de vet utilizando p com [ ].\n\tR: ");
    for (int i = 0; i < 5; i++) {
        (i==0) ? printf("v[%d] = %d\n", i, p[i]) : printf("\t   v[%d] = %d\n", i, p[i]);
        // o ternario acima foi utilizado apenas para a formatacao do output
    }
    printf("\n");
    
    printf("c. Todos os valores de vet utilizando p com *.\n\tR: ");
    for (int i = 0; i < 5; i++) {
        (i==0) ? printf("v[%d] = %d\n", i, *(p+i)) : printf("\t   v[%d] = %d\n", i, *(p+i));
        // o ternario acima foi utilizado apenas para a formatacao do output
    }
    printf("\n");

    printf("d. Faca a mesma coisa de b. e c. utilizando vet no lugar de p.\n\tR: ");
        for (int i = 0; i < 5; i++) {
        (i==0) ? printf("v[%d] = %d\n", i, vet[i]) : printf("\t   v[%d] = %d\n", i, vet[i]);
        // o ternario acima foi utilizado apenas para a formatacao do output
    }
    printf("\n");

    return 0;
}