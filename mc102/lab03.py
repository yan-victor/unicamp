r = (float(input()))/2
h = float(input())
dA = float(input())
dB = float(input())
dC = float(input())
pi = 3.14
vol = pi*r*r*h*1e3
if vol>=dA:
	print("posto A foi reabastecido")
	vol -= dA
	if(vol>=dB):
		print("posto B foi reabastecido")
		vol -= dB
		if(vol>=dC):
			print("posto C foi reabastecido")
		else:
			print("posto C nao foi reabastecido")
	elif vol>=dC:
		print("posto B nao foi reabastecido")
		print("posto C foi reabastecido")
	else:
		print("posto B nao foi reabastecido")
		print("posto C nao foi reabastecido")
elif vol>=dB:
	print("posto A nao foi reabastecido")
	print("posto B foi reabastecido")
	vol -= dB
	if(vol>=dC):
		print("posto C foi reabastecido")
	else:
		print("posto C nao foi reabastecido")
elif vol>=dC:
	print("posto A nao foi reabastecido")
	print("posto B nao foi reabastecido")
	print("posto C foi reabastecido")
else:
	print("posto A nao foi reabastecido")
	print("posto B nao foi reabastecido")
	print("posto C nao foi reabastecido")
