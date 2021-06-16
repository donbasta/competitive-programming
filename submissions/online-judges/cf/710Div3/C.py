tc = int(input())
for _ in range(tc):
    a = input()
    b = input()
    print(a, b)
    dp = [[0 for i in range(len(b) + 1)] for i in range(len(a) + 1)]
    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
            if a[i - 1] == b[j - 1]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
            print(i, j, dp[i][j])
    lcs = dp[len(a)][len(b)]
    print(lcs)
    ans = len(a) + len(b) -  2 * lcs
    print(ans)