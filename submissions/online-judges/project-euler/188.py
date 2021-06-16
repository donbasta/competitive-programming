def fpow(a,b,mod):
    ret = 1
    while b>0:
        if b%2 == 1:
            ret = ret*a % mod
        a = a*a % mod
        b //= 2
    return ret

def phi(n):
    nn = n
    ret = n
    i = 2
    while i*i <= nn:
        if nn % i == 0:
            ret -= ret//i
            while nn % i == 0:
                nn //= i
        i += 1
    if nn > 1:
        ret -= ret//nn
    return ret

def tetration(a,b,mod):
    p = phi(mod)
    if p == 1:
        return 1
    return fpow(a,tetration(a,b-1,phi(mod)),mod)

print(tetration(1777,1855,100000000))
