// https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    // here dp[i][j] -> number of i+1 length increasing subsequences possible ending with index j 
    // only need this till length 3 
    int dp1[3][1000] = {0} , dp2[3][1000] = {0}; 
    int numTeams(vector<int>& rating) {
        int n = rating.size() ; 
        for(int i = 0 ; i<n ; i++){
            dp1[0][i] = dp2[0][i] = 1 ; 
        }
        for(int i = 1; i<3 ; i++){
            for(int j = 0 ; j<n ; j++){
                for(int k = j-1 ; k>=0 ; k--){
                    if(rating[j]>rating[k]){
                        dp1[i][j] += dp1[i-1][k]; 
                    }
                }
            }
        }
        
        // to get increasing sequence in reverse i.e decreasing sequences
        reverse(rating.begin(), rating.end()); 
        for(int i = 1; i<3 ; i++){
            for(int j = 0 ; j<n ; j++){
                for(int k = j-1 ; k>=0 ; k--){
                    if(rating[j]>rating[k]){
                        dp2[i][j] += dp2[i-1][k]; 
                    }
                }
            }
        }
        
        int ans = 0 ; 
        for(int i = 0 ; i<n ; i++){
            ans += (dp1[2][i] + dp2[2][i]) ;  
        }
        return ans ;
    }
    // time complexity = O(n^2) -> at each level iteration we traverse array backwards to check for subsequence
    // space complexity = O(n)
};
