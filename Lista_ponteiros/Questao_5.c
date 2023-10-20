#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int ID_produto;
    int qtd;
    int preco;
} Produto;

int main() {

    Produto *p_lista=NULL, *p_lista_aux=NULL, produto_aux, swap_aux;
    char str[4]={'a'};

    int ID_aux, qtd_aux, preco_aux, flag_saida=0;
    int tam_lista=0; // (tam_lista - 1) == indice

    while (strcmp(str, "END") != 0) { 
        
        scanf(" %3[^' ']", str); // %3[^' '] == %s, mas limita os caracateres, mais seguro, previne invasao de memoria

        if(!strcmp(str, "NEW")) {

            tam_lista++;
            scanf("%d %d %d",&ID_aux, &qtd_aux, &preco_aux);
            p_lista_aux = p_lista;
            p_lista = (Produto *) realloc(p_lista_aux, (tam_lista * sizeof(Produto)));
            if(p_lista == NULL) {
                printf("Erro de alocacao de memoria\n Ultilma lista armazenada:\n");

                for (int i = 0; i < tam_lista; i++){
                    for (int j = 0; j < tam_lista; j++) {
                        if(p_lista_aux[i].ID_produto < p_lista_aux[j].ID_produto) { // swap
                        swap_aux = p_lista_aux[i];
                        p_lista_aux[i] = p_lista_aux[j];
                        p_lista_aux[j] = swap_aux;
                        }
                    }   
                }
                for (int i = 0; i < tam_lista; i++) {
                    printf("1. ID: %d, Qtd: %d, Preco: %d\n", p_lista_aux[i].ID_produto, p_lista[i].qtd, p_lista[i].preco);
                }

                free(p_lista_aux);
                exit(1);
            }
        
            produto_aux.ID_produto = ID_aux;
            produto_aux.qtd = qtd_aux;
            produto_aux.preco = preco_aux;

            p_lista[tam_lista-1] = produto_aux;

        }
        else if(!strcmp(str, "RM")) {

            scanf("%d", &ID_aux);

            for (int i = 0; ((i < tam_lista) && (!flag_saida)); i++) {
                if(ID_aux == p_lista[i].ID_produto) {

                    for (int j = i; j < (tam_lista-1); j++) {                      
                        p_lista[j] = p_lista[j+1];
                    }
                    tam_lista--;

                    p_lista_aux = p_lista;
                    p_lista = (Produto *) realloc(p_lista_aux, (tam_lista * sizeof(Produto)));
                    if(p_lista == NULL) {
                        printf("Erro de alocacao de memoria\n Ultilma lista armazenada:\n");

                        for (int i = 0; i < tam_lista; i++){
                            for (int j = 0; j < tam_lista; j++) {
                                if(p_lista_aux[i].ID_produto < p_lista_aux[j].ID_produto) { // swap
                                swap_aux = p_lista_aux[i];
                                p_lista_aux[i] = p_lista_aux[j];
                                p_lista_aux[j] = swap_aux;
                                }
                            }   
                        }
                        for (int i = 0; i < tam_lista; i++) {
                            printf("1. ID: %d, Qtd: %d, Preco: %d\n", p_lista_aux[i].ID_produto, p_lista[i].qtd, p_lista[i].preco);
                        }

                        free(p_lista_aux);
                        exit(1);
                    }

                    flag_saida = 1;
                }
            }
            flag_saida = 0;
            
        }
        else if(!strcmp(str, "END")) {

            for (int i = 0; i < tam_lista; i++){
                for (int j = 0; j < tam_lista; j++) {
                    if(p_lista[i].ID_produto < p_lista[j].ID_produto) { // swap
                    swap_aux = p_lista[i];
                    p_lista[i] = p_lista[j];
                    p_lista[j] = swap_aux;
                    }
                }   
            }
            for (int i = 0; i < tam_lista; i++) {
                printf("1. ID: %d, Qtd: %d, Preco: %d\n", p_lista[i].ID_produto, p_lista[i].qtd, p_lista[i].preco);
            }
        }
    }
    
    free(p_lista); free(p_lista_aux);
    return 0;
}

/*
Entradas testadas:

NEW 1 22 3
NEW 2 33 4
NEW 3 44 5
NEW 4 55 6
END

NEW 1 22 3
NEW 4 55 6
NEW 3 44 5
NEW 2 33 4
END

NEW 1 22 3
NEW 2 33 4
NEW 3 44 5
NEW 4 55 6
RM 2
RM 3
END

NEW 1 22 3
NEW 2 33 4
RM 1
NEW 3 44 5
RM 2
NEW 4 55 6
END

*/