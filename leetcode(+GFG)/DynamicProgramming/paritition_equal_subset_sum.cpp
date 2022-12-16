// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution
{
public:
    int arr[201][20001];
    bool SubsetSum(vector<int> &nums, int s, int n)
    {
        if (s == 0)
            return true;
        if (n == 0)
            return false;

        if (arr[n][s] != -1)
            return arr[n][s] ? true : false;

        if (nums[n - 1] <= s)
        {
            bool x = SubsetSum(nums, s - nums[n - 1], n - 1) || SubsetSum(nums, s, n - 1);
            arr[n][s] = x ? 1 : 0;
            return x;
        }
        bool x = SubsetSum(nums, s, n - 1);
        arr[n][s] = x ? 1 : 0;
        return x;
    }

    bool canPartition(vector<int> &nums)
    {
        memset(arr, -1, sizeof(arr));
        int s = 0;
        for (auto x : nums)
            s += x;
        if (s % 2)
            return false;
        // IF  SUM IS ODD THEN EQUAL PARTITION CANNOT BE MADE
        return SubsetSum(nums, s / 2, nums.size());
        // IF EQUAL partition can be made search if subset with sum = 0.5*sum of array exists 
    }
};
