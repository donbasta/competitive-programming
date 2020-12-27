def u(n):
	return (n**11+1)//(n+1)

def f(n, points):
	#interpolasi
	deg = len(points)
	ans = 0
	for i in range(1,deg+1):
		atas = 1
		bawah = 1
		for j in range(1,deg+1):
			if j == i:
				continue
			atas *= (n-j)
		for j in range(1, deg+1):
			if j == i:
				continue;
			bawah *= (i-j)
		ans += points[i-1] * atas / bawah
	return ans

u_n = [u(i) for i in range(11)]

def lagrange_interpolation(points):
	cur = len(points)+1
	while True:
		if u(cur) != f(cur, points):
			return f(cur, points)
		cur += 1

ans = 0
for i in range(1,11):
	ans += lagrange_interpolation(u_n[1:i+1])

print(ans)