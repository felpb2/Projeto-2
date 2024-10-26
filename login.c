#include "funcoes.h"

int login(Usuarios *info, int tamanho_info){

    char nome_usuario[20], senha[10], lixo[50];
	system("clear||cls");
	printf("+===============================+\n");
    printf("|     Bem-Vindo ao C-hadrez     |\n");
	printf("| Preencha os campos para jogar |\n");
	printf("+===============================+\n");
	printf("\n");
	printf("Nome(sem espaco): ");
	scanf(" %s", nome_usuario);
	getchar();
	printf("Senha: ");
	scanf("%s", senha);
	getchar();
	
	int i;
	for(i = 0; i < tamanho_info; i++){
		if(strcmp(info[i].nome_jogo, nome_usuario) == 0 && strcmp(info[i].senha, senha) == 0){
			printf("Usuario logado com sucesso !!!\n");
			printf("\n");
            return i;
		}
	}
    printf("Erro no Login!\n");
	printf("Digite qualquer coisa para continuar...\n");
	scanf("%s", &lixo);
	return -1;

}