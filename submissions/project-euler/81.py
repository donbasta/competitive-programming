with open("p081_matrix.txt") as file:
    lines = file.readlines()
    mat = [line.split(',') for line in lines]

size = len(mat)
assert size == 80

dp = [[0 for i in range(size)] for i in range(size)]
for i in range(size):
    for j in range(size):
        if i == 0:
            dp[i][j] = dp[i][j-1] + int(mat[i][j])
        elif j == 0:
            dp[i][j] = dp[i-1][j] + int(mat[i][j])
        else:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + int(mat[i][j])

print(dp[size-1][size-1])