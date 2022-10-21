#include<bits/stdc++.h>
using namespace std; 
#define ll long long 

ll dp[5000][5000] ; 
ll Solve(vector<int>& piles, int s, int e, int turn)
{
    //base case
    if(s==e && turn == 0 ) return piles[s]; // here p1 has to take last item by force
    if(s==e && turn == 1 ) return 0; // here p1 won't get anything  
    
    if(dp[s][e]!=-1) return dp[s][e] ; 
    // recursive case
    // alice turn -> add max

    // returns should be maximum for the case player 1 has turn -> optimising in player 1 turn 
    if(turn == 0){
        return dp[s][e] =  max(piles[s] + Solve(piles, s+1, e, 1-turn), piles[e] + Solve(piles, s, e-1, 1-turn)); 
    }
    // returns will be minimum for the case when player 2 has the turn -> optimising player 2 returns
    return dp[s][e] =  min(Solve(piles, s+1, e, 1-turn),Solve(piles, s, e-1, 1-turn)) ; 
}

ll stoneGame(vector<int>& piles) 
{
    for(int i = 0 ; i<5000 ; i++){
        for(int j = 0  ; j<5000 ; j++){
            dp[i][j] = -1 ; 
        }
    }
    ll alice = Solve(piles,0,piles.size()-1, 0) ; 
    return alice ;
}

int main(){

    ll n ; 
    cin>>n ; 

    vector<int> piles(n) ;
    for(int i = 0 ; i<n ; i++){
        cin>>piles[i] ;
    }

    cout<< stoneGame(piles) <<endl ;
    return 0; 
}
