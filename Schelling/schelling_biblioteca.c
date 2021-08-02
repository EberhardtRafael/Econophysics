#include "schelling.h"

//-------------------------------------------------------------------------------------------------------------
//A movimentação acontece somente se as coordenadas "sorteadas" corresponderem a um lote vazio.
void movimentacao(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

int movimentacao = TRUE;
int coordenadaU, coordenadaV;
	
	while(movimentacao){
	
		coordenadaU = (rand()%DIMENSAO_VIZINHANCA + 1);
		coordenadaV = (rand()%DIMENSAO_VIZINHANCA + 1);
		
			if(lote[coordenadaU][coordenadaV].existencia_individuo == 0){
				lote[coordenadaU][coordenadaV].existencia_individuo = 1; //Agora há alguém no lote sorteado.
				lote[coordenadaU][coordenadaV].especie = lote[coordenadaX][coordenadaY].especie; //Mesma espécie do antigo.
				lote[coordenadaX][coordenadaY].especie = 0; //Lote antigo vazio.
				lote[coordenadaX][coordenadaY].existencia_individuo = 0;// Não esquecer de esvaziar o lote antigo!
				lote[coordenadaX][coordenadaY].estado_felicidade = '-';	//Lote antigo vazio.			
				movimentacao = FALSE;			
			}				
	}
}

//-------------------------------------------------------------------------------------------------------------
//Conta quantos vizinhos distintos existem em torno da posição atual.
int verificaVizinho(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

int i, j;
int numero_distintos = 0;

	for(i = coordenadaX -1; i <= coordenadaX + 1; i++)
			for(j = coordenadaY -1; j <= coordenadaY + 1; j++)
				if(lote[i][j].especie != 0 && lote[coordenadaX][coordenadaY].especie != lote[i][j].especie) numero_distintos++;	
	
return numero_distintos;

}

//-------------------------------------------------------------------------------------------------------------
//Verifica se o número de vizinhos é maior que o limite de tolerância dado por CONDICAO_FELICIDADE.
void calculaFelicidade(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]){

int coordenadaX, coordenadaY;
int numero_distintos;


		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++)
				if(lote[coordenadaX][coordenadaY].existencia_individuo){ //Só verifica se houver alguém no lote.
					numero_distintos = verificaVizinho(lote, coordenadaX, coordenadaY);
						if(numero_distintos > CONDICAO_FELICIDADE){
							lote[coordenadaX][coordenadaY].estado_felicidade = 'i';
						}else lote[coordenadaX][coordenadaY].estado_felicidade = 'f';					
				}
}

//-------------------------------------------------------------------------------------------------------------
//Povoa a vizinhança em coordenadas aleatórias com quantidade de especie.
void seta_condicao_inicial(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int especie, int quantidade){
	
int coordenadaU, coordenadaV, n = 0;

	while(n < quantidade){
		coordenadaU = (rand()%DIMENSAO_VIZINHANCA + 1);
		coordenadaV = (rand()%DIMENSAO_VIZINHANCA + 1);
		
			if(lote[coordenadaU][coordenadaV].existencia_individuo == 0){
				lote[coordenadaU][coordenadaV].existencia_individuo = 1;
				lote[coordenadaU][coordenadaV].especie = especie;
				n++;
				
			}				
	}

}
