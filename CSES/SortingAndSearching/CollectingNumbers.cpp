
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n; 
    cin>>n ;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<bool> v(n+1, false);
    int ans = 0;

    for (int i = 0; i < n; i++){
        // a[i] -1 is not found till now one round extra to be taken 
        if(v[a[i]-1] == false){
            ans++;
        }
        v[a[i]] = true; 
    }

    cout << ans << endl;

    return 0;
}
