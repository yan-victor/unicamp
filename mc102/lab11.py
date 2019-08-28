#Yan Victor Souza Guimarães
#RA 245875 mc102q lab11

empresa = []
dp = []
compra = [0,0,0,0]
venda = [0,0,0,0]
for i in range(16):
	dp.append([])
	for j in range(16):
		dp[i].append([])
		for k in range(2):
			dp[i][j].append([])
			for l in range(4):
				dp[i][j][k].append(-1.0)
def f(x,mask,flag,emp,n):
	if x==n:
		return 0
	#print(x,mask,flag,emp)
	if(dp[x][mask][flag][emp]>-0.5):
		return dp[x][mask][flag][emp]
	if mask == 15:
		return 0
	if(flag==1):
		best = 0
		for i in range(4):
			if(i==emp):
				continue
			if(mask&(1<<i)==0):
				best = max(best,f(x+1,mask|(1<<emp),1,i,n)-empresa[i][x])
		dp[x][mask][flag][emp]=max(empresa[emp][x]+best,f(x+1,mask,flag,emp,n),f(x+1,mask|(1<<emp),1-flag,0,n)+empresa[emp][x])
		return dp[x][mask][flag][emp]
	else:
		best = f(x+1,mask,flag,emp,n)
		for i in range(4):
			if(mask&(1<<i)==0):
				best = max(best,f(x+1,mask,1-flag,i,n)-empresa[i][x])
		dp[x][mask][flag][emp]=best
		return best

n = int(input())
for i in range(4):
	empresa.append([])
	for j in range(n):
		empresa[i].append(float(input()))
#print(empresa)
#print(len(dp))
ans=f(0,0,0,0,n)
initx = 0
initmask = 0
initflag = 0
initemp = 0
compra = [-1,-1,-1,-1]
venda = [-1,-1,-1,-1]
for i in range(n-1):
	if(initflag==1):
		for j in range(4):
			if(j==initemp):
				continue
			if(initmask&(1<<j)==0):
				if(dp[i][initmask][initflag][initemp]==dp[i+1][initmask|(1<<initemp)][1][j]-empresa[j][i]+empresa[initemp][i]):
					venda[initemp]=i
					#print(initemp)
					compra[j]=i
					initemp=j
					initmask|=(1<<initemp)
		if(dp[i][initmask][initflag][initemp]==dp[i+1][initmask|(1<<initemp)][1-initflag][0]+empresa[initemp][i]):
			venda[initemp]=i
			initflag = 1 - initflag
			initmask|=(1<<initemp)
	else:
		for j in range(4):
			if(initmask&(1<<j)==0):
				if(dp[i][initmask][initflag][initemp] == dp[i+1][initmask][1-initflag][j]-empresa[j][i]):
					compra[j]=i
					initemp=j
					initflag = 1
for i in range(4):
	if(compra[i]>-1):
		if(venda[i]==-1):
			venda[i]=n-1
		print("acao %d: compra %d, venda %d, lucro %.2f" % (i+1, compra[i]+1, venda[i]+1, empresa[i][venda[i]]-empresa[i][compra[i]]))
print("Lucro: %.2f"%(ans))