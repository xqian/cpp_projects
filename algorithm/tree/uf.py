'''
Quick Find: Find O(1), union maybe slow O(n)
'''
class UF_Base:
    N=[]
    def __init__(self, n):
        for i in range(0,n):
            self.N.append(i)
            
    def connected(self,p,q):
        return self.N[p] == self.N[q]
        
    def Union(self,p,q):
        root = self.N[p]
        for i in range(1,len(self.N)):
            if self.N[i]==root:
                self.N[i]=self.N[q]
                
    def printRoot(self):
        for i in range(1,len(self.N)):
            print i,self.N[i]
                
# Test Code
def UF_UNITTEST():
    uf = UF_Base(10)
    uf.printRoot()

    uf.Union(3,2)
    uf.printRoot()
    uf.Union(1,2)
    uf.printRoot()
    print uf.connected(3,1)
    
'''
UF_QuickUnion: Lazy Union. But Find maybe slow.
'''
class UF_QuickUnion(UF_Base):
    def __init__(self, n):
        UF_Base.__init__(self,n)
    
    def root(self,m):
        if (m==self.N[m]):
            return m
        return self.root(self.N[m])

    def connected(self,p,q):
        return self.root(p) == self.root(q)

    def Union(self,p,q):
        #import pdb;pdb.set_trace()
        i = self.root(p)
        j = self.root(q)
        self.N[i]=j

def UF_QuickUnion_UNITTEST():
    uf = UF_QuickUnion(10)
    uf.printRoot()

    uf.Union(3,2)
    uf.printRoot()
    uf.Union(1,2)
    uf.printRoot()
    print uf.connected(3,1)
    
'''
UF_WeightQuickUnion: Improve from Lazy Union Alg. It tries to keep the tree flat. Union (O(ln)), Connected (O(ln)).
'''
class UF_WeightQuickUnion(UF_QuickUnion):
    size = []
    def __init__(self, n):
        UF_QuickUnion.__init__(self,n)
        for i in range(0,n):
            self.size.append(1)
        
    def Union(self,p,q):
        #import pdb;pdb.set_trace()
        i = self.root(p)
        j = self.root(q)
        
        if ( self.size[i] > self.size[j] ):
            self.N[j] = i
            self.size[i] = self.size[i] + self.size[j]
        else:
            self.N[i] = j
            self.size[j] = self.size[j] + self.size[i]

def UF_WeightQuickUnion_UNITTEST():
    uf = UF_WeightQuickUnion(10)
    uf.printRoot()

    uf.Union(3,2)
    uf.printRoot()
    uf.Union(1,2)
    uf.printRoot()
    print uf.connected(3,1)
    

'''
UF_WeightQuickUnion1: Improve from Lazy Union Alg. It tries to keep the tree flat. Union (O(ln)), Connected (O(ln)).
'''
class UF_PathCompressQuickUnion1(UF_WeightQuickUnion):
    def __init__(self, n):
        UF_WeightQuickUnion.__init__(self,n)
        
    def root(self,m):
        i = m
        # find root
        while (m != self.N[m]):
            m = self.N[m]
        
        # go through the path and point all middle node's root to m.
        while ( i != self.N[i] ):
            parent = self.N[i]
            self.N[i] = m
            i = parent
            
        return m

def UF_PathCompressQuickUnion1_UNITTEST():
    uf = UF_PathCompressQuickUnion1(10)
    uf.printRoot()

    uf.Union(3,2)
    uf.printRoot()
    uf.Union(1,2)
    uf.printRoot()
    print uf.connected(3,1)
    
'''
UF_WeightQuickUnion2: Improve from Lazy Union Alg. It tries to keep the tree flat. Union (O(ln)), Connected (O(ln)).
'''
class UF_PathCompressQuickUnion2(UF_WeightQuickUnion):
    def __init__(self, n):
        UF_WeightQuickUnion.__init__(self,n)

    def root(self,m):
        i = m
        # find root
        while (m != self.N[m]):
            #half path compression
            self.N[m] = self.N[self.N[m]]
            m = self.N[m]

        return m

def UF_PathCompressQuickUnion2_UNITTEST():
    uf = UF_PathCompressQuickUnion2(10)
    uf.printRoot()

    uf.Union(3,2)
    uf.printRoot()
    uf.Union(1,2)
    uf.printRoot()
    print uf.connected(3,1)
UF_PathCompressQuickUnion1_UNITTEST()