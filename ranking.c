#include "funcoes.h"

int comparar(const void *a, const void *b) {
    return ((Usuarios *)b)->pontuacao - ((Usuarios *)a)->pontuacao; // Ordem decrescente
}

void ranking(Usuarios *info, int tamanho, int p1, int p2){
	char nome_p1[20], nome_p2[20], lixo[50];
	int index_p1, index_p2, pont_p1;
	int i;

	strcpy(nome_p1, info[p1].nome_jogo);
	strcpy(nome_p2, info[p2].nome_jogo);

	qsort(info, tamanho, sizeof(Usuarios), comparar);
	
	system("clear||cls");
	printf("+===================================================+\n");
	printf("|                   -- RANKING --                   |\n");
	printf("+===================================================+\n");
	for (i = 0; i < tamanho; i++) {
		printf("| ");
		if( strcmp(nome_p1, info[i].nome_jogo) == 0){
            index_p1 = i;
			printf(YELLOW);
		}else if(  strcmp(nome_p2, info[i].nome_jogo) == 0){

            index_p2 = i;
			printf(YELLOW); 
		}

        printf("%2d --> Nome: %-12s | Pontuacao: %9d " RESET " |\n", i + 1, info[i].nome_jogo, info[i].pontuacao);
		
    }
	printf("+===================================================+\n\n");
	
	printf("Digite qualquer coisa para continuar...\n");
	scanf("%s", &lixo);
}