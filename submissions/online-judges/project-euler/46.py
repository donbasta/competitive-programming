from math import sqrt

def is_prime(n):
	for i in range(2,int(sqrt(n))+1):
		if n%i==0:
			return False
	return True

cur = 7
while True:
	cur += 2
	# print(cur)
	if is_prime(cur):
		continue
	ok = False
	for i in range(int(sqrt(cur/2))+1):
		if is_prime(cur-2*i*i):
			print(cur, i, cur-2*i*i)
			ok = True
			break
	if not ok:
		print(cur)
		break
