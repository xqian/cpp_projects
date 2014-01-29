/*Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

Notes: timeout
Focus: string str.length(), charAt()
public class Solution {
    public String strStr(String haystack, String needle) {
        int i=0;
        int j=0;
        
        while (i<haystack.length())
        {
            j=0;
            while (j<needle.length()){
                if (i+j < haystack.length() && 
                    haystack.charAt(i+j) == needle.charAt(j)) j++;
                else {
                    break;
                }
            }
            
            if (j == needle.length()) {
                return haystack.substring(i);
            }else{
                i++;
            }
        }
        
        return null;
    }
}
