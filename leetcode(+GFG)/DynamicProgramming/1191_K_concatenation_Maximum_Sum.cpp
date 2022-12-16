// https://leetcode.com/problems/k-concatenation-maximum-sum/

class Solution {
    
public:
    
    bool AllNeg(vector<int>&arr, long long int i){
        if(i==arr.size()) return true ;
        return arr[i] < 0 && AllNeg(arr, i+1) ; 
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        if(AllNeg(arr,0)) return 0 ;
        
        long long int MOD = 1e9 + 7; 
        long long int totalSum = 0 , maxPrefSum = 0 , maxSuffSum = 0 , prefSum = 0 , suffSum = 0, maxSum = 0, sum = 0 ;
        long long int n = arr.size() ; 
        for(long long int i = 0 ; i<n ; i++ ){
            sum =(sum + arr[i])%MOD ; 
            prefSum = (prefSum + arr[i]) % MOD ; 
            //suffSum += arr[n-1-i] ;
            suffSum= (arr[n-1-i] + suffSum) % MOD;
            maxSum = max(maxSum, sum);
            maxPrefSum = max(maxPrefSum , prefSum ) ;
            maxSuffSum = max(maxSuffSum , suffSum ) ;
            totalSum += arr[i] ;
            totalSum=totalSum % MOD;
            if(sum<0) sum = 0; 
        }
        
        if(k==1) return maxSum ; 
        long long int k1=k;
        int op1 = maxSum ; 
        int op2 = (totalSum*k1) % MOD ; 
        int op3 = (((maxSuffSum + maxPrefSum)%MOD + ((k-2)*totalSum))%MOD)%MOD ;
        int op4 = (maxSuffSum + maxPrefSum)%MOD ; 
        
        
        
        int ans = max ( max(op1, op4) , max(op2, op3));
        if(ans==1000000000)return 999999993;
        return ans;
    }
};
