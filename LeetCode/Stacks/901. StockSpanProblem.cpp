// Nearest greator to the left: O(N) space-time solution
// This below approach is basically using a stack and storing the relevant positions for further calculations.

// One other approach could be to just use a simple array to go on storing answer values per price. That will ensure the inclusion of all the
// lesser previous values, so for the current value, we can use the value of the last greator and so on .. --> DP approach

// Both solutions will work in O(N) time and space

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