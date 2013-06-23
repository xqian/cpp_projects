//This is amazing, no logic bugs found, pass at first execution!!!
class Store {
private:
    unordered_set<char> charSet; //BUG: write map
    unordered_multiset<char> charNeeded;
    unordered_multiset<char> extraChar;
public:
    void init(const string & s) { //BUG: forget void
        for(int i=0; i < s.length(); ++i) {
            if( charSet.find(s[i]) == charSet.end()) {
                charSet.insert(s[i]);
            }
            charNeeded.insert(s[i]);
        }
    }
    
    void addChar(char ch) {
        if( charSet.find(ch) == charSet.end()) return;
        auto iter = charNeeded.find(ch);
        if( iter == charNeeded.end()) {
            extraChar.insert(ch);
        }
        else {
            charNeeded.erase(iter);
        }
    }
    
    void removeChar(char ch) {
        if( charSet.find(ch) == charSet.end()) return;
        auto iter = extraChar.find(ch);
        if (iter == extraChar.end()) {
            charNeeded.insert(ch);
        }   
        else {
            extraChar.erase(iter);
        }
    }
    
    bool isFullWindow() {
        return charNeeded.empty();
    }
};

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( T.length() == 0) return string("");
        Store store;
        store.init(T);
        int bestStart;
        int bestLength = -1;
        int start = 0;
        for(int i=0; i < S.length(); ++i) {
            store.addChar(S[i]);
            if (store.isFullWindow() ) {
                while( store.isFullWindow()) {
                    store.removeChar(S[start++]);
                }
                if ( bestLength < 0 || i - start + 2 < bestLength) {
                    bestStart = start - 1;
                    bestLength = i - start + 2;
                }
            }
        }
        if ( bestLength > 0) {
            return S.substr(bestStart, bestLength);
        }
        else {
            return string("");
        }
    }
};