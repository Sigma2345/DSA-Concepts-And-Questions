// https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length() ;
        // if n=1 then replacing any char will give palindrome
        if(n==1) return "" ;
        for(int i = 0 ; i<n ; i++){
            // replace first non center alphabet not a
            if(i!=n/2 && palindrome[i]!='a'){
                palindrome[i] = 'a' ;
                return palindrome ;
            }
        }
        // no change in string so last letter  must be changed 
        palindrome[n-1] = 'b' ;
        return palindrome ;
    }
};
