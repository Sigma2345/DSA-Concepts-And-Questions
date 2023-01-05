// https://leetcode.com/problems/stone-game-iv/description/
#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    int dp[100000];
    bool f(int n)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        bool ans = 0;
        for (int i = 1; i * i <= n && !ans; i++)
        {
            ans = ans || !f(n - i * i); // for other turn ans should be false
        }
        return dp[n] = ans;
    }

    bool winnerSquareGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};
