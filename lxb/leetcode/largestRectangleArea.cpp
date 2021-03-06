http://oj.leetcode.com/submissions/detail/678002/
/*
 Question:

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/

class Solution {
    
public:
    struct Info{
        int index;
        int val;
        Info(int i, int v):index(i),val(v){};
    };
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<Info> S;
        int maxSize = 0;
        int i = 0;
        
        for (;i<height.size();i++){
            if (S.empty()) S.push(Info(i, height[i]));
            else{
                if (S.top().val <= height[i]) S.push(Info(i, height[i]));
                else{
                    int lowIndex = i;
                    //pop until empty or less than height[i]
                    while (!S.empty() && S.top().val > height[i]){
                        //compute
                        Info tmp = S.top();
                        S.pop();
                        maxSize = max(maxSize, (i - tmp.index)*tmp.val);
                        lowIndex = tmp.index;
                    }
                    
                    S.push(Info(lowIndex,height[i]));
                }
            }
        }
        
        //stack maybe not empty yet.
        while (!S.empty()){
            Info tmp = S.top();
            S.pop();
            maxSize = max(maxSize, (i - tmp.index)*tmp.val);
        }
        
        return maxSize;
    }
};
