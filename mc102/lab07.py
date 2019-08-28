# Nome: João Vitor Rebouças Farias
# RA: 256452
# Descrição: 

pvryu = 50
pvken = 50
b=50
a=50
i=0
z=0
c=0
d=0
while pvryu > 0 and pvken > 0:
	golpes = input().split()
	x = int(golpes[i])
	if x>0:
		a = pvken - x
		if z<0:
			print("Ryu: {} - {} = {}".format(-d+b,-d,b))
			d=0
		pvken = a
	if x<0:
		b = pvryu + x
		if z>0:
			print("Ken: {} - {} = {}".format(c+a,c,a))
			c=0
		pvryu = b
	z = x
	if z>0:
		c += z
	if z<0:
		d += z
if pvryu > 0:
	print("Ken: {} - {} = {}".format(c+a,c,a))
	j = True
else:
	print("Ryu: {} - {} = {}".format(-d+b,-d,b))
	j = False
pvryu = 50
pvken = 50
i=0
z=0
c=0
d=0
while pvryu > 0 and pvken > 0:
	golpes = input().split()
	x = int(golpes[i])
	if x>0:
		a = pvken - x
		if z<0:
			print("Ryu: {} - {} = {}".format(-d+b,-d,b))
			d=0
		pvken = a
	if x<0:
		b = pvryu + x
		if z>0:
			print("Ken: {} - {} = {}".format(c+a,c,a))
			c=0
		pvryu = b
	z = x
	if z>0:
		c += z
	if z<0:
		d += z
if pvryu > 0:
	print("Ken: {} - {} = {}".format(c+a,c,a))
	l = True
else:
	print("Ryu: {} - {} = {}".format(-d+b,-d,b))
	l = False
if j==True and l==True:
	print("Ryu venceu")
elif j==False and l==False:
	print("Ken venceu")
else:
	print("empatou")