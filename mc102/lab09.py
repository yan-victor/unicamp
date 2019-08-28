#Yan Victor Souza Guimarães
#RA 245875

n = int(input())
ans=0
for i in range(1,n+1):
	for j in range(1,n+1):
		if(i%j==0 or j%i==0):
			ans+=1
			print("*",end="")
		else:
			print("-",end="")
	print()
print(ans)