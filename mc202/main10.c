#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lab10.h"

void hi() {printf("hi\n");}

int main() {
	node* head = NULL;
	char q[20];
	int cnt=0;
	scanf("%s ",q);
	while(q[0]!='t') {
		if(q[0]=='i') {
			node* novo = malloc(sizeof(node));
			novo->l=NULL;
			novo->r=NULL;
			novo->pai = NULL;
			scanf("%d ",&(novo->v));
			//if(head) printf("%d\n",(*head)->v);
			if(!search(head,novo->v)) cnt++;
			if(head) insert(head,novo);
			else {
				head=novo;
			}
		} else if(!strcmp(q,"buscar")) {
			int busca;
			scanf("%d ",&busca);
			node* ax=NULL;
			if(head) ax = search(head,busca);
			if(ax) printf("%d pertence\n",busca);
			else printf("%d nao pertence\n",busca);
		} else if(q[0]=='b') {
			int l,r;
			scanf("%d %d ",&l,&r);
			int ok=0;
			intervalsearch(head,l,r,&ok);
			if(ok) printf("\n");
			else printf("nenhuma\n");
		} else if(q[0]=='p') {
			if(q[3]=='d') {
				int qry;
				scanf("%d ",&qry);
				node* nodeq = search(head,qry);
				if(nodeq) {
					nodeq = pred(nodeq);
					if(nodeq) printf("%d\n",nodeq->v);
					else printf("nao ha\n");
				} else printf("nao ha\n");
			} else {
				if(!head) printf("vazia\n");
				else {
					if(q[1]=='o') postord(head);
					else preord(head);
					printf("\n");
				}
			}
		} else if(q[0]=='e') {
			if(!head) printf("vazia\n");
			else {
				inord(head);
				printf("\n");
			}
		} else if(q[0]=='l') {
			if(!head) printf("vazia\n");
			else {
				bfs(head);
				printf("\n");
			}
		} else if(q[0]=='r') {
			int remo;
			scanf("%d ",&remo);
			node* noder = search(head,remo);
			if(noder) {
				head=rem(head,noder,cnt);
				cnt--;
			} 
			//printf("head %d\n",head->v);
		} else if(q[1]=='i') {
			if(!head) printf("vazia\n");
			else {
				node* minim = min(head);
				printf("%d\n",minim->v);
			}
		} else if(q[1]=='a') {
			if(!head) printf("vazia\n");
			else {
				node* minim = max(head);
				printf("%d\n",minim->v);
			}
		} else if(q[0]=='s') {
			int qry;
			scanf("%d ",&qry);
			node* nodeq = search(head,qry);
			if(nodeq) {
				nodeq = suc(nodeq);
				if(nodeq) printf("%d\n",nodeq->v);
				else printf("nao ha\n");
			} else printf("nao ha\n");
		}
		scanf("%s ",q);
	}
	if(head) end(head);
}