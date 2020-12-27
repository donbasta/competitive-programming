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

def banyakdivisor1(n):
    t = 2; ans = 1
    while n > 1:
        if t*t > n:
            break
        cur = 0
        while n%t == 0:
            cur += 1; n//=t
        ans *= (cur+1)
        t += 1
    if n > 1:
        ans = 2
    return ans

def ans(i):
    return (banyakdivisor1(i*i)+1)//2

TARGET = 1000

i = 2
while True:
    if ans(i) > TARGET:
        sol = i; break
    i += 1

print(sol)
