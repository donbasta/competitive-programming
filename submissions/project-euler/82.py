with open("p082_matrix.txt") as file:
    lines = file.readlines()
    mat_ = [list(map(int, line.split(','))) for line in lines]

sz = len(mat_)
assert sz == 80

mat = [[mat_[i][j] for i in range(sz)] for j in range(sz)]

dp = [[0 for _ in range(sz)] for _ in range(sz)]

dp[sz-1] = mat[sz-1]

for i in range(sz-2, -1, -1):
    pre = [0 for _ in range(sz)]
    pre[0] = mat[i][0]
    for j in range(1, sz):
        pre[j] = pre[j-1] + mat[i][j]
    for j in range(sz):
        tmp = []
        for k in range(sz):
            if j >= k:
                bawah = 0 if k == 0 else pre[k-1]
                tmp.append(pre[j] - bawah + dp[i+1][k])
            else:
                bawah = 0 if j == 0 else pre[j-1]
                tmp.append(pre[k] - bawah + dp[i+1][k]) 
        dp[i][j] = min(tmp)

print(min(dp[0]))
print(dp[sz-1])
print(mat[sz-1])