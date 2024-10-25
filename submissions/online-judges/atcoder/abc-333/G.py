from math import gcd


class F:
    def __init__(a, b):
        fpb = gcd(a, b)
        self.a = a // fpb
        self.b = b // fpb


def norm(p):
    fpb = gcd(p.a, p.b)
    return F(p.a // fpb, p.b // fpb)


def add(p, q):
    num = p.a * q.b + p.b * q.a
    den = p.b * q.b
    return norm(F(num, den))


def sub(p, q):
    num = p.a * q.b - p.b * q.a
    den = p.b * q.b
    return norm(F(num, den))


def gt(p, q):
    return p.x * q.y > p.y * q.x


def gte(p, q):
    return p.x * q.y >= p.y * q.x


ss = input()
N = int(input())

assert ss[:2] == "0."
p = int(ss[2:])
t = len(ss) - 2
q = int(10 ** t)
need = (q) // (N)

# largest 0 <= u1 <= p such that gcd(u1, 10^t) >= need

# smallest 10^t >= u2 >= p such that gcd(u2, 10^t) >= need

mn = int(10 ** 20)
pembilang = -1
for p2 in range(t + 1):
    for p5 in range(t + 1):
        now = int(2 ** p2) * int(5 ** p5)
        if now < need:
            continue
        A = (p // now) * now
        B = ((p + now - 1) // now) * now

        sel1 = p - A
        sel2 = B - p
        if sel1 <= mn:
            mn = sel1
            pembilang = A
        if B <= q and sel2 < mn:
            mn = sel2
            pembilang = B

fpb = gcd(pembilang, q)
numerator = (pembilang) // fpb
denominator = (q) // fpb
print(f"{numerator} {denominator}")

for i in range(t):
    p1 = int(ss[2:(2 + i + 1)])
    p2 = p1 + 1
    bwh = int(10 ** (i + 1) - 1)

    u1 = F(p1, bwh)
    u2 = F(p2, bwh)
