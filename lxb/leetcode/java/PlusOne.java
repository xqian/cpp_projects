//Given a number represented as an array of digits, plus one to the number.
//Focus: 1. may need one extra bit for 9,99 +1.
public class Solution {
    public int[] plusOne(int[] digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        reverse(digits);
        int carrier = 1;
        for (int i=0; i<digits.length;++i){
            digits[i] += carrier;
            if (digits[i] > 9){
                digits[i] -= 10;
                carrier = 1;
            }else{
                carrier = 0;
                break;
            }
        }
        
        if (carrier==1){
            int[] res = new int[digits.length+1];
            res[0] = 1;
            for (int i=digits.length-1,j=1;i>=0;--i,++j)
            {
                res[j] = digits[i];
            }
            return res;
        }else{
            reverse(digits);
            return digits;
        }
    }
    
    private void reverse(int[] arr){
        for (int i=0; i<arr.length/2;++i){
            int tmp = arr[i];
            arr[i] = arr[arr.length-1-i];
            arr[arr.length-1-i] = tmp;
        }
    }
}
