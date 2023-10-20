#include<stdio.h>

int main() {

    int Ai, Aj, Bi, Bj;

    scanf("%d %d %d %d", &Ai, &Aj, &Bi, &Bj);

    int matriz_A[Ai][Aj];
    int matriz_B[Bi][Bj];
    int matriz_final[Ai][Bj];
    int linha=0, coluna=0;
    int cf=0; // celula_final
    

    if((Bi != Aj) || (Ai != Bj)) {
        printf("Nao e possivel multiplicar\n");
    }
    else {
    for(linha=0; linha<Ai; linha++) {
        for(coluna=0; coluna<Aj; coluna++) {

            scanf("%d", &matriz_A[linha][coluna]);

        }
    }

    for(linha=0; linha<Bi; linha++) {
        for(coluna=0; coluna<Bj; coluna++) {

            scanf("%d", &matriz_B[linha][coluna]);

        }
    }

    for(linha=0; linha<Ai; linha++) {
        for(coluna=0; coluna<Bj; coluna++) {

            matriz_final[linha][coluna]=0;

        }
    }

    for(linha=0; linha<Ai; linha++) {
        for(coluna=0; coluna<Bj; coluna++) {
            for(cf=0; cf<Aj; cf++) { // Aj ou Bi

                matriz_final[linha][coluna] += matriz_A[linha][cf] * matriz_B[cf][coluna];

            }
        }
    }

    for(linha=0; linha<Ai; linha++) {
        printf("\n");
        for(coluna=0; coluna<Bj; coluna++) {

            printf("%d ", matriz_final[linha][coluna]);

        }
    }
    }

    return 0;
}