// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    unordered_map<string, int> dist ;    
    bool Check(string &s1, string &s2 ){
        int cnt = 0;
        for(int i=  0; i<s1.length() ; i++){
            if(s1[i] != s2[i]){
                cnt++ ;
            }
        }
        return cnt<=1 ? true : false; 
    } // checks if 2 strings conversion compatible

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string> > h ;
        int n = wordList.size() ; 
        //  checks if start word already present in vector
        // and also creates graph between elements of graph 
        bool startPresent = false ;
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                 if(Check(wordList[j],wordList[i])){
                    h[wordList[j]].push_back(wordList[i]); 
                    h[wordList[i]].push_back(wordList[j]); 
                }
                startPresent = startPresent || wordList[i] == beginWord ; 
            }
        }
        if(!startPresent){
            for(int i = 0 ; i<n  ; i++){
                if(Check(beginWord,wordList[i])){
                    h[beginWord].push_back(wordList[i]); 
                    h[wordList[i]].push_back(beginWord); 
                }
            }            
        }
        dist[beginWord] = -1 ; 
        dist[endWord] = -1 ; 
        for(int i = 0 ; i<n ; i++){
            dist[wordList[i]] = -1 ; 
        }

        // BFS
        dist[beginWord] = 0 ;
        queue<string> q; 
        q.push(beginWord);
        while(!q.empty()){
            auto x = q.front() ;
            q.pop() ; 
            for(auto y: h[x]){
                if(dist[y]==-1){
                    dist[y] = dist[x] +1 ;
                    q.push(y); 
                }
            }
        }
        
        return dist[endWord] == -1 ? 0 : dist[endWord] +1;
    }
};
