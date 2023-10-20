#include<stdio.h>

int main() {

    int i, j;
    int linha, coluna;
    int scan_prat; // scan das colunas na linha em questão, olha as prateleiras da debaixo

    scanf("%d %d", &i, &j);

    char matriz[i][j];

    for(linha=0; linha<i; linha++) {
        for (coluna=0; coluna<j; coluna++) {

            scanf(" %c", &matriz[linha][coluna]);

        }    
    }

    for(linha=0; linha<i; linha++) {
        for (coluna=0; coluna<j; coluna++) {

            if((matriz[linha-1][coluna] == 'o') && (matriz[linha][coluna] != '#')) { //faz gota cair se tiver n tiver prateleira
                matriz[linha][coluna] = 'o';
            }

            if((matriz[linha+1][coluna] == '#') && (matriz[linha][coluna] == 'o')) { //gota cai p direita

                for(scan_prat=coluna; scan_prat<j; scan_prat++) {

                    if((matriz[linha+1][scan_prat]=='#') || ((matriz[linha+1][scan_prat-1]=='#'))) {
                        matriz[linha][scan_prat] = 'o';
                    }
                }
            }

            if((matriz[linha+1][coluna] == '#') && (matriz[linha][coluna] == 'o')) { //gota cai p esquerda

                for(scan_prat=coluna; (scan_prat>=0); scan_prat--) {

                    if((matriz[linha+1][scan_prat+1]=='#')) {
                        matriz[linha][scan_prat] = 'o';
                    }
                }
            }   
        }    
    }

        for(linha=0; linha<i; linha++) {
            printf("\n");
            for (coluna=0; coluna<j; coluna++) {

                printf("%c", matriz[linha][coluna]);

            }    
        }

    return 0;
}