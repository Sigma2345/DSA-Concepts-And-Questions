// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    vector<pair<int,int>>prices ; 
    StockSpanner() {
        
    }    
    int next(int price) {
        // prices.push_back(price);
        int x = prices.size()-1; 
        int cnt = 1 ; 
        for(int i = x ; i>=0 ; i--){
            if(prices[i].first <= price ) {
                cnt+=prices[i].second ;
                prices.pop_back();}
            else break ; 
        }
        prices.push_back({price,cnt});
        return cnt ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
