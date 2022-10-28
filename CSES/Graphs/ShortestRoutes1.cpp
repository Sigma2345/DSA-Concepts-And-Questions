// https://cses.fi/problemset/task/1671

#include<bits/stdc++.h>
using namespace std; 
#define ll long long int 
#define INF 1e18

int main(){
    
    ll n, m ; 
    cin>>n>>m ; 

    vector< vector< pair<int,int> > > arr(n+1); 
    for(ll i = 0 ; i<m ; i++){
        ll src, des, dist ; 
        cin>>src>>des>>dist ; 
        arr[src].push_back({des, dist}); 
    }

    // dijkstra algo
    ll src = 1;  
    map < ll, ll> mp;
    for(ll i = 1;  i<=n ; i++){
        mp[i] = INF ; 
    } 
    mp[src] = 0; 
    set< pair<ll, ll> > s;  
    s.insert({0, src}); 
    while(!s.empty()){
        auto x = *(s.begin()); 
        s.erase(s.begin()); 
        ll parent = x.second , dist = x.first ;
        for(auto p: arr[parent]){
            ll child = p.first , childDist = mp[p.first], edgeDist = p.second; 
            if(childDist > edgeDist + dist){
                auto x1 = s.find({childDist, child});  
                if(x1!=s.end()){
                    s.erase(x1);
                }
                mp[p.first] = edgeDist + dist; 
                s.insert({mp[p.first], child}); 
            }
        }
    }

    for(ll i = 1;  i<=n ; i++){
        cout<<mp[i]<<' ' ;
    }
    cout<<endl ;

    return 0 ;
}
