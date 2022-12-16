class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length() , lastIndex[26] = {0} ;
        for(int i = 0 ; i<n ; i++) lastIndex[s[i]-'a'] = i ;
        
        stack<char> st ; 
        int freq[26] = {0} ; 
        // keeps count of char in stack
        for(int i = 0 ; i<n ; i++){
            // if already in stack skip the element
            if(freq[s[i]-'a']) continue ;
            
            // while bigger element found which is also found at index greater than i , keep popping it from stack
            while(!st.empty() && st.top() > s[i] &&  lastIndex[st.top()-'a'] > i ){
                freq[st.top()-'a']-- ; 
                st.pop() ;
            }
            
            st.push(s[i]) ;
            freq[s[i]-'a']++ ;
        }
        string ans = "" ;
        while(!st.empty()){
            // making reverse string 
            ans = st.top() + ans ; 
            st.pop() ;
        }
        return ans; 
    }
};
