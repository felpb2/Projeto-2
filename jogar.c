#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char tipo;
	int cor; // -1 = nada, 0 = branco, 1 = preto
	int ataqueB; // ataqueB > 0 casa atacada por uma peca branca
	int ataqueP; // ataqueP > 0 casa atacada por uma peca preta
} Peca;

// 'T' = torre
// 'C' = cavalo
// 'B' = bispo
// 'Q' = rainha
// 'R' = rei
// 'P' = peao
// '0' = nada

// tipo[8][8] = {
// {'T','C','B','Q','R','B','C','T'},
// {'P','P','P','P','P','P','P','P'},
// {'0','0','0','0','0','0','0','0'},
// {'0','0','0','0','0','0','0','0'},
// {'0','0','0','0','0','0','0','0'},
// {'0','0','0','0','0','0','0','0'},
// {'P','P','P','P','P','P','P','P'},
// {'T','C','B','Q','R','B','C','T'}
// };

// cor[8][8] = {
// { 1, 1, 1, 1, 1, 1, 1, 1},
// { 1, 1, 1, 1, 1, 1, 1, 1},
// {-1,-1,-1,-1,-1,-1,-1,-1},
// {-1,-1,-1,-1,-1,-1,-1,-1},
// {-1,-1,-1,-1,-1,-1,-1,-1},
// {-1,-1,-1,-1,-1,-1,-1,-1},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0}
// };

// ataqueP[8][8] = {
// { 0, 1, 1, 1, 1, 1, 1, 0},
// { 1, 1, 1, 4, 4, 1, 1, 1},
// { 2, 2, 3, 2, 2, 3, 2, 2},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0}
// };

// ataqueB[8][8] = {
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 0, 0, 0, 0, 0, 0, 0, 0},
// { 2, 2, 3, 2, 2, 3, 2, 2},
// { 1, 1, 1, 4, 4, 1, 1, 1},
// { 0, 1, 1, 1, 1, 1, 1, 0}
// };

// movimentos:
// bispo[i], i +ou- 7k, i +ou- 9k, k = int
// peao[i], i + 8 ou captura = i + 7 ou i + 9
// torre[i], i + 8k, ou i + k,  0 <= i +ou- k < 8, k = int
// rainha[i],  bispo[i] + torre[i];
// cavalo[i], i +ou- 6, i +ou- 10, i +ou- 15, i +ou- 17

void capturar(Peca (*tabuleiro)[8], int linha, int coluna){
    int i, *index;
    if(tabuleiro[linha][coluna].cor) index = &tabuleiro[linha][coluna].ataqueP;
    else index = &tabuleiro[linha][coluna].ataqueB;
    // index = armazena o endereço de ataqueB/ataqueP para que o 
    // valor seja alterado corretamente de acordo com a cor
    if(tabuleiro[linha][coluna].tipo == 'T' || tabuleiro[linha][coluna].tipo == 'Q'){ // torre
        for(i = linha + 1; i < 8; i++){
            *(index + (i - linha)*8*sizeof(int)) += 1;
            if(tabuleiro[i][coluna].tipo != '0') break;
        }
        for(i = linha - 1; i >= 0; i--){
            *(index + (i - linha)*8*sizeof(int)) += 1;
            if(tabuleiro[i][coluna].tipo != '0') break;
        }
        for(i = coluna + 1; i < 8; i++){
            *(index + (i - coluna)*sizeof(int)) += 1;
            if(tabuleiro[linha][i].tipo != '0') break;
        }
        for(i = coluna - 1; i >= 0; i--){
            *(index + (i - coluna)*sizeof(int)) += 1;
            if(tabuleiro[linha][i].tipo != '0') break;
        }
    }
    if(tabuleiro[linha][coluna].tipo == 'C'){
        if(linha + 2 < 8 && coluna + 1 < 8) *(index + 17*sizeof(int)) += 1;
        if(linha + 2 < 8 && coluna - 1 >= 0) *(index + 15*sizeof(int)) += 1;
        if(linha - 2 >= 0 && coluna + 1 < 8) *(index - 15*sizeof(int)) += 1;
        if(linha - 2 >= 0 && coluna - 1 >= 0) *(index - 17*sizeof(int)) += 1;
        if(linha + 1 < 8 && coluna + 2 < 8) *(index + 10*sizeof(int)) += 1;
        if(linha + 1 < 8 && coluna - 2 >= 0) *(index + 6*sizeof(int)) += 1;
        if(linha - 1 >= 0 && coluna + 2 < 8) *(index - 6*sizeof(int)) += 1;
        if(linha - 1 >= 0 && coluna - 2 >= 0) *(index - 10*sizeof(int)) += 1;
    }
    if(tabuleiro[linha][coluna].tipo == 'B' || tabuleiro[linha][coluna].tipo == 'Q'){ // bispo
        for(i = 1; linha + i < 8 && coluna + i < 8; i++){
            *(index + i*9*sizeof(int)) += 1;
            if(tabuleiro[linha+i][coluna+i].tipo != '0') break;
        }
        for(i = 1; linha + i < 8 && coluna - i >= 0; i++){
            *(index + i*7*sizeof(int)) += 1;
            if(tabuleiro[linha+i][coluna+i].tipo != '0') break;
        }
        for(i = 1; linha - i >= 0 && coluna + i < 8; i++){
            *(index - i*7*sizeof(int)) += 1;
            if(tabuleiro[linha+i][coluna+i].tipo != '0') break;
        }
        for(i = 1; linha - i >= 0 && coluna - i >= 0; i++){
            *(index - i*9*sizeof(int)) += 1;
            if(tabuleiro[linha+i][coluna+i].tipo != '0') break;
        }
    }
    if(tabuleiro[linha][coluna].tipo == 'R'){ // Rei
        if(linha + 1 < 8 && coluna + 1 < 8) *(index + 9*sizeof(int)) += 1;
        if(linha + 1 < 8 && coluna - 1 >= 0) *(index + 7*sizeof(int)) += 1;
        if(linha - 1 >= 0 && coluna + 1 < 8) *(index - 7*sizeof(int)) += 1;
        if(linha - 1 >= 0 && coluna - 1 >= 0) *(index - 9*sizeof(int)) += 1;
        if(linha + 1 < 8) *(index + 8*sizeof(int)) += 1;
        if(coluna + 1 >= 0) *(index + sizeof(int)) += 1;
        if(linha - 1 >= 0) *(index - 8*sizeof(int)) += 1;
        if(coluna - 1 >= 0) *(index - sizeof(int)) += 1;
    }
    if(tabuleiro[linha][coluna].tipo == 'P'){ // peao
        if(tabuleiro[linha][coluna].cor) index = &tabuleiro[linha+1][coluna].ataqueP;
        else index = &tabuleiro[linha-1][coluna].ataqueB;
        if(coluna < 7) *(index + sizeof(int)) += 1;
        if(coluna > 0) *(index - sizeof(int)) += 1;
    }
}

void jogar() {
	Peca tabuleiro[8][8];
	int i, j;
	for(i = 0; i < 8; i++){ // tabuleiro na posicao inicial
		for(j = 0; j < 8; j++){
			tabuleiro[i][j].ataqueB = 0;
            tabuleiro[i][j].ataqueP = 0;
            // cor peca
			if(i < 2) tabuleiro[i][j].cor = 1;
			else if(i < 6) tabuleiro[i][j].cor = -1;
			else tabuleiro[i][j].cor = 0;
			// tipo peca
			if(i > 1 && i < 6) tabuleiro[i][j].tipo = '0';
			else if(i == 1 || i == 6) tabuleiro[i][j].tipo = 'P';
			else if(i == 0 || i == 7){
				if(j == 0 || j == 7) tabuleiro[i][j].tipo = 'T';
				else if(j == 1 || j == 6) tabuleiro[i][j].tipo = 'C';
				else if(j == 2 || j == 5) tabuleiro[i][j].tipo = 'B';
				else if(j == 3) tabuleiro[i][j].tipo = 'Q';
				else if(j == 4) tabuleiro[i][j].tipo = 'R';
			} 
		}
	}
    
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tabuleiro[i][j].tipo == '0') continue;
            else capturar(tabuleiro,i,j);
        }
    }

	// for(i = 0; i < 8; i++){
	// 	for(j = 0; j < 8; j++) printf("%2d,", tabuleiro[i][j].cor);
	// 	printf("\n");
	// }
	// printf("\n");
	// for(i = 0; i < 8; i++){
	// 	for(j = 0; j < 8; j++) printf("%2c,", tabuleiro[i][j].tipo);
	// 	printf("\n");
	// }
    // printf("\n");
    // for(i = 0; i < 8; i++){
	// 	for(j = 0; j < 8; j++) printf("%2d,", tabuleiro[i][j].ataqueB);
	// 	printf("\n");
	// }
	// printf("\n");
	// for(i = 0; i < 8; i++){
	// 	for(j = 0; j < 8; j++) printf("%2d,", tabuleiro[i][j].ataqueP);
	// 	printf("\n");
	// }
    // printf("\n");
}
