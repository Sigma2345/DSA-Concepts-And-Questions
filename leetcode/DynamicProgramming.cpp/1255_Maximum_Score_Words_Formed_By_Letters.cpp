// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    int ans = 0 ; 
    int f(vector<int> &index, vector<int> freq, vector<int>&score, vector<string>&words){
        int subans = 0  ;
        for(int i = 0 ; i<index.size() ; i++){
            if(index[i]){
                for(int j = 0 ; j<words[i].length() ; j++){
                    // if no more letters left that subsequence is invalid
                    if(freq[words[i][j]-'a']==0){
                        return 0 ; 
                    }  
                    // reduce freq of the letter  once used
                    freq[words[i][j]-'a']-- ;
                    subans += score[words[i][j]-'a']; 
                }
            }
        }
        return subans; 
    }
    
    void Check(int i, vector<int> index, vector<int> &freq, vector<int> &score, vector<string> &words){
        //base case
        if(i==words.size()){
            // x is score formed by that subsequence and if invalid returns 0; 
            int x = f(index, freq, score, words); 
            ans = max(ans, x) ;
            return ; 
        }
        //recursive case
        Check(i+1, index, freq, score, words); 
        index[i] = 1 ; 
        Check(i+1, index, freq, score, words);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // freq vector storing freq of all letters
        vector<int> freq(26) ; 
        for(int i= 0  ; i<letters.size() ; i++){
            freq[letters[i]-'a']++ ; 
        }
        // index vector will store id ith word should be taken in consideration or not
        // 0-> not take in subsequence
        // 1-> take in subsequence
        vector<int> index(words.size(),0);    
        // now check all possible subsequences
        Check(0,index, freq, score, words); 
        return ans ;
    }
};
