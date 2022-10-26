// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    // dp[i][j] -> is substring from index i to j a pallindrome 
    bool dp[1000][1000] = {false} ;
    int countSubstrings(string s) {
        int ans = 0 ; 
        for(int i = s.length()-1 ; i>=0 ; i--){
            dp[i][i] = true ;
            for(int j = i+1 ; j<s.length() ; j++){
                int l = j-i+1 ; 
                // if l==2 then we cannot go forward and check as then i+1 > j-1 
                // so check for equality
                // if l>2 then check using dp
                dp[i][j] = l==2 ? s[i]==s[j] : (s[i]==s[j]) && dp[i+1][j-1]; 
                if(dp[i][j]) ans++ ;
            }
            
        }
        
        // adding length of string as single characters also form palindromic substrings
        return ans + s.length() ;
    }
};
