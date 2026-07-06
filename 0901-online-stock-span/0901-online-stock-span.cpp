class StockSpanner {
public:
   vector<int>ans;
   stack<int>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int i = ans.size()-1;
           while (!s.empty() && ans[s.top()] <= price) {
            s.pop();
        }

        int span;
        if (s.empty())
            span = i + 1;
        else
            span = i - s.top();

        s.push(i);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */