#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PI 3.14159265359

void geraEstocastica(double *epsilon, int n);
double valorEsperado(double *vetor,int dimensao);
double variancia(double *vetor, int dimensao);
void serieAjustadaPelaMedia(double *serie_ajustada, double *serie, int n);
void calculaSerieDesviadaAcumulada(double *serie_desviada_acumulada, double *serie_ajustada_pela_media, int t);
void calculaRange(double *range, double *serie_ajustada_pela_media, int n);
double calculaExtremo(double *serie, char max_min, int n);
void desvioPadraoAteN(double *desvio_padrao, double *serie, int n);
void reescalonamento(double *range_reescalonado, double *range, double *desvio_padrao, int n);
double valorEsperadoRS(int n);


int main(){

int i, n = 500, t;
double serie[n], serie_ajustada_pela_media[n], serie_desviada_acumulada[n], range[n];
double media, var, desvio_padrao[n], media_R_S[n], range_reescalonado[n];
double soma;

	geraEstocastica(serie, n);
	valorEsperado(serie, n);
	serieAjustadaPelaMedia(serie_ajustada_pela_media, serie, n);
	calculaSerieDesviadaAcumulada(serie_desviada_acumulada, serie_ajustada_pela_media, n);
	calculaRange(range, serie_ajustada_pela_media, n);
	desvioPadraoAteN(desvio_padrao, serie, n);
	reescalonamento(range_reescalonado, range, desvio_padrao, n);
	
	for(i = 5; i < n; i++){
		soma = 0;
		for(int j = 5; j < i; j++){
			soma += range_reescalonado[j];
			//printf("%d, %lf\n",i , soma);
		}
		
		//media_R_S[i] = valorEsperado(range_reescalonado, i);
		media_R_S[i] = soma/i;
		//printf("%d, %lf\n",i , media_R_S[i]);	
	
	} 
	

	for(i = 10; i < n; i++) printf("%lf\t%lf\t%lf\t%lf\n", log(i), log(media_R_S[i]), desvio_padrao[i], log(range_reescalonado[i]));
	
	return 0;
	
}

void geraEstocastica(double *epsilon, int n){

int i;
	
	for(i = 0; i < n; i++) epsilon[i] = (rand()%1000000)/100000.;

}

double valorEsperado(double *vetor,int dimensao){

int i;
double media, soma = 0;

	for(i = 0; i < dimensao; i++) soma += vetor[i];
	
	if(dimensao > 0) media = soma/(double)dimensao;	
	else media = 0;
		
	
return media;

}

double variancia(double *vetor, int dimensao){

int i;
double variancia, soma = 0;

	for(i = 0; i < dimensao; i++) soma += pow((vetor[i] - valorEsperado(vetor, dimensao)), 2);
	
	if(dimensao > 0) variancia = soma/(double)dimensao;
	else variancia = 0;
	
	return variancia;

}

void serieAjustadaPelaMedia(double *serie_ajustada, double *serie, int n){

int i;
double media;

	media = valorEsperado(serie, n);

	for(i = 0; i < n; i++) serie_ajustada[i] = serie[i] - media;

}

void calculaSerieDesviadaAcumulada(double *serie_desviada_acumulada, double *serie_ajustada_pela_media, int n){

int i, t;

	for(t = 0; t < n; t++){
		serie_desviada_acumulada[t] = 0;
		for(i = 0; i < t; i++) serie_desviada_acumulada[t] += serie_ajustada_pela_media[i];
	}
}

void calculaRange(double *range, double *serie_ajustada_pela_media, int n){

int i;
char U, D;

	for(i = 0; i < n; i++) range[i] = calculaExtremo(serie_ajustada_pela_media, 'U', i) - calculaExtremo(serie_ajustada_pela_media, 'D', i);

}

double calculaExtremo(double *serie, char max_min, int n){

int i, j;
double extremo = serie[0];

	switch (max_min){
		case 'U': 
			for(i = 0; i < n; i++)
				if(extremo < serie[i]) extremo = serie[i];
		break;
		case 'D':
			for(i = 0; i < n; i++)
				if(extremo > serie[i]) extremo = serie[i];
		break;	
	}	
	
	return extremo;
}

void desvioPadraoAteN(double *desvio_padrao, double *serie, int n){
 int i;

	for(i = 0; i < n; i++){
		if(n > 0) desvio_padrao[i] = sqrt(variancia(serie, i));
		else desvio_padrao[i] = 0;	
	} 

}


void reescalonamento(double *range_reescalonado, double *range, double *desvio_padrao, int n){

int i;

	for(i = 0; i < n; i++) range_reescalonado[i] = range[i]/desvio_padrao[i];
}

double valorEsperadoRS(int n){

int i;
double valor_esperado_R_S;
double soma = 0;
	 
	for(i = 0; i < n; i++) soma+= sqrt((n - i)/i);
	
	if(n >= 20) valor_esperado_R_S = (1/pow(n*PI/2, 0.5))*soma;
	else if(n < 20) valor_esperado_R_S = (n - 0.5)*(1/pow(n*PI/2, 0.5))*soma/n;
	
	return valor_esperado_R_S;
}
