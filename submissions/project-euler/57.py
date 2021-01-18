from math import floor, log

def cnt_digit(n):
    return floor(log(n, 10)) + 1

a = 17
b = 12
ans = 0
for i in range(997):
    a, b = 2 * b + a, b + a
    if cnt_digit(a) > cnt_digit(b):
        ans += 1

print(ans)