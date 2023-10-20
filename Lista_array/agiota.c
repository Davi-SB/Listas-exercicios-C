#include<stdio.h>

int main() {

    int matriz[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int n=20; //enésima entrada
    int linha=0, coluna=0;
    char dir; // direcao
    int maior_num=0;
    int x, y;

    while(n>0) {

        scanf(" %c", &dir);

        if(dir == 'c') {

            linha--;
            matriz[linha][coluna]++;

        }
        else if(dir == 'b') {

            linha++;
            matriz[linha][coluna]++;

        }
        else if(dir == 'e') {

            coluna--;
            matriz[linha][coluna]++;

        }
        else if(dir == 'd') {

            coluna++;
            matriz[linha][coluna]++;

        }
        n--;
    }

    /*for(linha=0; linha<4; linha++) {
        printf("\n");
        for(coluna=0; coluna<4; coluna++) {

            printf("%d ", matriz[linha][coluna]);

        }
    }*/

    for(linha=0; linha<4; linha++) {
        for(coluna=0; coluna<4; coluna++) {

            if(maior_num<matriz[linha][coluna]) {
                maior_num = matriz[linha][coluna];
                x=coluna;
                y=linha;
            }

        }
    }

    /*for(linha=0; linha<4; linha++) {
        for(coluna=0; coluna<4; coluna++) {

            if(maior_num==matriz[linha][coluna]) {
                x=coluna;
                y=linha;
            }
        }
    }*/

    printf("Coordenada X:%d, Y:%d", x, y);

    return 0;
}