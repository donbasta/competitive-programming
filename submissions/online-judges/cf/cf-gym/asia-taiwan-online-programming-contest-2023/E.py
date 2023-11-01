a, b, m = map(int, input().split())

A = [[a, m - 1], [1, 0]]
identity = [[1, 0], [0, 1]]


def mul(a, b):
    sz = len(a)
    d = [[0 for _ in range(sz)] for _ in range(sz)]
    for i in range(sz):
        for j in range(sz):
            for k in range(sz):
                d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % m
    return d


def fpow(a, b):
    ret = identity
    while (b > 0):
        if (b % 2 == 1):
            ret = mul(ret, a)
        a = mul(a, a)
        b = b // 2
    return ret


Ab = fpow(A, b - 1)
ret = (Ab[0][0] * a + Ab[0][1] * 2) % m
if ret < 0:
    ret += m

print(ret)
