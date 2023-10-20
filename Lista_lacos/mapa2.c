#include<stdio.h>

int main() {

    char orie1; // orientacao
    int km1; // d = direção
    int space=20, space_;

    while(1) {

        scanf("%c", &orie1);

        if(orie1=='x') break;
        
        space_=space;

        scanf("%d", &km1);

        if(orie1 == 'd') {

            space += (2*km1);

            while(km1>0) {
                while(space_>0) {
                    printf(" ");
                    space_--;
                }
                printf("->");
                km1--;
            }
            
            printf("\n");

        }
        else if(orie1 == 'f') {
            
            space_=space;

            while(km1>0) {
                while(space_>0) {
                    printf(" ");
                    space_--;
                }
                space_=space;
                printf("|\n");
                km1--;
            }
            //printf("\n");
        }
        else if(orie1 == 'e') {

            space -= (km1*2);
            space_ = space;

            while(km1>0) {
                while(space_>0) {
                    printf(" ");
                    space_--;
                }
                printf("<-");
                km1--;
            }

            printf("\n");

        }
    }
    while(space>0){
        printf(" ");
        space--;
    }
    printf("x");

    return 0;
}