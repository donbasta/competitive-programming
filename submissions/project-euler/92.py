def calc(x):
    ret = 0
    while x > 0:
        c = x % 10
        ret += c * c
        x //= 10
    return ret

MX = 10000000

ok = [-1 for _ in range(MX)]

ok[1] = 0
for i in [89, 145, 42, 20, 4, 16, 37, 58]:
    ok[i] = 1

ans = 0
for i in range(1, MX):
    if ok[i] == 1:
        ans += 1
    elif ok[i] == -1:
        ci = i
        tmp = []
        while ok[ci] == -1:
            tmp.append(ci)
            ci = calc(ci)
        isi = ok[ci]
        for j in tmp:
            ok[j] = isi
        if isi == 1:
            ans += 1

print(ok[1:10])

print("Ans: {}".format(ans))

