//  https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> &wt, int st, int e, int k)
{
    int indx = -1;
    while (st <= e)
    {
        int mid = st + (e - st) / 2;
        if (wt[mid] <= k)
        {
            indx = mid;
            st = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return indx;
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    sort(wt.begin(), wt.end());

    int s = 0, e = n - 1;

    int ans = 0;
    vector<int> vis(n, false);

    while (s < n )
    {

        if (!vis[s])
        {
            // find largest number less than or equal to x - wt[s] in range s+1 -> e
            int indx = binSearch(wt, s + 1, e, x - wt[s]);
            if (indx != -1)
            {
                vis[indx] = true;
                e = indx - 1;
            }
            ans++; 
            vis[s] = true;
        }
            s++;
    }

    cout << ans<<endl ; 

    return 0;
}

/**
 * @brief sort the array
 * find the largest number in range (s,e] s.t
 * it is smaller than (max_weight_allowed - wt[s])
 * if the index is found 2 are pushed in gondola 
 * else only s is pushed 
 * vis vector is used to check whether the index is visited already or not 
 */
