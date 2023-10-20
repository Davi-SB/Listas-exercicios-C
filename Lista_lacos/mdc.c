#include<stdio.h>

int main() {

    int x, y, x2, y2, x_da_vez, y_da_vez, x_ganhando, y_ganhando;
    int inc, inc_primo; // incremento
    int a, a2, b, c; // output
    int contDx1=2, contDx2=0, cont_primo; // contador
    int contDy1=2, contDy2=99999, cont_primo2; // contador
    scanf("%d %d", &y, &x);

    for(inc=y ; inc<=x ; inc++) {

        for(x2=2 ; x2<inc ; x2++) {

            if(inc%x2==0) {
                contDx1++;
            }

        }

        inc_primo=2;
        cont_primo=0;

        while(inc_primo<inc) {
        if(inc%inc_primo==0) cont_primo++;
        inc_primo++;
        }

        if(cont_primo!=0 && contDx1>contDx2) {
            contDx2 = contDx1;
            x_ganhando = inc;
        }

        contDx1 = 2;

    }

    a = x_ganhando;

    //printf("\n%d\n", a);

    for(inc=y ; inc<=x ; inc++) {

        for(x2=2 ; x2<inc ; x2++) {

            if(inc%x2==0) {
                contDy1++;
            }

        }

        inc_primo=2;
        cont_primo2=0;

        while(inc_primo<inc) {
        if(inc%inc_primo==0) cont_primo2++;
        inc_primo++;
        }

        if(cont_primo2!=0 && contDy1<contDy2) {
            contDy2 = contDy1;
            y_ganhando = inc;
        }

        contDy1 = 2;

    }

    b = y_ganhando;

    //printf("\n%d\n", b);

    //// calculando o mdc, a>b

    printf("%d ", a);
    printf("%d ", b);

    int aa, bb, r;

    aa = a;
    bb = b;

    if(aa%bb!=0) {	
        do {

        r=aa%bb;
        aa = bb;
        bb = r;
	
        } while (bb!=0);
    }
    else aa = bb;

    printf("%d", aa);

    return 0;
}
