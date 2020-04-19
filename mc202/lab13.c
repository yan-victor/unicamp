//Yan Victor Souza Guimarães RA245875
//Lab13 BFS

#include<stdio.h>
#include<stdlib.h>

int ini,fim,qnt,k;
int tam = 10000;

void pushback(int* v,int val) {
	v[(fim+1)%tam] = val;
	fim = (fim+1)%tam;
	qnt++;
	if(qnt==1) ini=fim;
}

void popfront(int* v) {
	if(qnt==0) return;
	ini=(ini+1)%tam;
	qnt--;
}

int v[10010];
int e[100010];
int deg[10010];
int ei[100010];
int ef[100010];
int cnt[10010];
int check[10010];
int dis[10010];

int bfs(int x) {
    int* q = malloc(8*sizeof(int));
    pushback(q,x);
    while(qnt) {
        int u = q[ini];
        popfront(q);
        printf("%d %d\n",u,dis[u]);
        for(int i=0;i<deg[u];i++) {
            if(!check[e[v[u]+i]]) {
                check[e[v[u]+i]]=1;
                dis[e[v[u]+i]]=dis[u]+1;
                pushback(q,e[v[u]+i]);
            }
        }
    }
} 

int main() {
    int n;
    int a,b,c=0;
    scanf("%d ",&n);
    scanf("%d,%d ",&a,&b);
    while(a) {
        deg[a]++;
        deg[b]++;
        ei[c]=a;
        ef[c]=b;
        c++;
        scanf("%d,%d ",&a,&b);
    }
    v[1]=0;
    for(int i=2;i<=n;i++) {
        v[i]=v[i-1]+deg[i-1];
    }
    for(int i=0;i<c;i++) {
        e[v[ei[i]]+cnt[ei[i]]]=ef[i];
        e[v[ef[i]]+cnt[ef[i]]]=ei[i];
        cnt[ei[i]]++;
        cnt[ef[i]]++;
    }
    int or;
    scanf("%d ",&or);
    check[or]=1;
    printf("Origem da busca: %d\n",or);
    printf("Vertices alcancados e distancias:\n");
    bfs(or);
}