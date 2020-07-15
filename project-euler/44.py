from math import sqrt

def pentagonal(n):
	return n*(3*n-1)//2

def is_pentagonal(n):
	lo = 1
	hi = 1+int(sqrt(2*n/3))
	while(lo <= hi):
		mid = (lo+hi)//2
		temp = pentagonal(mid)
		if temp == n:
			return True
		elif temp > n:
			hi = mid-1
		elif temp < n:
			lo = mid+1
	return False

print(is_pentagonal(6))

lol = 1
cur = pentagonal(lol)
ok = False
while True:
	now = 1
	print(cur)
	while True:
		print(now, " lol")
		a = pentagonal(now)
		if a+cur < pentagonal(now+1):
			break
		elif not is_pentagonal(a+cur):
			now += 1
			continue
		elif is_pentagonal(2*a+cur):
			print(cur) 
			ok = True
			break
		now += 1
	lol += 1
	cur = pentagonal(lol)
	if ok:
		break