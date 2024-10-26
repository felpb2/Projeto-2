#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define RESET       "\033[0m"
#define LIGHT_GRAY  "\033[47m" // Fundo cinza claro
#define DARK_GRAY   "\033[48;2;53;103;21m" // Fundo verde
#define YELLOW 		"\033[48;2;200;160;0m" // fundo Amarelo
#define BLACK_TEXT "\033[37m"  // Texto preto
#define WHITE_TEXT "\033[30m" // Texto branco


typedef struct{
	char resultado_partida[8];
	char adversario[50];
	int ganhos;
	char data[12];
} Historico;

typedef struct {
	Historico historico[50];
	char nome[50];
	char senha[10];
	char nome_jogo[50];
	int pontuacao;
	int tam_hist;
} Usuarios;

typedef struct {
	char tipo;
	int cor;
	int mover;
} Peca;


int JogadaValida(Peca (*tabuleiro)[8], int (*ataque)[8], int linha1, int linha2, int coluna1, int coluna2, int jogador);
void jogar(Usuarios *info, int player1, int player2, int tamanho_info);
void reto(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int max);
void diagonal(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int max);
void cavalo(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8]);
void roque(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8]);
void en_passant(Peca (*tabuleiro)[8], int (*ataque)[8], int linha, int coluna, int ulinha, int ucoluna);
char promocao();
int capturar(Peca (*tabuleiro)[8], int linha, int coluna, int (*ataque)[8], int ulinha, int ucoluna);


int menu_jogo(int player1, int player2, Usuarios *info, int tamanho_info);
int login(Usuarios *info, int tamanho_info);
int cadastro(Usuarios *info, int tamanho_info);

void pontuacao(Usuarios *info, int player1, int player2);

void ranking(Usuarios *info, int tamanho, int p1, int p2);
int tabela_opcoes( Usuarios *info, int player1, int player2);
int empatar(Usuarios *info, int player1, int player2);
int desisitir(Usuarios *info, int player1, int player2);

int historico(char *nome_usuario);
int criar_historico(char *nome_usuario, char *adversario, char *resultado_partida, int ganhos);
void obterDataAtual(char *data);
void atualizar_usuarios(Usuarios *info, int tamanho_info);

int lendo(Usuarios *info);
int lendo_binario(Usuarios *info);
int escreve_bin(Usuarios *info, int tamanho_info);

void montar_tabuleiro_inicial(Peca (*tabuleiro)[8]);
void imprimir_tabuleiro(Peca (*tabuleiro)[8], int (*ataque)[8], int jogador, char *nome_p1, char *nome_p2);
int comparar(const void *a, const void *b);

#endif


