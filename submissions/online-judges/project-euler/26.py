def euler(n):
    ans = n; cur = n; div = 2
    while(cur > 1):
        if div > cur/2:
            break
        if cur%div == 0:
            ans -= ans//div
            while cur%div == 0:
                cur //= div
        div += 1
    if cur > 1:
        ans -= 1
    return ans

def divisor(n):
    t = []; t.append(1); t.append(n)
    for i in range(2,n):
        if i*i > n:
            break
        if n%i == 0:
            t.append(i)
            if i*i != n:
                t.append(n//i)
    t.sort()
    return t

def pow(a,b,mod):
    if b == 0:
        return 1
    c = pow(a, b//2, mod)
    c *= c; c %= mod
    if b%2 == 1:
        c *= a; c %= mod
    return c

def modpow10(a,b):
    c = pow(10,a,b)-1
    if c < 0:
        c += b
    return c

def order10(n):
    ans = 0
    for i in divisor(euler(n)):
        if modpow10(i,n) == 0:
            ans = i; break
    return ans


maks = 1; ans = 7
for i in range(2,1000):
    if i%2!=0 and i%5!=0:
        if(order10(i) > maks):
            ans = i
            maks = max(maks, order10(i))

print(ans)