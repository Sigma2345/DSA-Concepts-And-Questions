class Solution {
public:
    int dp[500][500] ; 
    int Solve(vector<int>& piles, int s, int e, int turn){
        //base case
        if(s==e) return piles[s]; 
        
        if(dp[s][e]!=-1) return dp[s][e] ; 
        // recursive case
        // alice turn -> add max
        if(turn == 0){
            return dp[s][e] =  max(piles[s] + Solve(piles, s+1, e, 1-turn), piles[e] + Solve(piles, s, e-1, 1-turn)); 
        }
        return dp[s][e] =  min(Solve(piles, s+1, e, 1-turn),Solve(piles, s, e-1, 1-turn)) ; 
        
    }
    
    bool stoneGame(vector<int>& piles) {
        for(int i = 0 ; i<500 ; i++){
            for(int j = 0  ; j<500 ; j++){
                dp[i][j] = -1 ; 
            }
        }
        int alice = Solve(piles,0,piles.size()-1, 0) ; 
        int s = 0 ; 
        for(int i = 0 ; i<piles.size() ; i++){
            s += piles[i]; 
        }
        int bob = s - alice ; 
        if(alice > bob) return true ;
        return false; 
    }
};
