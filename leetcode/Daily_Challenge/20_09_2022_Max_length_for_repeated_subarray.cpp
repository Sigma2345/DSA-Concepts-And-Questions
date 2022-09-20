// https://leetcode.com/problems/maximum-length-of-repeated-subarray/


/*
    dp[i][j] = length of repeated subarray till index i in arr1 
    and index j in arr2
*/

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {

                    dp[i][j] = (i + 1) < nums1.size() && (j + 1) < nums2.size() ? dp[i + 1][j + 1] + 1 : 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
