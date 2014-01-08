/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
*/

// Focus: two pointers
public class Solution {
    public int maxArea(int[] height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // Two Pointers
        int left = 0;
        int right = height.length-1;
        int max_area = 0;
        while (left < right){
            int area = (right - left)*Math.min(height[left],height[right]);
            if (area > max_area) max_area = area;
            
            if (height[left] < height[right]){
                ++left;
            }else{
                --right;
            }
        }
        
        return max_area;
    }
}
