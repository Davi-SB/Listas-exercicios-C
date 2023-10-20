#include<stdio.h>

int main() {

    int x;
    int cont=0;
    int inc=2; //incremento

    printf("Digite um valor: ");
    scanf("%d", &x);

    while(inc<x) {

        if(x%inc==0) cont++;

        inc++;
    }

    if(cont>0) printf("O numero NAO eh primo!\n");
    else printf("O numero eh primo!!!\n");
    
    return 0;
}