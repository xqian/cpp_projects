//leetcode max container
//bug found by review code: b1
//bug found by test: b2

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> posLeft;
        vector<int> posRight;
        
        posLeft.push_back(0);
        for(int i=1; i < height.size(); ++i) {
            if ( height[posLeft.back()] < height[i]) { /*b2 posLeft.back() < height[i] */
                posLeft.push_back(i);
            }
        }
        
        posRight.push_back(height.size()-1);
        for(int i= height.size() -2; i >=0; --i) {
            if ( height[posRight.back()] < height[i]) { /*b2 posRight.back() < height[i] */
                posRight.push_back(i);
            }
            if ( height[i] == posLeft.back()) break;
        }
        
        int i = 0;
        int j = 0;
        int res = 0;
        while( i < posLeft.size() && j < posRight.size()) {
            res = max(res, calArea(height, posLeft[i], posRight[j])); 
            if ( height[posLeft[i]] < height[posRight[j]] ) i++; /*b1 posLeft[i] < posRight[j] */
            else if ( height[posLeft[i]] > height[posRight[j]]) j++; /*b1 posLeft[i] < posRight[j] */
            else {
                i++;
                j++;
            }
        }
        return res;       

    }
    
    int calArea(const vector<int> & height, int posLeft, int posRight) {
        return min(height[posLeft], height[posRight]) * (posRight-posLeft);
    }
};