#include<stdio.h>
#include<stdlib.h>

int ini,fim,tam=2,qnt,k;

void doubl(int* v) {
	printf("a\n");
	int* d = (int*)malloc((2*tam)*sizeof(int));
	for(int i=0;i<qnt;i++) {
		d[i]=v[(i+ini)%tam];
		printf("AAA %d %d %d %d\n",i,ini,d[i],fim); //debug
	}
	printf("aba\n");
	free(v);
	printf("bbb\n");
	v = (int*)malloc((2*tam)*sizeof(int));
	//v = d;
	for(int i=0;i<qnt;i++) {
		v[i]=(int)d[i];
		printf("BBB %d %d %d %d\n",i,ini,d[i],fim); //debug
	}
	printf("aaaa\n");
	free(d);
	tam*=2;
	ini=0;
	fim=qnt-1;
	printf("aa\n");
}

void half(int* v) {
	printf("b\n");
	int* d = (int*)malloc((tam>>1)*sizeof(int));
	for(int i=0;i<qnt;i++) {
		d[i]=(int)v[(i+ini)%tam];
	}
	free(v);
	v = (int*)malloc((tam>>1)*sizeof(int));
	for(int i=0;i<qnt;i++) {
		v[i]=(int)d[i];
	}
	free(d);
	tam>>=1;
	ini=0;
	fim=qnt-1;
	printf("bb\n");
} 

void pushfront(int* v,int val) {
	if(qnt==tam) doubl(v);
	v[(tam+ini-1)%tam]=val;
	ini = (tam+ini-1)%tam;
	qnt++;
	if(qnt==1) fim=ini;
}

void popfront(int* v) {
	if(qnt==0) return;
	ini=(ini+1)%tam;
	qnt--;
	if(!qnt) return;
	if(tam>=4*qnt) half(v);
}

void printfront(int* v) {
	if(!qnt) return;
	printf("%d\n",v[ini]);
}

void pushback(int* v,int val) {
	if(qnt==tam) doubl(v);
	v[(fim+1)%tam] = val;
	// /printf("wtf %d %d\n",fim,tam);
	fim = (fim+1)%tam;
	//printf("wtf %d %d\n",fim,tam);
	qnt++;
	if(qnt==1) ini=fim;
}

void popback(int* v) {
	if(qnt==0) return;
	fim=(tam+fim-1)%tam;
	qnt--;
	if(!qnt) return;
	if(tam>=4*qnt) half(v);
}

void printback(int* v) {
	if(!qnt) return;
	printf("%d\n",v[fim]);
}

void isempty() {
	if(qnt==0) printf("yes\n");
	else printf("no\n");
}

int main() {
	int* v = (int*)malloc(tam*sizeof(int));
	char* query;
	scanf("%s ",query);
	while(query[0]!='e') {
		k++;
		if(query[0]=='i') {
			if(query[1]=='s') isempty();
			else if(query[7]=='f') {
				int val;
				scanf("%d ",&val);
				pushfront(v,val);
			} else {
				int val;
				scanf("%d ",&val);
				pushback(v,val);
			}
		} else if(query[0]=='r') {
			if(query[7]=='f') popfront(v);
			else popback(v);
		} else {
			if(query[6]=='f') printfront(v);
			else printback(v);
		}
		scanf("%s ",query);
		printf("HO ");
		for(int i=0;i<tam;i++) {
			printf("%d ",v[i]);
		}
		printf("\n");
		printf("%d %d\n",ini,fim);
	}
	free(v);
}