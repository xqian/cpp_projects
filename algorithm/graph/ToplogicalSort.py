import Digraph

class ToplogicalSort(Digraph):
	def __init__(self):
		Digraph.__init__(self)
	
	def ToplogicalSort(self):
	    visited=[]
	    for v in self:
	        if v not in visited:
	            print "Find network:"
	            self.reverseStack = []
	            self.DFS(v,visited) 
	            print 'ToplogicalSort',self.reverseStack

	def DFS(self, v, visited):
	    if not v:
	        return

	    self.visit(v)
	    visited.append(v)
	    for w in v.getConnections():
	        if w not in visited:
	            found = self.DFS(w,visited)
	    self.reverseStack.append(w.getId())        
	    return 

def DigraphUnitTest():
    g = ToplogicalSort()
    for i in range(7):
        g.addNode(i)
    
    g.addEdge(0,5,5)
    g.addEdge(0,2,2)
    g.addEdge(0,1,2)
    g.addEdge(3,6,4)
    g.addEdge(3,5,9)
    g.addEdge(3,4,7)
    g.addEdge(5,4,3)
    g.addEdge(6,4,1)
    g.addEdge(6,0,8)
    g.addEdge(3,2,1)
    g.addEdge(1,4,1)

    g.ToplogicalSort()
DigraphUnitTest()