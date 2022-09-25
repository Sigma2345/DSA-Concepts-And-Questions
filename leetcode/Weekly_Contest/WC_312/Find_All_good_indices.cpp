// https://leetcode.com/contest/weekly-contest-312/problems/find-all-good-indices/

/*
atleast one element to the left can always be part of subarray
similar for right side

as a result ctsDec = 1
*/

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> a1(n), a2(n);
        a1[0] = 0;
        a2[n - 1] = 0;
        int ctsDec = 1;
        for (int i = 1; i < n; i++)
        {
            a1[i] = ctsDec;
            if (nums[i] <= nums[i - 1])
                ctsDec++;
            else
                // now only one element to the left can be part of subarray
                ctsDec = 1;
        }
        ctsDec = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            a2[i] = ctsDec;
            if (nums[i] <= nums[i + 1])
                ctsDec++;
            else
                ctsDec = 1;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            // cout<<a1[i]<< ' '<<a2[i]<<endl ;
            if (a1[i] >= k && a2[i] >= k)
                ans.push_back(i);
        }
        // cout<<endl;
        return ans;
    }
};
