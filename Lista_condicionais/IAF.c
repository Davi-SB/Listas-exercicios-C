#include<stdio.h>
#define e 2.71

int main() {

    float IAF1, IAF2, IAF3;
    float x1, y1, k1;
    float x2, y2, k2;
    float x3, y3, k3;

    scanf("%f %f %f", &x1 , &y1 , &k1 );
    scanf("%f %f %f", &x2 , &y2 , &k2 );
    scanf("%f %f %f", &x3 , &y3 , &k3 );

    IAF1 = (x1*x1*e)/y1;
    IAF2 = (x2*x2*e)/y2;
    IAF3 = (x3*x3*e)/y3;

    if(IAF1 < 0) IAF1 = IAF1*(-1);
    if(IAF2 < 0) IAF2 = IAF2*(-1);
    if(IAF3 < 0) IAF3 = IAF3*(-1);

    //if(IAF < 32.5) printf("Calouro");
    //else if(IAF <= 63.9) printf("Iniciado");
    //else if(IAF <= 127.9) printf("Morador do Grad");
    //else if(IAF <= 255.9) printf("Matematico Discreto");
    //else if(IAF <= 512) printf("Conserta impressoras");
    //else if(IAF > 512) printf("Sem volta");

    // PRINTFS 

    if(IAF1 < 32.5) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Calouro.\n", k1 , IAF1);
    else if(IAF1 <= 63.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Iniciado.\n", k1 , IAF1);
    else if(IAF1 <= 127.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Morador do Grad.\n", k1 , IAF1);
    else if(IAF1 <= 255.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Matematico Discreto.\n", k1 , IAF1);
    else if(IAF1 <= 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Conserta impressoras.\n", k1 , IAF1);
    else if(IAF1 > 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Sem volta.\n", k1 , IAF1);

    if(IAF2 < 32.5) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Calouro.\n", k2 , IAF2);
    else if(IAF2 <= 63.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Iniciado.\n", k2 , IAF2);
    else if(IAF2 <= 127.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Morador do Grad.\n", k2 , IAF2);
    else if(IAF2 <= 255.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Matematico Discreto.\n", k2 , IAF2);
    else if(IAF2 <= 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Conserta impressoras.\n", k2 , IAF2);
    else if(IAF2 > 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Sem volta.\n", k2 , IAF2);

    if(IAF3 < 32.5) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Calouro.\n", k3 , IAF3);
    else if(IAF3 <= 63.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Iniciado.\n", k3 , IAF3);
    else if(IAF3 <= 127.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Morador do Grad.\n", k3 , IAF3);
    else if(IAF3 <= 255.9) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Matematico Discreto.\n", k3 , IAF3);
    else if(IAF3 <= 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Conserta impressoras.\n", k3 , IAF3);
    else if(IAF3 > 512) printf("O aluno de indice %.0f possui o valor IAF igual a %.2f e a descricao de Sem volta.\n", k3 , IAF3);
    
    // ----------------------------------------------
    // MUITOS possíveis erros por causa de acentuação 
    // talvez erro pela quebra de linha \n
    // ----------------------------------------------

    return 0;
}