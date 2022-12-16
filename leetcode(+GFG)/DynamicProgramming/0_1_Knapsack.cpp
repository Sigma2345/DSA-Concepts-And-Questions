// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int arr[1001][1001];
    int RecSolve(int W, int wt[], int val[], int n)
    {
        // base case
        if (n == 0 || W == 0)
            return 0;

        // check
        if (arr[n][W] != -1)
            return arr[n][W];

        // recursive case
        if (wt[n - 1] <= W)
            return arr[n][W] = max(val[n - 1] + RecSolve(W - wt[n - 1], wt, val, n - 1), RecSolve(W, wt, val, n - 1));

        return arr[n][W] = RecSolve(W, wt, val, n - 1);
    }

    int TopDown(int W, int wt[], int val[], int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    arr[i][j] = max(val[i - 1] + arr[i - 1][j - wt[i - 1]], arr[i - 1][j]);
                }
                else
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
        return arr[n][W];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(arr, 0, sizeof(arr));
        // return RecSolve(W, wt, val, n) ;
        return TopDown(W, wt, val, n);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
