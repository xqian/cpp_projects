/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
Focus: 1. c++ vs java mapping
	  vector : ArrayList
	2. boolean dp[][] = new boolean[N][N]
	3. dfs. code style.
public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        ArrayList<String> r = new ArrayList<String>();
        int len = s.length();
        boolean dp[][] = new boolean[len][len];
        dfs(s, 0, dp, r, res);
        return res;
    }
    
    private void dfs(String s, int start, boolean dp[][], ArrayList<String> r, ArrayList<ArrayList<String>> res) {
        if (start == s.length()) {
            if (r.size() > 0) {
                res.add(new ArrayList<String>(r));
            }
        } else {
            for (int j = start; j < s.length(); ++j) {
                if ((start == j) 
                    || (j - start > 1 && s.charAt(j) == s.charAt(start) && dp[start + 1][ j -1])
                    || (j - start == 1 && s.charAt(j) == s.charAt(start))) {
                        dp[start][j] = true;
                        r.add(s.substring(start, j + 1));
                        dfs(s, j + 1, dp, r, res);
                        r.remove(r.size() - 1);
                    }
            }
        }
    }
}
