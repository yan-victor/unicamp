v = []
for i in range(0,4):
	v.append(int(input()))

soma = 0

ok = False

for i in v:
	soma += i

for i in range(4):
	if 2*v[i] == soma:
		ok = True
	for j in range(i+1,4):
		if(2*(v[i]+v[j])==soma):
			ok = True
if ok:
	print("sim")
else:
	print("nao")