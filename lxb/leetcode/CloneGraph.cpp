http://oj.leetcode.com/problems/clone-graph/

Round2: Method 1 report wrong answer. Do you know why?

Input:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}
Output:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5,5,5#5}
Expected:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}

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
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mapTable;
        set<int> visited;
        
        //BFS
        queue<UndirectedGraphNode *> Q;
        Q.push(node);
        
        while(!Q.empty()){
            UndirectedGraphNode *curr = Q.front();
            Q.pop();
            visited.insert(curr->label);
            
            //clone it.
            if (mapTable.find(curr) == mapTable.end()){
                mapTable[curr] = new UndirectedGraphNode(curr->label);
            }
            
            //put neighbour into Queue
            for (int i=0; i<curr->neighbors.size();i++){
                // create neighbour if not visited before.
                if (mapTable.find(curr->neighbors[i]) == mapTable.end()){
                    mapTable[curr->neighbors[i]] = new UndirectedGraphNode(curr->neighbors[i]->label);
                }
                
                //clone neighbor relationship
                mapTable[curr]->neighbors.push_back(mapTable[curr->neighbors[i]]);
                
                if (visited.find(curr->neighbors[i]->label) == visited.end()){
                    Q.push(curr->neighbors[i]);
                }
            }
        }
        
        return mapTable[node];
    }
};

/* Method 2 */

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

