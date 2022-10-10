// 1. O(N^2) time and constant space solution
// Got all the hints spot on, and despite non-optimised approach, runtime 0 ms (faster than 100% xD)

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
    string breakPalindrome(string palindrome) {
        for(int i = 0; i < palindrome.size(); i++)
        {
            if(palindrome[i] == 'a' and i != palindrome.size()-1)
                continue;
            else if(palindrome[i] == 'a' and i == palindrome.size()-1)
            {
                char temp1 = palindrome[i];
                palindrome[i] = 'b';
                if(!checkPalindrome(palindrome))
                    return palindrome;
                else
                    palindrome[i] = temp1;
            }
            else
            {
                char temp2 = palindrome[i];
                palindrome[i] = 'a';
                if(!checkPalindrome(palindrome))
                    return palindrome;
                else
                    palindrome[i] = temp2;
            }
        }
        return "";
    }
};

// 2. O(N) time and constant space. Despite optimised, still only faster than 45% ?

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size();
        if(N == 1)
            return  "";
        
        for(int i = 0; i < N/2; i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[N-1] = 'b';
        return palindrome;
    }
};