# cnt = 0

# for i in range(1,2**30+1):
# 	print(i)
# 	if i&(i<<1) == 0:
# 		cnt += 1

# print(cnt)

a = 1
b = 2
for i in range(3,5):
	c = b
	b = a + b
	a = c
print(b)