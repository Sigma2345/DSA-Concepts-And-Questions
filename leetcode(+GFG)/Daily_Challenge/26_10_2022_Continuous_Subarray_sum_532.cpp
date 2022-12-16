// https://leetcode.com/problems/continuous-subarray-sum/

class Solution{
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	// initialize the hash map with index 0 for sum 0
        unordered_map<int, int> hashMap{{0, 0}};
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            // if the remainder sum % k occurs for the first time
            if (!hashMap.count(s % k))
                hashMap[s % k] = i + 1;
            // if the subarray size is at least two
            else if (hashMap[s % k] < i)
                return true;
        }
        return false;
    }
};
