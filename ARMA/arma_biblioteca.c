#include "arma.h"

//---------------------------------------------------------------------------------------------------------
void calculaARMA(double *arma, double *X, int n, char sinal){

double box_muller[1000], gamma0[1000], gamma1[1000];
double phi, theta;
int i;

	geraBoxMuller(box_muller, n);
	calculaGammap(gamma0, X, n, 0);
	calculaGammap(gamma1, X, n, 1);
	phi = calculaPhi(gamma0, gamma1, X , box_muller, n, sinal);	
	theta = calculaTheta(gamma0, gamma1, X, box_muller, phi, n);
	
	for(i = 1; i < n; i++) arma[i] = X[i - 1]*theta + box_muller[i] + phi*box_muller[i];
	
}

//---------------------------------------------------------------------------------------------------------
void geraBoxMuller(double *box_muller, int n){

int i;
double estocastica1[1000], estocastica2[1000];
	
	geraEstocastica(estocastica1, n);
	geraEstocastica(estocastica2, n);	
	
	for(i = 0; i < n; i++) box_muller[i] = sqrt(-2*log(estocastica1[i]))*cos(2*PI*estocastica2[i]);
	
}

//---------------------------------------------------------------------------------------------------------
void geraEstocastica(double *epsilon, int n){

int i;
	
	for(i = 0; i < n; i++) epsilon[i] = (rand()%1000000)/1000000.;

}

//---------------------------------------------------------------------------------------------------------
void calculaGammap(double *gammap, double *X, int n, int p){

int i;

	for(i = 1; i < n; i++) gammap[i] = X[i - p]*X[i];

}

//---------------------------------------------------------------------------------------------------------
double valorEsperado(double *vetor,int dimensao){

int i;
double media, soma;

	for(i = 0; i < dimensao; i++) soma += vetor[i];
		
	media = soma/(double)dimensao;
	
return media;

}

//---------------------------------------------------------------------------------------------------------
double variancia(double *vetor, int dimensao){

int i;
double variancia, soma;

	for(i = 0; i < dimensao; i++) soma += pow((vetor[i] - valorEsperado(vetor, dimensao)), 2);
	
	variancia = soma/(double)dimensao;
	
	return variancia;

}

//---------------------------------------------------------------------------------------------------------
double calculaTheta(double *gamma0, double *gamma1, double *X, double *box_muller, double phi, int n){

double numerador, denominador, theta;
	
	numerador = valorEsperado(gamma0, n) - variancia(box_muller, n)*phi + pow(valorEsperado(X,n),2); 
	denominador = valorEsperado(gamma0, n);
	
	theta = numerador/denominador;
	
	return theta;

}

//---------------------------------------------------------------------------------------------------------
double calculaPhi(double *gamma0, double *gamma1, double *X, double *box_muller, int n, char sinal){

double numerador, numerador1, numerador2, numerador3, numerador4,numerador5, numerador6, denominador;
double phi;

	numerador1 = variancia(box_muller,n)*valorEsperado(X, n)/valorEsperado(gamma0, n);		
	numerador2 = pow(numerador1, 2);	
	numerador3 = pow(valorEsperado(gamma1,n),2)/valorEsperado(gamma0,n)-valorEsperado(gamma0,n);
	numerador4 = pow(valorEsperado(X,n),2)*valorEsperado(gamma1,n)/valorEsperado(gamma0,n) + variancia(box_muller,n);
	numerador5 = numerador3 - numerador4; 
	numerador6 = 1 - variancia(box_muller,n)/valorEsperado(gamma0, n);
		switch (sinal){
			case '+': numerador = numerador1 + sqrt(numerador2 - 4*variancia(box_muller,n)*numerador5*numerador6); //Para phi+
			break;
			case '-': numerador = numerador1 - sqrt(numerador2 - 4*variancia(box_muller,n)*numerador5*numerador6); //Para phi-
			break;		
		}
	
	denominador = 2*variancia(box_muller,n)*numerador5;
	
	phi = numerador/denominador;
	
return phi;
	
}

//---------------------------------------------------------------------------------------------------------

/*
void correlacao(double *vetor1, double *vetor2, int dimensao){

int i, j;
double numerador, denominador1, denominador2, correlacao;
double vetor12[dimensao], vetor11[dimensao], vetor22(dimensao);

	produto_vetor_vetor(dimensao, vetor1, vetor2, vetor12);
	produto_vetor_vetor(dimensao, vetor1, vetor1, vetor11);
	produto_vetor_vetor(dimensao, vetor2, vetor2, vetor22);

	numerador = valorEsperado(vetor12, dimensao) - valorEsperado(vetor1, dimensao)*valorEsperado(vetor2, dimensao);
	denominador1 = sqrt(valorEsperado(vetor11, dimensao)) - pow(sqrt(valorEsperado(vetor11, dimensao)),2);
	denominador2 = sqrt(valorEsperado(vetor22, dimensao)) - pow(sqrt(valorEsperado(vetor22, dimensao)),2); //Dividi para caber.
	
	correlacao = numerador/(denominador1*denominador2);
	
}
*/
