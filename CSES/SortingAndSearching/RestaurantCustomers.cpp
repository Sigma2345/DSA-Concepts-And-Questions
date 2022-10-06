// https://cses.fi/problemset/task/1619/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
 
int main()
{
 
    ll n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        ll start, depart;
        cin >> start >> depart;
        events.pb({start, 0});
        events.pb({depart, 1});
    }
 
    sort(events.begin(), events.end());
    
    // if we get some ending we do subtract simultaneously running events 

    ll run_max = 0, run_pref = 0;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].second == 0)
        {
            run_pref++;
        }
        else
        {
            run_pref--;
        }
        run_max = max(run_max, run_pref);
    }
    cout << run_max << endl;
 
    return 0;
}
