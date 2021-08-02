#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#ifndef _perBak_H_
#define _perBak_H_

#define DIMENSAO_UNIVERSO 100 
#define DIMENSAO_TABULEIRO 10


typedef struct celula{

int gradiente;
int valor_critico;
int estado_ativacao;

}cell;

void iniciaSimulacao(int numero_graos, cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]);
void ativacao(cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);
void Regra(cell tabuleiro[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);

#endif
