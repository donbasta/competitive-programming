DIV = int(1e10)

def binpow(a,b,mod=DIV):
	res = 1
	while b>0:
		if b%2==1:
			res = res*a%mod
		a = a*a%mod
		b = b//2
	return res

cur = 0
for i in range(1,1001):
	cur = cur+binpow(i,i)%DIV

cur %= DIV
print(cur)
