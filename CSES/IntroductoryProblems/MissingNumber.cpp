#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; 
    cin>>n ; 

    vector<bool> arr(n,false) ;

    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        arr[x-1] = true; 
    }

    for (int i = 0; i<n ; i++){
        if(!arr[i])
            cout << (i + 1) << endl; 
    }

    return 0; 
}
