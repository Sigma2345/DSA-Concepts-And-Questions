//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // construct matrix denoting lcs
    set<string> ans ; 
    int LCS[101][101] ;
    int f(string s, string t , int i, int j){
        if(i==0 || j==0 ){
            return 0 ; 
        }
        
        if(LCS[i][j] != -1 ) return LCS[i][j]; 
        
        if(s[i-1]==t[j-1]){
            return LCS[i][j] = 1 + f(s,t,i-1,j-1); 
        }
        
        return LCS[i][j] = max(f(s,t,i-1,j), f(s,t,i,j-1)); 
    }
    
    void solve(string s, string t, int i, int j, string a, int len){
        //base case
        if( (i==0 || j==0) && len==0){
            cout<<a<<endl ;
            // ans.insert(a); 
        }

        if(i==0 || j==0) return ; 

        //recursive case
        if(s[i-1] == t[j-1]){
            solve(s,t,i-1,j-1,s[i-1]+a, len-1);
            return; 
        }
        else if(LCS[i-1][j] > LCS[i][j-1]){
            solve(s, t, i-1, j, a, len);  
            return; 
        }
        else if(LCS[i-1][j] < LCS[i][j-1]){
            solve(s, t, i, j-1, a, len);
            return ; 
        }
        solve(s, t, i-1, j, a, len);
        solve(s, t, i, j-1, a, len); 
    }
	
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    memset(LCS, -1, sizeof(LCS)); 
	   	    int x = f(s, t, s.length(), t.length());
	   	    string a = ""; 
 		    solve(s, t, s.length(), t.length(), a, x);
		    vector<string> b ;
		    for(auto x: ans){
		        b.push_back(x);
		    }
		    return b; 
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends
