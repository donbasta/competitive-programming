from math import log10 as log

p, q = map(int, input().split())

d = 1
loss = 0
while True:
    temp = int(d ** 5)
    if p <= q * temp:
        break
    else:
        loss += (q * temp - p)
        d += 1

l, r = d, int(10 ** 18)
x, y = p - loss, r

duotrigintillionaire = int(10 ** 99)
def ok(u):
    tmp = x + (q * ((u * (u + 1)) ** 2) * (2 * u * u + 2 * u - 1) // 12) - (p * u)
    return tmp >= duotrigintillionaire

while l <= r:
    mid = (l + r) // 2
    if ok(mid):
        y = mid
        r = mid - 1
    else:
        l = mid + 1

print(x)
print(y)