//MC202 Lab03
//Tarefa Contatos
//Yan Victor Souza Guimarães
//RA 245875

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct contato{
	char nome[60];
	char end[110];
	char num[15];
	char data[15];
	bool r;
};

void insert(struct contato *v,int *idx,struct contato read) {
	printf("Contato para %s inserido.\n\n",read.nome);
	v[(*idx)]=read;
	(*idx)++;

}

void rem(struct contato *v,int *idx,char *remove) {
	int qnt=0;
	for(int i=0;i<*idx;i++) {
		if(strcmp(v[i].nome,remove)==0) {
			if(!v[i].r) qnt++;
			if(!v[i].r) v[i].r=1;
		}
	}
	printf("Contatos de %s removidos: %d\n\n",remove,qnt);
}

bool attempt(char *A,char *B) {
	bool ok = 0;
	for(int i=0;i<strlen(A);i++) {
		if(A[i]==B[0]) {
			ok = 1;
			for(int j=1;j<strlen(B);j++) {
				if(A[i+j]!=B[j]) {
					ok=0;
					break;
				}
			}
			if(ok) break;
		}
	}
	return ok;
}

void search(struct contato *v,int *idx,char* query) {
	int qnt=0;
	printf("Resultado da busca:\n");
	for(int i=0;i<(*idx);i++) {
		if(v[i].r==0&&strstr(v[i].nome,query)) {
			qnt++;
			printf("(%d) %s\t%s\t%s\t%s\n",qnt,v[i].nome,v[i].end,v[i].num,v[i].data);
		}
	}
	if(qnt==0) printf("Nenhum Contato.\n");
	printf("\n");
}

void pt(struct contato *v,int *idx) {
	int qnt=0;
	printf("Listagem:\n");
	for(int i=0;i<(*idx);i++) {
		if(v[i].r==0) {
			qnt++;
			printf("(%d) %s\t%s\t%s\t%s\n",qnt,v[i].nome,v[i].end,v[i].num,v[i].data);
		}
	}
	if(qnt==0) printf("Nenhum Contato.\n");
	printf("\n");
}


int main() {
	char c;
	scanf("%c ",&c);
	int idx=0;
	struct contato v[10010];
	while(c!='f') {
		if(c=='i') {
			struct contato read;
			scanf("%[^\n] ",read.nome);
			scanf("%[^\n] ",read.end);
			scanf("%[^\n] ",read.num);
			scanf("%[^\n] ",read.data);
			read.r=0;
			insert(v,&idx,read);
		} else if(c=='r') {
			char remove[110];
			scanf("%[^\n] ",remove);
			rem(v,&idx,remove);
		} else if(c=='b') {
			char busca[110];
			scanf("%[^\n] ",busca);
			search(v,&idx,busca);
		} else pt(v,&idx);
		scanf("%c ",&c);
	}
}