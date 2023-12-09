class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> s;
    int next(int price) {
        int ans = 1;
        while(!s.empty() && s.top().first <= price){
            ans += s.top().second;
            s.pop();
        }
        s.push({price,ans});
        return ans;
    }
};
