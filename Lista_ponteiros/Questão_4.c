#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char **str_pont=NULL, **pont_aux=NULL, str[100];
    int i=0; // indice do ponteiro duplo, ou seja, do vetor de ponteiros de array

    while (scanf(" %99[^\n]", str) != EOF) {

        pont_aux = str_pont;
        str_pont = (char **) realloc(pont_aux, ((i+1) * sizeof(char *))); // aumenta o vetor de ponteiros na media do necessario
        if(str_pont == NULL) { // caso haja um prblema, dados contuam apontados pelo pont_aux
            for(;i>=0; i--){
            free(pont_aux[i]);
            }
            free(pont_aux);
            printf("Erro de alocacao de memoria"); exit(1);
        }

        str_pont[i] = (char *) malloc(strlen(str)+1);
        if(str_pont[i] == NULL) {
            for(;i>=0; i--){
            free(pont_aux[i]);
            }
            free(pont_aux);
            printf("Erro de alocacao de memoria 2"); exit(1);
        }
        strcpy(str_pont[i], str);

        i++;
    }    
    i--; // i eh incrementado antes do EOF, ou seja, fica maior do que deveria em 1

    /*
    for (int j = 0; j < i; j++) { // esse for serve como um breakpoint e mostra que o codigo foi executado corretamente
        printf("- %s\n", str_pont[j]);
    }
    */
    
    for(;i>=0; i--){free(str_pont[i]); free(pont_aux[i]);}
    free(str_pont); free(pont_aux);
    
    return 0;
}