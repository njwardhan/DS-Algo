// Problem Link: https://www.codingninjas.com/codestudio/problems/check-palindrome_920555?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13
// Solution not fully accepted - TLE for one test case ..
// But some good use case of Recursion!

bool PaliCheck(string check, int start, int end)
{
    if(start >= end)
        return true;
    
    if(check[start] == check[end])
        return PaliCheck(check, start+1, end-1);
    else
        return false;
}

string binaryRep(long long N)
{
    if(N == 1)
        return "1";
	
    int answer = N % 2;
    
    return to_string(answer) + binaryRep(N/2);
}

bool checkPalindrome(long long N)
{
	string check = binaryRep(N);
    
    return PaliCheck(check, 0, check.size()-1);
}