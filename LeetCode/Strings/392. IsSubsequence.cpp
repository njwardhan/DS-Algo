// O(size of t + size of s) time ramificaion
// Daily Coding challenge of March 2 2022

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, check = 0;
        
        while(i < t.size() and check < s.size())
        {
            if(t[i] == s[check])
            {
                check++;
                i++;
            }
            else
                i++;
        }
        if(check == s.size())
            return true;
        else
            return false;
    }
};