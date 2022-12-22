#include<bits/stdc++.h>
using namespace std;

int f(vector<list<int>> &h, vector<int> &parent, int src){
    int ans = 0; 
    for(auto x: h[src]){
        ans += f(h, parent, x) + 1; 
    }
    // storing in parents src
    // no repetition since data structure is tree
    return parent[src] = ans; 
}

    int main()
{

    int n ;
    cin >>n  ; 

    vector< list<int> > h(n+1);

    for (int i = 0; i < n - 1; i++){
        int x; 
        cin>>x ;
        h[x].push_back(i + 2); 
    }

    vector<int> parent(n + 1, -1);
    int x = f(h, parent, 1);

    for (int i = 1; i <= n; i++){
        cout << parent[i] << ' '; 
    }

    cout << endl; 

    return 0;
}
