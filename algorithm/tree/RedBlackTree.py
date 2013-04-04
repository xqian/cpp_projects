from BST import *

RED = True
BLACK = False

class  Node():
    def  __init__(self,key,value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.size = 1
        self.color = RED

class RedBlackTree(BSTTree):
    def __init__(self):
        BSTTree.__init__(self)    

    def rotateLeft(self, h):
        x = h.right
        h.right = x.left  
        x.left = h

        x.color = h.color
        h.color = RED

        x.size = h.size
        h.size = self.size(h.left) + self.size(h.right) + 1
        return x
        
    def rotateRight(self, h):
        x = h.left
        h.left = x.right
        x.right = h

        x.color = h.color
        h.color = RED

        x.size = h.size
        h.size = self.size(h.left) + self.size(h.right ) + 1
        return x

    def flipColor(self, h):
        h.left.color = BLACK
        h.right.color = BLACK
        h.color = RED
        return h

    def isRed(self, h):
        if h == None:
            return BLACK

        return h.color
       
    def put(self, root, key, value):
        #import pdb;pdb.set_trace()
        if root == None:
            return Node(key,value)
            
        ret = compareTo(root.key, key)
        if ret == 0:
            root.value = value
        elif ret > 0:
            root.left = self.put(root.left, key, value)
        else:
            root.right = self.put(root.right, key, value)
        
        #insert rotate left,rotate right and flip operation
        if self.isRed(root.right) and self.isRed(root.left)==BLACK:
            root = self.rotateLeft(root)
        if self.isRed(root.left) and self.isRed(root.left.left):
            root = self.rotateRight(root)
        if self.isRed(root.left) and self.isRed(root.right):
            root = self.flipColor(root)

        root.size = self.size(root.left)  + 1 + self.size(root.right)
        return root
    
    def Put(self,key,value):
        self.root = self.put(self.root,key,value)
        self.root.color = BLACK
             
def TestPut():
    bstree = RedBlackTree()
    bstree.Put(1,'1')
    print 'size',bstree.size(bstree.root)
    bstree.Put(3,'3')
    print bstree.size(bstree.root)
    
    #import pdb;pdb.set_trace()
    
    bstree.Put(2,'2')
    import pdb;pdb.set_trace()
    print bstree.size(bstree.root)
    #import pdb;pdb.set_trace()
    bstree.Put(5,'5')
    print bstree.size(bstree.root)
    #import pdb;pdb.set_trace()
    bstree.Put(4,'4')
    print 'size',bstree.size(bstree.root)
    #import pdb;pdb.set_trace()
    
    bstree.travel()

def TestRangeSize():
    bstree = RedBlackTree()
    bstree.Put(1,'1')
    bstree.Put(3,'3')
    bstree.Put(2,'2')
    bstree.Put(5,'5')
    bstree.Put(4,'4')

    bstree.travel()

    print "select(2)",bstree.Select(2)
    print "select(3)",bstree.Select(3)
    print "select(5)",bstree.Select(5)
    print "rank(1)=", bstree.Rank(1)
    print "rank(2)=", bstree.Rank(2)    
    print "rank(3)=", bstree.Rank(3)
    print "rank(4)=", bstree.Rank(4)
    print "rank size(2,4):", bstree.rangeSearch(1.2,3)

TestRangeSize()
#TestPut()

    
        