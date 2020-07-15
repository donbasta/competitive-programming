def divisorsum(n):
	if n==1:
		return 1
	else:
		ans = 1
		for i in range(2,n):
			if i*i > n:
				break
			if n%i==0:
				ans += i
				if i*i != n:
					ans += n//i
		return ans

ami = 0

for i in range(1,10000):
	if divisorsum(divisorsum(i)) == i and divisorsum(i) != i:
		ami += i

print(ami)