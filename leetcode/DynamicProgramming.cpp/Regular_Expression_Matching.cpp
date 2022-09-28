// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    
    // dp[i][j] => is string matching till ith char of s string and jth char of p string 
    bool isMatch(string s, string p) {
        vector < vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false));
        // blank char always matches to blank character
        dp[0][0] = true ; 
        
        // every time * comes see if it takes the preceeding character then 
        // is matching possible
        for(int j = 1 ; j<p.length()+1 ; j++ ){
            if(j>=2 && p[j-1]=='*'){
                dp[0][j] = dp[0][j-2] ; 
            }
        }
        
        
        for(int i = 1 ; i<=s.length() ; i++){
            for(int j = 1 ; j<=p.length() ; j++){
                // if char are matching or one of them is . 
                // then check if prev strings matching
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1] ; 
                }
                // if p[j-1] = * 
                // first check without substring is possible 
                // eg mis* -> is mi matching
                // or if the preceeding char is matching 
                // then check miss* matching by checking dp[i-1][j] 
                else if(p[j-1]=='*'){
                    dp[i][j] = j>=2 && (s[i-1] == p[j-2] || p[j-2]=='.') ? dp[i][j-2] || dp[i-1][j]  : dp[i][j-2] ; 
                }
            }
        }
        return dp[s.length()][p.length()]; 
    }
};
