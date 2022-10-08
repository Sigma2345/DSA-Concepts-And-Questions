// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxNum = INT_MIN ; 
    bool AllNeg(vector<int>&nums, int i){
        
        if(i==nums.size()) return true ; 
        maxNum = max(maxNum , nums[i]);
        return nums[i]<0 && AllNeg(nums, i+1) ; 
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        // all negative 
        if(AllNeg(nums, 0)) return maxNum ; 
        int totalSum = 0 ; 
        int maxSum = 0 , sum = 0 ; 
        //kadane 
        for(int i = 0  ; i<nums.size() ; i++){
            sum += nums[i] ; 
            maxSum = max(sum, maxSum);
            
            if(sum<0) sum = 0 ;
            totalSum += nums[i] ; 
            nums[i] *= -1 ; 
        }
        
        //kadane for negative array
        int maxSum2 = 0 , sum2 = 0 ; 
        for(int i = 0  ; i<nums.size() ; i++){
            sum2 += nums[i] ; 
            maxSum2 = max(sum2, maxSum2);
            
            if(sum2<0) sum2 = 0 ;
            nums[i] *= -1 ; 
        }
        
        return max(maxSum , totalSum+maxSum2) ; 
    }
};
