// 1. O(N) time but the space ramification ain't the best here

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int sub_size = part.size();
        int i = 0;
        
        while(i < s.size())
        {
            if(s[i] == part[0] && part == s.substr(i, sub_size))
            {
                s = s.substr(0, i) + s.substr(i + sub_size);
                i = 0;
                continue;
            }
            i++;
        }
        return s;
    }
};

// 2. O(N) time and constant space --> better solution! 
// Leetcode performance wise, this solution has a worse time and better space performance ..

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) < s.length())
            s.erase(s.find(part), part.length());
        return s;
    }
};