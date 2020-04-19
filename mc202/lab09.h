#include<stdlib.h>
#include<stdio.h>

struct node{
	int v;
	struct node *l,*r;
};
typedef struct node node;

void pushback(node** v,node* val);
void popfront(node** v);
void insert(node* x,node* novo);
int search(node* x,int val);
void preord(node* x);
void inord(node* x);
void postord(node* x);
void bfs(node* x);
void end(node* x);