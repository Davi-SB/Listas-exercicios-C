#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[30];
    char tipo[10];
    float ataque;
    float defesa;
    float f_vantagem;
} Pokemon;

int main() {

    int n, br_eak=0;
    Pokemon inimigo;
    scanf(" %s%s%f%f%d", inimigo.nome, inimigo.tipo, &inimigo.ataque, &inimigo.defesa, &n);

    Pokemon lista[n];
    Pokemon aux;

    for (int i = 0; i < n; i++) {
        scanf(" %s%s%f%f", lista[i].nome, lista[i].tipo, &lista[i].ataque, &lista[i].defesa);

        if(!strcmp(lista[i].tipo,"agua") && !strcmp(inimigo.tipo,"fogo")) lista[i].ataque *= 1.5;
        if(!strcmp(lista[i].tipo,"grama") && !strcmp(inimigo.tipo,"agua")) lista[i].ataque *= 1.5; // se o de ash tem vantagem
        if(!strcmp(lista[i].tipo,"fogo") && !strcmp(inimigo.tipo,"grama")) lista[i].ataque *= 1.5;

        lista[i].f_vantagem = (lista[i].ataque - inimigo.defesa);
    }
    
    for (int i = 0; i < n; i++) { // sort decrescente
        for (int j = i; j < n; j++) {
            if(lista[i].f_vantagem < lista[j].f_vantagem) { // swap
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            }
            else if((lista[i].f_vantagem == lista[j].f_vantagem) && (i!=j)) {
                for (int k = 0; !br_eak; k++) {
                    if(lista[i].nome[k] > lista[j].nome[k]) {

                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux; 

                        br_eak=1;
                    }
                }
                br_eak=0;                
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, lista[i].nome);
    }
    
	return 0;
}