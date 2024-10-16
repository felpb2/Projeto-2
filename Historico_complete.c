// DATA ATUAL
void obterDataAtual(char *data) { // pega o dia/mes/ano atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Formatar a data no formato "DD/MM/AAAA"
    strftime(data, 11, "%d/%m/%Y", tm_info);
}

// HISTORICO USUARIOS
int historico_usuarios(char *nome_usuario){

	FILE * arquivo;
	
	arquivo = fopen("historico.txt","r");

	if(arquivo == NULL){  // caso o arquivo não abra corretamento 
		printf("Erro ao abrir o arquivo !!!\n");
		return 1;
	}
	
	char linhas[255];
	int verificador_de_historico = 0;
	
	
	
	while(fgets(linhas,255,arquivo)){   // fica pegando linhas até achar uma vazia

        char data[14], adversario[50], resultado_partida[9], usuario[50];
		int ganhos;


		// no arquivo -- > usuario(chave de comparacao); resultado_partida; ganhos; adversario; data
	
		int result = sscanf(linhas,"%s ; %s ; %d ; %s ; %s", usuario, resultado_partida, &ganhos, adversario, data);
		
		
		if(result == 5 && strcmp(usuario, nome_usuario) == 0) {   
		    verificador_de_historico++;  // se existe historico
		    char sinal = ' ';
		    
		    if(strcmp(resultado_partida, "Vitoria") == 0) {
		        sinal = '+';
		        printf("DATA: %-10s | Adversario: %-20s | %-8s %c %d\n", data, adversario, resultado_partida, sinal, ganhos);
		    } else if(ganhos == 0) {
		        printf("DATA: %-10s | Adversario: %-20s | %-8s\n", data, adversario, resultado_partida);
		    } else {
		        sinal = '-';
		        printf("DATA: %-10s | Adversario: %-20s | %-8s %c %d\n", data, adversario, resultado_partida, sinal, ganhos);
		    }
		}

	}
	
	if(verificador_de_historico == 0){
		printf("Usuário não jogou nenhuma partida ainda.\n");
	}
	
	fclose(arquivo);
	return 0;
}

// CRIAR HISTORICO
int criar_historico(char *nome_usuario, char *adversario, char *resultado_partida, int ganhos){

	FILE *arquivo;
	arquivo = fopen("historico.txt","a");
	
	if(arquivo == NULL){   // caso o arquivo não abra corretamento 
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



