#include<stdio.h>

int main() {

    int dimensao=0, i=0, k=0, temp=0;
    scanf("%d", &dimensao);
    int tam=(dimensao*dimensao);
    int vet[tam];
    int d=0; //denominador
    int cont=0;

    for (i=0; i<tam; i++) {
        scanf("%d", &vet[i]);
    }

    for (i=0; i<tam; i++) {
        if(vet[i]==2) {
            vet[i]=vet[i];
        }
        else if((vet[i]%2)==0) { //par e diferente de dois
            vet[i]=0;
        }
        else {
            for(d=3; d<=vet[i]; d++) {
                if((vet[i]%d)==0) {
                    cont++;
                }
            }
            if(cont>1) {
                vet[i]=0;
            }
            cont=0;
        }
    }

    for(i=0; i<tam; i++) {
        for(k=i; k<tam; k++) {

            if(vet[i]>vet[k]) {

                temp=vet[i];
                vet[i]=vet[k];
                vet[k]=temp;

            }

        }
    }
    
    for (i=0; i<tam; i++) {
        if(vet[i]!=0) printf("%d ", vet[i]);
    }

    return 0;
}