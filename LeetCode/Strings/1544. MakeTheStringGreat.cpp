// ** Actually a stack question lol

// 1. O(N^2) time, constant space solution

class Solution {
public:
    string makeGood(string s) {
        int k, i = 0;
        while(i < s.size()-1 and !s.empty())
        {
            if(tolower(s[i]) == tolower(s[i+1]) and int(s[i]) != int(s[i+1]))
            {
                s.erase(i, 2);
                k++;
                i = 0;
            }
            else
                i++;
        }
        return s;
    }
};

// 2. With constant space, this is still in O(N^2) time because the erase() function runs in O(N) time, so N*N .. 

class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while(i < s.size()-1 and !s.empty())
        {
            if(tolower(s[i]) == tolower(s[i+1]) and int(s[i]) != int(s[i+1]))
            {
                s.erase(i, 2);
                if(i != 0)
                    i--;
            }
            else
                i++;
        }
        return s;
    }
};

// 3. This is finally in O(N) time and space

class Solution {
public:
    string makeGood(string s) {
        stack<int> q;
        int i = 0;
        
        while(i < s.size())
        {
            if(q.empty())
                q.push(s[i]);
            else if(tolower(q.top()) == tolower(s[i]) and int(q.top()) != int(s[i]))
                q.pop();
            else
                q.push(s[i]);
            
            i++;
        }
        
        string answer = "";
        while(!q.empty())
        {
            char temp = q.top();
            q.pop();
            answer += temp;
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};