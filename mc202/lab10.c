#include<stdio.h>
#include<stdlib.h>
#include "lab10.h"

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
		else {
			x->l = nov;
			nov->pai = x;
		}
	} else {
		if(x->r) insert(x->r,nov);
		else {
		 	x->r = nov;
			nov->pai = x;
		}
	}
}

node* search(node* x,int val) {
	if(!x) return NULL;
	if(x->v==val) return x;
	if(x->v>val) {
		return search(x->l,val);
	} else {
		return search(x->r,val);
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

node* min(node* x) {
	if(x->l) return min(x->l);
	return x;
}

node* max(node* x) {
	if(x->r) return max(x->r);
	return x;
}

node* suc(node* x) {
	if(x->r) return min(x->r);
	node* aux = x->pai;
	while(aux) {
		if(aux->v>x->v) return aux;
		aux = aux->pai;
	}
	return NULL;
}

node* pred(node* x) {
	if(x->l) return max(x->l);
	node* aux = x->pai;
	while(aux) {
		if(aux->v<x->v) return aux;
		aux = aux->pai;
	}
	return NULL;
}

node* rem(node* y,node* x,int cnt) {
	if(cnt==1) {
		free(x);
		return NULL;
	}
	if(x->l && x->r) {
		node* aux = suc(x);
		if(aux->v==x->r->v) {
			x->r->l = x->l;
			x->r->pai = x->pai;
			if(x->pai) {
				if(x->pai->v>x->r->v) x->pai->l = x->r;
				else x->pai->r = x->r;
			} else {
				free(x);
				return aux;
				//printf("headd %d\n",y->v);
			}
		} else {
			x->v = aux->v;
			return rem(y,aux,cnt);
		}
	} else if(x->l) {
		x->l->pai = x->pai;
		if(x->pai) {
			if(x->pai->v>x->l->v) x->pai->l = x->l;
			else x->pai->r = x->l;
		} else {
			y = x->l;
			free(x);
		 	return y;
		}
 	} else if(x->r) {
 		x->r->pai = x->pai;
 		if(x->pai) {
 			if(x->pai->v>x->r->v) x->pai->l = x->r;
			else x->pai->r = x->r;
		} else {
			y = x->r;
			free(x);
			return y;
		}
 	} else if(x->pai) {
 		if(x->pai->v>x->v) {
			x->pai->l = NULL;
		}
		else x->pai->r = NULL;
 	} 
 	free(x);
 	return y;
}

void intervalsearch(node* x,int l,int r,int *ok) {
	if(!x) return;
	intervalsearch(x->l,l,r,ok);
	if(x->v>=l&&x->v<=r) {
		*ok = 1;
		printf("%d ",x->v);
	}
	intervalsearch(x->r,l,r,ok);
}

void end(node* x) {
	if(x->l) end(x->l);
	if(x->r) end(x->r);
	free(x);
}