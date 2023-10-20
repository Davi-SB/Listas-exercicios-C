#include<stdio.h>
#include<string.h>

int main() {

	int m;
    scanf ("%d", &m);

    char vet_pisca_pisca[m][61];
    char str_aux[61]={};
    int interacoes=0;
    int desligou=0;
    char str_grande[200]={}; // numero arbitrario

    for (int j = 0; j < m; j++) { // repete o numero de casos
        
        scanf(" %s", str_aux);
        scanf("%d", &interacoes);

        while (interacoes>0) {

            desligou=0;

            if(str_aux[0]=='X') { // desligado
                str_aux[0]='O'; // troca o estado, liga
                //ligou++;
            }
            else { // str_aux[0]=='O', ligado
                str_aux[0]='X'; // troca o estado, desliga
                desligou=1;
            }

            unsigned int i=1;
            while(desligou) { // se o led foi desligado

            if(str_aux[i]=='X') { // desligado
                str_aux[i]='O'; // troca o estado, liga
                desligou=0;
            }
            else if(str_aux[i]=='O') { // str_aux[i]=='O', ligado
                str_aux[i]='X'; // troca o estado, desliga
                desligou=1;
            }

            if(i<strlen(str_aux)) i++;
            else desligou=0;
            
            }                
            interacoes--;
        }
        strcpy(vet_pisca_pisca[j], str_aux);
    }
    
    for (int i = 0; i < m; i++) { // printa fios
            printf("%s\n", vet_pisca_pisca[i]); // vazio
        }    

    strcat(str_grande, vet_pisca_pisca[0]);
    for (int i = 1; i < m; i++) { // junta num fio so e adiciona as ligacoes
        
        if(strlen(str_grande) % 2 == 0) { // par

            if(str_grande[strlen(str_grande)-1] == vet_pisca_pisca[i][0]) strcat(str_grande, "@");
            else strcat(str_grande, "$");

        }
        else { // impar

            if(str_grande[strlen(str_grande)-1] == vet_pisca_pisca[i][0]) strcat(str_grande, "#");
            else strcat(str_grande, "%");

        }

        strcat(str_grande, vet_pisca_pisca[i]);
    }
    
    for (unsigned int i = 0; i < strlen(str_grande); i++) {
        
        printf("%c", str_grande[i]);

    }
    

	return 0;
}