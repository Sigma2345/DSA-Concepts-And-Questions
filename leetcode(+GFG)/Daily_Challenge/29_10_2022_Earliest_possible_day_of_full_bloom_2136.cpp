// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // no use of planting on non consecutive days 
        // minimise growtime is only thing we can do 
        // so plants that have higher grow time should be planted first and 
        // fast growing plants at last
        vector< pair<int, int> > arr; 
        for(int i = 0 ; i<plantTime.size() ; i++){
            arr.push_back({growTime[i], plantTime[i]}); 
        }
        sort(arr.rbegin(), arr.rend()); 
        int curans = 0 , result = 0   ; 
        for(int i = 0 ; i<arr.size() ; i++){
            curans += arr[i].second ;
            // checking if bloom time of the plant exceeds max time required 
            result = max(result, curans +  arr[i].first); 
            
        }
        return result ; 
    }
};
