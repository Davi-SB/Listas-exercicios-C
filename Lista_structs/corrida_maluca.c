#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct {
        char tipo[10];
        int valor;
        int performance;
}
peca;

int main() {
        int dinheiro = 0, N = 0, motores = 0, rodas = 0, latarias = 0, performanceAnalisar = 0, dinheiroAnalisar = 0, mangos = 0;
        int motoresVet[10] = {}, latariasVet[10] = {}, rodaVet[10] = {}, perfoAtual = 0, gastoAtual = 0, achou = 0;
        scanf("%d %d", & dinheiro, & N);
        peca pecas[N];
        // Fazer a contagem e armazenar em vetores separados cada tipo de peca
        for (int i = 0; i < N; i++) {
                scanf(" %s %d %d", pecas[i].tipo, & pecas[i].valor, & pecas[i].performance);
                if (strcmp(pecas[i].tipo, "Motor") == 0) {
                        motoresVet[motores++] = i;                        
                } else if (strcmp(pecas[i].tipo, "Lataria") == 0) {
                        latariasVet[latarias++] = i;
                } else if (strcmp(pecas[i].tipo, "Roda") == 0) {
                        rodaVet[rodas++] = i;
                }
        }
        // Se não for possivel fazer um carro logo de cara(alguma das pecas estiver faltando, ja acaba por aqui)
        if (rodas < 1 || motores < 1 || latarias < 1) {
                printf("Nao foi possivel construir uma caranga...");
                return 0;
        }
        // Fazer as combinacoes 3 a 3 de todas as pecas
        for (int i = 0; i < motores; i++) {
                // Motor atual motoresVet[i]
                for (int z = 0; z < latarias; z++) {
                        // Lataria atual latariaVet[z]
                        for (int y = 0; y < rodas; y++) {
                                // Roda atual rodasvet[y]
                                // Calcular a performance e custo de cada combinacao
                                perfoAtual = pecas[motoresVet[i]].performance + pecas[latariasVet[z]].performance + pecas[rodaVet[y]].performance;
                                gastoAtual = pecas[motoresVet[i]].valor + pecas[latariasVet[z]].valor + pecas[rodaVet[y]].valor;
                                if (achou == 0 || (perfoAtual >= performanceAnalisar && gastoAtual <= dinheiro)) {
                                        // Analisar com a melhor combinacao anterior 
                                        if (perfoAtual > performanceAnalisar && dinheiro >= gastoAtual) {
                                                achou = 1;
                                                performanceAnalisar = perfoAtual;
                                                dinheiroAnalisar = gastoAtual;
                                        } else if (performanceAnalisar == perfoAtual && dinheiroAnalisar > gastoAtual || achou == 0) {
                                                achou = 1;
                                                performanceAnalisar = perfoAtual;
                                                dinheiroAnalisar = gastoAtual;
                                        }
                                }
                        }
                }

        }
        // Basicamente vai tirar a melhor performance e menor gasto de dinheiro dentre as pecas
        if (dinheiroAnalisar <= dinheiro) {
                printf("Minha nave tem uma performance de %d pontos\n", performanceAnalisar);
                if (dinheiroAnalisar < dinheiro) {
                        mangos = fabs(dinheiro - dinheiroAnalisar);
                        printf("E ainda me sobraram %d mangos!\n", mangos);
                }
        } else {
                printf("Nao foi possivel construir uma caranga...");
        }

        return 0;
}
