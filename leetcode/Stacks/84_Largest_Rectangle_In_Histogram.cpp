// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ; 
        vector<int> l(n,0);
        vector<int> r(n,0);
        l[0] = 0 , r[n-1] = n-1 ;
        stack<int>s; 
        s.push(0); 
        for(int i = 1 ; i<n ; i++ ){
            // getting first index from left for ith element where height of that wall 
            // is less than height of current wall
            while(!s.empty() && heights[i] <= heights[s.top()] ) s.pop() ;
            // means no entry till corner is less in height
            if(s.empty()){
                l[i] = 0 ; 
            }
            // boundary of ith element wall ends at that index so subtract 1
            else l[i] = s.top()+1 ;
            s.push(i) ;
        }
        while(!s.empty()) s.pop(); 
        s.push(n-1); 
        for(int i = n-2 ; i>=0 ; i--){
            while(!s.empty() && heights[i] <= heights[s.top()] ) s.pop() ;
            if(s.empty()){
                r[i] = n-1 ; 
            }
            // boundary of ith element wall ends at that index so subtract 1
            else r[i] = s.top()-1 ;
            s.push(i) ;
        }
        int maxArea = 0 ; 
        for(int i = 0 ; i<n ; i++){
            // cout<<heights[i]<<' '<<l[i]<<' '<<r[i]<<endl ;
            maxArea = max(maxArea, heights[i]*(r[i]-l[i]+1)); 
        }
        return maxArea ; 
    }
};
