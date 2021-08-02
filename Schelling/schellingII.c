#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define DIMENSAO_UNIVERSO 52
#define DIMENSAO_VIZINHANCA 50
#define QUANTIDADE1 1000
#define QUANTIDADE2 1000
#define CONDICAO_FELICIDADE 2
#define FALSE 0
#define TRUE 1

//-------------------------------------------------------------------------------------------------------------

typedef struct vizinhanca{

int existencia_individuo;
int especie;
char estado_felicidade;

}terreno;

//-------------------------------------------------------------------------------------------------------------
void movimentacao(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);
int verificaVizinho(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);
void calculaFelicidade(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]);
void seta_condicao_inicial(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int especie, int quantidade);

//-------------------------------------------------------------------------------------------------------------

int main(){

int i;
int coordenadaX, coordenadaY;
int repeticao, numero_felizes = 0, numero_infelizes = 0;
terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO];
 
	srand(time(NULL));	
	
	for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				lote[coordenadaX][coordenadaY].existencia_individuo = 0;
				lote[coordenadaX][coordenadaY].especie = 0;
				lote[coordenadaX][coordenadaY].estado_felicidade = '-';
			}				
			
	seta_condicao_inicial(lote, 1, QUANTIDADE1);
	seta_condicao_inicial(lote, 2, QUANTIDADE2);
	
	calculaFelicidade(lote);
				
	/*
	while(numero_felizes < QUANTIDADE1 + QUANTIDADE2){
	
		numero_felizes = 0;
		
		calculaFelicidade(lote);		
						
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++)
				if(lote[coordenadaX][coordenadaY].estado_felicidade == 'i'){
					movimentacao(lote, coordenadaX, coordenadaY);					
				}else if(lote[coordenadaX][coordenadaY].estado_felicidade == 'f') numero_felizes++;
				
		}		
		
			
		printf("splot \'-\' u 1:2:3\n");
		
		printf("\n");
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				printf("%d %d %d\n", coordenadaX, coordenadaY, lote[coordenadaX][coordenadaY].especie);
			
			}
			//printf("\n");
		
		
		printf("e\n");
		//printf("pause 0.1\n");		
	
		}
		printf("pause -1");
		
		
		
		printf("\n");
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				printf("%d\t", lote[coordenadaX][coordenadaY].especie);
			
			}
			printf("\n");
		}
				
	
	}
	*/	

return 0;

}

//-------------------------------------------------------------------------------------------------------------
void movimentacao(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

int movimentacao = TRUE;
int coordenadaU, coordenadaV;
	
	while(movimentacao){
	
		coordenadaU = (rand()%DIMENSAO_VIZINHANCA + 1);
		coordenadaV = (rand()%DIMENSAO_VIZINHANCA + 1);
		
			if(lote[coordenadaU][coordenadaV].existencia_individuo == 0){
				lote[coordenadaU][coordenadaV].existencia_individuo = 1;
				lote[coordenadaU][coordenadaV].especie = lote[coordenadaX][coordenadaY].especie;
				lote[coordenadaX][coordenadaY].existencia_individuo = 0;
				lote[coordenadaX][coordenadaY].existencia_individuo = 0;
				lote[coordenadaX][coordenadaY].estado_felicidade = '-';				
				movimentacao = FALSE;			
			}				
	}
	
	calculaFelicidade(lote);
}


//-------------------------------------------------------------------------------------------------------------
int verificaVizinho(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY){

int i, j;
int numero_distintos = 0;

	for(i = coordenadaX -1; i <= coordenadaX + 1; i++)
			for(j = coordenadaY -1; j <= coordenadaY + 1; j++)
				if(lote[i][j].especie != 0 && lote[coordenadaX][coordenadaY].especie != lote[i][j].especie) numero_distintos++;	
	
return numero_distintos;

}

//-------------------------------------------------------------------------------------------------------------
void calculaFelicidade(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]){

int coordenadaX, coordenadaY;
int numero_distintos;


		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++)
				if(lote[coordenadaX][coordenadaY].existencia_individuo){
					numero_distintos = verificaVizinho(lote, coordenadaX, coordenadaY);
						if(numero_distintos > CONDICAO_FELICIDADE){
							lote[coordenadaX][coordenadaY].estado_felicidade = 'i';
							movimentacao(lote, coordenadaX, coordenadaY);
						}else lote[coordenadaX][coordenadaY].estado_felicidade = 'f';					
				}
				
		printf("splot \'-\' u 1:2:3\n");
		
		printf("\n");
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				printf("%d %d %d\n", coordenadaX, coordenadaY, lote[coordenadaX][coordenadaY].especie);
			
			}
			//printf("\n");
		
		}
		printf("e\n");
		printf("pause 0.2\n");		
	
		
		//printf("pause -1");
}

//-------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------


