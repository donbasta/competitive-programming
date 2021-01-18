from math import floor, log


def count_digit(n):
    return floor(log(n, 10)) + 1

ans = 0
n = 1
while True:
    if 9 ** n < 10 ** (n - 1):
        break
    for i in range(1, 10):
        a = i ** n
        if n == count_digit(a):
            ans += 1 
    n += 1

print (ans)