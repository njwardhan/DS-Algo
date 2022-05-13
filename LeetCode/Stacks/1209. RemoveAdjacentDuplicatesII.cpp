// Daily Challenge: 6th May 2022
// O(N) time and space solution, N = size of the string

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> help;
        
        for(int i = 0; i < s.size(); i++)
        {            
            if(!help.empty() and help.top().first == s[i])
            {
                ++help.top().second;
                if(help.top().second == k)
                    help.pop();
            }
            else
                help.push({s[i], 1});
        }
        
        string answer;
        while(!help.empty())
        {
            for(int i = 1; i <= help.top().second; i++)
                answer.push_back(help.top().first);
            help.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};