// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int a[101][10001];
    bool fRec(vector<int> arr, int sum, int n)
    {
        // base case
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (a[n][sum] != -1)
            return a[n][sum] == 1 ? true : false;

        // recursive case
        if (arr[n - 1] <= sum)
        {
            bool x = fRec(arr, sum - arr[n - 1], n - 1) || fRec(arr, sum, n - 1);
            a[n][sum] = x == 0 ? 0 : 1;
            return x;
        }
        bool x = fRec(arr, sum, n - 1);
        a[n][sum] = x == 0 ? 0 : 1;
        return x;
    }

    bool TopDown(vector<int> arr, int sum, int n)
    {
        for (int i = 0; i <= n; i++)
        {
            a[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    a[i][j] = (a[i - 1][j - arr[i - 1]] || a[i - 1][j]) ? 1 : 0;
                }
                else
                {
                    a[i][j] = a[i - 1][j] ? 1 : 0;
                }
            }
        }
        return a[n][sum] ? 1 : 0;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        memset(a, 0, sizeof(a));
        // return fRec(arr, sum, arr.size());
        return TopDown(arr, sum, arr.size());
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends
