#include "funcoes.h"

int login(Usuarios *info, int tamanho_info){

    char nome_usuario[20], senha[10];

    printf("Bem-Vindo ao C-hadrez\n");
	printf("Preencha os campos para jogar: \n");
	printf("Nome: ");
	scanf("%s", nome_usuario);
	printf("Senha: ");
	scanf("%s", senha);
	
	int i;
	for(i = 0; i < tamanho_info; i++){
		if(strcmp(info[i].nome_jogo, nome_usuario) == 0 && strcmp(info[i].senha, senha) == 0){
			printf("Usuário logado com sucesso !!!\n");
            return i;
		}
	}
    printf("Erro no Login!\n");
	return -1;

}