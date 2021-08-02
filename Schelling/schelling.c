/*
Ainda tenho que fazer uma versão do programa em que posso escolher tolerâncias diferentes para as diferentes espécies, além da possibilidade de se introduzirem mais espécies.
Também, tenho que fazer a versão em que todo mundo quer se mover numa determinada direção preferencial enquanto tentam ficar próximos dos seus, só para ver o que acontece.
*/

#include "schelling_biblioteca.c"

int main(){

int i;
int coordenadaX, coordenadaY;
int repeticao, numero_felizes = 0, numero_infelizes = 0;
terreno lote[DIMENSAO_UNIVERSO][DIMENSAO_UNIVERSO];
 
	srand(time(NULL));	
	
	//Povoa o Universo com lotes contendo 0 indivíduos, de espécie 0 e de felicidade '-':
	for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				lote[coordenadaX][coordenadaY].existencia_individuo = 0;
				lote[coordenadaX][coordenadaY].especie = 0;
				lote[coordenadaX][coordenadaY].estado_felicidade = '-';
			}		
			
	seta_condicao_inicial(lote, 1, QUANTIDADE1); //Povoa a Vizinhança com QUANTIDADE1 indivíduos da espécie 1.
	seta_condicao_inicial(lote, 2, QUANTIDADE2); //Povoa a Vizinhança com QUANTIDADE2 indivíduos da espécie 2.
	
	//Comandos do Gnuplot:
	printf("set view 0, 0, 1, 1\n"); //Iniciar observando de cima.
	printf("set pm3d\n");
	printf("set ticslevel 0.0\n");
	
	//Loop que termina somente quando todos os indivíduos estiverem felizes:
	while(numero_felizes < QUANTIDADE1 + QUANTIDADE2){
	
		numero_felizes = 0; //O número de felizes será recalculado a cada loop.
		
		calculaFelicidade(lote); //Calcula a felicidade de cada indivíduo baseado na quantidade de vizinhos distintos.	
		
		//Conta o número de vizinhos calculado acima, reorganiza a vizinhança se houver infelizes.				
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++)
				if(lote[coordenadaX][coordenadaY].estado_felicidade == 'i'){
					movimentacao(lote, coordenadaX, coordenadaY);	//Se for infeliz, se muda.				
				}else if(lote[coordenadaX][coordenadaY].estado_felicidade == 'f') numero_felizes++;				
		}		
				
		printf("splot \'-\' u 1:2:3 palette\n"); //Para printar os dois níveis com cores diferentes.
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++)
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++)
				if(lote[coordenadaX][coordenadaY].especie != 0)
					printf("%d %d %d\n\n", coordenadaX, coordenadaY, lote[coordenadaX][coordenadaY].especie);
		//Tem que imprimir com uma linha em branco entre os dados, para o Gnuplot colocar em cores diferentes.		
		
		printf("e\n"); //P/ Gnuplot plotar novos dados sobre o mesmo gráfico e gerar animação.
		printf("pause 0.1\n");
		
		
		//Para printar na tela apenas os números correspondentes às espécies, comentar os prints acima e descomentar abaixo:
		/*
		printf("\n");
		for(coordenadaX = 0; coordenadaX < DIMENSAO_UNIVERSO; coordenadaX++){
			for(coordenadaY = 0; coordenadaY < DIMENSAO_UNIVERSO; coordenadaY++){
				printf("%d\t", lote[coordenadaX][coordenadaY].especie);
			
			}
			printf("\n");
		}
		*/		
	
	}
	
	printf("pause -1");
		

return 0;

}
