http://oj.leetcode.com/problems/merge-intervals/

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
    
    struct mycompare{
        bool operator() (const Interval &l, const Interval &r)
        {
            return l.start < r.start;
        }
    } myobj;
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        // sort interval by start
        //sort(intervals.begin(), intervals.end(), myobj);   //Method 1.
        sort(intervals.begin(), intervals.end(), mycomp());  //Method 2.
        
        vector<Interval> result;
        
        const int len = intervals.size();
        if (len < 1) return result;
        
        Interval curr = intervals[0];
        for (int i=1; i<len; i++)
        {
            //decide whether merge by compare item i and i-1
            if (intervals[i].start <= curr.end && intervals[i].start >= curr.start )
            {
                curr.start=min(intervals[i].start, curr.start);
                curr.end = max(intervals[i].end, curr.end);
            }else{
                // No overlap
                result.push_back(curr);
                curr = intervals[i];
            }
        }
        
        //last one
        result.push_back(curr);
        
        return result;
    }
};

Method 2: use subfunction to simplify logic:
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
    
    struct mycomp{
        bool operator() (const Interval &l, const Interval &r)
        {
            return l.start < r.start;
        }
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // sort interval by start
        sort(intervals.begin(), intervals.end(), mycomp());
        vector<Interval> res;
        int len = intervals.size();
        if (len==0) return res;
        res.push_back(intervals[0]);
        
        for (int i=1; i<len; ++i){
            Interval t;
            if (mergeInterval(res.back(), intervals[i], t)){
                res.back() = t;
            }else{
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
    
private:
    bool mergeInterval(const Interval &a, const Interval &b, Interval &c)
    {
        if (b.start > a.end) return false;
        
        c.start = a.start;
        c.end = max(a.end, b.end);
        return true;
    }
};
