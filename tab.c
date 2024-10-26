#include "funcoes.h"

void imprimir_tabuleiro(Peca (*tabuleiro)[8], int (*ataque)[8], int jogador, char *nome_p1, char *nome_p2){
    char pos_linha[8] = {'a','b','c','d','e','f','g','h'};
	int i, j;

	system("clear||cls");
	
	printf("+==================================+\n");
	printf("| Pecas Pretas: letras minusculas  |\n");
	printf("| Pecas Brancas: letras maiusculas |\n");
	printf("+==================================+\n");
	if(jogador) printf("| Turno das Pretas: %-12s   |\n", nome_p2);
	else printf("| Turno das Brancas: %-12s  |\n", nome_p1);
	printf("+==================================+\n\n");

	for ( i = 0; i < 9; i++) {
        for ( j = 0; j < 8; j++) {
			if(i == 8){
				printf(" %d ",j+1);
				if(j == 7) printf("\n");
				continue;
			}
			// Alternar entre as cores de fundo
            if ((i + j) % 2 == 1) {
                printf(LIGHT_GRAY);  // Casa clara
            } else {
                printf(DARK_GRAY);    // Casa escura
            }
			if(ataque[i][j] == 1 || ataque[i][j] == -1 || ataque[i][j] == 3 || ataque[i][j] == 4 || ataque[i][j] == 5) printf(RESET YELLOW);

            // Adicionar peca com cor de texto apropriada
            if (tabuleiro[i][j].tipo != '0') {
                if(tabuleiro[i][j].cor) {
                    printf(BLACK_TEXT " %c " RESET, tabuleiro[i][j].tipo + 32); // Peças pretas
                } else {
                    printf(WHITE_TEXT " %c " RESET, tabuleiro[i][j].tipo); // Peças brancas
                }
            } else {
                printf("   "); // Espaço vazio
            }
        }
        printf(RESET " %c\n", pos_linha[i]); // Resetar cores após cada linha
    }
}

void montar_tabuleiro_inicial(Peca (*tabuleiro)[8]){
    int i,j;
    for(i = 0; i < 8; i++){ // tabuleiro na posicao inicial
		for(j = 0; j < 8; j++){
            tabuleiro[i][j].mover = 0;
            // cor peca
			if(i < 2) tabuleiro[i][j].cor = 1;
			else if(i < 6) tabuleiro[i][j].cor = -1;
			else tabuleiro[i][j].cor = 0;
			// tipo peca
			if(i > 1 && i < 6) tabuleiro[i][j].tipo = '0';
			else if(i == 1 || i == 6) tabuleiro[i][j].tipo = 'P'; // peao
			else if(i == 0 || i == 7){
				if(j == 0 || j == 7) tabuleiro[i][j].tipo = 'T'; // torre
				else if(j == 1 || j == 6) tabuleiro[i][j].tipo = 'C'; // cavalo
				else if(j == 2 || j == 5) tabuleiro[i][j].tipo = 'B'; // bispo
				else if(j == 3) tabuleiro[i][j].tipo = 'Q'; // rainha
				else if(j == 4) tabuleiro[i][j].tipo = 'R'; // rei
			} 
		}
	}
}

// int criar_historico(char *nome_usuario, char *adversario, char *resultado_partida, int ganhos)
