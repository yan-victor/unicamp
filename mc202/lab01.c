//MC202 Lab01 
//Tarefa Submatriz
//Yan Victor Souza Guimarães
//RA 245875

#include<stdio.h>

const int N = 1010;


int max(int a,int b) {
	return a>b ? a : b;
}

int main() {
	int mat[N][N];
	int prefix[N][N];
	int n,m,r,s;
	scanf("%d %d %d %d",&n,&m,&r,&s); //leitura da entrada

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&mat[i][j]); //leitura da entrada
			prefix[i][j] = mat[i][j]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1]; //construção da soma de prefixo 2D
		}
	}

	int resposta = 0;

	//depois analisa a soma de cada matriz r por s, e pega a soma maxima

	for(int i=r;i<=n;i++) {
		for(int j=s;j<=m;j++) {
			int soma = prefix[i][j]-prefix[i][j-s]-prefix[i-r][j]+prefix[i-r][j-s];
			resposta = max(soma,resposta);
		}
	}

	printf("%d\n",resposta);
}