## Objetivo do projeto

Com o objetivo de propor um Xadrez com mínimo de auxilio ao usúario, desenvolvemos o C-hadez, Um tipo de xadrez totalmente livre de restrições de movimento que exige uma atenção dobrada para evitar derrotas por distrações. Nessa versão conservam-se as mecânicas básicas do xadrez convencional, pórem sem o bloqueio no movimento de peças que impedem o rei ser atacado, como também, não há avisos de xeque e xeque mate, então sempre pense duas vezes antes de mover cada peça.

## Forma de compilação
bash
```bash
for nome in {cadastro,empatar_desistir,historico,jogar,lendo_escreve,login,menu_jogo,pontuacao,ranking,tab,atualizar_usuarios,movimentos}; do gcc -o $nome.o -c $nome.c; done;
ar rcs biblioteca.a *.o
gcc -o projeto main.c biblioteca.a
```
powershell
```powershell
gcc -o cadastro.o -c cadastro.c
gcc -o empatar_desistir.o -c empatar_desistir.c
gcc -o historico.o -c historico.c
gcc -o jogar.o -c jogar.c
gcc -o lendo_escreve.o -c lendo_escreve.c
gcc -o login.o -c login.c
gcc -o menu_jogo.o -c menu_jogo.c
gcc -o pontuacao.o -c pontuacao.c
gcc -o ranking.o -c ranking.c
gcc -o tab.o -c tab.c
gcc -o atualizar_usuarios.o -c atualizar_usuarios.c
gcc -o movimentos.o -c movimentos.c
ar rcs biblioteca.a *.o
gcc -o projeto main.c biblioteca.a
```
## Modo de execução:
bash e powershell
```
./projeto
```
## Explicação sobre a forma de uso do programa:

Ao ser executado o programa apresenta aos usuários um menu inicial, permitindo que escolham entre cadastrar um novo usuário, logar com dois usuários existentes ou fechar o programa.

Cadastar um novo usuário requer seu nome, um apelido a ser exibido no jogo e uma senha. Caso o número de usuários cadastrados exceda 25, não poderão ser criados novos.

Após preencherem os campos da opção logar corretamente, os usuários serão levados ao menu do jogo, onde possuem 5 opções:
1. Jogar:
>Inicia a partida de C-hadrez, permitindo que a cada rodada os jogadores escolham entre mover uma peça, propor um empate ou desistir do jogo. Ao final da partida, são computados os pontos obtidos ou perdidos por cada jogador.

2. Ranking:
>Mostra o ranking dos jogadores, ressaltando em amarelo os dois atualmente jogados.

3. Pontuação:
>Mostra as pontuações dos dois jogadores atualmente logados.

4. Histórico:
>Mostra o histórico do jogador escolhido, contendo seu nome, o resultado da partida, os pontos obtidos ou perdidos, qual era seu adversario e a data em que ocorreu a partida. 

5. Sair:
>Retorna ao menu inicial, permitindo novamente o cadastro, login, ou apenas fechar o programa.

## Nomes:

Rafael Hideaki Yara
RA: 24.124.056-3

Maurício Yudi Kuniyoshi
RA: 24.124.032-4

Felipe Bechelli do Prado
RA: 24.124.002-7
