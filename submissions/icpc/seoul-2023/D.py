import sys
from math import gcd

n = int(input())
s = input()


def F(x, y, z):
    a = y[0] * z[1]
    b = y[1] * z[0]
    fpb = gcd(a, b)
    a //= fpb
    b //= fpb
    c = x[0] * b + x[1] * a
    d = x[1] * b
    fpb = gcd(c, d)
    c //= fpb
    d //= fpb
    return [c, d]


st = []
for i in range(n):
    c = s[i]
    if c == '(':
        st.append([])
    elif c == ')':
        if (len(st) == 0) or (len(st[-1]) != 3):
            print(-1)
            sys.exit(0)
        cur = st.pop()
        res = F(cur[0], cur[1], cur[2])
        if len(st) > 0:
            st[-1].append(res)
        else:
            if i < n - 1:
                print(-1)
            else:
                print(f"{res[0]} {res[1]}")
            sys.exit(0)
    else:
        if len(st) > 0:
            st[-1].append([ord(c) - ord('0'), 1])
        else:
            print(-1)
            sys.exit(0)
print(-1)
