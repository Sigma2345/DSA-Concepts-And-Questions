// https://cses.fi/problemset/task/2183
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int n;
    cin >> n;
    vector<int> C;
    for (long long int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        C.push_back(x);
    }
    sort(C.begin(), C.end());
    long long int run_sum = 1;
    for (long long int i = 0; i < C.size(); i++)
    {
        if (run_sum < C[i])
            break;
        run_sum += C[i];
    }
    cout << run_sum << endl;

    return 0;
}
