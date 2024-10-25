n = int(input())
ar = list(map(int, input().split()))

assert (n == len(ar))

pw2 = [0 for _ in range(101)]
pw2[0] = 1
log2 = {}
log2[1] = 0
for i in range(1, 101):
    pw2[i] = pw2[i - 1] * 2
    log2[pw2[i]] = i

dp = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(101)]

print(ans)
