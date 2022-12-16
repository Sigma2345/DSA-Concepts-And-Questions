// https://leetcode.com/problems/my-calendar-iii/

// everytime book is called we sort the entire array 
// cnt max number of events at  any instance

class MyCalendarThree {
public:
    vector < pair<int, int> > v ;
    MyCalendarThree(){
    }
    
    int book(int start, int end) {
        v.push_back({start,0});
        v.push_back({end,-1}); 
        sort(v.begin(), v.end()) ;
        int rpref = 0 ; 
        int ans =0; 
        for(int i = 0 ; i<v.size() ; i++){
            if(v[i].second==0){
                rpref++ ; 
            }
            else{
                rpref-- ; 
            }
            ans = max(ans, rpref); 
        }
        return ans ;
    }
};
