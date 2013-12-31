http://oj.leetcode.com/problems/maximal-rectangle/

/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int maxArea = 0;
        if (matrix.size() == 0) return 0;
        
        vector<int> hist(matrix[0].size(),0);
        
        for (int row=0; row< matrix.size(); row++)
        {
            //compute hist.
            for (int col=0; col<matrix[0].size();col++)
            {
                if (matrix[row][col] == '0') {
                    hist[col] = 0;
                }else{
                    hist[col] += 1;
                }
            }
            
            //get max hist rectangle area
            maxArea = max(maxArea, largestRectangleArea(hist));
        }
        
        return maxArea;
    }
    
public:
    struct Item{
        int index;
        int height;
        Item(int i,int h):index(i),height(h){};
        Item():index(-1),height(0){};
    };
    

private:
    int largestRectangleArea(vector<int> &height) {
        stack<Item> S;
        int N = height.size();
        int area = 0;
        
        for (int i=0; i<N; i++)
        {
            if (S.empty()) {
                S.push(Item(i,height[i]));
                continue;
            }
            
            //compare
            if (height[i] < S.top().height){
                //pop till empty or smaller item appear
                Item item;
                while (!S.empty() && S.top().height > height[i]) {
                    item = S.top();
                    S.pop();
                    
                    area = max(area, (i - item.index)*item.height);
                }
                
                //push. Pay attention to the index
                S.push(Item(item.index, height[i]));
            }else{
                S.push(Item(i,height[i]));
            }
        }
        
        //stack maybe not empty yet
        while(!S.empty()){
            Item item = S.top(); S.pop();
            area = max(area, (N - item.index)*item.height);
        }
        
        return area;
    }
};
