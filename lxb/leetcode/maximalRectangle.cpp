http://oj.leetcode.com/problems/maximal-rectangle/

/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

Note: There is bug.

Submission Result: Wrong Answer

Input:	["01101","11010","01110","11110","11111","00000"]
Output:	8
Expected:	9


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
            
            //get max history rectangle size
            maxArea = max(maxArea, maxRectHistArea(matrix, hist));
        }
        
        return maxArea;
    }
    
private:
    int maxRectHistArea(vector<vector<char> > &matrix, vector<int> &hist)
    {
        stack<int> S; //store array index;
        int maxArea = INT_MIN;
        
        for (int i=0; i<hist.size(); i++)
        {
            if (S.empty()) {
                S.push(i);
                continue;
            }
            
            while(!S.empty() && hist[S.top()] > hist[i]) {
                int index = S.top();
                S.pop();
                
                int area = (i - index)*hist[index];
                if (area > maxArea) maxArea = area;
            }
            
            S.push(i);
        }
        
        //clean stack
        while(!S.empty()){
            int area = (hist.size() - S.top())*hist[S.top()];
            if (area > maxArea) maxArea = area;
            S.pop();
        }
        
        return maxArea;
    }
};
