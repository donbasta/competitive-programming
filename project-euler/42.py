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


with open('words.txt') as be:
    baris = be.readlines()
    arr = [x.split(',') for x in baris]
    words = arr[0]

for i in range(len(words)):
	words[i] = words[i][1:len(words[i])-1]

cnt = 0
for i in words:
	temp = 0
	for j in i:
		temp += (ord(j)-ord('A')+1)
	if is_triangle(temp):
		cnt += 1

print(cnt)