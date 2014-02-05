/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
Discuss
*/
Focus: 1. temporary ArrayList<Integer> usage.
	2. dfs for combination problem pattern.  
		for (int start = index; start < s.lengt(); start++) {
			dfs(... , start + 1);
		}

public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        Arrays.sort(num);
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        dfs(num, target, list, res, 0);
        
        return res;
    }
    
    private void dfs(int[] num, int gap, ArrayList<Integer> list, ArrayList<ArrayList<Integer>> res, int index) {
        if (gap == 0) {
            res.add(new ArrayList<Integer>(list));
            // Focus 1: Wrong if just add list. list is an object and keep changing!!!
            //res.add(list);
            return;
        }
        
        for (int start = index; start < num.length; ++start) {
            if (start > index && num[start] == num[start - 1]) {
                continue;
            }
            
            //pruing
            if (num[start] > gap) return;
            
            list.add(num[start]);
            
            //Focus 2: pay attention to index value. It is start + 1 !!
            dfs(num, gap - num[start], list, res, start + 1);
            
            //Focus 3: remove last element from ArrayList
            list.remove(list.size() - 1);
        }
    }
}
