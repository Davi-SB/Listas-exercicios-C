#include<stdio.h>

int main() {

    int d;
    int c1, c2, c3, c4;
    float cb1, cb2, cb3, cb4; // cb = custo/benefí­cio
    float med; // med = média

    scanf("%d %d %d %d %d", &d, &c1, &c2, &c3, &c4);

    cb1 = 75 / c1;
    cb2 = 50 / c2;
    cb3 = 25 / c3;
    cb4 = 50 / c4;

    med = (cb1 + cb2 + cb3 + cb4) / 4;

    if(c1<=d) { // cabe no bolso
        cb1>=med ? printf("eh dento\n") : printf("EH BOMBA TORRESMO\n"); // não é bomba
    }
    else {
        printf("foi de comes\n");
    }

    if(c2<=d) { // cabe no bolso
        cb2>=med ? printf("eh dento\n") : printf("EH BOMBA TORRESMO\n"); // não é bomba
    }
    else {
        printf("foi de comes\n");
    }

    if(c3<=d) { // cabe no bolso
        cb3>=med ? printf("eh dento\n") : printf("EH BOMBA TORRESMO\n"); // não é bomba
    }
    else {
        printf("foi de comes\n");
    }

    if(c4<=d) { // cabe no bolso
        cb4>=med ? printf("eh dento\n") : printf("EH BOMBA TORRESMO\n"); // não é bomba
    }
    else {
        printf("foi de comes\n");
    }

    return 0;
}