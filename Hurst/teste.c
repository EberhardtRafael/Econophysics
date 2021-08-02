#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void calculaRange(int *range, int *serie_ajustada_pela_media, int n);
int calculaExtremo(int *serie, char max_min, int n);
void calculaCu(int *bunda, int *cu);

int main(){

int n;
int  cu[10], bunda[10], serie_ajustada_pela_media[10], range[10];


	for(int i = 0; i < 10; i++) bunda[i] = rand()%10;
	
	for(int i = 0; i < 10; i++) printf("%d, %d\n", i, bunda[i]);
	
	printf("\n");
	
	//calculaCu(bunda, cu);
	calculaRange(range, bunda, 10);
	
	//for(int i = 1; i < 10; i++) printf("%d\n", range[i]);


}


void calculaRange(int *range, int *bunda, int n){

int i;
char U, D;

	for(i = 0; i < n; i++){
	
		//range[i] = calculaExtremo(bunda, U, i) - calculaExtremo(bunda, 'D', i);
		printf("%d, %d,  %d\n", i, calculaExtremo(bunda, 'D', i), calculaExtremo(bunda, 'U', i));
	
	
	} 

}

int calculaExtremo(int *serie, char max_min, int n){

int i, j;
int extremo = serie[0];

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

void calculaCu(int *bunda, int *cu){

int i, t;

	for(t = 1; t < 10; t++){
		cu[t] = 0;
		for(i = 0; i < t; i++) cu[t] += bunda[i];
	}
}
