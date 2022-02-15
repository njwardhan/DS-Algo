// 1. Brute Force Approach: O(2 * size of string) = O(size of string) time and O(size of string) space
// The extra used up space is the issue here!

class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
                k += tolower(s[i]);
        }
        
        int start = 0, end = k.size()-1;
        while(start <= end)
        {
            if(k[start++] == k[end--])
                continue;
            else
                return false;
        }
        return true;
    }
};

// 2. Optimized solution performing faster than 100% LC solutions xD
// O(size of string) time and constant space!

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        
        while(start <= end)
        {
            if(!isalpha(s[start]) && !isdigit(s[start]))
            {
                start++;
                continue;
            }
            if(!isalpha(s[end]) && !isdigit(s[end]))
            {
                end--;
                continue;
            }
            
            if(tolower(s[start++]) == tolower(s[end--]))
                continue;
            else
                return false;
        }
        return true;
    }
};