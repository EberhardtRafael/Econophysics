#ifndef _arma_H_
#define _arma_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359

void calculaARMA(double *arma, double *X, int n, char sinal);
void geraBoxMuller(double *box_muller, int n);
void geraEstocastica(double *epsilon, int n);
void calculaGammap(double *gammap, double *X, int n, int p);
double valorEsperado(double *vetor,int dimensao);
double variancia(double *vetor, int dimensao);
double calculaTheta(double *gamma0, double *gamma1, double *X, double *box_muller, double phi, int n);
double calculaPhi(double *gamma0, double *gamma1, double *X, double *box_muller, int n, char sinal);

#endif
