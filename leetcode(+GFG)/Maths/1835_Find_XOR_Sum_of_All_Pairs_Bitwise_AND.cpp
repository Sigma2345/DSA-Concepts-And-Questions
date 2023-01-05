// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/
#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int ans2 = arr2[0];
        int ans1 = arr1[0];

        for (int i = 1; i < n1; i++)
        {
            ans1 = ans1 ^ arr1[i];
        }

        for (int i = 1; i < n2; i++)
        {
            ans2 = ans2 ^ arr2[i];
        }

        return ans1 & ans2;
    }
};

// on simplyfying we get that the answer is 
// [a1^a2^...an] & [b1^b2^b3...bm]

