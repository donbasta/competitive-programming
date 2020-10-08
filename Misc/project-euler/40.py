# def banyak_digit(n):
# 	ans = 0
# 	while n>0:
# 		ans += 1
# 		n //= 10
# 	return ans

# def kth_digit(n,k):
# 	t = banyak_digit(n)
# 	for i in range(t-k):
# 		n //= 10
# 	return n%10

cur = 1
total_digit = "a"
while(len(total_digit) <= 1000000):
	total_digit += str(cur)
	cur += 1

ans = 1
lol = [1,10,100,1000,10000,100000,1000000]
for j in lol:
	ans *= int(total_digit[j])

print(ans)