// Recursive Solution

class Solution {
public:
    void solve(string digits, vector<string>& answer, string s, int index, vector<string> mapping)
    {
        // base case
        if(index == digits.size())
        {
            if(s.size() != 0)
                answer.push_back(s);
            return;
        }   

        string currentshit = mapping[digits[index] - '0'];
    
        for(int i = 0; i < currentshit.size(); i++)
        {
            s += currentshit[i];
            solve(digits, answer, s, index+1, mapping);
            // backtracking
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        solve(digits, answer, s, 0, mapping);
        return answer;
    }
};