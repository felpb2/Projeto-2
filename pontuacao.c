#include "funcoes.h"

//void pontuacao(Usuarios *info,  int a, int b){return;};


void pontuacao(Usuarios *info, int player1, int player2){

    printf("|--------------------|\n
            |     Pontuações     |\n
            |--------------------|\n");
    printf(" Nome: %s | Pontuação:  %d \n", info[player1].nome_jogo, info[player1].pontuacao);
    printf(" Nome: %s | Pontuação:  %d \n", info[player2].nome_jogo, info[player2].pontuacao);

    return 0;
}