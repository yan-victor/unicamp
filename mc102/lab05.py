#Yan Victor RA 245875
#lab05 - Susy - MC102q

t = int(input()) #Entrada: tempo restante
c = int(input()) #Entrada: combustivel minimo para fugir
v = list(map(int,input().split()))
atual = 0
for i in range(t):
	atual += v[i]
	if(atual>=c):
		print("sim") #Saída: combustivel minimo atingido
		print(i+1)	#Saída: tempo
		break
if(atual<c):
	print("nao") #Saída: combustivel minimo nao atingido
	print(t+1) #Saída: tempo