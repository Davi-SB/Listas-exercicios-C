#include<stdio.h>

int main() {

    int dt; // dt = doces totais
    int dp1 , dp2, dp3; // dp = doces poquemÃ£o
    int soma1, soma2;

    scanf("%d%d%d%d", &dt, &dp1, &dp2, &dp3);

    if(dt<dp1 && dt<dp2 && dt<dp3){
        printf("0");
    }

    else if(dp1<=dp2 && dp2<=dp3) {
        soma1 = dp1 + dp2;
        if(soma1<=dt) {
            soma2 = soma1 + dp3;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }
    /////
    else if(dp1<=dp3 && dp3<=dp2) {
        soma1 = dp1 + dp3;
        if(soma1<=dt) {
            soma2 = soma1 + dp2;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }
    else if(dp2<=dp1 && dp1<=dp3) {
        soma1 = dp2 + dp1;
        if(soma1<=dt) {
            soma2 = soma1 + dp3;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }
    else if(dp2<=dp3 && dp3<=dp1) {
        soma1 = dp2 + dp3;
        if(soma1<=dt) {
            soma2 = soma1 + dp1;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }
    else if(dp3<=dp2 && dp2<=dp1) {
        soma1 = dp3 + dp2;
        if(soma1<=dt) {
            soma2 = soma1 + dp1;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }
    else if(dp3<=dp1 && dp1<=dp2) {
        soma1 = dp3 + dp1;
        if(soma1<=dt) {
            soma2 = soma1 + dp2;
            if(soma2<dt) printf("3\n");
            else printf("2\n");
        }
        else {
            printf("1\n");
        }
    }

    return 0;
}