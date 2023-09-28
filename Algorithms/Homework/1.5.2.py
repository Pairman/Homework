'''quick-union'''

class UF:
        visit = 0
        size = 0
        count = 0
        id = [0]

        def __init__(self, N):
                self.size, self.count = N, N
                self.id = list(range(N))

        def find(self, p):
                while p != self.id[p]:
                        p = self.id[p]
                        self.visit += 2
                return p

        def connected(self, p, q):
                return self.find(p) == self.find(q)

        def union(self, p, q):
                pRoot, qRoot = self.find(p), self.find(q)
                if pRoot == qRoot:
                        return
                self.id[pRoot] = qRoot
                self.visit += 1
                self.count -= 1

N = int(input())
uf = UF(N)

while True:
        p, q = map(int, input().split())
        
        if uf.connected(p, q):
                print("connected("+str(p)+", "+str(q)+"), id = "+str(uf.id)+", visit = "+str(uf.visit)+", count = "+str(uf.count))
                continue

        uf.union(p, q)
        print("union("+str(p)+", "+str(q)+"), id = "+str(uf.id)+", visit = "+str(uf.visit)+", count = "+str(uf.count))