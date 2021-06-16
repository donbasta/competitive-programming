class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.sz = [1 for i in range(n)]

    def fpar(self, n):
        if n != self.p[n]:
            self.p[n] = self.fpar(self.p[n])
        return self.p[n]

    def merge(self, a, b):
        a = self.fpar(a)
        b = self.fpar(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.sz[a] += self.sz[b]
        self.p[b] = a
        return True

n = 6
dsu = DSU(n)

dsu.merge(0, 1)
dsu.merge(1, 2)
dsu.merge(3, 5)
for i in range(n):
    print(i, dsu.fpar(i))