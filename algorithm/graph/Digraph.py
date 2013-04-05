from graph import *

class Digraph(Graph):
	def __init__(self):
		Graph.__init__(self)

	def addEdge(self, f, to,weight=0):
		if f not in self.nodeList:
			self.addNode(f)
		if to not in self.nodeList:
			self.addNode(to)
		self.nodeList[f].addNeighbor(self.getNode(to),weight)
	
	def adj(self, v):
	    node = self.getNode(v)
	    return node.getConnections()
	    
	def V(self):
	    return self.nodeList
	    
	def E(self):
	    edge = []
	    for v in self.V():
	        node = self.getNode(v)
	        for w in self.adj(v):
	            edge.append( [v, w.getId(), node.getWeight(w)] )
	    return edge
	
	def reverse(self):
	    for v in self.V():
	        node = self.getNode(v)
	        neighbors = self.adj(v)
	        
	        # Tip: use dict.keys() to iterate to avoid RuntimeError: dictionary changed size during iteration
	        for w in neighbors.keys():
	            w.addNeighbor(node,node.getWeight(w))
	            node.removeConnectTo(w)
	            
	def existEdgeBetweenVAndW(self,v,w):
	    nodeV = self.getNode(v)
	    nodeW = self.getNode(w)
	    return nodeW in nodeV.getConnections()
	
	def DirectDFS(self, v, visited, u, path):
	    if not v:
	        return False
	    path.append(v.getId())
	    if ( v == u):
	        print "Path:",path
	        return True
	        
	    self.visit(v)
	    visited.append(v)
	    for w in v.getConnections():
	        if w not in visited:
	            found = self.DirectDFS(w,visited,u,path)
	            if found:
	                return True
	            path.pop()
	                
	    return False
	# Does one Path exist from v to w
	def IsThereOnePath(self,v,w):
	    visited=[]
	    nodeV = self.getNode(v)
	    nodeW = self.getNode(w)
	    return self.DirectDFS(nodeV, visited, nodeW,[])

	    
def DigraphUnitTest():
    g = Digraph()
    for i in range(7):
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
    print "Edge number:", len(g.E()) , g.E()
    
    #g.reverse()
    #print "Reversed Edge number:", len(g.E()) , g.E()
    
    print "Path 0->5 ?", g.IsThereOnePath(5,1)

DigraphUnitTest()