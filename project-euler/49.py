def perm(i,j):
	digit_i = []
	digit_j = []
	while i>0:
		digit_i.append(i%10)
		i //= 10
	while j>0:
		digit_j.append(j%10)
		j //= 10
	digit_j.sort()
	digit_i.sort()
	return digit_i == digit_j

N = int(1e4+69)
is_prime = [True for i in range(N)]
primes = []
prefix = [0]

#sieve
is_prime[0] = False
is_prime[1] = False
for i in range(2,N):
	if is_prime[i]:
		if(i > 1000):
			primes.append(i)
		for j in range(2*i,N,i):
			is_prime[j] = False

cnt = 0
for i in primes:
	for j in primes:
		if j <= i:
			continue
		if perm(i,j) and (2*j-i < (N-69)) and is_prime[2*j-i] and perm(i,2*j-i):
			print(i,j,2*j-i)
			cnt += 1
	if cnt == 2:
		break