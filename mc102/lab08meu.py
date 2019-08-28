a = int(input())
rlp=2000
klp=2000
damage=0
r=0
b=0

def f(x):
	if(x>0):
		return 1
	return 0
def pft(x):
	ans = 0
	for i in range(1,x):
		if(x%i==0):
			ans+=i
	if(ans==x):
		return True
	return False
tri = [1]
for i in range(2,64):
	tri.append(tri[len(tri)-1]+i)
#for i in range(1,10):
#	print(tri[i])

while(rlp>0 and klp>0):
	if(pft(abs(a))):
		a*=3
	elif abs(a) in tri:
		a*=2
	if(f(a)>0):
		klp-=a
	else:
		rlp+=a
	if(b==0):
		damage+=a
		b=a
		a=int(input())
		continue
	if(f(a)!=f(b)):
		if(f(damage)==1):
			print("Ken:",klp+damage,"-",damage,"=",klp)
		else:
			print("Ryu:",rlp-damage,"-",-damage,"=",rlp)
		damage = a
	else:
		damage+=a
	#print(rlp,klp,damage)
	if(rlp<=0):
		print("Ryu:",rlp-damage,"-",-damage,"=",rlp)
		break
	elif klp<=0:
		r+=1
		print("Ken:",klp+damage,"-",damage,"=",klp)
		break

	b=a
	a = int(input())
damage=0
b=0
a = int(input())
rlp=2000
klp=2000

while(rlp>0 and klp>0):
	if(pft(abs(a))):
		a*=3
	elif abs(a) in tri:
		a*=2
	if(f(a)>0):
		klp-=a
	else:
		rlp+=a
	if(b==0):
		damage+=a
		b=a
		a=int(input())
		continue
	if(f(a)!=f(b)):
		if(f(damage)==1):
			print("Ken:",klp+damage,"-",damage,"=",klp)
		else:
			print("Ryu:",rlp-damage,"-",-damage,"=",rlp)
		damage = a
	else:
		damage+=a
	if(rlp<=0):
		print("Ryu:",rlp-damage,"-",-damage,"=",rlp)
		break
	elif klp<=0:
		r+=1
		print("Ken:",klp+damage,"-",damage,"=",klp)
		break
	b=a
	a = int(input())
if r==2:
	print("Ryu venceu")
elif r==1:
	print("empatou")
else:
	print("Ken venceu")