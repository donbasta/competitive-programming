def banyakdivisor(n):
    if n == 1:
        return 1
    t = 2
    for i in range(2,n):
        if i*i > n:
            break
        if n%i == 0:
            t += 1
            if i*i != n:
                t += 1
    return t

ans = 0

for i in range(1,250001):
    ans += banyakdivisor(i)//2
        
print(ans)
