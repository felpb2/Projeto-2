#include "funcoes.h"
// 'T' = torre
// 'C' = cavalo
// 'B' = bispo
// 'Q' = rainha
// 'R' = rei
// 'P' = peao
// '0' = nada
// 1 = preto
// 0 = branco
// -1 = nada
// jogador 0 branco
// jogador 1 preto
void reto(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int max){

    int i, lado[4] = {1,1,1,1};
    if(tabuleiro[linha][coluna].tipo == 'P'){ // se for um peao
        if(tabuleiro[linha][coluna].cor) lado[1] = 0; // preto
        else lado[0] = 0; // branco
        if(tabuleiro[linha][coluna].mover == 0) max = 2;
        lado[2] = 0;
        lado[3] = 0;
    }
    for(i = 1; i <= max; i++){
        if(linha + i < 8 && lado[0]){ // baixo
            ataque[linha+i][coluna] = 1;
            if(tabuleiro[linha+i][coluna].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha+i][coluna].cor) ataque[linha+i][coluna] = 2;
                if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha+i][coluna] = 0;
                lado[0] = 0;
            }
        }
        if(linha - i >= 0 && lado[1]){ // cima
            ataque[linha-i][coluna] = 1;
            if(tabuleiro[linha-i][coluna].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha-i][coluna].cor) ataque[linha-i][coluna] = 2;
                if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha-i][coluna] = 0;
                lado[1] = 0;
            }
        }
        if(coluna + i < 8 && lado[2]){ // direita
            ataque[linha][coluna+i] = 1;
            if(tabuleiro[linha][coluna+i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha][coluna+i].cor) ataque[linha][coluna+i] = 2;
                if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha][coluna+i] = 0;
                lado[2] = 0;
            }
        }
        if(coluna - i >= 0 && lado[3]){ // esquerda
            ataque[linha][coluna-i] = 1;
            if(tabuleiro[linha][coluna-i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha][coluna-i].cor) ataque[linha][coluna-i] = 2;
                if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha][coluna-i] = 0;
                lado[3] = 0;
            }
        }
    }
}

void diagonal(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int max){
    int i, lado[4] = {1,1,1,1};
    
    if(tabuleiro[linha][coluna].tipo == 'P'){ // se for um peao
        if(!tabuleiro[linha][coluna].cor){ // branco
            lado[0] = 0;
            lado[1] = 0;
        } else { // preto
            lado[2] = 0;
            lado[3] = 0;
        }
    }
    for(i = 1; i <= max; i++){
        if(linha + i < 8 && coluna + i < 8 && lado[0]){ // baixo direita
            ataque[linha+i][coluna+i] = 1;
            if(tabuleiro[linha+i][coluna+i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha+i][coluna+i].cor) ataque[linha+i][coluna+i] = 2;
                lado[0] = 0;
            } else if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha+i][coluna+i] = 0;
        }
        if(linha + i < 8 && coluna - i >= 0 && lado[1]){ // baixo esquerda
            ataque[linha+i][coluna-i] = 1;
            if(tabuleiro[linha+i][coluna-i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha+i][coluna-i].cor) ataque[linha+i][coluna-i] = 2;
                lado[1] = 0;
            } else if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha+i][coluna-i] = 0;
        }
        if(linha - i >= 0 && coluna + i < 8 && lado[2]){ // cima direita
            ataque[linha-i][coluna+i] = 1;
            if(tabuleiro[linha-i][coluna+i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha-i][coluna+i].cor) ataque[linha-i][coluna+i] = 2;
                lado[2] = 0;
            } else if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha-i][coluna+i] = 0;
        }
        if(linha - i >= 0 && coluna - i >= 0 && lado[3]){ // cima esquerda
            ataque[linha-i][coluna-i] = 1;
            if(tabuleiro[linha-i][coluna-i].tipo != '0'){
                if(tabuleiro[linha][coluna].cor == tabuleiro[linha-i][coluna-i].cor) ataque[linha-i][coluna-i] = 2;
                lado[3] = 0;
            } else if(tabuleiro[linha][coluna].tipo == 'P') ataque[linha-i][coluna-i] = 0;
        }
    }
}

void cavalo(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8]){

    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];
        if (novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8) {
            ataque[novaLinha][novaColuna] = 1;
            if (tabuleiro[novaLinha][novaColuna].tipo != '0') {
                if (tabuleiro[linha][coluna].cor == tabuleiro[novaLinha][novaColuna].cor) {
                    ataque[novaLinha][novaColuna] = 2; // mesma cor
                }
            }
        }
    }
}

void roque(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8]){
    int linha_rei;
    if(tabuleiro[linha][coluna].cor) linha_rei = 0; // repto
    else linha_rei = 7; // bracno
    
    if(tabuleiro[linha_rei][5].tipo == '0' && tabuleiro[linha_rei][6].tipo == '0')
        // if(!ataqueRei[linha_rei][5] && !ataqueRei[linha_rei][6])
            if(tabuleiro[linha_rei][7].tipo == 'T' && tabuleiro[linha_rei][7].mover == 0) 
                ataque[linha_rei][6] = 3; // roque pequeno

    if(tabuleiro[linha_rei][3].tipo == '0' && tabuleiro[linha_rei][2].tipo == '0' && tabuleiro[linha_rei][1].tipo == '0')
        // if(!ataqueRei[linha_rei][3] && !ataqueRei[linha_rei][2])
            if(tabuleiro[linha_rei][0].tipo == 'T' && tabuleiro[linha_rei][0].mover == 0) 
                ataque[linha_rei][2] = 4; // roque grande
}

void en_passant(Peca (*tabuleiro)[8], int (*ataque)[8], int linha, int coluna, int ulinha, int ucoluna){
    int linha_ep, lixo;
    if(tabuleiro[linha][coluna].cor == 0) linha_ep = 3; // branco
    else linha_ep = 4; // preto
    if(linha != linha_ep || ulinha != linha_ep) return;
    if(!(ucoluna == coluna + 1 || ucoluna == coluna - 1)) return;
    if(tabuleiro[ulinha][ucoluna].tipo != 'P') return;
    if(tabuleiro[ulinha][ucoluna].mover != 1) return;
    if(tabuleiro[linha][coluna].cor == 0) ataque[linha-1][ucoluna] = 5; // branco
    else ataque[linha+1][ucoluna] = 5; // preto
}

char promocao(){
	int escolha;
	char opcao[4] = {'C','T','B','Q'};
	char lixo[50];
	while(1){
		system("clear||cls");
		printf("+==================+\n");
		printf("|      Opcoes      |\n");
		printf("|==================|\n");
		printf("| 1 -- > Cavalo    |\n");
		printf("| 2 -- > Torre     |\n");
		printf("| 3 -- > Bispo     |\n");
		printf("| 4 -- > Rainha    |\n");
		printf("+==================+\n");
		scanf("%d", &escolha);
		getchar();
		if(escolha > 0 && escolha < 5) return opcao[escolha-1];
		else {
			printf("Opcao invalida!\n");
			printf("Digite qualquer coisa para continuar...\n");
			scanf("%s", &lixo);
		}
	}
}

int capturar(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int ulinha, int ucoluna){
    int i,j;
    if(tabuleiro[linha][coluna].tipo == 'T'){ // torre
        reto(tabuleiro,linha,coluna,ataque,8);
    }
    if(tabuleiro[linha][coluna].tipo == 'C'){ // CAVALO
        cavalo(tabuleiro,linha,coluna,ataque);
    }
    if(tabuleiro[linha][coluna].tipo == 'B'){ // bispo
        diagonal(tabuleiro,linha,coluna,ataque,8);
    }
    if(tabuleiro[linha][coluna].tipo == 'Q'){ // Rainha
        reto(tabuleiro,linha,coluna,ataque,8);
        diagonal(tabuleiro,linha,coluna,ataque,8);
    }
    
    if(tabuleiro[linha][coluna].tipo == 'R'){ // Rei
        diagonal(tabuleiro,linha,coluna,ataque,1);
        reto(tabuleiro,linha,coluna,ataque,1);
        if(tabuleiro[linha][coluna].mover == 0) roque(tabuleiro,linha,coluna,ataque);
    }
    if(tabuleiro[linha][coluna].tipo == 'P'){ // peao
        diagonal(tabuleiro,linha,coluna,ataque,1);
        reto(tabuleiro,linha,coluna,ataque,1);
        en_passant(tabuleiro, ataque, linha, coluna, ulinha, ucoluna);
    }
    return 0;
}
