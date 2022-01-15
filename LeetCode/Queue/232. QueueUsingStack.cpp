// Solution strictly using only two stacks: O(1) time for push and empty whereas O(N) for pop and peek operations.

class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int N;
    
public:
    MyQueue() {
        N = 0;
    }
    
    void push(int x) {
        s1.push(x);
        N++;
    }
    
    int pop() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int d = s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        N--;
        return d;
    }
    
    int peek() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int d = s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return d;
    }
    
    bool empty() {
        if( N == 0 )
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

