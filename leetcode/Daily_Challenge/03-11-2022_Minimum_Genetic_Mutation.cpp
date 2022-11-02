// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    // do bfs and check distance with end
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size()==0){
            return start == end ? 0: -1 ;
        }
        bank.push_back(start) ;
        unordered_map<string, list<string> > h ; 
        for(int i = 0 ; i<bank.size() ; i++){
            for(int j = i+1 ; j<bank.size() ; j++){
                int freq1[26] = {0}, freq2[26] = {0} ;
                int diff = 0 ; 
                for(int k = 0 ; k<8 ; k++){
                    if(bank[i][k] != bank[j][k]) diff++ ;
                }
                if(diff==1){
                    h[bank[i]].push_back(bank[j]) ;
                    h[bank[j]].push_back(bank[i]) ;
                }
            }
        }
        
        
        string src = start ;
        unordered_map<string, bool> vis ;
        unordered_map<string, int>  dis; 
        for(int i = 0 ; i<bank.size() ; i++){
            dis[bank[i]] = INT_MAX ;
        }
        dis[start] = 0 ; 
        dis[end] = INT_MAX ; 
        queue<string> q  ;
        q.push(src) ;
        vis[src] = true;
        while(!q.empty()){
            string x = q.front() ;
            q.pop() ;
            for(auto m: h[x]){
                if(!vis[m]){
                    q.push(m);
                    dis[m] = dis[x] + 1 ;
                    vis[m] = true; 
                }
            }
        }
        
        return dis[end] == INT_MAX ? -1 : dis[end];  
    }
};
