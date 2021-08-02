/*
Este código implementa o modelo ARMA(1,1), que é bastante utilizado em economia e serve para bastante coisa que não dá tempo de descrever aqui. Mas aí está.
*/

#include "arma_biblioteca.c"

int main(){


int i, j, dim, n = 0;
double *ARMA_plus, *ARMA_minus;
double *dolar = 0, *abertura = 0, *maxima = 0, *minima = 0, *X = 0;
char gambiarra[1000][100];
//Bah, vou fazer uma gambiarra para alocar memória aos vetores que vou ler do arquivo. Fôda-se.

	srand(time(NULL));

FILE *arq;

	arq = fopen("dados_dolar.dat", "r");
	
	if(arq == NULL) printf("Falha ao abrir o arquivo!");
	else
		while(!feof(arq)){
			fgets(*gambiarra, 60, arq);
			n++;
		}
		
	fclose(arq);	
	
	dim = n -1;
	
	dolar = malloc(dim*sizeof(double));
	abertura = malloc(dim*sizeof(double));
	maxima = malloc(dim*sizeof(double));
	minima = malloc(dim*sizeof(double));
	X = malloc(dim*sizeof(double));
	
	arq = fopen("dados_dolar.dat", "r");

	if(arq == NULL) printf("Falha ao abrir o arquivo!");
	else
		for(i = 0; i < dim; i++) fscanf(arq, "%lf\t%lf\t%lf\t%lf\t%lf\n", &dolar[i], &abertura[i], &maxima[i], &minima[i], &X[i]);
				
	fclose(arq);	
	
	//for(i = 0; i < dim; i++) printf("%lf\t%lf\t%lf\t%lf\t%lf\n", dolar[i], abertura[i], maxima[i], minima[i], X[i]);
		
	ARMA_plus = malloc(n*sizeof(double));
	ARMA_minus = malloc(n*sizeof(double));
	
	
	calculaARMA(ARMA_plus, X, n, '+');
	calculaARMA(ARMA_minus, X, n, '-');
	
	for(i = 1; i < dim; i++) printf("%d\t%lf\t%lf\t%lf\t%lf\n", dim - i, dolar[i], X[i], ARMA_plus[i], ARMA_minus[i]);
	
		
return 0;

}
