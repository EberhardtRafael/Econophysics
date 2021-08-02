#include "markowitz.h"


//--------------------------------------------------------------------------------------------------------------------
void preenche_vetor_aleatorio(int dimensao, double *vetor){

int i;

	for(i = 0; i < dimensao; i++) vetor[i] = (rand()/(double)RAND_MAX);	
}

//--------------------------------------------------------------------------------------------------------------------
void normaliza_vetor(int dimensao, double *vetor){

int i;
double soma_entradas_vetor = 0;

	for(i = 0; i < dimensao; i++) soma_entradas_vetor += vetor[i];

	for(i = 0; i < dimensao; i++) vetor[i] = vetor[i]/soma_entradas_vetor;
}

//--------------------------------------------------------------------------------------------------------------------
void multiplica_matriz_vetor(int dimensao, double *produto, double matriz[NUMERO_ATIVOS][NUMERO_ATIVOS], double *vetor){

int i, j;



	for(i = 0; i < dimensao; i++){
		produto[i] = 0;
		for(j = 0; j < dimensao; j++)
			produto[i] += matriz[i][j]*vetor[j];
	}
		
}

//--------------------------------------------------------------------------------------------------------------------
double multiplica_vetor_vetor(int dimensao, double *vetor1, double *vetor2){

int i;
double produto = 0;

	for(i = 0; i < dimensao; i++)
		produto += vetor1[i]*vetor2[i];
		
	return produto;
}

//--------------------------------------------------------------------------------------------------------------------
void printa_matriz(int dimensao, double matriz[NUMERO_ATIVOS][NUMERO_ATIVOS]){

int i, j;

	for(i = 0; i < dimensao; i++){
		for(j = 0; j < dimensao; j++)
			printf("%f\t", matriz[i][j]);
		printf("\n");
	}
	
	printf("\n");
}

//--------------------------------------------------------------------------------------------------------------------
void printa_vetor(int dimensao, double *vetor){

int i;

	for(i = 0; i < dimensao; i++)
			printf("%f\t", vetor[i]);
	printf("\n");

}
