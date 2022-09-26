// https://leetcode.com/problems/satisfiability-of-equality-equations/

/*
    the following approach is brute forced and unoptimized
    traverse the array and mark edge in adjacency list between characters that are claimed to be equal

    then , in next iteration, traverse the array and whenever get not equal to sign 
    then DFS on first character and check that it is not connected to second character

    if connected , return false
*/

class Solution {
public:
    
    bool DFS(int src, vector< list<int> > v, vector<int> &check, int des){
        if(check[src]) return false; 
        if(src == des){
            return true ;
        }
        check[src] = 1 ;
        bool ans = false ;
        for(auto x: v[src]){
            ans = ans || DFS(x,v,check,des); 
        }
        return ans ;
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector< list<int> > v(26) ;
        for(int i = 0 ; i<equations.size() ; i++){
            if(equations[i][1]=='='){
                v[equations[i][0]-'a'].push_back(equations[i][3]-'a') ;
                v[equations[i][3]-'a'].push_back(equations[i][0]-'a') ;
            }
        }
        
        for(int i = 0 ; i<equations.size() ; i++){
            vector<int> check(26,0); 
            if(equations[i][1] == '!' && DFS(equations[i][0]-'a', v, check, equations[i][3]-'a'))
                return false; 
        }
        
        return true ;
    }
};
