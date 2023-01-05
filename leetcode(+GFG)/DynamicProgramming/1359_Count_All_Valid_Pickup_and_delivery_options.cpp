// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    int countOrders(int n)
    {
        int MOD = 1e9 + 7;
        vector<long long int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] * (i) * (2 * i - 1);
            dp[i] %= MOD;
        }

        return dp[n];
    }
};

// f(n) = (2n)!/(2!)ⁿ
// f(n) = f(n-1)*n*(2n-1)
