http://oj.leetcode.com/problems/text-justification/
/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

Method 0: passed

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0, N = words.size();
        while (i < N)
        {
            int length = words[i].size();
            int j = i + 1;
            while (j < N && length + words[j].size() + (j-i) <= L)
                length += words[j++].size();
            // build line
            string s(words[i]);
            bool isLastLine = (j == N);
            bool oneWord = (j == i + 1);
            int average = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1);
            for (int k = i + 1; k < j; ++k) {
                s.append(extra > 0 ? average + 1 : average, ' ');
                s.append(words[k]);
                extra--;
            }
            s.append(L - s.size(), ' ');
            // push line
            res.push_back(s);
            i = j;
        }
        return res;
    }
};


Method 1: Issue: Memory Limit Exceeded

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> res;
        if (L==0) return words;
        
        int used = 0;
        vector<string> line;
        for (auto &word:words)
        {
            //can be added?
            if (used + word.size() <= L){
                used += word.size() + 1;
                line.push_back(word);
                continue;
            }else{
                addOneLine(line, res, used, L);
                
                line.clear();
                line.push_back(word);
                used = word.size() + 1;
            }
        }
        
        return res;
    }
    
    void addOneLine(vector<string> &line, vector<string> &res, int used, int L)
    {

        
        //build string.
        string oneline;
        //just one word
        if (line.size() == 1) {
            oneline = line[0];
            for (int i=line[0].size(); i<=L; i++) oneline += ' ';
            res.push_back(oneline);
            return;
        }
                
        //remove last space used.
        int spaces = (L - 1 - used) /(line.size() -1) + 1; //we already alloced one to seperate each word.
        int moreSpace = (L - 1 - used) % (line.size() - 1);
        
        for (int i=0; i<line.size();i++){
            oneline += line[i];
            
            for (int k=0; k< spaces; k++){
                oneline += ' ';
            }
                    
            if (i < moreSpace){
                oneline += ' ';
            }
        }
                
        res.push_back(oneline);
    }
};

Method 2: special case error?
Submission Result: Wrong Answer

Input:	[""], 0
Output:	[]
Expected:	[""]


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> res;
        
        int used = 0;
        vector<string> line;
        int j = 0;
        for (int i=0; i<words.size(); i++)
        {
            //can be added?
            if (used + words[i].size() <= L){
                used += words[i].size() + 1;
                continue;
            }else{
                //j..i
                bool isOneWord = i == j+1 ;
                int spaces = isOneWord ? L-words[j].size() : (L - 1 - used) /(i -j -1) + 1; //we already alloced one to seperate each word.
                int moreSpace = isOneWord ? 0: (L - 1 - used) % (i - j - 1);
                
                string oneline;
                for (int k=j; k < i; ++k){
                    oneline += words[k];
            
                    for (int l=0; l< spaces; l++){
                        oneline += ' ';
                    }
                    
                    if (k-j < moreSpace){
                        oneline += ' ';
                    }
                }
                
                //next start
                j = i;
                used = words[i].size();
            }
        }
        
        return res;
    }
};
