#Yan Victor ra245875
#lab06 - susy - mc102q

c = int(input()) #Capacidade
a = int(input()) #Tamanho carro inicial
while(a!=0):
	if(a>0):
		if(a<=c):
			c-=a
			print("Seja bem-vindo! Capacidade restante:",c)
		else:
			print("Veiculo muito grande! Capacidade restante:",c)
	else:
		c-=a
		print("Volte sempre! Capacidade restante:",c)
	a = int(input()) #Tamanho proximo carro