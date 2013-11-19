http://oj.leetcode.com/problems/decode-ways/

/*Question
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int N = s.size();
        if (N == 0 ) return 0;
       
       vector<int> DP(N+1,0); //DP[i] means the ways to decode it from string i..N-1
       DP[N] = 1;
       
       // State transition:
       // DP[i] = DP[i+1]
       // DP[i] += DP[i+2] if s[i-1] == '1' || s[i-1] =='2' && s[i] < '7'
       
       for (int i=N-1; i>=0; i--){
           if (s[i] == '0') {
               //Invalid
               DP[i] = 0;
               continue;
           }
           
           DP[i] = DP[i+1];
           
           if (i+1 < N && (s[i] == '1' || (s[i] =='2' && s[i+1] <= '6') ) )
           {
               DP[i] += DP[i+2];  //critical
           }
       }
       
       return DP[0];
    }
};
