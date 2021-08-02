//Todas as bibliotecas standard utilizadas são inclusas no header.

#include "perBak.h"


//------------------------------------------------------------------------------------------------------------------------
//Ativa aleatoriamente uma célula no tabuleiro.

void iniciaSimulacao(int numero_graos, cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]){

int coordenadaU, coordenadaV;
int i;

	for(i = 0; i < numero_graos; i++){ //Ativacão() acontece numero_graos vezes aleatoriamente. 
		coordenadaU = (rand()%DIMENSAO_TABULEIRO + 1);
		coordenadaV = (rand()%DIMENSAO_TABULEIRO + 1);
		ativacao(tabuleiro, coordenadaU, coordenadaV);	
	}
	
}

//------------------------------------------------------------------------------------------------------------------------
//Aplica a regra de atualização para a célula ativada.

void ativacao(cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

	tabuleiro[coordenadaX][coordenadaY].estado_ativacao = 1;
	
	Regra(tabuleiro, coordenadaX, coordenadaY);
	
	//A ativação da célula termina aqui. O resto abaixo serve apenas para imprimir os dados, mas não faz parte do algoritmo PerBak.
	
	
	/*Os comandos seguintes servem para fazer uma animação no Gnuplot do sistema em três dimensões. Só funciona se plotar os valores num 		arquivo e depois chamar com o Gnuplot:
	>> ./perBak > blabla.dat
	>> gnuplot blabla.dat
	É fácil converter o programa para criar o arquivo, mas to com preguiça. Já fiz todo o resto...
	*/
	
	printf("set pm3d\n");
	printf("set ticslevel 0.0\n");
	printf("set xrange[0:10]\n");
	printf("set yrange[0:10]\n");
	printf("set zrange[0:5]\n");
	printf("set dgrid3d 100,100\n");
	//printf("set hidden3d\n");	
	printf("splot \'-\' u 1:2:3\n");
	
	for(int i = 0; i < DIMENSAO_UNIVERSO; i++)
		for(int j = 0; j < DIMENSAO_UNIVERSO; j++) printf("%d %d %d\n",i, j, tabuleiro[i][j].gradiente);
		
	printf("e\n");
	printf("pause 0.1\n");

	
	//Querendo printar o tabuleiro na tela apenas com os númerosd e grãos em cada célula, usar o seguinte trecho:
	/*	
	printf("\n");
	for(int i = 0; i < DIMENSAO_UNIVERSO; i++){
		for(int j = 0; j < DIMENSAO_UNIVERSO; j++){
			printf("%d\t", tabuleiro[i][j].gradiente);
		}
		printf("\n");	
	}
	printf("\n");
	*/
	
		
}

//------------------------------------------------------------------------------------------------------------------------
/*
A quantidade de grãos na célula ativada aumenta em 1. Caso numero de grãos > 4, o monte desmorona e distribui seus grãos para os vizinhos. 
A função Regra() chama a função Ativacao(), que chama a Regra() e assim por diante, até se atingir o equilíbrio. Dessa forma, a simulação pode ser longa mesmo se deixarmos cair somente um grão de areia, caso ele caisa no lugar certo e a configuração seja certa.
*/

void Regra(cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

	tabuleiro[coordenadaX][coordenadaY].gradiente += 1; //Aumenta em 1 o número de grãos.
	
	//Verifica se número de grãos > 4:
	//(Verifica se a célula ativada corresponde ao centro ou bordas do tabuleiro)
	if(tabuleiro[coordenadaX][coordenadaY].gradiente > tabuleiro[coordenadaX][coordenadaY].valor_critico){
		tabuleiro[coordenadaX][coordenadaY].gradiente -= 4;
				
			if(coordenadaX > 1 && coordenadaX < DIMENSAO_TABULEIRO){
				if(coordenadaY > 1 && coordenadaY < DIMENSAO_TABULEIRO){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);				
				}else if(coordenadaY == 1){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);				
				}else if(coordenadaY == DIMENSAO_TABULEIRO){//Deixa else if, pois se Universo > Tabuleiro, não quero ativar.
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
				}			
			}else if(coordenadaX == 1){
				if(coordenadaY > 1 && coordenadaY < DIMENSAO_TABULEIRO){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
				}else if(coordenadaY == 1){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);					
				}else if(coordenadaY == DIMENSAO_TABULEIRO){
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
				}			
			}else if(coordenadaX == DIMENSAO_TABULEIRO){
				if(coordenadaY > 1 && coordenadaY < DIMENSAO_TABULEIRO){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  + 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
				}else if(coordenadaY == 1){
					ativacao(tabuleiro, coordenadaX, (coordenadaY + 1));
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);					
				}else if(coordenadaY == DIMENSAO_TABULEIRO){
					ativacao(tabuleiro, (coordenadaX  - 1), coordenadaY);
					ativacao(tabuleiro, coordenadaX, (coordenadaY - 1));
				}	
			}
					
	}  
	
	tabuleiro[coordenadaX][coordenadaY].estado_ativacao = 0; //Desativa a célula atual.	

}
