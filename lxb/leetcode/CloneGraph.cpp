http://oj.leetcode.com/problems/clone-graph/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!node) return NULL;
        
        std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        std::unordered_map<int,bool> visited;
        
        //BFS travel graph
        std::queue<UndirectedGraphNode *> Q;
        Q.push(node);
        
        while (!Q.empty()){
            UndirectedGraphNode *curr = Q.front();
            Q.pop();
            visited[curr->label] = true;
            
            //clone if not exist
            if ( map.find(curr) == map.end())
            {
                map[curr] = new UndirectedGraphNode(curr->label);
            }
            
            for (int i=0; i < curr->neighbors.size(); i++){
                UndirectedGraphNode *cloneNeighborNode;
                
                if (visited.find(curr->neighbors[i]->label) == visited.end()){
                    visited[curr->neighbors[i]->label] = true;
                    Q.push(curr->neighbors[i]);
                    
                    //clone neighbors
                    cloneNeighborNode = new UndirectedGraphNode(curr->neighbors[i]->label);
                    map[curr->neighbors[i]] = cloneNeighborNode;
                }else{
                    cloneNeighborNode = map[curr->neighbors[i]];
                }
                
                //set neighbour link
                map[curr]->neighbors.push_back(cloneNeighborNode);
            }
        }
        
        return map[node];
    }
};

// test:  
