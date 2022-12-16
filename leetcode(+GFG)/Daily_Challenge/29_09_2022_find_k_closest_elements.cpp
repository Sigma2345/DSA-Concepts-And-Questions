// https://leetcode.com/problems/find-k-closest-elements/

/*
 ->for minheap we just push the negative of all nums 
 in maxheap . 
 ->we push the -(distance b/w number and x) , -number
 -> -ve of number is pushed so as to prefer -1,1 over -1,5 when pushed in heap  
 -> take out the first k elements in ans vector and sort them
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue < pair<int,int> > pq;
        for(int i = 0 ; i<arr.size() ; i++){
            pq.push({-1*abs(arr[i]-x),-arr[i]});
        }
        vector<int> ans ; 
        for(int i = 0 ; i<k ; i++){
            auto x = pq.top() ; 
            ans.push_back(-x.second);
            pq.pop() ;
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};
