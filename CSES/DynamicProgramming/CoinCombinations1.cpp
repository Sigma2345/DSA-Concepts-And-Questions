
// https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
 
/*
    n-> num of coins
    val-> desired sum

    at every step the sum the number of ways is sum of number of ways 
    we can make [i-coins[j]] value where i is desired sum and coins[j] is value of jth coin
*/

int main() {
 
	int m = 1000000007 ;
	int n, val ;
	cin >> n >> val ;
    


	vector<int> C(n);
	for (int i = 0 ; i < n ; i++) {
		int x ;
		cin >> x ;
		C[i] = x ;
	}
 
	vector<int> dp(val + 1) ;
	for (int i = 0 ; i <= val ; i++) dp[i] = 0 ;
	dp[0] = 1 ;
 
	for (int i = 1 ; i <= val ; i++) {
		for (int j = 0 ;  j < C.size(); j++) {
			if (i >= C[j]) {
				dp[i] =  dp[i] + dp[i - C[j]] % m ;
				dp[i] %= m ;
			}
		}
	}
	cout << dp[val] << endl;
 
	return 0 ;
}
