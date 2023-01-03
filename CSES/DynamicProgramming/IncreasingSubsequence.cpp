#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; 
    cin>>n ;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> ans(n+1, INT_MAX); 
    // ans[i] -> last element satisfying it 
    ans[1] = a[0];
    for (int i = 1; i < n; i++){
        // bin search
        // largest number smaller than a[i]
        int indx = -1, s = 1, e = n;
        while(s<=e){
            int mid = s + (e - s) / 2; 
            if(ans[mid] < a[i]){
                indx = mid;
                s = mid + 1; 
            }
            else{
                e = mid - 1; 
            }
        }
        if(indx == -1){
            ans[1] = ans[1] > a[i] ? a[i] : ans[1];
        }
        else{
            ans[indx+1] = a[i]; 
        }
    }

    for(int i = n ; i>=1 ; i--){
        if(ans[i]!=INT_MAX){
            cout << i << endl;
            return 0; 
        }
    }

    return 0; 
}

// storing last element in ans array 
// find the length subsequence of which the number can be part of 
// if it cannot be part of any 
// check if it smaller than ans[1]
// if yes append it there 
