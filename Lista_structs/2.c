#include<stdio.h>
#include<string.h>

typedef struct {
	char nome_album[20];
	int flag_emprestado;
	char classificacao[6];
} Album;

typedef struct {
	char nome[20];
	int m;
	Album lista_album[30]; // 30 == tamanho arbitrario de M
} Artista;

int main() {

	int n; // numero de cantores
	scanf("%d", &n);

	Artista lista[n], aux;

	int vet_sorteados[3]={};

	for (int i = 0; i < n; i++) { // armazena artista e albuns
		scanf(" %19[^\n]%d", lista[i].nome, &lista[i].m);

		for (int j = 0; j < (lista[i].m); j++) {
			scanf(" %s%d%s", lista[i].lista_album[j].nome_album, &lista[i].lista_album[j].flag_emprestado, 
			lista[i].lista_album[j].classificacao); // testar %[^\n] no ultimo
		}		
	}

	scanf("%d%d%d", &vet_sorteados[0], &vet_sorteados[1], &vet_sorteados[2]); // armazena os CDs sorteados,

	
	//									 manipulação de dados já armazenados

	// ordenar os artistas por ordem alfabetica

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			if((strcmp(lista[i].nome, lista[j].nome)) < 0) { // swap
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
			}
		}
	}

	// matriz com todos os albuns organizados

	int albuns_totais=0; // soma dos m de cada artista
	for (int i = 0; i < n; i++) {
		albuns_totais += lista[i].m;
	}
	// printf("\nTotal de albuns: %d\n", albuns_totais); // break point

	char mat[albuns_totais][3][20]; 
	// matriz com todos os nomes dos albuns na coluna 1 e sua classificação na coluna 2, artista na coluna 3
	int vet_flag_emprestado[albuns_totais]; // vetor com a flag de emprestimo, associado ao algum pelo indice

	int k=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < lista[i].m; j++) {

		strcpy(mat[k][0], lista[i].lista_album[j].nome_album);
		strcpy(mat[k][1], lista[i].lista_album[j].classificacao);	
		strcpy(mat[k][2], lista[i].nome);
		vet_flag_emprestado[k] = lista[i].lista_album[j].flag_emprestado;

		//printf("\n%s___%s___%s   flag: %d\n", mat[k][0], mat[k][1], mat[k][2], vet_flag_emprestado[k]); // break point

		k++;	
		}
	}


	// matriz apenas com os albuns sorteados

	char mat_sorteados[3][3][20]; // colunas: nome do album, classificacao, artista
	int vet_flag_emprestado_sorteados[3];
	//char aux_nome[20], aux_classificacao[20], aux_artista[20];
	//int aux_flag;

	for (int i = 0; i < 3; i++) {
	strcpy(mat_sorteados[i][0], mat[vet_sorteados[i]-1][0]); // primeira coluna vai ter o nome do album
	strcpy(mat_sorteados[i][1], mat[vet_sorteados[i]-1][1]); // segunda coluna vai ter a classificacao, estrelinhas
	strcpy(mat_sorteados[i][2], mat[vet_sorteados[i]-1][2]); // terceirca coluna vai ter o nome do artista
	vet_flag_emprestado_sorteados[i] = vet_flag_emprestado[vet_sorteados[i]-1];
	}
	
	// Ordenar os 3 CDs em ordem decrescente da quantidade de estrelinhas

	int vet_linha[]={0,1,2};
	int aux_linha=0, aux_estrela=0;
	int vet_estrelas[]={strlen(mat_sorteados[0][1]), strlen(mat_sorteados[1][1]), strlen(mat_sorteados[2][1])};


	for (int i = 0; i < 3; i++) { // ordenar o vet_estrela e fazer os mesmos swaps com o vet_linha
		for (int j = 0; j < n-1; j++) {
			if(vet_estrelas[j] > vet_estrelas[j+1]) { // swap
				aux_estrela = vet_estrelas[i];
				vet_estrelas[i] = vet_estrelas[j];
				vet_estrelas[j] = aux_estrela;

				aux_linha = vet_linha[i];
				vet_linha[i] = vet_linha[j];
				vet_linha[j] = aux_linha;
			}
		}
	}

	// printar a matriz se a flag=0


	for (int i = 0; i < 3; i++) {
		if(vet_flag_emprestado_sorteados[vet_linha[i]] == 0) {
			printf("%s - %s\n", mat_sorteados[vet_linha[i]][2], mat_sorteados[vet_linha[i]][0]);
		}
		else {
			printf("Infelizmente %s ta emprestado:(\n", mat_sorteados[vet_linha[i]][0]);
		}
	}
	
	return 0;
}