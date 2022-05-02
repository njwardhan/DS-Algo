// Daily Challenge: 1st May 2022
// 1. O(s.size + t.size) time and space solution, or simply put, O(N) time and space --> not the best LC performacne

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#' and !a.empty())
                a.pop_back();
            
            else if(s[i] == '#' and a.empty())
                continue;
            
            else
                a.push_back(s[i]);
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == '#' and !b.empty())
                b.pop_back();
            
            else if(t[i] == '#' and b.empty())
                continue;
            
            else
                b.push_back(t[i]);
        }
        if(a == b)
            return true;
        
        return false;
    }
};

// 2. O(N) time and constant space solution --> faster than 100% LC!
// Indexing had to be taken care of!

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0, j = 0;
        
        while(i < s.size())
        {
            if(s[i] == '#' and i == 0)
                s.erase(i, 1);
            
            else if(s[i] == '#' and i != 0)
            {
                s.erase(i-1, 2);
                i--;
            }
            else
                i++;
        }

        while(j < t.size())
        {
            if(t[j] == '#' and j == 0)
                t.erase(j, 1);
            
            else if(t[j] == '#' and j != 0)
            {
                t.erase(j-1, 2);
                j--;
            }
            else
                j++;
        }
        return s == t;
    }
};

