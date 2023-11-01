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
            ret = ret * z % y
        o //= 2
        z = z * z % y
    return ret

# numpy and scipy are available for use
import numpy
import scipy

t = get_number()

for tt in range(t):
    a = get_word()
    if(a[0] == "-"):
        a = a[1:]
    idx = -1
    for i in range(len(a)):
        if(a[i] == '.'):
            idx = i
    b = 90
    if(idx >= 0):
        a = a[:idx] + a[(idx+1):]
        while(idx < len(a)):
            b *= 10
            idx += 1
    a = int(a)
    
    while(a%2 == 0 and b%2 == 0):
        a //= 2
        b //= 2
    while(a%3 == 0 and b%3 == 0):
        a //= 3
        b //= 3
    while(a%5 == 0 and b%5 == 0):
        a //= 5
        b //= 5
    
    if (a%2 == 0):
        if b == 1:
            d = 1
        else:
            a //= 2
            c = inverse(a, b)
            d = min((b-1)//2 * c % b, (b+1)//2 * c % b)
    else:
        d = b//2
    
    # if(a % 2 == 0 and b % 4 == 2):
    #     a //= 2
    #     b //= 2
    #     c = inverse(a, b)
    #     d = min((b-1)//2 * c % b, (b+1)//2 * c % b)
    # else:
    #     d = b//2
    print(d)
