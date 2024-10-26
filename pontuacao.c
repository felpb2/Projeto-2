#include "funcoes.h"

//void pontuacao(Usuarios *info,  int a, int b){return;};


void pontuacao(Usuarios *info, int player1, int player2){
    char lixo[50];
    system("clear||cls");
    printf("+============================================+\n");
    printf("|                 Pontuacoes                 |\n");
    printf("+============================================+\n");
    printf("| Nome: %-12s | Pontuacao:  %9d |\n", info[player1].nome_jogo, info[player1].pontuacao);
    printf("| Nome: %-12s | Pontuacao:  %9d |\n", info[player2].nome_jogo, info[player2].pontuacao);
    printf("+============================================+\n");
    
    printf("Digite qualquer coisa para continuar...\n");
	scanf(" %s", lixo);
    return;
}