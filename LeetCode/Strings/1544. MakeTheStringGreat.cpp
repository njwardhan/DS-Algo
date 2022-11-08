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

// 2. O(N) time, constant space solution

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