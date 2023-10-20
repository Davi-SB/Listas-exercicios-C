#include<stdio.h>
#include<stdlib.h>

int main() {

    char c = 'a';
    char *pc;

    pc = &c; // pc ponta para c

    printf("\na. O endereco de c e o valor guardado por ele.\n");
    printf("\tR: Endereco: %p\n\t   Valor guardado por ele: %c\n\n", &c, c);

    printf("b. O valor que pc armazena e o valor guardado no endereco apontado por ele.\n");
    printf("\tR: Valor que pc armazena: %p\n\t   Valor guardado no endereco apontado: %c\n\n", pc, *pc);

    printf("c. O endereco de pc\n");
    printf("\tR: Endereco de pc: %p\n\n", &pc);

    printf("d. O endereco do valor guardado no endereco apontado por pc e o valor guardado no endereco de pc (utilize &*p e *&p), explicando por que os valores sao iguais.\n");
    printf("\tR: Endereco do valor guardado no endereco apontado por pc: %p\n\t   Valor guardado no endereco de pc: %p\n\tOs valores em questao sao iguais visto que um ponteiro eh, essencialmente, um endereco de memoria. O endereco do valor guardado no endereco apontado por pc eh simplesmente o endereco de c, bem como o valor de pc, um ponteiro, endereco de memoria\n\n", &*pc, *&pc);

    return 0;
}