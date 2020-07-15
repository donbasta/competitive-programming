from math import sqrt

def is_triangle(n):
	lo = 1
	hi = int(sqrt(2*n))
	while(lo <= hi):
		mid = (lo+hi)//2
		temp = mid*(mid+1)//2
		if temp == n:
			return True
		elif temp > n:
			hi = mid-1
		elif temp < n:
			lo = mid+1
	return False

def is_pentagonal(n):
	lo = 1
	hi = 1+int(sqrt(2*n/3))
	while(lo <= hi):
		mid = (lo+hi)//2
		temp = mid*(3*mid-1)//2
		if temp == n:
			return True
		elif temp > n:
			hi = mid-1
		elif temp < n:
			lo = mid+1
	return False

cnt = 0
cur = 1
while True:
	print(cur)
	cur += 1
	temp = cur*(2*cur-1)
	if is_pentagonal(temp) and is_triangle(temp):
		print(temp)
		break