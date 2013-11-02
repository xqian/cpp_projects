http://oj.leetcode.com/problems/add-binary/

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int aLen = a.size();
        int bLen = b.size();
        
        int carrier=0;
        int sum = 0;
        
        vector<char> result;
        int i = 0;
        for (; i< aLen && i<bLen; i++){
            int sum = a[i] - '0' + b[i] - '0' + carrier;
            result.push_back(sum%2 + '0');
            carrier = sum / 2;
        }
        
        if (aLen > bLen){
            for (;i<aLen; i++)
            {
                int sum = a[i] - '0' + carrier;
                result.push_back(sum % 2 + '0');
                carrier = sum / 2;
            }
            
            if (carrier) result.push_back('1');
        }else if (bLen>aLen){
            for (;i<bLen; i++){
                int sum = b[i] - '0' + carrier;
                result.push_back(sum % 2 + '0');
                carrier=sum / 2;
            }
            if (carrier) result.push_back('1');
        }else{
            if (carrier) result.push_back('1');
        }
        
        reverse(result.begin(), result.end());
        
        return string(result.begin(), result.end());
        
    }
};
