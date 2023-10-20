#include<stdio.h>
int main() {

    float X , Y, pessoas, tt; // tt = tempo total em horas
    char lugar;
    scanf("%f %f %c %f", &X , &Y , &lugar , &pessoas);

    if(X >= 0 && X < 24 && Y >= 0 && Y < 24 && X < Y) {
        
        tt = Y - X;

        switch(lugar) {

            case 'A' :
                if(tt > 1) {
                    if(tt >= 1.5 * 1) { 
                        pessoas <= 9 ? printf("O uninho faz a boa, obrigado querida mae line\n") : printf("Infelizmente o uninho nao tanka, rodamos!\n");
                    }
                    else {
                        pessoas <= 5 ? printf("O uninho faz a boa, obrigado querida mae line\n") : printf("Infelizmente o uninho nao tanka, rodamos!\n");
                    }
                }
                else printf("Infelizmente o uninho nao tanka, rodamos!\n");
                break;
   
            case 'B' :
                if(tt > 0.75) {
                    if(tt >= 1.5 * 0.75) { 
                    (pessoas <= 9) ? printf("O uninho faz a boa, obrigado querida mae line\n") : printf("Infelizmente o uninho nao tanka, rodamos!\n");
                    }
                    else {
                        (pessoas <= 5) ? printf("O uninho faz a boa, obrigado querida mae line\n") : printf("Infelizmente o uninho nao tanka, rodamos!\n");
                    }
                }
                else printf("Infelizmente o uninho nao tanka, rodamos!\n");
                break;
   
            default:
                printf("Infelizmente o uninho nao tanka, rodamos!\n");
        }

    }
    else
        printf("Entrada Invalida\n");

    return 0;
}