ans = 0
MIL = 1000000

for i in range(23, 101):
    cur = 1
    j = 0
    while j <= i:
        j += 1
        cur = cur * (i - j + 1) // j
        if cur > MIL:
            ans += (i - j*2 + 1)
            break

print (ans)