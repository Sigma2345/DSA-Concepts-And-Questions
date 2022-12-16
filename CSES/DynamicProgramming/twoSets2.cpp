#include<bits/stdc++.h>
using namespace std;
#define long long long int
int MOD = 1e9 + 7; 

// similar to knapsack problem 
long solve(int n, int s){
    vector<vector<long>> arr(n+1, vector<long>(s+1, 0));
    for (int i = 1; i<=n ; i++){
        arr[i][0] = 1; 
    }
    for (int i = 1; i<=n ; i++){
        for (int j = 1; j <= s; j++){
            if(i<=j){
                arr[i][j] = arr[i-1][j-i] + arr[i-1][j] ;
                // arr[i-1][j-1] -> tells we have taken current element and deducted it 
                // arr[i-1][j] -> not considering current element 
            }
            else{
                arr[i][j] = arr[i - 1][j]; 
            }
            arr[i][j] %= MOD ; 
        }
    }


    return arr[n][s]; 
}

int main(){

    int n ; 
    cin>>n ;

    int s = 0;
    for (int i = 1; i <= n; i++){
        s += i ; 
    }

    if(s%2==1){
        cout << 0 << endl;
        return 0; 
    }
    // if sum of elements is odd then equal partititon can never be created

    s = s / 2; 
    long  x = solve(n, s);
    // cnt number of subsets that can be formed with sum = s/2
    x %= MOD;  
    cout << x << endl;

    return 0; 
}
