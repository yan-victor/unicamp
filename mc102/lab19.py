func = []
def dfs(x):
	mark[x]=1
	for u in v[x]:
		if mark[u]==0: 
			dfs(u)
			func.append(u)

n,k = map(int,input().split())
mark = [0 for i in range(n)]
v = [[] for i in range(n)]
for i in range(n):
	linha = list(map(int,input().split()))
	for j in range(n):
		if(linha[j]==1):
			v[i].append(j)
dfs(k)
func.sort()
if(len(func)>0): print(k,end=" ")
else: print(k)
for i in range(len(func)):
	if(i<(len(func)-1)): print(func[i],end=" ")
	else: print(func[i])