/*
Este programa tem o intuito de implementar a bala de Markowitz.
Na carteira de Markowitz, é possível minimizar a volatilidade dos retornos. A volatilidade, por sua vez, é variância dos ativos.
*/

#include "markowitz_bibliotecas.c"


int main(){

double matriz_de_covariancia[NUMERO_ATIVOS][NUMERO_ATIVOS]; 
double pesos_ativos[NUMERO_ATIVOS], valoresEsperadosRetorno[NUMERO_ATIVOS];
double SW[NUMERO_ATIVOS] = {};
double  WSW, alpha0;
int i, j;


//Seja a matriz de covariância, S, dada por, como exemplo, por ora:    
matriz_de_covariancia[0][0]=2.32451;
matriz_de_covariancia[0][1]=0.72126;
matriz_de_covariancia[0][2]=0.72429;
matriz_de_covariancia[0][3]=0.58176;
matriz_de_covariancia[0][4]=-0.15729;
matriz_de_covariancia[1][0]=matriz_de_covariancia[0][1];
matriz_de_covariancia[1][1]=1.93242;
matriz_de_covariancia[1][2]=-1.41652;
matriz_de_covariancia[1][3]=2.14816;
matriz_de_covariancia[1][4]=-0.75262;
matriz_de_covariancia[2][0]=matriz_de_covariancia[0][2];
matriz_de_covariancia[2][1]=matriz_de_covariancia[1][2];
matriz_de_covariancia[2][2]=13.9427;
matriz_de_covariancia[2][3]=-2.97533;
matriz_de_covariancia[2][4]=0.92005;
matriz_de_covariancia[3][0]=matriz_de_covariancia[0][3];
matriz_de_covariancia[3][1]=matriz_de_covariancia[1][3];
matriz_de_covariancia[3][2]=matriz_de_covariancia[2][3];
matriz_de_covariancia[3][3]=5.68934;
matriz_de_covariancia[3][4]=-1.06381;
matriz_de_covariancia[4][0]=matriz_de_covariancia[0][4];
matriz_de_covariancia[4][1]=matriz_de_covariancia[1][4];
matriz_de_covariancia[4][2]=matriz_de_covariancia[2][4];
matriz_de_covariancia[4][3]=matriz_de_covariancia[3][4];
matriz_de_covariancia[4][4]=1.00834;

//Seja a seguinte matriz de valores esperados de retorno:
valoresEsperadosRetorno[0]=-0.28048;
valoresEsperadosRetorno[1]=-0.64429;
valoresEsperadosRetorno[2]=0.41381;
valoresEsperadosRetorno[3]=-0.45714;
valoresEsperadosRetorno[4]=0.41762;

	//printf("\nMatriz de covariancia:\n");
	//printa_matriz(NUMERO_ATIVOS, matriz_de_covariancia);

	for(i = 0; i < 100000; i++){
	
		srand(i+1);
		
		preenche_vetor_aleatorio(NUMERO_ATIVOS, pesos_ativos);
		
		normaliza_vetor(NUMERO_ATIVOS, pesos_ativos);

		//Produto SW:
		multiplica_matriz_vetor(NUMERO_ATIVOS, SW, matriz_de_covariancia, pesos_ativos)	;

		//Produto WSW:
		WSW = multiplica_vetor_vetor(NUMERO_ATIVOS, pesos_ativos, SW);

		//Produto alpha0 = W*alphai
		alpha0 = multiplica_vetor_vetor(NUMERO_ATIVOS, pesos_ativos, valoresEsperadosRetorno);

		printf("%f\t%f\n", alpha0, WSW);

		/*				
		printf("\nValores esperados de retorno de cada ativo:\n");
		printa_vetor(NUMERO_ATIVOS, valoresEsperadosRetorno);
		printf("\nPesos dos ativos:\n");
		printa_vetor(NUMERO_ATIVOS, pesos_ativos);
		printf("\nProduto matriz de covariancia por pesos dos ativos:\n");
		printa_vetor(NUMERO_ATIVOS, SW);
		printf("\n");
		*/		
	}
	
	
return 0;

}
