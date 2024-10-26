#include "funcoes.h"

// DATA ATUAL
void obterDataAtual(char *data) { // pega o dia/mes/ano atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Formatar a data no formato "DD/MM/AAAA"
    strftime(data, 11, "%d/%m/%Y", tm_info);
}

// HISTORICO USUARIOS
int historico(char *nome_usuario){

	FILE * arquivo;
	
	arquivo = fopen("historico.txt","r");

	if(arquivo == NULL){  // caso o arquivo não abra corretamento 
		printf("Erro ao abrir o arquivo !!!\n");
		return 1;
	}
	
	char linhas[255], lixo[50];
	int verificador_de_historico = 0;
	char data[14], adversario[25], resultado_partida[9], usuario[20];
	int ganhos;


	system("clear||cls");
	printf("+====================================================================+\n");
	printf("|                            Historico                               |\n");
	printf("+====================================================================+\n");

	while(fgets(linhas,255,arquivo)){   // fica pegando linhas até achar uma vazia

		// no arquivo -- > usuario(chave de comparacao); resultado_partida; ganhos; adversario; data
	
		int result = sscanf(linhas,"%s ; %s ; %d ; %s ; %s", usuario, resultado_partida, &ganhos, adversario, data);
		
		
		if(result == 5 && strcmp(usuario, nome_usuario) == 0) {   
		    verificador_de_historico++;  // se existe historico
		    char sinal = ' ';
		    
		    if(strcmp(resultado_partida, "Vitoria") == 0) {
		        sinal = '+';
		        printf("|DATA: %-15s | Adversario: %-12s | %-8s %c %5d |\n", data, adversario, resultado_partida, sinal, ganhos);
		    } else if(ganhos == 0) {
		        printf("|DATA: %-15s | Adversario: %-12s | %-8s %c %5d |\n", data, adversario, resultado_partida, ' ', 0);
		    } else {
		        sinal = '-';
		        printf("|DATA: %-15s | Adversario: %-12s | %-8s %c %5d |\n", data, adversario, resultado_partida, sinal, ganhos);
		    }
		}

	}
	printf("+====================================================================+\n");
	
	if(verificador_de_historico == 0){
		printf("Usuario nao jogou nenhuma partida ainda.\n");
	}
	
	printf("Digite qualquer coisa para continuar...\n");
	scanf(" %s", &lixo);

	fclose(arquivo);
	return 0;
}

// CRIAR HISTORICO
int criar_historico(char *nome_usuario, char *adversario, char *resultado_partida, int ganhos){

	FILE *arquivo;
	arquivo = fopen("historico.txt","a");
	
	if(arquivo == NULL){   // caso o arquivo nao abra corretamento 
		printf("Erro ao abrir o arquivo !!!\n");
		return 1;
	}
	
	char data[12];
	obterDataAtual(data);
	
	// no arquivo -- > nome_usuario; resultado_partida; ganhos; adversario; data
	// precisou escrever os items assim pora conseguir ler mellhor as linhas quando se busca o historico da pessoa
	
	fprintf(arquivo, "%s ; %s ; %d ; %s ; %s \n", nome_usuario, resultado_partida, ganhos, adversario, data);



	fclose(arquivo);
	return 0;
}
