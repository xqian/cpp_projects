/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
//Focus: 1. ArrayList<T> arraylist; arraylist.size(), arraylist.get(i), arraylist.add()
	 2. merge interval.

//Method 1:
public class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        // skip non overlap ones
        ArrayList<Interval> res = new ArrayList<Interval>();
        int i = 0;
        for (; i<intervals.size(); i++){
            if (newInterval.start <= intervals.get(i).end) break;
            else res.add(intervals.get(i));
        }
        
        //merge
        Interval mergeInterval = new Interval(newInterval.start, newInterval.end);

        while (i< intervals.size() && 
            intersect(mergeInterval, intervals.get(i))){
                mergeInterval.start = Math.min(intervals.get(i).start, mergeInterval.start);
                mergeInterval.end = Math.max(intervals.get(i).end, mergeInterval.end);
                i++;
        }
        
        res.add(mergeInterval);
        
        //copy left block
        while (i<intervals.size()) {
            res.add(intervals.get(i));
            i++;
        }
        return res;
    }
    
    private boolean intersect(Interval v1, Interval v2){
        if (v1.end < v2.start || v2.end < v1.start) return false;
        return true;
    }
}

//Method 2:
  Focus: 1. using Array to operation. Array[] arr=new Array[arrylist.size()]. arr.length
		arrlist.toArray(arr)  arrlist.clear()
	 2. Customize array sort. Arrays.sort(arr, new CustComp())
	 3. class CustComp implements Comparator<T> { public int compare(T t1, T t2) }
	 4. Then merge sorted Interval. More general, robust for library usage and easier.

public class Solution {
    public class IntervalCmp implements Comparator<Interval>{
        public int compare(Interval v1, Interval v2){
            if (v1.start < v2.start) return -1;
            else if (v1.start == v2.start) return 0;
            else    return 1;
        }
    }
    
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        intervals.add(newInterval);
        Interval[] arr = new Interval[intervals.size()];
        intervals.toArray(arr);
        Arrays.sort(arr, new IntervalCmp());
        
        intervals.clear();
        // now merge the sorted Intervals array
        int start = arr[0].start;
        int end = arr[0].end;
        for (int i=0; i<arr.length; i++){
            if (end >= arr[i].start) {
                end = Math.max(end, arr[i].end);
            }else {
                intervals.add(new Interval(start,end));
                start = arr[i].start;
                end = arr[i].end;
            }
        }
        
        //last one.
        intervals.add(new Interval(start,end));
        
        return intervals;
    }
}
