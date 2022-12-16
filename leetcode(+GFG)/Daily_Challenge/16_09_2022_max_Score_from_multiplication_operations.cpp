// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

/*
    the ques is  based on dynamic programming 
    based on the overlapping subproblems found in the ques

    -> the number of operations on the right can be
        given by  [ (nums.size() - 1) - (op-left) ]
    
    -> the dp would be of size multipliers.size**2
       since the max index the left pointer can 
       go is multipliers.size()
 */

class Solution
{
public:
    int f(vector<int> &nums, vector<int> &multipliers, int op, int left, vector<vector<int>> &dp)
    {
        // base case
        if (op == multipliers.size())
        {
            return 0;
        }

        if (dp[op][left] != INT_MIN)
            return dp[op][left];

        // recursive case
        int op1 = nums[left] * multipliers[op] + f(nums, multipliers, op + 1, left + 1, dp);
        int op2 = nums[(nums.size() - 1) - (op - left)] * multipliers[op] + f(nums, multipliers, op + 1, left, dp);
        return dp[op][left] = max(op1, op2);
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        vector<vector<int>> dp(multipliers.size() + 1, vector<int>(multipliers.size() + 1, INT_MIN));
        return f(nums, multipliers, 0, 0, dp);
    }
};
