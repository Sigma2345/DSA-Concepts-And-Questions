// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // anagrams have identical freq array 
        // make  freq array and push all the same freq array strings in the same vector mapping 
        map< vector<int> , vector<string> > h ; 
        for(int i = 0 ; i<strs.size() ; i++){
            vector<int> freq(26,0); 
            for(int j = 0;  j<strs[i].length() ; j++){
                freq[strs[i][j]-'a']++ ; 
            }
            h[freq].push_back(strs[i]) ;
        }
        vector< vector<string> > ans ;
        for(auto x: h){
            ans.push_back(x.second) ;
        }
        return ans ;
    }
};
