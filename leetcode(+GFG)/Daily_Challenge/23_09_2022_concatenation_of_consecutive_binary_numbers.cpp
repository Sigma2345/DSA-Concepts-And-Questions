// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

/**
    the approach for the solution is that each number will push the bits in the ans 
    by the length of bits in the ans
    and then the number gets added to the sum

    calculation of the bits can be done the following way 
    numBits = log2(n) + 1
*/

class Solution {
public:
    
    int numBits(int n){
        return log2(n) + 1; 
    }
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7  ; 
        for(int i = 1;  i<=n ; i++ ){
            int len = numBits(i) ;
            long x = (ans<<len)%MOD ; 
            ans = ( x + i  )%MOD ;
        }
        return ans; 
    }
};
