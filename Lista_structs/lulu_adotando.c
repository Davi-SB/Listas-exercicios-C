#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[101];
    int idade;
    float altura;
    float dist_X; // distancia do numero magico
} Filho;

int main() {

    int n, m; // numero de crianças, quantas serao adotadas
    float X; // numero magico
    scanf("%d%d%f", &n, &m, &X);

    Filho lista[n];
    Filho aux;
    
    for (int i = 0; i < n; i++) {
        scanf(" %s %d %f", lista[i].nome, &lista[i].idade, &lista[i].altura);
        lista[i].dist_X = (X - (lista[i].altura * lista[i].idade * strlen(lista[i].nome)));
        if(lista[i].dist_X<0) lista[i].dist_X *= -1; // módulo
    }
    for (int i = 0; i < n; i++) { // quanto maior a dist_X, mais pra baixo da lista --> ordem crescente
        for (int j = 0; j < n; j++) {

            if(lista[i].dist_X < lista[j].dist_X) { //swap
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux; 
            }           
        }        
    }
    for (int i = 0; i < m; i++) {
        printf("%s\n", lista[i].nome);
    }    
}