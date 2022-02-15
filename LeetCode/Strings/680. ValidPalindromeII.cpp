// Not the best solution :(
// O(N)? time and constant space

bool checkPalindrome(string k)
{
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

class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        
        while(start <= end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                if(checkPalindrome(s.substr(0, start) + s.substr(start + 1, s.size()-1)))
                    return true;
                else if(checkPalindrome(s.substr(0, end) + s.substr(end + 1, s.size()-1)))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};