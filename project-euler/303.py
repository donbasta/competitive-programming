def good(n):
	while n>0:
		if n%10 > 2:
			return False
		n //= 10
	return True

def f(n):
	cur = n
	while not good(cur):
		cur += n
	return cur

ans = 0
for i in range(1,10001):
	ans += f(i)//i

print(ans)
