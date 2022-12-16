// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false)); 
        dp[0][0] = true ; // if both strings of 0 zero length then ans is true 
        
        bool isStar = true ; 
        // till the time initial chars are * empty string can also be true
        for(int i  = 1 ; i<=p.length() ; i++){
            if(p[i-1]!='*'){
                isStar = false ;
                break ; 
            }
            dp[0][i] = true ;
        }
        
        for(int i =  1;  i<=s.length() ; i++){
            for(int j = 1;  j<=p.length() ; j++){
                if(p[j-1]!='*'){
                    if(p[j-1]=='?'){
                        // check prev match only
                        dp[i][j] = dp[i-1][j-1] ;
                    }
                    else{
                        // check that just before is satisfied 
                        // current is satisfied
                        dp[i][j] = (dp[i-1][j-1]) && (s[i-1] == p[j-1]); 
                    }
                }
                else{
                    // i , j-1 -> * replace by empty char
                    // i-1, j-1 -> replace single char
                    // i-1, j -> replace * by multiple chars
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1] ; 
                }
            }
        }        
        return dp[s.length()][p.length()]; 
    }
};
