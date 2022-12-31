// https://leetcode.com/problems/cherry-pickup-ii/description/

class Solution {
public:

    int dp[70][70][70] ; 
    int f(vector<vector<int>>& grid, int i, int j, int k){
        //base case
        if(j<0 || j>=grid[0].size()) return 0; 
        if(k<0 || k>=grid[0].size()) return 0; 
        if(i==grid.size()) return 0; 

        if(dp[i][j][k] != -1){
            return dp[i][j][k] ; 
        }
        //recursive case
        // j == k -> then give it to for max profit

        int ans = 0 ;
        for(int l1 = -1 ; l1<=1 ; l1++){
            for(int l2 = -1 ; l2<=1 ; l2++){
                int x = grid[i][j] + grid[i][k] ; 
                if(j==k) x/=2 ;
                ans = max(ans, x + f(grid, i+1, j+l1, k+l2)); 
            }
        }
        return dp[i][j][k] =  ans ;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp)) ;
        return f(grid, 0, 0, grid[0].size()-1);       
    }
};
