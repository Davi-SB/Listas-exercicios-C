#include<stdio.h>
#include<string.h>

int main() {

    // declarar e receber a quantidade de senhas

    int qtd; // primeira entrada, numero de senhas a serem inseridas, tamanho do vetor principal
    scanf("%d", &qtd);
    int tam = qtd*2; // tamanho do vetor principal contando com os hifens

    // declarar variáveis

    char vet[tam][100]; // 100 não foi especificado pela questão, limite arbitrario
    char srt_aux[100]={};
    int flag_maxima=0;
    int cont=0;

    // receber senhas. vai ser tudo um vetor de strings, cada senha será um termo
    // antes de ir para o vetor principal, oa senha vai pra uma string intermediaria que já acusa uma flag em caso de senha invalida e criptografa
    // o vetor já começa com um '-' e a cada checagem, adiciona outro

    for (int i = 0; i < tam; i++) {
        strcpy(vet[i], "-"); i++;

        scanf(" %99[^\n]", srt_aux);

        for (unsigned int j = 0; j < strlen(srt_aux); j++) {

            cont++;

            if(srt_aux[j]<'A' || srt_aux[j]>'Z') {

                if(srt_aux[j]<'0' || srt_aux[j]>'9') {

                    flag_maxima=1;
                }
            }

                if(srt_aux[j]=='0') srt_aux[j]='6';
                else if(srt_aux[j]=='1') srt_aux[j]='7';
                else if(srt_aux[j]=='2') srt_aux[j]='9';
                else if(srt_aux[j]=='3') srt_aux[j]='8';
                else if(srt_aux[j]=='4') srt_aux[j]='A';
                else if(srt_aux[j]=='5') srt_aux[j]='2';
                else if(srt_aux[j]=='6') srt_aux[j]='B';
                else if(srt_aux[j]=='7') srt_aux[j]='F';
                else if(srt_aux[j]=='8') srt_aux[j]='1';
                else if(srt_aux[j]=='9') srt_aux[j]='C';
                else if(srt_aux[j]=='A') srt_aux[j]='0';
                else if(srt_aux[j]=='B') srt_aux[j]='D';
                else if(srt_aux[j]=='C') srt_aux[j]='E';
                else if(srt_aux[j]=='D') srt_aux[j]='3';
                else if(srt_aux[j]=='E') srt_aux[j]='5';
                else if(srt_aux[j]=='F') srt_aux[j]='4';
        }

        strcpy(vet[i], srt_aux);
    }

    if(flag_maxima) printf("Alguma senha eh invalida!\n"); // essa quebra de linha não é dita na questão, talvez de erro!!!!!!!!!!!!!!!!!
    else {

        for (int i = 0; i < tam; i++) {
            printf("%s", vet[i]);
        }

        printf(" %d", cont);
    }

    return 0;
}