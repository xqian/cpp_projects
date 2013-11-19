http://oj.leetcode.com/problems/scramble-string/

Issue: Very hard. Here is the DFS solution brute force, but inefficient and timeout.
Solutions: 1. Handling array and move away from off-by-one error by using array start index + len, compared two index.
	   2. Handle anagram method. Hash, unordered_multiset<char> to allow dup.
	   3. prune it as much as possible, as early as possible.

/* Question:
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

Method 3: This works! Solution from Jing.

class Solution { 
public: 
bool isScramble(string s1, string s2) { 
// Start typing your C/C++ solution below 
// DO NOT write int main() function 
    if ( s1.length() != s2.length() ) return false; 
    if ( s1.length() == 0) return true; 
    return isScramble(s1, 0, s2, 0, s1.length()); //BUG s1.length()-1 
} 

bool isScramble(const string & s1, int start1, const string & s2, int start2, int len) { 
    if ( !isAnagram(s1,start1, s2, start2, len) ) return false; 
    if( len == 1) return true; 
    for(int i=1; i <len; ++i) { 
        if ( isAnagram(s1, start1, s2, start2, i) ) { 
            if ( isScramble(s1, start1, s2, start2, i) && isScramble(s1, start1+i, s2, start2+i, len-i)) { 
            return true; 
            } 
        }else if ( isAnagram(s1, start1, s2, start2 + len - i, i) ) { 
            if(isScramble(s1, start1, s2, start2 + len - i, i) && 
                isScramble(s1, start1+i, s2, start2,len-i)) 
            { 
                return true; 
            } 
        } 
    } 
    return false; 
} 

bool isAnagram(const string & s1, int start1, const string & s2, int start2, int len) { 
    unordered_multiset<char> s; //BUG: forget multi 
    for(int i=0; i < len; ++i) { 
        s.insert(s1[start1+i]); 
    } 
    
    for(int i=0; i < len; ++i) { 
        auto iter = s.find(s2[start2+i]); 
        if (iter == s.end()) { 
            return false; 
        } else { 
            s.erase(iter); 
        } 
    } 
    return true; 
    } 
}; 


Method 4: Finally, it worked. :()
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        
        if (s1.size() == 1) return s1==s2;
        
        return isScramble(s1, 0, s2, 0, s1.size());
    }
    
    
private:
    bool isScramble(const string &s1, int start1, const string &s2, int start2, int len)   //tip: array index +len to operate.
    {
        //prune
        if ( ! isAnagram(s1, start1, s2, start2, len) ) {
            return false;
        }
        
        if (len==1) return true;
        
        for (int i=1; i< len; i++) //Bug prone: < len, otherwise, it's the same problem.
        {
            if ( isAnagram(s1, start1, s2, start2, i) &&
                 isScramble(s1,start1,s2,start2,i) &&
                 isScramble(s1,start1+i, s2, start2+i, len-i))
                 return true;
            
            if ( isAnagram(s1, start1, s2, start2 + len-i,i) &&
                 isScramble(s1,start1, s2, start2+len-i, i) && 
                 isScramble(s1,start1+i,s2,start2,len-i) )
                return true;
        }
        
        return false;
    }
    
    bool isAnagram(const string &s1, int start1, const string &s2, int start2, int len)
    {
        vector<int> hash(256,0);  //hardcode? Ok.. enn
        for (int i=0; i<len; i++ ){
            hash[s1[start1+i]]++;
        }
        
        for (int j=0; j<len; j++){
            hash[s2[j+start2]]--;
            if (hash[s2[j+start2]] < 0) return false;
        }
        
        for (int i=0; i<hash.size(); i++)
        {
            if (hash[i] != 0) return false;
        }
        
        return true;
    }
};


Method 1: timeout.
Submission Result: Time Limit Exceeded
Last executed input:	"abcdefghijklmn", "efghijklmncadb"


class Solution {
public:
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        
        if (s1.size() == 1) return s1==s2;
        
        for (int i=1; i<s1.size();i++)
        {
            string s1_left = s1.substr(0,i);
            string s1_right = s1.substr(i,s1.size()-i);
            string s2_left1 = s2.substr(0,i);
            string s2_right1 = s2.substr(i,s2.size()-i);
            string s2_left2 = s2.substr(0,s2.size()-i);
            string s2_right2 = s2.substr(s2.size()-i,i);
            
            if ( ( isScramble(s1_left, s2_left1) && isScramble(s1_right,s2_right1)) ||
                 ( isScramble(s1_left, s2_right2) && isScramble(s1_right,s2_left2)))
                 return true;
        }
        
        return false;
    }
};


/* Failure trial 2: timeout this time */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        
        if (s1.size() == 1) return s1==s2;
        
        return isScramble(s1, 0, s2, 0, s1.size());
    }
    
    
private:
    bool isScramble(string &s1, int start1, string &s2, int start2, int len)
    {
        //prune
        if ( ! isAnagram(s1, start1, s2, start2, len) ) {
            return false;
        }
        
        if (len==1) return true;
        
        for (int i=start1; i< len; i++)
        {
            if ( isAnagram(s1, start1, s2, start2, i-start1+1) &&
                 isScramble(s1,start1,s2,start2,i-start1+1) &&
                 isScramble(s1,i+1, s2, i+1, len - (i-start1 +1)))
                 return true;
            
            if ( isAnagram(s1, start1, s2, start2 + len-(i-start1+1),i-start1+1) &&
                 isScramble(s1,start1,s2,start2+len-(i-start1+1),i-start1+1) && 
                 isScramble(s1,i+1,s2,start2,len - (i-start1+1)) )
                return true;
        }
        
        return false;
    }
    
    bool isAnagram(string &s1, int start1, string &s2, int start2, int len)
    {
        vector<int> hash(256,0);
        for (int i=0; i<len; i++ ){
            hash[s1[start1+i]]++;
        }
        
        for (int j=0; j<len; j++){
            hash[s2[j+start2]]--;
            if (hash[s2[j+start2]] < 0) return false;
        }
        
        for (int i=0; i<hash.size(); i++)
        {
            if (hash[i] != 0) return false;
        }
        
        return true;
    }
};
