def sumdigit(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n //= 10
    return ret

ans = 1
lul = [0, 0]
for i in range(1, 100):
    a = 1
    for j in range(1, 100):
        a = a * i
        if sumdigit(a) > ans:
            ans = sumdigit(a)
            lul = [i, j]

print(ans, lul)