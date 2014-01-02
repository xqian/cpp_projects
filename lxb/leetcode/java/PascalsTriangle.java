/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
//Focus: 1. how to operate 2D ArrayList. (two phase, init 1D and add)
	 2. ArrayList<T> a; a.get(index), a.set(index,value), a.size()

public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        //init.
        for (int i=0; i<numRows; ++i)
        { 
            ArrayList<Integer> row = new ArrayList<Integer>();
            for (int j=0; j<=i; ++j){
                row.add(1);
            }
            res.add(row);
        }
        
        for (int j=2; j<numRows; ++j)
        {
            ArrayList<Integer> prev = res.get(j-1);
            ArrayList<Integer> curr = res.get(j);
            for (int k=1; k<j;++k){
                curr.set(k,prev.get(k-1) + prev.get(k));
            }
        }
        
        return res;
    }
}
