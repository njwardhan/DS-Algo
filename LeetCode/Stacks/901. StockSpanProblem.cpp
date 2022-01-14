// Nearest greator to the left: O(N) space-time solution

class StockSpanner {
    stack<pair<int, int> > st;
    int answer = 1, c = 0;
    
public:
    StockSpanner() {}
    
    int next(int price) {
        c++;
        while(!st.empty() && price >= st.top().first)
            st.pop();
        
        if(!st.empty())
            answer = c - st.top().second;
        else
            answer = c;
        
        st.push({price, c});
        return answer;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */