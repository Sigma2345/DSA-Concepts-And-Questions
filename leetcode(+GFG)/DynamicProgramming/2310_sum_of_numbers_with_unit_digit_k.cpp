class Solution
{
public:
    int dp[3001][10];
    int f(int num, int k)
    {
        // if num<0 then no combination possible
        if (num < 0)
        {
            return -1;
        }
        // combination achieved
        if (num == 0)
        {
            return 0;
        }
        // one combination is achieved
        if (num % 10 == k)
        {
            return 1;
        }

        if (dp[num][k] != -1)
            return dp[num][k];


        int ans = INT_MAX;
        for (int i = 0; i <= (num - k) / 10; i++)
        {
            // check k, 10 + k, 20 + k 
            int x = 10 * i + k;
            int ch = f(num - k, k);
            if (ch != -1 && ch != INT_MAX)
            {
                ans = min(ans, 1 + ch);
            }
        }
        return dp[num][k] = ans;
    }

    int minimumNumbers(int num, int k)
    {
        if (k == 0 && num % 10)
        {
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        int x = f(num, k);
        return x == INT_MAX ? -1 : x;
    }
};
