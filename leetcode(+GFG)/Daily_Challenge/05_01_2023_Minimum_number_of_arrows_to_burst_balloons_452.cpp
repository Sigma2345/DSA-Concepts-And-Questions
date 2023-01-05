// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool f(int st, int e, int k)
    {
        return (k >= st && k <= e);
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            int st = points[i][0], e = points[i][1];
            while (i < points.size() && (f(st, e, points[i][0]) || f(st, e, points[i][1])))
            {
                st = max(st, points[i][0]);
                e = min(e, points[i][1]);
                i++;
            }
            ans++;
        }
        return ans;
    }
};

// sort the points array
// decreasing the st and e size 

