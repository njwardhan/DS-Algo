// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-string/1

// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends

string Reverse(string str, int start, int end)
{
    if(start >= end)
        return str;
    
    swap(str[start], str[end]);
    start++;
    end--;
    return Reverse(str, start, end);
}

//User function Template for C++

string reverseWord(string str){
    
    return Reverse(str, 0, str.size()-1);
  
}