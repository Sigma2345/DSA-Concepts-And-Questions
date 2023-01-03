// https://cses.fi/problemset/task/1084/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> apartments(n);
    vector<int> demand(m);

    for (int i = 0; i < n; i++)
    {
        cin >> apartments[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> demand[i];
    }

    // priority queue
    sort(apartments.begin(), apartments.end());
    sort(demand.begin(), demand.end());

    int ans = 0;
    int index = 0;
    for (int i = 0; i < m; i++)
    {

        int minVal = max(0, demand[i] - k), maxVal = demand[i] + k;
        int k = index;
        for (; k < n && apartments[k] < minVal; k++)
            ;

        if (k != n && apartments[k] <= maxVal)
        {
            ans++;
            k++;
        }
        index = k;
    }

    cout << ' ' << ans << endl;
    return 0;
}

/**
 * @brief the concept is that every demand has same window 
 * so in a sorted demand array 
 * an apartment cannot fulfill demand[i-1] because it is less
 * then for sure it cannot be acquired by customer with demand[i] 
 */
