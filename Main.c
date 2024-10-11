#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teste{
	char nome[50];
	char senha[10];
	char nome_jogo[50];
	int pontuacao;

} Usuarios;


int lendo(){
	printf("Lendo arquivo!!\n");
	return 0;
}

int main(int argc, char *argv[]){

	Usuarios *info;
    info = malloc(25*sizeof(Usuarios));
    
	int tamanho_info = lendo(info);
	int escolha, i;

	/*
	int index_players[3];
	// menu login / cadastro
	for(i = 0; i < tamanho_info; i++){ //prototipo leitura
		printf("%s, %s, %s, %d\n", info[i].nome, info[i].nome_jogo, info[i].senha, info[i].pontuacao);
	}
	*/

	for(i = 0; i < 3; i++){
		escolha = 1;
		while(escolha){
            printf("Oque desejam fazer?: \n");
			printf("|----------------------|\n");
			printf("|         Login        |\n");
			printf("|----------------------|\n");
			printf("|1 --> Cadastrar       |\n");
			printf("|2 --> Login           |\n");
			printf("|3 --> Fechar          |\n");
			printf("|----------------------|\n");
			scanf("%d",&escolha);
            getchar();
		    switch (escolha){
		        case 1:
					printf("Hello World!!\n");
					break;
				case 2:
					if(!tamanho_info){
						printf("Hello World!!\n");
						break;
					}
					printf("Hello World!!\n");
					break;
				case 3:
					printf("Saindo\n");
					return 0;
				default:
					printf("Op  o inv lida!!!\n");
			}
		}
	}

	return 0;
}
