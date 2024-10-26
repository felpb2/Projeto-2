#include "funcoes.h"

int escreve_bin(Usuarios *info, int tamanho_info){
    FILE *arquivo;

    arquivo = fopen("usuarios.bin", "wb");
    int i;
    for (i = 0; i < tamanho_info; i++) {
     	fwrite(&info[i], sizeof(Usuarios), 1, arquivo);
    }
    fclose(arquivo);
    return 0;
}

int lendo_binario(Usuarios *info){
    FILE *arquivo;

    int tamanho = 0;
    arquivo = fopen("usuarios.bin", "rb"); // le o arquivo de contas

    if(arquivo == NULL){
        return 1;
    }

    while (fread(&info[tamanho],sizeof(Usuarios),1 ,arquivo)) {
        tamanho++;
    }                // tamanho = quantidade de contas + 1
    fclose(arquivo); // fecha o arquivo de contas
    return tamanho;
}


// ic = 0; // (tam_info)
// arquivo = fopen("usuarios.bin", "rb"); // le o arquivo de contas
// while (fread(&info[ic],sizeof(Usuarios),1 ,arquivo)) {
// ic++;
// }                // ic = quantidade de contas + 1
// fclose(arquivo); // fecha o arquivo de contas


int lendo(Usuarios *info){
    char linha[255];
    FILE *arquivo;
    int contador = 0, posicao_struct = 0;
    arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!!!\n");
        return -1;
    }

    // verificar se o arquivo esta vazio
    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    if (tamanho == 0) {
        fclose(arquivo);
        return 0;
    }
    rewind(arquivo);  // Voltar para o início do arquivo

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';  // Remover a nova linha

        char *token = strtok(linha, " ; ");
        contador = 0;

        while (token != NULL) {
            if (contador == 0) {
                strcpy(info[posicao_struct].nome, token);
            } else if (contador == 1) {
                strcpy(info[posicao_struct].senha, token);
            } else if (contador == 2) {
                strcpy(info[posicao_struct].nome_jogo, token);
            } else if (contador == 3) {
                info[posicao_struct].pontuacao = atoi(token);
            }
            contador++;
            token = strtok(NULL, " ; ");
        }
        posicao_struct++;
    }
    fclose(arquivo);
    return posicao_struct;
}