// https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    int Solve(int st, string &s, vector< vector<bool> > &v, vector<int> &ans){
        //base case
        if(st==s.length()) return 0;         
        if(ans[st]!=-1) return ans[st] ; 
        // recursive case
        int minCost = INT_MAX ;
        for(int i = st ; i<s.length() ; i++){
            if(v[st][i] == true ){ // check if ahead cuts can be applied if st...i is palindrome
                int cost = 1 + Solve(i+1,s,v,ans);
                minCost = min(minCost, cost) ;
            }
        }
        return ans[st] = minCost ;
    }
    
    
    int minCut(string &s) {
        // store if s[i...j] is pallindrome or not
        if(s.length()==1) return 0; 
        vector< vector<bool> > dp(s.length(), vector<bool>(s.length(), true)) ;
        for(int i = s.length()-1  ; i>=0 ; i--){
            for(int j = i+1 ; j<s.length() ; j++){
                if(i+1 >= j-1){
                    dp[i][j] = s[i] == s[j]  ; 
                }
                else{
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : false ;                 
                }
            }
        }
        vector< int > ans(s.length(),-1); 
        return Solve(0,s,dp, ans)-1;
    }
};
