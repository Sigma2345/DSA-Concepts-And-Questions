#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll binSearch(vector<vector<ll> > &arr, ll k)
{
    // smallest index greater than k
    ll ans = arr.size();
    ll s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        if (arr[mid][0] > k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

ll f(vector<vector<ll>> &arr, ll i, vector<ll> &dp)
{
    // base case
    if (i >= arr.size())
    {
        return 0;
    }

    if(dp[i]!=-1) return dp[i]; 

    // recursive case
    // op1 include
    ll op1 = 0, op2 = 0;
    ll nextIndex = binSearch(arr, arr[i][1]);
    op1 = arr[i][2] + f(arr, nextIndex, dp);
    // op2 exclude
    op2 = f(arr, i + 1, dp);
    return dp[i] = max(op1, op2);
}

int main()
{

    ll n;
    cin >> n;

    vector<vector<ll>> arr(n, vector<ll>(3, 0));

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }
    // standard knapsack type problem
    sort(arr.begin(), arr.end());
    vector<ll> dp(n, -1);
    ll x = f(arr, 0, dp);
    cout << x << endl;

    return 0;
}
