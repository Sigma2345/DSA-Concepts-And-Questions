// https://leetcode.com/problems/cycle-length-queries-in-a-tree/description/

#include<bits/stdc++.h>
using namespace std; 

class Solution
{
public:
    int solve(int n1, int n2)
    {
        // base case
        if (n1 == n2)
            return 0;
        // recursive case
        if (n1 < n2)
            return solve(n2, n1);
        return 1 + solve(n1 / 2, n2);
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(1 + solve(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};

// solution -> find the distance from LCA of each node and add 1 -> in order to form a cycle 
