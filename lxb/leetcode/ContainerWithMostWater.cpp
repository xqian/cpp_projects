http://oj.leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);
            if (result < area) result = area;
            
            if (height[left] < height[right]) left++;
            else right --;
        }
        
        return result;
    }
};
