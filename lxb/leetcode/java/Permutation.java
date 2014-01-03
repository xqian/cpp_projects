/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Discuss
*/
// Focus: 1. pay attention to extension.
public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        dfs(num,0,res);
        return res;
    }
    
    private void dfs(int[] num, int index, ArrayList<ArrayList<Integer>> res){
        //base
        if (index == num.length){
            ArrayList<Integer> oneResult = new ArrayList<Integer>();
            for (int j=0; j<num.length;++j){
                oneResult.add(num[j]);
            }
            res.add(oneResult);
            return;
        }
        
        //extension
        for (int i=index; i<num.length; ++i){
            if (i==index || num[i] != num[index]){
                swap(num,index, i);
                dfs(num,index+1, res);
                swap(num,index, i);
            }
        }
    }
    
    private void swap(int[] num, int i, int j){
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
}
