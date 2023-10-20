#include <stdio.h>
#include <string.h>

int main() {

    char txt1[600] = {}, txt2[600] = {};
    char palavra1[50][100] = {}, palavra2[50][100] = {};
    double i_plagio;
    int comeco1 = 0, aux = 0, auxj = 0; 
    int palavras_total = 0;
    int qtd1 = 0, qtd2 = 0; 
    int cont_palavra_comum = 0, cont = 0;

    scanf("%[^\n]%*c%[^\n]%*c", txt1, txt2);

    for (unsigned int i = 0; i < strlen(txt1) + 1; i++) {
    if (txt1[i] == ',' || txt1[i] == ' ' || txt1[i] == '\0') {
    for (unsigned int z = comeco1; z < i; z++) {
        if (txt1[z] >= 65 && txt1[z] <= 90) {
                palavra1[aux][auxj] = txt1[z] + 32;
        } 
        else {
                palavra1[aux][auxj] = txt1[z];
        }
        auxj++;
    }
    if (txt1[i] == ',') {
        comeco1 = i + 2;
    } else {
        comeco1 = i + 1;
        palavras_total++, qtd1++;
    }
    auxj = 0;
    aux++;
    }
    }

    aux = 0, comeco1 = 0, auxj = 0;
    for (unsigned int i = 0; i < strlen(txt2) + 1; i++) {
        if (txt2[i] == ',' || txt2[i] == ' ' || txt2[i] == '\0') {
            for (unsigned int z = comeco1; z < i; z++) {
                if (txt2[z] >= 65 && txt2[z] <= 90) {
                    palavra2[aux][auxj] = txt2[z] + 32;
                } 
                else {
                    palavra2[aux][auxj] = txt2[z];
                }
                auxj++;

            }
            if (txt2[i] == ',') {
                comeco1 = i + 2;
            } 
            else {
                comeco1 = i + 1;
                palavras_total++, qtd2++;
            }
            auxj = 0;
            aux++;
        }
    }
    for (int i = 0; i < qtd1; i++) {
        cont = 0;
        for (int p = 0; p < i; p++) {
            if (strcmp(palavra1[i], palavra1[p]) == 0) {
                cont = 1;
            }
        }
        for (int z = 0; z < qtd2 && cont == 0; z++) {
            if (strcmp(palavra1[i], palavra2[z]) == 0) {
                cont_palavra_comum++;
                cont = 1;
            }
        }
    }
    i_plagio = ((cont_palavra_comum + 0.0) * 100) / (palavras_total + 0.0); // p formatar forçadamente
    printf("%.1f", i_plagio);
    return 0;
}
