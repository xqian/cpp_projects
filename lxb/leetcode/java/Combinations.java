//Focus: Runtime Error 1,1,
public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        ArrayList<Integer> oneSol = new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        
        dfs(n,k,oneSol,res);
        return res;
    }
    
    private void dfs(int n, int k, ArrayList<Integer> oneSol, ArrayList<ArrayList<Integer>> res){
        //base
        if (k==0){
            res.add(oneSol);
            return;
        }
        
        if (n<k) return;
        
        // not choose n
        dfs(n-1, k, oneSol, res);
        
        // or choose n
        oneSol.add(n);
        dfs(n-1, k-1, oneSol, res);
        oneSol.remove(n);
    }
}
