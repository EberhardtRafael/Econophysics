#ifndef _schelling_H_
#define _schelling_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define DIMENSAO_UNIVERSO 20
#define DIMENSAO_VIZINHANCA 18
#define QUANTIDADE1 155 //Com essa DIMENSAO_VIZINHANCA, a simulação demora demais para rodar se QUANTIDADE(i) > 156. Fica legal com 155.
#define QUANTIDADE2 155
#define CONDICAO_FELICIDADE 2 //É muito interessante CONDICAO_FELICIDADE = 0 ou 1, mas demora demais. Tem que diminuir muito QUANTIDADE(i).
#define FALSE 0
#define TRUE 1


typedef struct vizinhanca{

int existencia_individuo;
int especie;
char estado_felicidade;

}terreno;

void movimentacao(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);
int verificaVizinho(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int coordenadaX, int coordenadaY);
void calculaFelicidade(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO]);
void seta_condicao_inicial(terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO], int especie, int quantidade);

#endif
