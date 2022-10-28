// https://leetcode.com/problems/strictly-palindromic-number/

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2 ; i<=n-2 ; i++){
            int x = log2(n)/log2(i);  // gets the largest power of i needed for n
            string s = "" ; 
            int y = n ; 
            while(y){
                int x1 = y/(pow(i,x)) ; // get the integer with pow(i,x)
                s += to_string(x1) ; 
                y -= (x1*pow(i,x)) ; // subtract it to go to lower powers
                x-- ; 
            }
            for(int i = 0 ; i<x ; i++) s  = s + '0' ; // at end all 0s left on right need to be appended
            for(int i = 0 ; i<s.length()/2 ; i++){
                if(s[i] != s[s.length()-i-1]){
                    return false;
                }  
            }
        }
        return true ;
    }
};
