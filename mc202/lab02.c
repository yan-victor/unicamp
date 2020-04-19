//MC202 Lab02
//Tarefa Espera
//Yan Victor Souza Guimarães
//RA 245875

#include<stdio.h>

const int INF = 0x3f3f3f3f;  //infinito

int at[15];

int max(int a,int b) {
	return a>b?a:b;
}

int main() {
	int n,c,t,d;
	int tempotot = 0;
	int maisdez = 0;
	scanf("%d %d",&c,&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&t,&d);
		int menor_atendente_tempo=INF;
		int menor_atendente;
		for(int j=0;j<c;j++) {
			if(at[j]<menor_atendente_tempo) {
				menor_atendente_tempo=at[j];
				menor_atendente = j;
			} 
		}
		//printf("a %d\n",menor_atendente_tempo);
		if(menor_atendente_tempo>t) {
			tempotot += menor_atendente_tempo-t;
			if(at[menor_atendente]-t>10) maisdez++;
		}
		at[menor_atendente]=max(t,menor_atendente_tempo)+d; 
	}
	double resp = ((double)tempotot)/((double)n);
	printf("Espera media para %d clientes: %.1lf minutos\n",n,resp);
	printf("Numero de clientes que esperaram mais que 10 minutos: %d\n",maisdez);
}