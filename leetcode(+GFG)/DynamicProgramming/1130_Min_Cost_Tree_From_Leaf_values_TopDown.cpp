class Solution {
public:
    int dp[50][50] ; // stores solution for index s to e
    int maxVal[50][50]; // stores maxVal from index i to j  
    int solve(vector<int>&arr, int s, int e){
        //base case
        if(s==e) return 0 ;// leaf node

        //check        
        if(dp[s][e]!=-1) return dp[s][e] ;
        //recursiive case
        int ans = INT_MAX ; 
        for(int k = s; k<e ; k++){
            // subproblem
            ans = min(ans, maxVal[s][k]*maxVal[k+1][e] + solve(arr,s,k)+solve(arr,k+1,e));
        }
        return dp[s][e] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size() ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                dp[i][j] = -1 ; 
            }
        }
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i ; j<n ; j++){
                if(i==j) maxVal[i][j] = arr[i]; 
                else maxVal[i][j] = max(maxVal[i+1][j], maxVal[i][j-1]); 
            }      
        }
        return solve(arr,0,n-1);
    }
};
