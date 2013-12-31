http://oj.leetcode.com/problems/clone-graph/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

Solution: use hash to keep mapping relationship. Use set to record the visited. Code simplification.

Method 0: DFS
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    typedef UndirectedGraphNode UGNode;
    typedef unordered_map<UGNode *, UGNode *> HashTable;
    typedef unordered_set<UGNode *> HashSet;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!node) return NULL;
        HashTable mapTable;
        HashSet visited;
        
        dfs(node,mapTable,visited);
        
        return mapTable[node];
    }
    
private:
    void dfs(UGNode *node, HashTable &mapTable, HashSet &visited){
        cloneNode(node,mapTable);
        visited.insert(node);
        
        for (auto nbor:node->neighbors){
            cloneNode(nbor, mapTable);
            mapTable[node]->neighbors.push_back(mapTable[nbor]);
            
            if (visited.find(nbor) == visited.end() && nbor != node){
                dfs(nbor,mapTable,visited);
            }
        }
    }
    
    void cloneNode(UGNode *src, HashTable &mapTable){
        if (mapTable.find(src) == mapTable.end()){
            mapTable[src] = new UGNode(src->label);
        }
    }
};


Method 1: BFS

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    typedef UndirectedGraphNode UGNode;
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
       
       if (!node) return NULL;
       
       // BFS
       queue<UGNode *> que;
       unordered_map<UGNode*, UGNode *> map_table;
       que.push(node);
       set<UGNode *> visited;
       
       while (!que.empty()){
            UGNode *curr = que.front();
            que.pop();
            visited.insert(curr);
            cloneNode(curr,map_table);
            
            for (auto nbor:curr->neighbors){
                cloneNode(nbor,map_table);
                
                if (visited.find(nbor) == visited.end() && nbor != curr){
                    visited.insert(nbor);
                    que.push(nbor);
                }
                
                map_table[curr]->neighbors.push_back(map_table[nbor]);
            }
       }
       
       return map_table[node];
     }
     
private:
    void cloneNode(UGNode * src, unordered_map<UGNode *,UGNode *> &map_table)
    {
        if (map_table.find(src) != map_table.end()) return;
        map_table[src] = new UGNode(src->label);
    }
};



Round2: Method 1 report wrong answer. Do you know why?

Input:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}
Output:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5,5,5#5}
Expected:	{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}
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

