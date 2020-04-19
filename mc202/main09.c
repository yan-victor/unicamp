#include<stdlib.h>
#include<stdio.h>
#include "lab09.h"

void hi() {printf("hi\n");}

int main() {
	node* head = NULL;
	char q[20];
	scanf("%s ",q);
	while(q[0]!='t') {
		if(q[0]=='i') {
			node* novo = malloc(sizeof(node));
			novo->l=NULL;
			novo->r=NULL;
			scanf("%d ",&(novo->v));
			//if(head) printf("%d\n",(*head)->v);
			if(head) insert(head,novo);
			else {
				head=novo;
			}
		} else if(q[0]=='b') {
			int busca;
			scanf("%d ",&busca);
			int ax = 0;
			if(head) ax = search(head,busca);
			if(ax) printf("%d pertence\n",busca);
			else printf("%d nao pertence\n",busca);
		} else if(q[0]=='p') {
			if(!head) printf("vazia\n");
			else {
				if(q[1]=='r') {
					preord(head);
				} else postord(head);
				printf("\n");
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
		} 
		scanf("%s ",q);
	}
	if(head) end(head);
}