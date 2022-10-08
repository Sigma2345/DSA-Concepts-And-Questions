// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // 0 1 1 1 
        // 1 1 2 2  
        // 0 1 2 3
        int sum = 0 ;         
        int r = matrix.size() , c = matrix[0].size() ; 
        vector< vector<int> > dp(r , vector<int>(c,0)) ;
        for(int i = 0 ; i<r ; i++){
            dp[i][0] = matrix[i][0] ;
            sum += dp[i][0] ; 
        }
        for(int i = 0 ; i<c ; i++){
            dp[0][i] = matrix[0][i] ;
            sum += dp[0][i] ;
        }
        
        for(int i = 1 ; i<r ; i++){
            for(int j = 1 ; j<c ; j++){
                if(matrix[i][j]){
                    // i,j requires i-1,j i-1,j-1 and i,j-1 to form a square 
                    // min length of square would be  min of three indices + 1
                    if(matrix[i-1][j] && matrix[i-1][j-1] && matrix[i][j-1]){
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1] , dp[i-1][j-1])) + 1; 
                    }
                    else{
                        dp[i][j] = 1 ; 
                    }
                }
                sum += dp[i][j] ; 
            }
        }
        // in case first entry in matrix is non zero we double counted it
        // in initial counting 
        return  matrix[0][0] ?  sum-1 : sum ;
    }
};
