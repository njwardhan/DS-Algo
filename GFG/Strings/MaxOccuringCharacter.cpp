//problem link: https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#
// O(size of the string) time and O(26) space .. multiple times space taken up as per the problem's expectations.
// Using a hash table might solve the space issue ..  

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
    
        for(int i = 0; i < str.size(); i++)
            arr[tolower(str[i]) - 'a']++;
        
        int max_position = 0;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] > arr[max_position])
                max_position = i;
        }
    
        return char(max_position + 'a');
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends