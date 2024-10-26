#include "funcoes.h"

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "portuguese");

	Usuarios *info;
    info = malloc(25*sizeof(Usuarios));

	char lixo[50];
    int tamanho_info = lendo_binario(info);
    int escolha, i;
	int index_players[2] = {-1,-1};
    
    if(tamanho_info == 1){
        tamanho_info = lendo(info);
    }
	
	// menu login / cadastro

    while(1){ //verifica 
        index_players[0] = -1;
        index_players[1] = -1;
        system("clear||cls");
        printf("Oque desejam fazer?: \n");
        printf("+=======================+\n");
        printf("|         Login         |\n");
        printf("|=======================|\n");
        printf("|1 --> Cadastrar        |\n");
        printf("|2 --> Login            |\n");
        printf("|3 --> Fechar           |\n");
        printf("+=======================+\n");
        scanf("%d",&escolha);
        getchar();
        switch (escolha){
            case 1:
                cadastro(info,tamanho_info);
                tamanho_info = lendo(info);
                break;
            case 2:
                if(tamanho_info < 2){
                    
                    printf("Nao existem usuarios suficientes cadastrados!\n precisamos de mais cadastros\n");
                    printf("%d\n",tamanho_info);
                    break;
                }
                // printf("tamanho info: %d\n",tamanho_info);
                for(i = 0; i < 2; i++){
                    printf("Player %d:\n\n", i+1);
                    index_players[i] = login(info, tamanho_info); //retorna o index do usuario na struct
                    if(index_players[i] == -1) break; // caso nao encontre o index retornado sera -1
                }
                break;
            case 3:
                printf("Saindo\n");
                return 0;
            default:
                printf("Opcao invalida!!!\n");
                printf("Digite qualquer coisa para continuar...\n");
	            scanf(" %s", &lixo);
        }
        if(index_players[0] < 0 || index_players[1] < 0 || index_players[0] == index_players[1]) continue;
        
        while(!menu_jogo(index_players[0],index_players[1], info, tamanho_info));
    }
    // for(i = 0; i < tamanho_info; i++) printf("%s %s %s %d\n", info[i].nome, info[i].senha, info[i].nome_jogo, info[i].pontuacao);
    free(info);
    return 0;
}