# from itertools import *
import itertools
from math import sqrt

def is_prime(n):
	for i in range(2,int(sqrt(n))):
		if n%i==0:
			return False
	return True

def bactrack_prime(n):
	ans = []
	li = [i for i in range(1,n+1)]
	perm_obj = itertools.permutations(li)
	perm_list = list(perm_obj)
	for i in perm_list:
		temp = 0
		for j in i:
			temp = temp*10+j
		if is_prime(temp):
			ans.append(temp)
	if ans:
		print(max(ans))
	elif n>3:
		bactrack_prime(n-1)

bactrack_prime(9)