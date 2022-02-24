// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-array-elements2502/1#
// Recursive Solution

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Complete this function

int sumElement(int arr[],int n)
{
    if(n == 0)
		return 0;
	if(n == 1)
        return arr[0];
        
    return arr[0] + sumElement(arr+1, n-1);
}




// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<sumElement(arr,n)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends