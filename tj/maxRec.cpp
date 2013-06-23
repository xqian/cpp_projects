//Compare previous code

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size() == 0) return 0;
        stack<int> s;
        int area = 0;
        for(int i=0; i < height.size(); ++i) {
            if( s.empty()) {
                s.push(i);
            }
            else if ( height[s.top()] < height[i]) {
                s.push(i);
            }
            else if ( height[s.top()] == height[i]) {
                continue; //Bug: missed this condition
            }
            else {
                int lastPop = 0; //Bug: miss this condition
                while( !s.empty() && height[s.top()] > height[i]) {
                    int t = s.top();
                    s.pop();
                    int s = height[t] * (i - t);
                    area = max(area, s);
                    lastPop = t; 
                }
                height[lastPop] = height[i];
                s.push(lastPop);
            }
        }
        while(!s.empty()) {
            int t = s.top();
            s.pop();
            int s = height[t] * (height.size() - t);
            area = max(area, s);
        }
        return area;
    }
};