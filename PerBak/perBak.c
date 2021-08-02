/*
Este programa implementa um autômato celular idimensional referente ao modelo de Per Bak para criticalidade auto-organizada. O modelo aqui implementado simula grãos de areia sendo empilhados em montes sobre um tabuleiro de 8X8 lados. No momento em que um dos montes atinge uma autura limite - aqui escolhida como 4, este desmorona e cada um de seus vizinhos recebe um grão a mais.
O universo deve ser maior que o tabuleiro para o caso de um mont na borda desmoronar. Em vez de aareia vazar, ela se acumula nos cantos, mas isso não interfere no comportamento central, o qual é o mais importante.
Na tentativa de melhor estruturar o programa, criando um header e uma biblioteca, o compilador alegou que eu estava defninindo duas vezes as mesmas funções, o que eu não estava. Tenho imporessão de que o problema se origina a partir da definição de uma estrutura, pois não sei como essa porra funciona em se tratando de ser global, privada e o caralho. iz a mesma coisa que em outros códigos, nos quais deu tudo certo - sem estruct.
*/

#include "perBak_library.c"

int main(){

int i, j;
int coordenadaX, coordenadaY;
int numero_graos = 100; //Uso 100 grãos somente para ter certeza de que várias células serão ativadas. Mas é demasiado.
cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]; //Cria um "tabuleiro" de DIMENSAO_TABULEIRO X DIMENSAO_TABULEIRO quadros, sendo cada um uma célula contendo várias informações (estrutura definida do header).(como eu queria fazer isso em Java...)

	srand(time(NULL));
	
	//Cria o cenário:
	for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
		for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
			tabuleiro[coordenadaX][coordenadaY].gradiente = 0; //O universo inteiro começa com 0 grãos.
			tabuleiro[coordenadaX][coordenadaY].valor_critico = 4; 
			tabuleiro[coordenadaX][coordenadaY].estado_ativacao = 0;
		}
		
	//Popula com gãos a parte do universo correspondente ao tabuleiro:
	//O tabuleiro começa em 1 para deixar uma borda vazia. É melhor deixar a simulação acontecer no canto do Universo, em vez de no centro,
	//pois o Gnuplot, por default, começa em (0,0).	
	for(coordenadaX = 1; coordenadaX < DIMENSAO_TABULEIRO; coordenadaX++)
		for(coordenadaY = 1; coordenadaY < DIMENSAO_TABULEIRO; coordenadaY++){
			tabuleiro[coordenadaX][coordenadaY].gradiente = (rand()%3 + 1); //Começo com 1 - 3 grãos, aleatoriamente.
			tabuleiro[coordenadaX][coordenadaY].valor_critico = 4;
		}	
	
	iniciaSimulacao(numero_graos, tabuleiro); //Única função que chamo no main(). Não há nenhum loop acontecendo aqui.
	//printf("pause -1\n"); //Isso é um comando do Gnuplot, onde a simulação vai rodar. Sem o Gnuplot, o programa deve ser adaptado.
	
				
return 0;

}

