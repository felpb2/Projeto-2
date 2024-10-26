#include "funcoes.h"

void atualizar_usuarios(Usuarios *info, int tamanho_info){
    int i;
    
    FILE * arquivo;
    arquivo = fopen("usuarios.txt","w");

    for(i = 0; i < tamanho_info; i++){
        fprintf(arquivo, "%s;%s;%s;%d \n", info[i].nome, info[i].senha, info[i].nome_jogo, info[i].pontuacao);
    }
    fclose(arquivo);
    escreve_bin(info,tamanho_info);
    return;
}

//  fei;123;fei;0  -- nome // senha // nome_jogo // pontuacao