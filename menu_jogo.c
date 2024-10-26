#include "funcoes.h"

int menu_jogo(int player1, int player2, Usuarios *info, int tamanho_info){
	int escolha, qual_jogador;
	char lixo[50];

	system("clear||cls");	
	printf("Oque desejam fazer?: \n");
	printf("+======================+\n");
	printf("|         Menu         |\n");
	printf("|======================|\n");
	printf("|1 --> Jogar           |\n");
	printf("|2 --> Ranking         |\n");
	printf("|3 --> Sua pontuacao   |\n");
	printf("|4 --> Historico       |\n");
	printf("|5 --> Sair            |\n");
	printf("+======================+\n");
	scanf("%d",&escolha);
    getchar();
	switch (escolha){
		case 1:
			jogar(info, player1, player2, tamanho_info);
			escreve_bin(info, tamanho_info);
			break;
		case 2:

			ranking(info, tamanho_info, player1, player2);
			break;

		case 3:

			pontuacao(info, player1, player2);
			break;

		case 4:
			system("clear||cls");
			printf("+======================+\n");
			printf("|      Historico       |\n");
			printf("|     Qual jogador     |\n");
			printf("|======================|\n");
			printf("|Jogador 1 -- > 0      |\n");
			printf("|Jogador 2 -- > 1      |\n");
			printf("+======================+\n");
			printf("Digite o seu numero: ");
			scanf("%d", &qual_jogador);
			getchar();
			if(qual_jogador == 0){
				historico(info[player1].nome_jogo);
			}else if(qual_jogador == 1){
				historico(info[player2].nome_jogo);
			}else{
				printf("Opcao invalida !!\n");
				printf("Digite qualquer coisa para continuar...\n");
				scanf(" %s", &lixo);
				getchar();
			}
					
			break;

		case 5:

			return 1;

		default:
			printf("Opcao invalida !!\n");
	}
	return 0;
}

int tabela_opcoes( Usuarios *info, int player1, int player2){
	
	int escolha;
	char lixo[50];
	printf("+==================+\n");
	printf("|      Opcoes      |\n");
	printf("|==================|\n");
	printf("| 1 -- > Mover     |\n");
	printf("| 2 -- > desistir  |\n");
	printf("| 3 -- > Empatar   |\n");
	printf("+==================+\n");
	
	scanf("%d", &escolha);
	getchar();
	
	switch (escolha){
			case 1:
				return 0;
				break;
				
			case 2:
				if(desisitir( info, player1, player2)){
					return 1;
				}else return 2;
				break;
			case 3:
				if(empatar( info, player1, player2)){
					return 1;
				} else return 2;
				break;
			default:
				printf("Opcao invalida !!!\n");
				printf("Digite qualquer coisa para continuar...\n");
				scanf(" %s", &lixo);
				return 2;

	}

	return 0;
}
