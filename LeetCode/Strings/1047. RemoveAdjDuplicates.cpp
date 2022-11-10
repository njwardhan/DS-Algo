// 1. ~O(N) time and constant space. Not the best LC solution though.. 

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0; 
            
        while(i < s.size())
        {
            if(s[i] == s[i+1])
            {
                s.erase(i, 2);
                if(i != 0)
                    i--;
                else
                    i=0;
            }
            else
                i++;
        }
        return s;
    }
};

// 2. O(N) time but O(N) space as well. Decent LC performance ..

class Solution {
public:
    string removeDuplicates(string s) {
        
        string result = "";
        
        for(char c : s)
        {
            if(result.length() && result.back() == c)
                result.pop_back();
            else
                result.push_back(c);  
        }
        return result;
    }
};

// 3. Stack approach - O(N) space time solution with decent LC performance

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        int i = 0;
        
        while(i < s.length())
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
            
            i++;
        }
        
        string answer = "";
        while(!st.empty())
        {
            char temp = st.top();
            st.pop();
            answer += temp;
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};