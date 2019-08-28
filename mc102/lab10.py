#Yan Victor Souza Guimaraes
#RA 245875 lab10 mc102q
import math

expval=[0]
qnt=[0]
qnt*=200
expval*=200
val=[]
def check(x):
	for i in range(len(val)):
		if(val[i]==x):
			return i
	return -1
n = int(input())
for i in range(n):
	idx,pca,pcf = map(int,input().split())
	aux = check(idx)
	if(aux==-1):
		val.append(idx)
		idx = len(val)-1
	else:
		idx = aux
	exp = pcf/pca
	expval[idx]+=exp
	qnt[idx]+=1
idx,pca = map(int,input().split())
while(idx!=0 or pca!=0):
	idx = check(idx)
	print(math.ceil((pca*expval[idx])/qnt[idx]))
	idx,pca = map(int,input().split())

