http://oj.leetcode.com/problems/longest-palindromic-substring/

//Method 1： DP, time O(n2), space O(n2）
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        
        //DP. DP[i][j]  whether substr of s(i..j) is palindrom.
        bool DP[1000][1000]={false};
        int begin = 0;
        int maxLen = 1;
        string result = ""+ s[0];
        
        //base (odd)
        // 1 character is palindrome
        for (int i=0;i<s.size();i++){
            DP[i][i] = true;
        }
        
        // 2 characers case (even)
        for (int j=0; j<s.size()-1;j++){
            if (s[j] == s[j+1]){
                DP[j][j+1] = true;
                begin = j;
                maxLen = 2;
            }
        }
        
        // DP[i][j] = {0 if s[i]!=s[j]; else DP[i+1][j-1] && s[i]=s[j]
        int n=s.size();
        
        for (int len=3;len<=n;len++){
            for (int i=0; i<n-len+1;i++){
                int j = i+len-1;
                if (s[i] == s[j] && DP[i+1][j-1]){
                    begin = i;
                    maxLen = len;
                    DP[i][j] = true;
                }
            }
        }
        
        // get max and return
        return s.substr(begin,maxLen);
    };
};

//Method2: expand from center. O(1) space, O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        
        string result = "";
        
        for (int i=0; i<s.size()-1;i++){
            //center. one node
            string p1 = expandCenter(s,i,i);
            if (p1.size() > result.size()){
                result = p1;
            }
            
            //center. two nodes
            if (s[i] == s[i+1]){
                string p2 = expandCenter(s,i,i+1);
                if (p2.size() > result.size()){
                    result = p2;
                }
            }
        }
        
        return result;
    };
    
    string expandCenter(string &s, int l, int r)
    {
        int size=s.size();
        while (l>=0 && r<size && s[l] == s[r]){
            l--;
            r++;
        }
        
        return s.substr(l+1, r-l-1);
    }
};

//Method3: Not pass OJ!!!!

class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (s.size() < 2 ) return s;
        
        // suffix array for s and reverse(s)
        string r = s;
        reverse(r.begin(), r.end());
        
        //different first and second string.
        r += "$";
        s += "!";
        
        // establish suffix array
        vector<string> suffixArray;
        int len = s.size();
        for (int i=0; i< len-1; i++)
        {
            suffixArray.push_back(s.substr(i,len-i));
            suffixArray.push_back(r.substr(i,len-i));
        }
        
        
        // sort suffix array
        sort(suffixArray.begin(), suffixArray.end());
        
        int maxPalindromeLen = 0;
        string result;
        // go through the two suffix array and get longest consective prefix.
        for (int i=0; i<suffixArray.size()-1; i++){
            int prelen = prefix(suffixArray[i], suffixArray[i+1]);
            
            if (prelen > maxPalindromeLen){
                if (isPalindrome(suffixArray[i].substr(0,prelen))){
                    maxPalindromeLen = prelen;
                    result = suffixArray[i].substr(0,prelen);
                }
            }
        }
        
        return result;
    };
    
    int prefix(string S1, string S2){
    
    if (S1.size() == 0 || S2.size() == 0 ) return 0;
    
    char endCharS1 = S1[S1.size()-1];
    char endCharS2 = S2[S2.size()-1];
    
    if (endCharS1 == '$' and endCharS2 == '$') return 0; 
    if (endCharS1 == '!' and endCharS2 == '!') return 0; 
    
    int count = 0;
    for (int i=0; i<S1.size() && i < S2.size();i++){
          if (S1[i] == S2[i]) count++;
          else break;
    }
    
    return count;
    }
    
    bool isPalindrome(string s){
        if (s.size() < 2) return true;
        
        int i=0;
        int j = s.size() - 1;
        
        while(i<j && s[i] == s[j]) {i++,j--;}
        
        return (i>=j);
    }
};
