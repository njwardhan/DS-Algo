// Nearest greator to the right: O(N) space-time solution. (Space because a new stack is created ..)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> answer(size,0);
        stack<int> hope;
        
        for (int i = size-1; i >= 0; i--)
        {    
            while(!hope.empty() && temperatures[i] >= temperatures[hope.top()]) 
                    hope.pop();
            
            if(!hope.empty())
                answer[i] = hope.top() - i;
            hope.push(i);
        }
        return answer;
    }
};