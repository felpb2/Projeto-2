#include "funcoes.h"

int JogadaValida(Peca (*tabuleiro)[8], int (*ataque)[8], int linha1, int linha2, int coluna1, int coluna2, int jogador){
    system("clear||cls");
    if(tabuleiro[linha2][coluna2].tipo != '0' &&
        tabuleiro[linha2][coluna2].cor == tabuleiro[linha1][coluna1].cor) {
        printf("Falha ao mover a peca: Impossivel capturar peca de mesma cor\n");
        return 1;
    }
    if(tabuleiro[linha1][coluna1].cor == 0 && jogador == 1 ||
    tabuleiro[linha1][coluna1].cor == 1 && jogador == 0){
        printf("Falha ao mover a peca: Peca de cor errada\n");
        return 1;
    }
    if(ataque[linha2][coluna2] == 0 || ataque[linha2][coluna2] == 2){
        printf("Falha ao mover a peca: Movimento invalido\n");
        return 1;
    }
    return 0;
}

void jogar(Usuarios *info, int player1, int player2, int tamanho_info) {
	Peca tabuleiro[8][8];
    int i, j, jogador = 0;
    int linha1, linha2, coluna1, coluna2; // linha/coluna 1 = primeira posicao ; linha/coluna 2 = segunda posicao
    int ulinha = 0,ucoluna = 0; // ulinha = ultima linha ; ucoluna = ultima coluna
    int saldo1,saldo2; // pontos ganhos/perdidos na partida
    int opcao = 0;
    int ataque[8][8];
    char posicao_peca[2], lixo[50];

    Peca vazio;
    
    vazio.tipo = '0';
    vazio.cor = -1;
    vazio.mover = 0;
    // system("clear||cls");
    montar_tabuleiro_inicial(tabuleiro);
    while(1){
        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                ataque[i][j] = 0;
            }
        }
        // system("clear||cls");
        imprimir_tabuleiro(tabuleiro, ataque, jogador, info[player1].nome_jogo, info[player2].nome_jogo);
        // jogador = 0 = branco = player1
        // jogador = 1 = preto = player2
        if(jogador == 0){
            opcao = tabela_opcoes(info, player1, player2);
            if(opcao == 1) break;
            if(opcao == 2) continue;
        }else{
            opcao = tabela_opcoes(info, player2, player1);
            if(opcao == 1) break;
            if(opcao == 2) continue;
        }
        printf("Digite a posicao da peca que voce deseja mover:\n");
        scanf(" %s", &posicao_peca);
        getchar();
        linha1 = (int)posicao_peca[0] - 97;
        coluna1 = (int)posicao_peca[1] - 49;
        printf("%d %d\n", linha1, coluna1);
        if(linha1 > 8 || coluna1 > 8 || linha1 < 0 || coluna1 < 0){
            system("clear||cls");
            printf("Erro ao mover a peca\n");
            printf("Digite qualquer coisa para continuar...\n");
            scanf("%s", &lixo);
            continue;
        }
        
        capturar(tabuleiro,linha1,coluna1,ataque,ulinha,ucoluna);
        
        // system("clear||cls");

        ataque[linha1][coluna1] = -1;
        imprimir_tabuleiro(tabuleiro, ataque, jogador, info[player1].nome_jogo, info[player2].nome_jogo);

        printf("Digite a posicao que voce deseja ir com a peca selecionada:\n");
        scanf(" %s",&posicao_peca);
        getchar();
        linha2 = (int)posicao_peca[0] - 97;
        coluna2 = (int)posicao_peca[1] - 49;
        
        if(linha2 > 8 || coluna2 > 8 || linha2 < 0 || coluna2 < 0){
            system("clear||cls");
            printf("Erro ao mover a peca\n");
            printf("Digite qualquer coisa para continuar...\n");
            scanf("%s", &lixo);
            continue;
        }
        printf("%d %d\n", linha2, coluna2);
        if(JogadaValida(tabuleiro,ataque,linha1,linha2,coluna1,coluna2,jogador)){
            printf("Digite qualquer coisa para continuar...\n");
            scanf("%s", &lixo);
            continue;
        }
        if(tabuleiro[linha2][coluna2].tipo == 'R'){
            srand(time(NULL));
            saldo1 = 10 + rand()%11;
            saldo2 = 10 + rand()%11;
            printf("+========================+\n");
            printf("|       Fim de jogo      |\n");
            if(jogador == 0){
                criar_historico(info[player1].nome_jogo, info[player2].nome_jogo, "Vitoria", saldo1);
                criar_historico(info[player2].nome_jogo, info[player1].nome_jogo, "Derrota", saldo2);

                info[player1].pontuacao += saldo1;
                info[player2].pontuacao -= saldo2;
                printf("| Vencedor: %12s |\n", info[player1].nome_jogo);
            } else{
                criar_historico(info[player2].nome_jogo, info[player1].nome_jogo, "Vitoria", saldo1);
                criar_historico(info[player1].nome_jogo, info[player2].nome_jogo, "Derrota", saldo2);

                info[player2].pontuacao += saldo2;
                info[player1].pontuacao -= saldo1;
                printf("| Vencedor: %12s |\n", info[player2].nome_jogo);
            }
            printf("+========================+\n\n");
            
            printf("Digite qualquer coisa para continuar...\n");
            scanf("%s", &lixo);
            break;
        }
        if(ataque[linha2][coluna2] == 1){
            tabuleiro[linha2][coluna2] = tabuleiro[linha1][coluna1];
            tabuleiro[linha2][coluna2].mover = tabuleiro[linha1][coluna1].mover + 1;
            tabuleiro[linha1][coluna1] = vazio;
        }
        if(ataque[linha2][coluna2] == 3){
            tabuleiro[linha2][6] = tabuleiro[linha1][4];
            tabuleiro[linha2][6].mover = tabuleiro[linha1][4].mover + 1;
            tabuleiro[linha2][5] = tabuleiro[linha1][7];
            tabuleiro[linha2][5].mover = tabuleiro[linha1][7].mover + 1;
            tabuleiro[linha1][4] = vazio;
            tabuleiro[linha1][7] = vazio;
        }
        if(ataque[linha2][coluna2] == 4){
            tabuleiro[linha2][2] = tabuleiro[linha1][4];
            tabuleiro[linha2][2].mover = tabuleiro[linha1][4].mover + 1;
            tabuleiro[linha2][3] = tabuleiro[linha1][0];
            tabuleiro[linha2][3].mover = tabuleiro[linha1][0].mover + 1;
            tabuleiro[linha1][4] = vazio;
            tabuleiro[linha1][0] = vazio;
        }
        if(ataque[linha2][coluna2] == 5){
            tabuleiro[linha2][coluna2] = tabuleiro[linha1][coluna1];
            tabuleiro[linha2][coluna2].mover = tabuleiro[linha2][coluna2].mover + 1;
            tabuleiro[linha1][coluna1] = vazio;
            tabuleiro[ulinha][ucoluna] = vazio;
        }
        if(tabuleiro[linha2][coluna2].tipo == 'P'){
            if((tabuleiro[linha2][coluna2].cor == 1 && linha2 == 7)||
            (tabuleiro[linha2][coluna2].cor == 0 && linha2 == 0))
                tabuleiro[linha2][coluna2].tipo = promocao();
        }
        ulinha = linha2;
        ucoluna = coluna2;
        jogador = 1 - jogador;
    }
    atualizar_usuarios(info, tamanho_info);
}
