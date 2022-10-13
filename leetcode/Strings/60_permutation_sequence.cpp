//  https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<char> nums(n) ;
        for(int i = 0 ; i<n ; i++){
            nums[i] = char((i+1)+'0');      
        }

        
        vector<int> fact(n+1) ; 
        fact[0] = 1 ;
        string s = "" ;
        for(int i = 1 ; i<=n ; i++){
            fact[i] = fact[i-1]*i; 
        }

        if(k==fact[n]){
            for(char a: nums) s = a + s ; 
            return s; 
        }
        
        int  i = 1 ;
        while(i<=n){
            int x = k/(fact[n-i]) ;
            if(k%fact[n-i]==0) x-- ; 
            s = s + nums[int(x)]; 
            int y = nums[int(x)] ;
            auto new_vec = remove(nums.begin(), nums.end(), y);
            if(x!=0) k = k - fact[n-i]*x ;
            i++ ; 
        }
        
        return s ; 
    }
};
