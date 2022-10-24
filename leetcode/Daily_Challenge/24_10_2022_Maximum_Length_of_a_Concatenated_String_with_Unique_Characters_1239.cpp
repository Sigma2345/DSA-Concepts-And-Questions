// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    int ans = 0 ;  
    
    void f(string s, vector<string> &arr, int i){
        
        //base case
        // any string with length > 26 must have repeated characters
        if(s.length()>26) return  ;
        if(i==arr.size() || s.length()<=26){
            int maxLength = 0, isAllowed = 1 ; 
            vector<int> freq(26) ;
            for(int i = 0 ; i<s.length() ; i++){
                freq[s[i]-'a']++ ; 
                // if any char repeat -> string invalid
                if(freq[s[i]-'a']>=2){
                    isAllowed = 0 ; 
                    break; 
                }
            }
            if(isAllowed) maxLength = s.length() ;
            ans = max(ans, maxLength); 
            return ;
        }
        
        //recursive case
        // exclude string
        f(s, arr, i+1);
        // include string
        f(s+arr[i], arr, i+1); 
    }
    
    
    int maxLength(vector<string>& arr) {
        f("", arr, 0); 
        return ans ;
    }
};
