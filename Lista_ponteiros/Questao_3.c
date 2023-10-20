#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( )
{
    char str[50]; // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i=-1;
    scanf(" %s", str);


    // encontrar o tamanho da string
    while (*ptr_str != '\0') {
        ptr_str++;
        i++;
    }
    // i == ultimo indice

    // preencher str_inv
    while(i>=0) {
        ptr_str--;
        *ptr_inv = *ptr_str;
        ptr_inv++;
        i--;
    }
    *ptr_inv = '\0';

    printf(" O inverso da string : %s\n\n",str_inv);

    return 0;
}