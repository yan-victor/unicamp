#include<stdio.h>
#include<stdlib.h>
#include "lab09.h"

int ini,fim,qnt,k;
int tam = 10000;

void pushback(node** v,node* val) {
	v[(fim+1)%tam] = val;
	fim = (fim+1)%tam;
	qnt++;
	if(qnt==1) ini=fim;
}

void popfront(node** v) {
	if(qnt==0) return;
	ini=(ini+1)%tam;
	qnt--;
}

void insert(node* x,node* nov) {
	//printf("x->val %d %d\n",x->v,nov->v);
	if(x->v==nov->v) return;
	//hi();
	if(x->v>nov->v) {
		if(x->l) insert(x->l,nov);
		else x->l = nov;
	} else {
		if(x->r) insert(x->r,nov);
		else x->r = nov;
	}
}

int search(node* x,int val) {
	if(x->v==val) return 1;
	if(x->v>val) {
		if(x->l) return search(x->l,val);
	    return 0;
	} else {
		if(x->r) return search(x->r,val);
		return 0;
	}
}

void preord(node* x) {
	if(!x) return;
	printf("%d ",x->v);
	preord(x->l);
	preord(x->r);
}

void inord(node* x) {
	if(!x) return;
	inord(x->l);
	printf("%d ",x->v);
	inord(x->r);
}

void postord(node* x) {
	if(!x) return;
	postord(x->l);
	postord(x->r);
	printf("%d ",x->v);
}

void bfs(node* x) {
	if(!x) return;
	node** v = malloc(10000*sizeof(node));
	pushback(v,x);
	while(qnt) {
		node* aux = v[ini];
		popfront(v);
		printf("%d ",aux->v);
		if(aux->l) pushback(v,aux->l);
		if(aux->r) pushback(v,aux->r);
	}
}

void end(node* x) {
	if(x->l) end(x->l);
	if(x->r) end(x->r);
	free(x);
}