#Yan Victor Souza Guimarães ra245875
#mc102q lab18 
import sys
mat = []
conv = []
dirx = [1,0,-1]
diry = [1,0,-1]
image = open(sys.argv[1])
s = image.readline()
s = image.readline()
m,n = map(int,s.split())
mat2 = [[0 for j in range(m)] for i in range(n)]
s = image.readline()
for i in range(n):
	s = image.readline()
	mat.append(list(map(int,s.split())))
image.close()
image = open(sys.argv[2])
s = image.readline()
d = int(s)
for i in range(3):
	s = image.readline()
	conv.append(list(map(int,s.split())))
image.close()
for i in range(n):
	for j in range(m):
		if(i==0 or j == 0 or j == m-1 or i == n-1):
			mat2[i][j]=mat[i][j]
			continue
		soma = 0
		for x in dirx:
			for y in diry:
				soma += mat[i+x][j+y]*conv[1+x][1+y]
		soma = soma//d
		mat2[i][j]=soma
		if(mat2[i][j]<0): mat2[i][j]=0
		if(mat2[i][j]>255): mat2[i][j]=255
print("P2")
print(m,n)
print("255")
for i in range(n):
	for j in range(m):
		if(j<(m-1)): print(mat2[i][j],end=" ")
		else: print(mat2[i][j],end="  ")
	print()
"""image=open("resultado.pgm","w")
image.write("P2\n")
image.write(str(m))
image.write(" ")
image.write(str(n))
image.write("\n")
image.write("255")
image.write("\n")
for i in range(n):
	for j in range(m):
		image.write(str(mat2[i][j]))
		if(j<(m-1)): image.write(" ")
	if(i<(n-1)): image.write("\n")
image.close()
"""