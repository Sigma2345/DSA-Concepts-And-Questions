// https://leetcode.com/contest/weekly-contest-312/problems/longest-subarray-with-maximum-bitwise-and/

/*
    THE PROBLEM IS SIMPLY TO GET THE MAX NUMBER IN THE ARRAY
    AND LENGTH OF LARGEST SUBARRAY WHICH CONTAINS
    ALL THE NUMBERS
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxVal = nums[0], n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxVal = max(nums[i], maxVal);
        }
        int ans = 1;
        for (int i = 0; i < n;)
        {
            if (nums[i] == maxVal)
            {
                int j = i;
                while (j < n && nums[j] == maxVal)
                {
                    j++;
                }
                ans = max(ans, j - i);
                i = j;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
