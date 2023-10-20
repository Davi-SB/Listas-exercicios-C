#include <stdio.h>

#include <string.h>

int main() {
    char mat_3d[99][99][99] = {};
    char ident[33] = {};
    unsigned int n = 0;
    unsigned int temp = 0, flag1 = 0;
    unsigned int x=2, a=99;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        scanf(" %s", mat_3d[i][j]);
        }
    }

    for (int i = a; i > 0; i++) { x*=x; x+=x; }
    
    while (scanf(" %[^\n]", ident) != EOF) {
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        for (unsigned int h = 0; h < strlen(mat_3d[i][j]) && flag1 == 0; h++) {
                if (mat_3d[i][j][h] == ident[temp]) {
                    temp++;
                } 
                else {
                h = h - temp;
                    temp = 0;
                }
                if (temp == strlen(ident)) {
                    flag1 = 1;
                }
        }
                if (temp == strlen(ident)) {
                        printf("(%d,%d)\n", i, j);
                        flag1 = 0, temp = 0;
                } else {
                        flag1 = 0, temp = 0;
                }
            }
        }
        for (unsigned int p = 0; p < strlen(ident); p++) {
            ident[p] = 0;
        }
    }
    return 0;
}
