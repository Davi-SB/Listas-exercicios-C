#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[16];
    float valor_mercado;
    int grandes_jogadores;
    int qtd_titulos;
    char flag_ney[4];
    char flag_flamengo[4];
} Clube;

int main() {

	int n;
    scanf("%d", &n);

    Clube lista[n], aux;

    for (int i = 0; i < n; i++) {
        
        scanf(" %15[^\n]%f %d %d %3[^\n] %3[^\n]", lista[i].nome, &lista[i].valor_mercado, &lista[i].grandes_jogadores, &lista[i].qtd_titulos, lista[i].flag_ney, lista[i].flag_flamengo);

        lista[i].valor_mercado += (lista[i].grandes_jogadores * 100); // cada jogador da 100 pontos

        lista[i].valor_mercado += (lista[i].qtd_titulos * 2000); // cada titulo da 2000 pontos

        if(!strcmp(lista[i].flag_ney, "sim")) lista[i].valor_mercado += 10000; // ter ney da 10k pontos

        if(!strcmp(lista[i].flag_flamengo, "sim")) lista[i].valor_mercado += 20000; // ser o flamengo da 20k pontos

    }

    // ordenar os structs na lista na ordem decrescent>

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(lista[i].valor_mercado > lista[j].valor_mercado) { // swap              
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }       
    }
    
    // printar o output

    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", lista[i].nome, lista[i].valor_mercado);
    }
    
	return 0;
}