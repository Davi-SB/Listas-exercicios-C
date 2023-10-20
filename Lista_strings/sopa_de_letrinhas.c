#include<stdio.h>
#include<string.h>

int main() {

	char vet_sopa[30]={};
    char vet_tirado_sopa[30]={};
    int N=0, cont_print=0;
    char vet_palavras[N][50];
    unsigned int letra_encontrada=0;

    scanf(" %s", vet_sopa);
    scanf("%d", &N);

    for (int i=0; i<N; i++) { // escaneia as palavras
        scanf(" %s", vet_palavras[i]);
    }
    
    for (int i=0; i<N; i++) { // esse for vai passar por cada palavra e procurar ela na sopa
        
        //procurar letras em comum

        for (unsigned int j = 0; j < strlen(vet_palavras[i]); j++) { // uma palavra
            for (unsigned int k = 0; k < strlen(vet_sopa); k++) { // passa por todas as letras
                
                if(vet_palavras[i][j] == vet_sopa[k]){ 
                    letra_encontrada++; 
                    vet_tirado_sopa [k]= vet_sopa[k]; // forma de evitar uma letra ser contada duas vezes
                    vet_sopa[k]= '@';
                }
            }

            if(letra_encontrada == strlen(vet_palavras[i])) { 

                cont_print++;

            }
            else { // devolver as palavras da matriz tirado para a sopa

                for (unsigned int w = 0; w < strlen(vet_tirado_sopa); w++) {
                    if(vet_tirado_sopa[w] != '@') {
                        vet_sopa[w] = vet_tirado_sopa[w];
                        vet_tirado_sopa[w] = '@';
                    }
                }
            }

            letra_encontrada=0;

        }
    }
    
    printf("E possivel formar %d palavras com esse conjunto\n", cont_print);

	return 0;
}