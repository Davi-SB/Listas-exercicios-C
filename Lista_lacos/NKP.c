#include <stdio.h>

int main() {

    int N, K, P, Q=0;
    int x; // num testado do intervalo
    int d; //denominador
    int inc=2, cont1=0;
    int div_valido=0;
    int x0;

    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &P);

    x0=K;

    for(x=N; x<K && div_valido!=P; x+=2) {

        div_valido=0;

        for(d=3; d<=x; d++) {

            if(x%d==0){
                for(inc=1; inc<=d; inc++) {
                    if(d%inc==0) cont1++; // se entrar nesse if, UMA VEZ, Ã© primo
                }
            }

            if((cont1==2) && ((x/d)%d!=0)) {

                div_valido++;
            }   

            cont1=0;

        }
    }

    if(x0==x) printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    else {

    int xCERTOPORRA;
    xCERTOPORRA = (x-1);
    
    for(x; x<K; x++) {

        div_valido=0;

        for(d=3; d<=x; x+=2) {

            if(x%d==0){
                for(inc=1; inc<=d; inc++) {
                    if(d%inc==0) cont1++; // se entrar nesse if, UMA VEZ, Ã© primo
                }
            }

            if((cont1==2) && ((x/d)%d!=0)) {

                div_valido++;
            }   

            cont1=0;

            

        }

        if(div_valido==P) Q++;
    }





    printf("%d %d\n", xCERTOPORRA, Q);
    }

    return 0;
}