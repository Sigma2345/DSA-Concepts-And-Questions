// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort so that binary search can be applied 
        sort(nums.begin(), nums.end()); 
        // ans 
        int prevSum = nums[0] + nums[1] + nums[2] ; 
        int n = nums.size() ; 
        for(int i = 0 ; i<n-2 ; i++){
            int s = i+1 , e = n-1 ;
            while(s<e){
                // this current sum
                int curSum = nums[i] + nums[s] + nums[e]  ;
                // if curSum more close than prevSum 
                // change prevSum to curSum 
                if(abs(curSum-target) < abs(prevSum-target)){
                    prevSum = curSum ; 
                }
                // if value is less increment the sum
                if( curSum < target ) s++ ; 
                // if value is more then decrement the sum
                else if ( curSum > target ) e-- ; 
                // if equality achieved then this is closest
                else return target ; 
            }
        }
        return prevSum ; 
    }
};
