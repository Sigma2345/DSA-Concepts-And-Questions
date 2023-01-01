// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/description/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPyramids(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> prefix(r + 1, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + grid[i][j];
            }
        }

        // consider all 1s as apex of matrix
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j])
                {
                    int x = i, y1 = j, y2 = j;
                    int cnt = 1;
                    while (x < r && y1 >= 0 && y2 < c)
                    {
                        int num1 = prefix[x + 1][y2 + 1] - prefix[x + 1][y1];
                        if (num1 == cnt)
                        {
                            if (cnt > 1)
                                ans++;
                            cnt += 2;
                        }
                        else
                        {
                            break;
                        }
                        x++, y1--, y2++;
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j])
                {
                    int x = i, y1 = j, y2 = j;
                    int cnt = 1;
                    while (x >= 0 && y1 >= 0 && y2 < c)
                    {
                        int num1 = prefix[x + 1][y2 + 1] - prefix[x + 1][y1];
                        if (num1 == cnt)
                        {
                            if (cnt > 1)
                                ans++;
                            cnt += 2;
                        }
                        else
                        {
                            break;
                        }
                        x--, y1--, y2++;
                    }
                }
            }
        }

        return ans;
    }
};

// the idea is to consider each 1 as an apex 
// start counting towards bottom and up 
// the number of pyramids formed by it 
