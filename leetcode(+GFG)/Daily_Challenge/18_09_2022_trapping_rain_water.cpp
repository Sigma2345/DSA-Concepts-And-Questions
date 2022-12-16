// https://leetcode.com/problems/trapping-rain-water/

/*
    the approach is that the max amount of water
    that can be trapped abpve a block
    is the min of height surrounding walls and 
    removing the size of the block

    so left_max[i] stores max height val on left
    and right_max[i] stores max height val on right
    of index i
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left_max(n, height[0]);
        for (int i = 1; i < n; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        vector<int> right_max(n, height[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans + (min(left_max[i], right_max[i]) - height[i]);
        }
        return ans;
    }
};
