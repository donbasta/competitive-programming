
N = int(1e6+69)
is_prime = [True for i in range(N)]
primes = []
prefix = [0]

#sieve
is_prime[0] = False
is_prime[1] = False
for i in range(2,N):
	if is_prime[i]:
		primes.append(i)
		for j in range(2*i,N,i):
			is_prime[j] = False

primes_part = [x for x in primes if x <= 50000]
banyak_prima = len(primes_part)

cur = 0
for i in range(banyak_prima):
	cur += primes[i]
	prefix.append(cur)


ok = False
ans = -1
for i in range(banyak_prima,0,-1):
	for j in range(banyak_prima-i,0,-1):
		temp = prefix[i+j]-prefix[j]
		print(i,j)
		if temp < (N-69) and is_prime[temp]:
			ok = True
			ans = temp
			break
	if ok:
		break


for i in range(20):
	print(is_prime[i], prefix[i])



print(ans, banyak_prima)



