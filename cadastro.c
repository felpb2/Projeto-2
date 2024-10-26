#include "funcoes.h"

int cadastro(Usuarios *info, int tamanho_info){


	system("clear||cls");

	Usuarios conta;
	int pontuacao, i, verificar;
	char letra[50];
	FILE *arquivo;
	
	if(tamanho_info == 25){
		printf("Limite de usuarios atingido(25)!!!\n");
		return -1;
	}
	while(1) {

		system("clear||cls");

		verificar = 0;
		printf("Bem-Vindo ao C-hadrez\n");
		printf("Preencha os campos para jogar: \n");
		
		printf("Nome: ");
		scanf("%s", conta.nome);
		getchar();
		
		printf("Nome do Usuario(max 12): ");
		scanf("%s", conta.nome_jogo);
		getchar();

		if(strlen(conta.nome_jogo) > 12){
			printf("Ultrapassou o limite de caracteres estabelecido(12) !!!\n");
			printf("Digite qualquer letra para continuar: ");
			scanf(" %s", letra);
			getchar();
			continue;
		}
		
		printf("Senha: ");
		scanf("%s", conta.senha);
		getchar();
		
		for(i = 0; i < tamanho_info; i++){
			if(!strcmp(conta.nome_jogo,info[i].nome_jogo)){
				printf("Usuario ja cadastrado!\n");
				verificar = 1;
				break;
			}
		}
		if(verificar){
			continue;
		}
		conta.pontuacao = 0;
		tamanho_info++;
		info[tamanho_info] = conta;
		break;
	}
	
	arquivo = fopen("usuarios.txt","a");
	fprintf(arquivo,"%s;%s;%s;%d\n", conta.nome, conta.senha, conta.nome_jogo, conta.pontuacao);
	fclose(arquivo);
	return 1;
}
