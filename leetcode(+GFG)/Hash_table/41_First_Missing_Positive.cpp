// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int i = 0 , n= nums.size(); 
        
        while(i<n){
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]); 
            }
            else i++ ;
        } // swaps all numbers to there correct place 
        
        // check if the number we got is in place or not 
        for(int i = 0 ; i<n ; i++){
            if(nums[i] != i+1) return i+1 ;
        }
        return n+1; 
    }
};
