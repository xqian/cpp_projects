class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > res;
        vector<string> vs;
        vs.insert(vs.end(), dict.begin(), dict.end());
        vector<vector<int> > neighbor(vs.size(), vector<int>());
        calNeighbor(vs, neighbor);
        int start_i;
        auto iter = find(vs.begin(), vs.end(), start);
        if (iter == vs.end()) return res;
        start_i = iter - vs.begin();
        int end_i;
        iter = find(vs.begin(), vs.end(), end);
        if ( iter == vs.end()) return res;
        end_i = iter - vs.begin();
        vector<int> distanceToDst(vs.size(),-1);//BUG, forget init
        bfs(neighbor, start_i, end_i, distanceToDst);
        vector<int> path;
        dfsGetPath( neighbor, start_i, end_i, distanceToDst, vs, res, path);
        return res;
    }
    
    void calNeighbor(const vector<string> & vs, vector<vector<int> > & neighbor) {
        for(int i=0; i < vs.size(); ++i) {
            for(int j=i+1; j < vs.size(); ++j) {
                if( diffByOne(vs[i], vs[j])) {
                    neighbor[i].push_back(j);
                    neighbor[j].push_back(i);
                }
            }
        }
    }
    
    bool diffByOne(const string & s1, const string & s2) {
        int diff = 0;
        if( s1.length() != s2.length()) return false;
        for(int i=0; i < s1.length(); ++i) {
            if( s1[i] != s2[i]) {
                diff++;
                if ( diff >1) return false;
            }
        }     
        return true;
    }
    
    void dfs(const vector<vector<int> > & neighbor, 
         int cur, int dst, vector<vector<int> > & bestPath, 
         vector<int> &path, vector<int> & isVisited) {
            if ( isVisited[cur]) return;
            if ( cur == dst) {
                path.push_back(dst);                
                if( bestPath.size() == 0) {
                    bestPath.push_back(path);
                }
                else if ( bestPath[0].size() == path.size()) {
                    bestPath.push_back(path);
                }
                else if ( bestPath[0].size() > path.size()) {
                    bestPath.clear();
                    bestPath.push_back(path);
                }
                path.pop_back();
            }
            else if( bestPath.size() == 0 || path.size() < bestPath[0].size()) {
                isVisited[cur] = 1;
                path.push_back(cur);
                for(int i=0; i < neighbor[cur].size(); ++i) {
                    dfs(neighbor, neighbor[cur][i], dst, bestPath, path, isVisited);                    
                }
                path.pop_back();
                isVisited[cur] = 0;
            }            
    }
    
    void bfs(const vector<vector<int> > & neighbor, int src, int dst, vector<int> & distanceToDst) {
        queue<int> q;
        q.push(dst);
        distanceToDst[dst] = 0;
        while( !q.empty()) {
            int t = q.front();
            q.pop();
            for(int i=0; i < neighbor[t].size(); ++i) {
                if ( distanceToDst[neighbor[t][i]] == -1) {
                    distanceToDst[neighbor[t][i]] = distanceToDst[t]+1;
                    if ( neighbor[t][i] == src) return;
                    else {
                         q.push(neighbor[t][i]); //BUG forget push
                    }
                }

            }
        }        
    }
    
    void dfsGetPath(const vector<vector<int> > & neighbor, int cur, int dst, 
             const vector<int> & distanceToDst, const vector<string> & vs, 
             vector<vector<string> > & res, vector<int> & path) {
         path.push_back(cur);
         if( cur == dst) {
            addPath(res, path, vs);
            path.pop_back();
            return;
         }
         for(int i=0; i < neighbor[cur].size(); ++i) {
            if ( distanceToDst[cur] - 1 == distanceToDst[neighbor[cur][i]] ) {
                dfsGetPath(neighbor, neighbor[cur][i], dst, distanceToDst, vs, res, path);
            }
         }
         path.pop_back();         
    }
    
    void addPath(vector<vector<string> > & res, const vector<int> & path, const vector<string> & vs) {
        res.push_back(vector<string>());
        for(int i=0; i < path.size(); ++i) {
            res.back().push_back(vs[path[i]]);
        }
    }
};