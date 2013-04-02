class Node():
    def __init__(self, key, payload=None):
        self.id = key
        self.connectedTo = {}
        self.payload = payload
    
    def addNeighbor(self, nbr,weight=0):
        self.connectedTo[nbr] =  weight
    
    def __str__(self):
        return "{} connected to {}".format(self.id, str([x.id for x in self.connectedTo]))
        
    def removeConnectTo(self,nbr):
        if nbr in self.connectedTo:
            del self.connectedTo[nbr]
        
        return nbr

    def getConnections(self):
        return self.connectedTo
        
    def getId(self):
        return self.id
        
    def getWeight(self,other):
        if other in self.connectedTo:
            return self.connectedTo[other]
        return None

class Graph():
    def __init__(self):
        self.nodeList = {}
        self.num = 0
    
    def addNode(self, key):
        node = Node(key)
        self.nodeList[key] = node
        self.num += 1
        return node
    
    def addEdge(self, f, to,weight=0):
        if f not in self.nodeList:
            self.addNode(f)
        if to not in self.nodeList:
            self.addNode(to)

        ### Be careful !!! Add Node as key, not int!    
        self.nodeList[f].addNeighbor(self.getNode(to),weight)
        
    def getNode(self,key):
        if key in self.nodeList:
            return self.nodeList[key]
        else:
            return None
            
    def __contains__(self, key):
        return key in self.nodeList
        
    def getNodes(self):
        return self.nodeList.values()
        
    def __iter__(self):
        return iter(self.getNodes())
        
    def __str__(self):
        return "Graph node: {}".format(str([x.id for x in self]))

    def visit(self,n):
        print n.getId()

    def DFS(self, n, visited):
        if not n:
            return

        self.visit(n)
        visited.append(n)
        for v in n.getConnections():
            if v not in visited:
                self.DFS(v,visited)

    def DFS_nonRecursive(self,n,visited):
        stack = [] 
        stack.append(n)

        while len(stack):
            v = stack.pop()
            #mark it as visited
            self.visit(v)
            visited.append(v)

            #put all unvisited neighbor into stack
            for w in v.getConnections():
                if w not in visited:
                    stack.append(w)

            print v.getId(),":", str([x.id for x in stack])

    def travelGraphDFS(self):
        visited=[]
        for v in self:
            if v not in visited:
                print "Find network:"
                #self.DFS(v,visited) 
                self.DFS_nonRecursive(v,visited)

    def BFS(self,n,visited):
        import Queue
        q = Queue.Queue()
        q.put(n)

        while not q.empty():
            v = q.get()
            #mark it as visited
            self.visit(v)
            visited.append(v)

            #put all unvisited neighbor into queue
            for w in v.getConnections():
                if w not in visited:
                    q.put(w)

    def travelGraphBFS(self):
        visited=[]
        for v in self:
            if v not in visited:
                print "Find network:"
                self.BFS(v,visited) 

def UnitTest():
    g = Graph()
    for i in range(6):
        g.addNode(i)
    
    g.addEdge(0,1,5)
    g.addEdge(0,5,2)
    g.addEdge(1,2,4)
    g.addEdge(2,3,9)
    g.addEdge(3,4,7)
    g.addEdge(3,5,3)
    g.addEdge(4,0,1)
    g.addEdge(5,4,8)
    g.addEdge(5,2,1)
        
    print g
    
    for v in g:
        for w in v.getConnections():
            print "{}, {}".format(v.getId(), w.getId())   

    g.travelGraphDFS()
    #g.travelGraphBFS()
            
UnitTest() 
    
        
        