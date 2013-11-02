http://oj.leetcode.com/problems/insert-interval/

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Discuss


*/

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
