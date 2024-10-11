#include <stdio.h>

#define RESET       "\033[0m"
#define LIGHT_GRAY  "\033[48;5;248m" // Fundo cinza claro
#define DARK_GRAY   "\033[48;5;22m" // Fundo cinza escuro
#define BLACK_TEXT  "\033[30m"        // Texto preto
#define WHITE_TEXT  "\033[37m"        // Texto branco

// Fun��o para imprimir o tabuleiro de xadrez com pe�as
void printBoard() {
    // Representa��o das pe�as
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, // Pe�as pretas
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // Pe�es pretos
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Casa vazia
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Casa vazia
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Casa vazia
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Casa vazia
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // Pe�es brancos
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  // Pe�as brancas
    };

	int i, j;
    for ( i = 0; i < 8; i++) {
        for ( j = 0; j < 8; j++) {
            // Alternar entre as cores de fundo
            if ((i + j) % 2 == 0) {
                printf(LIGHT_GRAY);  // Casa clara
            } else {
                printf(DARK_GRAY);    // Casa escura
            }

            // Adicionar pe�a com cor de texto apropriada
            if (board[i][j] != ' ') {
                if (board[i][j] >= 'a') {
                    printf(BLACK_TEXT " %c " RESET, board[i][j]); // Pe�as pretas
                } else {
                    printf(WHITE_TEXT " %c " RESET, board[i][j]); // Pe�as brancas
                }
            } else {
                printf("   "); // Espa�o vazio
            }
        }
        printf(RESET "\n"); // Resetar cores ap�s cada linha
    }
}
