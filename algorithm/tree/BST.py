def compareTo(key1, key2):
    if key1 > key2:
        return 1
    elif key1 < key2:
        return -1
    else:
        return 0

class  Node():
    def  __init__(self,key,value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.size = 1

class BSTTree():
    def __init__(self):
        self.root = None
    
    def insert(self, key, value):
        if self.root == None:
            self.root = Node(key,value)
            return
        
        cur = self.root
        
        while (cur != None):
            parent = cur
            ret = compareTo(cur.key, key)
            if ret > 0:
                cur = cur.left
                continue
            elif ret < 0:
                cur = cur.right
                continue
            else:
                cur.value = value
                break
        
        if cur == None:
            newNode = Node(key,value)
            if ret > 0:
                parent.left = newNode
            elif ret < 0:
                parent.right = newNode

    def DelMin(self):
        self.root = self.delMin(self.root)
        
    def delMin(self, cur):
        if cur == None:
            return None
        
        if cur.left == None:
            return cur.right
        
        cur.left = self.delMin(cur.left)
        cur.size = self.size(cur.left) + 1 + self.size(cur.right) 
        return cur
    
    def DelMax(self):
        self.root = self.delMax(self.root)

    def delMax(self, cur):
        if cur == None:
            return None

        if cur.right == None:
            return cur.left

        cur.right = self.delMax(cur.right)
        cur.size = self.size(cur.left) + 1 + self.size(cur.right)
        
        return cur

    def size(self,root):
        if root == None:
            return 0
        
        return root.size    

    def inOrderTravel(self,cur):
        if cur == None:
            return
        self.inOrderTravel(cur.left)
        self.queue.append(cur)
        self.inOrderTravel(cur.right)
        
    def travel(self):
        print "travel tree: key, value,size"
        self.queue = []
        self.inOrderTravel(self.root)
    
        for i in range(0,len(self.queue)):
            print 'key={}, size={}'.format(self.queue[i].key,self.queue[i].size)
    
    # How may key is less than k?
    def rank(self, cur, key):
        if cur == None:
            return 0
        
        r = compareTo(cur.key, key)
        if r == 0:
            return self.size(cur.left)
        elif r > 0:
            return self.rank(cur.left, key)
        else:
            return self.size(cur.left) + 1 + self.rank(cur.right, key)
        
    def Rank(self,key):
        return self.rank(self.root, key)
           
    def put(self, root, key, value):
        if root == None:
            root = Node(key,value)
            return root
            
        ret = compareTo(root.key, key)
        if ret == 0:
            root.value = value
        elif ret > 0:
            root.left = self.put(root.left, key, value)
        else:
            root.right = self.put(root.right, key, value)
        
        root.size = self.size(root.left)  + 1 + self.size(root.right)
        return root
    
    def Put(self,key,value):
        self.root = self.put(self.root,key,value)
    
    def query(self,key):
        cur = self.root
        while (cur != None):
            ret = compareTo(cur.key,key)
            if ret == 0:
                return cur 
            
            if ret > 0:
                cur = cur.left
            elif ret < 0:
                cur = cur.right
        
        return None
        
    def min(self,root):
        cur = root
        while (cur != None and cur.left != None):
            cur = cur.left
        return cur

    def max(self,root):
        cur = root
        while (cur != None and cur.right != None):
            cur = cur.right
        return cur
    
    def floor(self,root,key):
        if root == None:
            return None
            
        result = compareTo(root.key, key)
        if result == 0:
            return root
        if result > 0:
            return self.floor(root.left, key)
        else:
            n = self.floor(root.right, key)
            if n == None:
                return root
            else:
                return n

    def ceiling(self,root,key):
        if root == None:
            return None

        result = compareTo(root.key, key)
        if result == 0:
            return root
        if result < 0:
            return self.ceiling(root.right, key)
        else:
            n = self.ceiling(root.left, key)
            if n == None:
                return root
            else:
                return n            
                
    def Ceiling(self,key):
        return self.ceiling(self.root,key)
        
    def Floor(self,key):
        return self.floor(self.root,key)
    
    def delete(self, cur, key):
        if cur == None:
            return None
        
        ret = compareTo(cur.key, key)
        if ret < 0 :
            cur.right = self.delete(cur.right, key)
        elif ret > 0:
            cur.left = self.delete(cur.left, key)
        else:
            if cur.right == None:
                return cur.left
            
            t = cur
            cur = self.Min(t.right)
            cur.right = self.delMin(t.right)
            cur.left = t.left
        
        cur.size = self.size(cur.left) + 1 + self.size(cur.right)
        return cur    
        
    def Delete(self,key):
        self.root = self.delete(self.root,key)
    
    def contains(self, key):
        return self.query(key) != None
        
    def rangeSearch(self, lowKey, highKey):
        if  self.contains(highKey):
            return self.Rank(highKey) - self.Rank(lowKey) + 1
        else:
            return self.Rank(highKey) - self.Rank(lowKey)

    def select(self, current, n):
        if current == None:
            return None

        if self.size(current.left) > n:
            return self.select(current.left, n)
        elif self.size(current.left) < n :
            return self.select(current.right, n - self.size(current.left) - 1 )
        else:
            return current
    
    def Select(self, n):
        r = self.select(self.root, n)
        if r != None:
            return r.key
        else:
            return None
def TestDelete():
    bstree = BSTTree()
    bstree.Put(3,'3')
    bstree.Put(2,'2')
    bstree.Put(5,'5')
    bstree.Put(4,'4')

    print 'Test Delete'
    bstree.Delete(4)
    bstree.travel()
    print bstree.root.size

def TestRangeSize():
    bstree = BSTTree()
    bstree.Put(1,'1')
    bstree.Put(3,'3')
    bstree.Put(2,'2')
    bstree.Put(5,'5')
    bstree.Put(4,'4')

    print "select(2)",bstree.Select(2)
    print "select(3)",bstree.Select(3)
    print "select(5)",bstree.Select(5)
    print "rank(1)=", bstree.Rank(1)
    print "rank(2)=", bstree.Rank(2)    
    print "rank(3)=", bstree.Rank(3)
    print "rank(4)=", bstree.Rank(4)
    print "rank size(2,4):", bstree.rangeSearch(1.2,3)
            
def TestSize():
    bstree = BSTTree()
    bstree.Put(1,'1')
    bstree.Put(3,'3')
    bstree.Put(2,'2')
    bstree.Put(5,'5')
    bstree.Put(4,'4')
    
    print "range size:", bstree.rangeSize(2,4.5)
    
    q4 = bstree.query(4)
    print q4.value,bstree.min(bstree.root).value,bstree.max(bstree.root).value
    
    print bstree.root.size
    
    print bstree.Rank(5)
    bstree.travel()
    
    print 'Test Delete'
    bstree.Delete(5)
    bstree.travel
    print bstree.root.size
    
    print 'Test DelMin'
    bstree.DelMin()
    bstree.travel()
    print 'size', bstree.root.size
    
    print 'Test DelMax'
    bstree.DelMax()
    bstree.travel()
    print 'size',bstree.root.size
    
def TestInsert():    
    bstree = BSTTree()
    bstree.insert(3,'3')
    bstree.insert(2,'2')
    bstree.insert(5,'5')
    bstree.insert(4,'4')

    q4 = bstree.query(4)
    print q4.value,bstree.min(bstree.root).value,bstree.max(bstree.root).value
    floor=bstree.Floor(1)
    if floor != None:
        print floor.key
    else:
        print 'All value are bigger than it'

    ceiling=bstree.Ceiling(2.1)
    if ceiling != None:
        print ceiling.key
    else:
        print 'All value are smaller than it'

#TestRangeSize()    
    
        