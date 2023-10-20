#include<stdio.h>
#include<string.h>

typedef struct {
    char bebida[10];
    char comida[15];
    char atracao[25];
    char nome[30];
    int agregados;
    int flag_vip;
} Convidado;

int main() {

    int n;
    scanf("%d", &n);

    Convidado lista[n];
    int vet_votos_atracao[5]={}, vet_votos_comidas[5]={}, vet_votos_bebidas[5]={};
    
    for (int i = 0; i < n; i++) { // armazena dados e votos na struct e nos vet_votos 
        scanf(" %s%d%s%s%[^\n]", lista[i].nome, &lista[i].agregados, lista[i].comida, lista[i].bebida, lista[i].atracao);

        if(!strcmp(lista[i].comida, "coxinha")) vet_votos_comidas[0]++;
        else if(!strcmp(lista[i].comida, "brigadeiro")) vet_votos_comidas[1]++;
        else if(!strcmp(lista[i].comida, "risoto")) vet_votos_comidas[2]++;
        else if(!strcmp(lista[i].comida, "picanha")) vet_votos_comidas[3]++;
        else if(!strcmp(lista[i].comida, "pizza")) vet_votos_comidas[4]++;

        if(!strcmp(lista[i].bebida, "agua")) vet_votos_bebidas[0]++;
        else if(!strcmp(lista[i].bebida, "cafe")) vet_votos_bebidas[1]++;
        else if(!strcmp(lista[i].bebida, "suco")) vet_votos_bebidas[2]++;
        else if(!strcmp(lista[i].bebida, "monster")) vet_votos_bebidas[3]++;
        else if(!strcmp(lista[i].bebida, "pitu")) vet_votos_bebidas[4]++;
        
        if(!strcmp(lista[i].atracao, " Gustavo Mioto")) vet_votos_atracao[0]++;
        else if(!strcmp(lista[i].atracao, " Billie Eilish")) vet_votos_atracao[1]++;
        else if(!strcmp(lista[i].atracao, " Pericles")) vet_votos_atracao[2]++;
        else if(!strcmp(lista[i].atracao, " Shevchenko e Elloco")) vet_votos_atracao[3]++;
        else if(!strcmp(lista[i].atracao, " Joao Gomes")) vet_votos_atracao[4]++;
    }
    
    int maior_freq=0, num_mais_freq=0;
    int cont=0;

    // definindo numero de agregados, numero mais frequente no vetor
    for (int i = 0; i < n; i++) { // fixo

        for (int j = 0; j < n; j++) { // varre a string
            if(lista[i].agregados == lista[j].agregados) cont++;
        }

        if(cont > maior_freq) { // se aparecer mais vezes que outro
            maior_freq = cont;
            num_mais_freq = lista[i].agregados; 
        }
        else if((cont == maior_freq) && (lista[i].agregados < num_mais_freq)) { // se a quantidade for igual
            //maior_freq = cont; linha desnecessária, ocorre para etrar no if
            num_mais_freq = lista[i].agregados; 
        }

        cont = 0;
    }
    // ao final desse for, a saida esperada vai estar armazenada na variavel num_mais_freq
    
    printf("%d\n", num_mais_freq); // break point
    

    // encontrando a comida mais votada, encontrar a posicao com maior valor no vetor
    int indice_comida=0, mais_votos_c=0;

    for (int i = 0; i < 5; i++) {
        if(mais_votos_c < vet_votos_comidas[i]) {
            mais_votos_c = vet_votos_comidas[i];
            indice_comida=i;
        }
        else if(mais_votos_c == vet_votos_comidas[i]) {
            if(i==1) indice_comida=1; // se for o brigadeiro, ele ganha de todos

            else if(i==0 && indice_comida!=1) indice_comida=0; // se for a coxinha, ganha se não for o brigadeiro

            else if(i==3 && indice_comida!=1 && indice_comida!=0) indice_comida=3; // se for a picanha, ganha se não for o brigadeiro nem coxinha

            else if(i==4 && indice_comida!=1 && indice_comida!=0 && indice_comida!=3) indice_comida=4; // se for a pizza, ganha se não for o brigadeiro nem coxinha nem picanha

            //else if(i==4) // se for a risoto, ganha de ngm
        }
    }

    char comida_vencedora[15];

    if(indice_comida==0) strcpy(comida_vencedora, "coxinha");
    else if(indice_comida==1) strcpy(comida_vencedora, "brigadeiro");
    else if(indice_comida==2) strcpy(comida_vencedora, "risoto");
    else if(indice_comida==3) strcpy(comida_vencedora, "picanha");
    else if(indice_comida==4) strcpy(comida_vencedora, "pizza");

    printf("%s\n", comida_vencedora); // break point

    // encontrando a beibda mais votada, encontrar a posicao com maior valor no vetor
    int indice_bebida=0, mais_votos_b=0;

    for (int i = 0; i < 5; i++) {
        if(mais_votos_b < vet_votos_bebidas[i]) {
            mais_votos_b = vet_votos_bebidas[i];
            indice_bebida=i;
        }
        else if(mais_votos_b == vet_votos_bebidas[i]) {
            if(i==0) indice_bebida=0; // se for o agua, ganha de todos

            else if(i==1 && indice_bebida!=0) indice_bebida=1; // se for o cafe, ganha se não for agua

            else if(i==3 && indice_bebida!=0 && indice_bebida!=1) indice_bebida=3; // se for monster, ganha se não for o agua nem cafe

            else if(i==4 && indice_bebida!=0 && indice_bebida!=1 && indice_bebida!=3) indice_bebida=4; // se for  pitu, ganha se não for agua, cafe nem monster

            //else if(i==2) // se for suco, ganha de ngm
        }
    }

    char bebida_vencedora[10];

    if(indice_bebida==0) strcpy(bebida_vencedora, "agua");
    else if(indice_bebida==1) strcpy(bebida_vencedora, "cafe");
    else if(indice_bebida==2) strcpy(bebida_vencedora, "suco");
    else if(indice_bebida==3) strcpy(bebida_vencedora, "monster");
    else if(indice_bebida==4) strcpy(bebida_vencedora, "pitu");

    printf("%s\n", bebida_vencedora); // break point
    

    // encontrando a atracao mais votada, encontrar a posicao com maior valor no vetor
    int indice_atracao=0, mais_votos_a=0;

    for (int i = 0; i < 5; i++) {
        if(mais_votos_a < vet_votos_atracao[i]) {
            mais_votos_a = vet_votos_atracao[i];
            indice_atracao=i;
        }
        else if(mais_votos_a == vet_votos_atracao[i]) {
            if(i==1) indice_atracao=1; // se for billie, ganha de todos

            else if(i==0 && indice_atracao!=1) indice_atracao=0; // se for gustavo, ganha se não for billie

            else if(i==4 && indice_atracao!=1 && indice_atracao!=0) indice_atracao=4; // se for joao, ganha se não for billie nem gustavo

            else if(i==2 && indice_atracao!=1 && indice_atracao!=0 && indice_atracao!=4) indice_atracao=2; // se for pericles, ganha se não for billie, gustavo nem joao

            //else if(i==3) // se for shevchenko, ganha de ngm
        }
    }

    char atracao_vencedora[25];

    if(indice_atracao==0) strcpy(atracao_vencedora, "Gustavo Mioto");
    else if(indice_atracao==1) strcpy(atracao_vencedora, "Billie Eilish");
    else if(indice_atracao==2) strcpy(atracao_vencedora, "Pericles");
    else if(indice_atracao==3) strcpy(atracao_vencedora, "Shevchenko e Elloco");
    else if(indice_atracao==4) strcpy(atracao_vencedora, "Joao Gomes");

    printf("%s\n", atracao_vencedora); // break point

    //definindo convidados vip
    int vet_vip[25]={};
    char atracao_vencedora_space[35]=" ";
    strcat(atracao_vencedora_space, atracao_vencedora);

    for (int i = 0; i < n; i++) {
        if(lista[i].agregados == num_mais_freq) vet_vip[i]++;
        if(!strcmp(lista[i].comida, comida_vencedora)) vet_vip[i]++;
        if(!strcmp(lista[i].bebida, bebida_vencedora)) vet_vip[i]++;
        if(!strcmp(lista[i].atracao, atracao_vencedora_space)) vet_vip[i]++;
        //        tem um espaço no começo , n tem

        if(vet_vip[i]>=2) lista[i].flag_vip=1;
        else lista[i].flag_vip=0;
    }

    // ordenando eles em ordem alfabetica
    Convidado aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if((strcmp(lista[i].nome, lista[j].nome)) < 0) { // swap
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    printf("convidados vip:\n");
    for (int i = 0; i < n; i++) {
        if(lista[i].flag_vip==1) printf("%s\n", lista[i].nome);
    }

    return 0;
}