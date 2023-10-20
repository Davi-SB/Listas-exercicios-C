#include<stdio.h>

int main() {

    int i=0; // i = N
    int j=7;
    scanf("%d", &i);
    char mat[i][j+1];
    int linha=0, coluna=0;
    int contL=0, contN=0; // Letra e numero
    int cont_corretas=0;

    for (linha=0; linha<i; linha++) {
        for(coluna=0; coluna<j; coluna++) {

            scanf(" %c", &mat[linha][coluna]);

            if((mat[linha][coluna]>='A') && (mat[linha][coluna]<='Z')) contL++;
            else if((mat[linha][coluna]>='0') && (mat[linha][coluna]<='9')) contN++;
        }

        if(contL==3 && contN==4) {
            mat[linha][7]='1';
            cont_corretas++;
        }
        else mat[linha][7]='0';

        contL=0;
        contN=0;

    }

    printf("%d placas:\n", cont_corretas);

    for (linha=0; linha<i; linha++) {

        if(mat[linha][7]=='1') {

            for(coluna=0; coluna<j; coluna++) {

                printf("%c", mat[linha][coluna]);

            }

            printf("\n");

        }
    }

    printf("%d erros:\n", i-cont_corretas);

    for (linha=0; linha<i; linha++) {

        if(mat[linha][7]=='0') {

            for(coluna=0; coluna<j; coluna++) {

                printf("%c", mat[linha][coluna]);

            }

            printf("\n");

        }
    }

    /*for (linha=0; linha<i; linha++) {
        printf("\n");
        for(coluna=0; coluna<j+1; coluna++) {

            printf("%4c", mat[linha][coluna]);

        }
    }*/
    

    return 0;
}