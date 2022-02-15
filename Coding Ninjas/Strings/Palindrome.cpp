// Question link: https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5

// 1. Brute Force: O(size of string) time-space solution

bool checkPalindrome(string s)
{
    string k="";
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

// 2. In this approach, no new array is created and hence the solution is constant space and O(size of string) time!

bool checkPalindrome(string s)
{
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