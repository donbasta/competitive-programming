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

        
def oiler(x):
    y = x
    if(x % 2 == 0):
        y = y // 2
    if(x % 3 == 0):
        y = y // 3 * 2
    if(x % 5 == 0):
        y = y // 5 * 4
    return y

def inverse(x, y):
    ret = 1
    z = x
    o = oiler(y) - 1
    while(o > 0):
        if(o % 2 == 1):
            ret = (ret * z) % y
        o //= 2
        z = (z * z) % y
    return ret

def ceilz(a, b):
    if a % b == 0:
        return a//b
    return a//b + 1

# numpy and scipy are available for use
import numpy
import scipy
import math

t = get_number()

for tt in range(t):
    a = get_word()
    if(a[0] == "-"):
        a = a[1:]
    idx = -1
    for i in range(len(a)):
        if(a[i] == '.'):
            idx = i
    b = 1
    if(idx >= 0):
        a = a[:idx] + a[(idx+1):]
        while(idx < len(a)):
            b *= 10
            idx += 1
    a = int(a)

    fpb = 1
    while(a%2 == 0 and b%2 == 0):
        a //= 2
        b //= 2
        fpb *= 2
    while(a%3 == 0 and b%3 == 0):
        a //= 3
        b //= 3
        fpb *= 3
    while(a%5 == 0 and b%5 == 0):
        a //= 5
        b //= 5
        fpb *= 5
    
    fp = math.gcd(a, 90)
    a2 = a // fp
    l = 90 // fp
    # c habis dibagi sama fp
    if a2 % 2 == 0 and l % 2 == 1:
        d, x, y = egcd(a2, l)
        LCM = l * a2 // math.gcd(l, a2)
        k = max(ceilz(-x*a2, LCM), ceilz(y*l, LCM))
        # k = max(-x*a2//LCM, y*l//LCM)
        lmao = x + k * LCM//a2

        kk = max(ceilz(x * a2, LCM), ceilz(-y*l, LCM))
        lmao = min(lmao, x + kk * LCM//a2)
        d = b * lmao
    else:
        d = b * l

    print(d)
