class StockSpanner {
public:
    int i = 0;
    stack<pair<int,int>> s;
    StockSpanner() {
        return;
    }
    
    int next(int price) {
        int ans = 1, bef = -1;
        while(!s.empty() && s.top().first <= price){
            s.pop();
        }
        if(!s.empty()) bef = s.top().second;
        ans = i - bef;
        s.push({price, i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */