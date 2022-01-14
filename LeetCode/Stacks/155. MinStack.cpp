// O(1) space-time solution

class MinStack {
    stack<int> st;
    stack<int> minst;
    
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minst.size() == 0 or minst.top() >= val)
            minst.push(val);
    }
    
    void pop() {
        if(minst.top() == st.top())
            minst.pop();
        if(st.empty())
            return ;
        
        st.pop();
    }
    
    int top() {
        if(st.empty()) 
            return -1;
        
        return st.top();
    }
    
    int getMin() {
        if(minst.empty()) 
            return -1;
        
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */