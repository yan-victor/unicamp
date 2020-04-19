//Yan Victor RA245875
//Lab 10 - MC202

#include<stdlib.h>
#include<stdio.h>

struct node{
	int v;
	struct node *l,*r,*pai;
};
typedef struct node node;

void pushback(node** v,node* val);
void popfront(node** v);
void insert(node* x,node* novo);
node* search(node* x,int val);
void preord(node* x);
void inord(node* x);
void postord(node* x);
void bfs(node* x);
node* min(node* x);
node* max(node* x);
node* suc(node* x);
node* pred(node* x);
node* rem(node* y,node* x,int cnt);
void intervalsearch(node* x,int l,int r,int *ok);
void end(node* x);