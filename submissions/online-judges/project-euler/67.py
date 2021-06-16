with open("p067_triangle.txt") as file:
    lines = file.readlines()
    mat = [list(map(int, line.split())) for line in lines]

dp = mat
n = 100

dp[0][0] = mat[0][0]
for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i-1][j] + mat[i][j]
        elif j == i:
            dp[i][j] = dp[i-1][j-1] + mat[i][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + mat[i][j]

print (max(dp[n-1]))