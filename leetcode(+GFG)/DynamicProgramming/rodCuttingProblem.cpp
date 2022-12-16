// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// User function Template for C++

class Solution
{
public:
    int a[1001][1001];
    int f(int price[], int n, int len)
    {
        // base case
        if (n == 0 || len == 0)
            return 0;

        if (a[n][len] != -1)
            return a[n][len];

        // recursive case
        if (n <= len)
        {
            return a[n][len] = max(price[n - 1] + f(price, n, len - n), f(price, n - 1, len));
        }
        // price[n - 1] + f(price, n, len - n) -> this is we take price[n-1] and divide further
        // f(price, n - 1, len) -> leave price[n-1] and look further
        return a[n][len] = f(price, n - 1, len);
    }

    int ftopDown(int price[], int n)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                {
                    a[i][j] = max(price[i - 1] + a[i][j - i], a[i - 1][j]);
                }
                else
                {
                    a[i][j] = a[i - 1][j];
                }
            }
        }

        return a[n][n];
    }

    int cutRod(int price[], int n)
    {
        // code here
        memset(a, 0, sizeof(a));
        // return f(price, n, n);
        return ftopDown(price, n);
    }
};
