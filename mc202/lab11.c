//RA245875 Lab11 - Hashing
//Yan Victor Souza GuimarÃ£es

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define ll long long
#define TAM 5381
const int mod = 1000000007;

struct pair{
	int val;
	char* pal;
};
typedef struct pair pair;

pair tab[TAM];
 
ll rh(char *str) {
  int tam = strlen(str);
  ll sum = 0;
  ll p = 7451;
  ll pp = 1;
  for(int i=tam-1;i>=0;i--) {
	sum = (sum+((ll)(str[i]))*pp)%mod;  
	pp=(pp*p)%mod;	
  }
  return sum;
}

ll rh2(char *str) {
  int tam = strlen(str);
  ll p = 2417;
  ll sum = 0;
  ll pp = 1;
  for(int i=tam-1;i>=0;i--) {
	sum = (sum+((ll)str[i])*pp)%mod;  
	pp=(pp*p)%mod;	
  }
  return sum;
}

void insert(char* str,int* idx) {
	ll k = 0;
	while(1) {
		ll hash = (rh(str)+k*rh2(str))%mod;
		hash = hash%TAM;
		if(tab[hash].val==-1||tab[hash].val==-2) {
			tab[hash].val=*idx;
			(*idx)++;
			tab[hash].pal=str;
			break;
		}
		k++;
	}
}

int search(char* str) {
	ll k = 0;
	while(1) {
		ll hash = (rh(str)+k*rh2(str))%mod;
		hash = hash%TAM;
		if(tab[hash].val>=0||tab[hash].val==-2) {
			if(!strcmp(tab[hash].pal,str)) return tab[hash].val;
		} else return -1;
		k++;
	}
}

void rem(char* str) {
	ll k = 0;
	while(1) {
		ll hash = (rh(str)+k*rh2(str))%mod;
		hash = hash%TAM;
		if(tab[hash].val>=0||tab[hash].val==-2) {
			if(!strcmp(tab[hash].pal,str)) {
				tab[hash].val=-2;
				tab[hash].pal="0";
			}
		} else return;
		k++;
	}
}
 
int main() {
	int idx=0;
	char q;
	char* qry;
	for(int i=0;i<TAM;i++) {
		tab[i].val=-1;
	}
	scanf("%c ",&q);
	while(q!='f') {
		if(q=='i') {
			scanf("%s ",qry);
			if(search(qry)==-1) insert(qry,&idx);
		} else if(q=='r') {
			scanf("%s ",qry);
			rem(qry);
		} else {
			scanf("%s ",qry);
			int aux = search(qry);
			if(aux>=0) printf("%s encontrada, id %d\n",qry,aux);
			else printf("%s nao encontrada\n",qry);
		}
		scanf("%c ",&q);
	}
}