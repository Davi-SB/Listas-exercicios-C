#include<stdio.h>
#include<stdlib.h>

int main() {
    int x , y , c;
    scanf("%d %d %d" , &x , &y , &c);

    //printf("%d %d" , abs(y)+1, abs(x)+1);
    
    if(x > 0 && y > 0 && c == 1) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y > 0 && c == 2) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y < 0 && c == 3) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y > 0 && c == 4) { 
        printf("caminhada invalida\n");
    }
    /////////
    else if(x > 0 && y > 0 && c != 2) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y > 0 && c != 1) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y < 0 && c != 4) { 
        printf("caminhada invalida\n");
    }
    else if(x < 0 && y > 0 && c != 3) { 
        printf("caminhada invalida\n");
    }
    else {
    printf("%d passos em y e %d passos em x\n" , 
    abs(y)+1, abs(x)+1 );
    }
    return 0;
}