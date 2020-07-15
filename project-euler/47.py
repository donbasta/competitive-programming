from math import sqrt


def banyak_faktor_prima(n):
	cnt = 0
	temp = n
	for i in range(2,int(sqrt(n))):
		if temp%i == 0:
			cnt += 1
			while temp%i == 0:
				temp //= i
	if temp > 1:
		cnt += 1
	return cnt

def yes(n):
	a = (banyak_faktor_prima(n)==4)
	b = (banyak_faktor_prima(n+1)==4)
	c = (banyak_faktor_prima(n+2)==4)
	d = (banyak_faktor_prima(n+3)==4)
	return a and b and c and d

cur = 1
while True:
	if yes(cur):
		print(cur)
		break
	cur += 1
