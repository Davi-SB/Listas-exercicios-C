#include <stdio.h>

int main() {
    
        int T = 0;         
        int qtd_n = 0;
        int temp = 0;
        int temp2 = 0;
        int verf1 = 0;
        int guardado = 0;
        int posicao = 0;
        int cont1 = 0;
        int cont2 = 0;
        int temp3 = 0;
        int b;
        int i;
        int a;
        int x;
        scanf("%d", & T);
        for (b = 0; b < T; b++) {
        temp = 0;
        scanf("%d", & qtd_n);
        int vet[150] = {}, vet_[150][150] = {};
        for (i = 0; i < 150; i++)
        {
                for (a = 0; a < 150; a++)
                {
                vet_[i][a] = -1000000;
                }
        }
        for (i = 0; i < qtd_n; i++) {
                scanf("%d", & vet[i]);
        }
        guardado = 0;
        for (x = 0; x < qtd_n; x++) {
                verf1 = 0;
                for (i = posicao; verf1 != 1 && guardado != 1; i++) {
                        posicao = i; 
                        if (temp == 0 || vet[i] < vet_[temp2][temp - 1]) {vet_[temp2][temp] = vet[i];temp++;
                        } else if (vet[i] > vet_[temp2][temp - 1] && verf1 == 0) {
                                temp2 += 1; verf1 = 1; posicao = i; temp = 0;
                        }
                        if (i == qtd_n - 1) {
                                verf1 = 1; guardado = 1; temp2 = 0, temp = 0, posicao = 0;
                        }
                }
        }
        for (i = 0; i < 10; i++) {
                for (a = 0; a < qtd_n; a++) {
                        if (vet_[i][a] != -1000000) { cont1++;}
                }
                if (cont1 > cont2 || cont2 == 0) {
                        cont2 = cont1; temp3 = i;
                }
                cont1 = 0;
        }
        if (cont2 == 1) {
                printf("0\n");        
        } else {
                printf("%d\n", cont2);
        for (i = 0; i < cont2; i++) {
                printf("%d ", vet_[temp3][i]);
        }
        printf("\n");
        }
        temp3 = 0, cont2 = 0;
}
return 0;}
