#include "funcoes.h"

int empatar(Usuarios *info, int player1, int player2){
	char DecisaoP1, DecisaoP2;
	char lixo[50];
	printf("Desejam empatar(S/N)?\n");
	printf("escolha Player --> %s:\n", info[player1].nome_jogo);
	scanf(" %c", &DecisaoP1);

	printf("escolha Player --> %s:\n", info[player2].nome_jogo);
	scanf(" %c", &DecisaoP2);

	if (DecisaoP1 == 'S' && DecisaoP2 == 'S') {

		printf(" --  Empatada  -- \n");
		criar_historico(info[player1].nome_jogo, info[player2].nome_jogo, "Empate", 0);
		criar_historico(info[player2].nome_jogo, info[player1].nome_jogo, "Empate", 0);
		printf("Digite qualquer coisa para continuar...\n");
		scanf("%s", &lixo);
		return 1;

	}
	
	printf("Empate negado !!!\n");
	printf("Digite qualquer coisa para continuar...\n");
	scanf("%s", &lixo);
	return 0;
}

int desisitir(Usuarios *info, int player1, int player2){
	char lixo[50];
    char Decisao;
	int saldo1, saldo2;
    printf("Deseja mesmo desistir?(S/N):\n");
	printf("Player -- > %s\n", info[player1].nome_jogo);
    scanf(" %c", &Decisao);
    if (Decisao == 'S') {
        printf("Desistencia, fim de jogo!\n");
		srand(time(NULL));
		saldo1 = 10 + rand()%11;
		saldo2 = 10 + rand()%11;

	
		criar_historico(info[player1].nome_jogo, info[player2].nome_jogo, "Derrota", saldo2);
		criar_historico(info[player2].nome_jogo, info[player1].nome_jogo, "Vitoria", saldo1);

		info[player1].pontuacao -= saldo1;
		info[player2].pontuacao +=  saldo2;
		printf("Digite qualquer coisa para continuar...\n");
		scanf("%s", &lixo);
	
		return 1;
    }
		
	printf("Desistencia negada !!\n");
	printf("Digite qualquer coisa para continuar...\n");
	scanf("%s", &lixo);
	return 0;
}
