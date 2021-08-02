#ifndef _markowitz_H_
#define _markowitz_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define NUMERO_ATIVOS 5

void preenche_vetor_aleatorio(int dimensao, double *vetor);
void normaliza_vetor(int dimensao, double *vetor);
void multiplica_matriz_vetor(int dimensao, double *produto, double matriz[NUMERO_ATIVOS][NUMERO_ATIVOS], double *vetor);
double multiplica_vetor_vetor(int dimensao, double *vetor1, double *vetor2);
void printa_matriz(int dimensao, double matriz[NUMERO_ATIVOS][NUMERO_ATIVOS]);
void printa_vetor(int dimensao, double *vetor);

#endif

