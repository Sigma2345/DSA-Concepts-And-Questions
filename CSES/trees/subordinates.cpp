#include<bits/stdc++.h>
using namespace std;

void findParent(vector<int> &parent, vector<int> &arr, int src){
	parent[arr[src]]++ ; 
	if(arr[src] == src) return ;
	findParent(parent ,arr, arr[src]) ;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n+1,0);
    vector<int> parent(n+1,0); 
    arr[1] = 1 ; 
    for (int i = 1; i < n; i++){
        cin >> arr[i+1]; 
    }
    for(int i = 2 ; i<n ; i++)
    	findParent(parent, arr, i);

    for(int i = 1; i<=n ; i++){
    	cout<<parent[i]<<' ' ; 
    }
    cout<<endl ;

    return 0; 
}
