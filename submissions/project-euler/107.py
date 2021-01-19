with open("p107_network.txt") as file:
    lines = file.readlines()
    mat = [line.split(',') for line in lines]

class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.sz = [1 for i in range(n)]

    def fpar(self, n):
        if n == self.p[n]:
            return n
        self.p[n] = self.fpar(self.p[n])
        return self.p[n]

    def merge(self, a, b):
        a = self.fpar(a)
        b = self.fpar(b)
        # print("tesuto")
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.sz[a] += self.sz[b]
        self.p[b] = a
        return True

SZ = 40
assert len(mat) == SZ
edges = []
dsu = DSU(SZ)

tot = 0
for i in range(SZ):
    for j in range(i):
        if str.isnumeric(mat[i][j]):
            tot += int(mat[i][j])
            edges.append((int(mat[i][j]), i, j))

edges = sorted(edges)
idx = 0
num_edge = 0
# print(edges)

while num_edge < SZ - 1:
    (w, a, b) = edges[idx]
    if dsu.merge(a, b):
        tot -= w
        num_edge += 1
    idx += 1

print("Maximum saving = {}".format(tot))