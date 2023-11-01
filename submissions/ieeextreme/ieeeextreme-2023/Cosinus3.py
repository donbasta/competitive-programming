# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   


input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)


def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)
    

def egcd(a, b): 
    #return gcd, x, y such that ax + by = gcd
    if b == 0:
        return a, 1, 0
    d, x1, y1 = egcd(b, a % b)
    return d, y1, x1 - y1 * (a // b)

def ceilz(a, b):
    if a % b == 0:
        return a//b
    return (a // b) + 1
    # if a > 0:
    #     return (a//b) + 1
    # return a//b

# numpy and scipy are available for use
# import numpy
# import scipy
# import math
# from math import gcd

t = get_number()

for _ in range(t):
    a = get_word()
    if (a[0] == '-'):
        a = a[1:]
    idx = -1
    for i in range(len(a)):
        if a[i] == '.':
            idx = i
            break
    b = 1
    if idx != -1:
        b = 10 ** (len(a) - 1 - idx)
        a = a[:idx] + a[idx + 1:]
    a = int(a)
    
    if a == 0:
        print(1)
        continue

    while (a%2 == 0) and (b%2 == 0):
        a //= 2
        b //= 2
    while (a%3 == 0) and (b%3 == 0):
        a //= 3
        b //= 3
    while (a%5 == 0) and (b%5 == 0):
        a //= 5
        b //= 5

    fp, _, _ = egcd(a, 90)
    a1 = a // fp
    l = 90 // fp
    # print(a, b, fp, a1, l)
    # print(gcd(a1, b * l))
    if (a1 % 2 == 1):
        n = b * l
    else:   
        assert l % 2 == 1
        assert b % 2 == 1
        dd, xx, yy = egcd(a1, l * b)
        # print(f"dd = {dd}, xx = {xx}, yy = {yy}")
        assert yy % 2 == 1
        kpk = (l * b) // dd * a1
        # print(f"kpk = {kpk}")
        kk = ceilz((1-xx) * a1, kpk)
        nn = xx + (kk * kpk) // (a1)

        kkk = ceilz((1+xx) * a1, kpk)
        nnn = -xx + (kkk * kpk) // (a1)
        # print(f"kk = {kk}, nn = {nn}, kkk = {kkk}, nnn = {nnn}")
        n = min(nn, nnn)
    assert n > 0
    print(n)
