http://oj.leetcode.com/problems/insert-interval/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<Interval> result;
        int n = intervals.size();
        
        //pass all un-overlapped on the left
        int i=0;
        while (i<n && intervals[i].end < newInterval.start) {
            result.push_back(intervals[i]);
            i++;
        }
        
        //find the position to insert or merge
        while (i<n && intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end)
        {
            //merge
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        
        result.push_back(newInterval);
        
        //push all left
        while (i<n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
