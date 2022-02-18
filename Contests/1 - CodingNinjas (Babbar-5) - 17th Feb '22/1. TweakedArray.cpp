// Problem Link: https://www.codingninjas.com/codestudio/contests/love-babbar-contest-5/problems/16620


// O(2n) = O(n) time and constant space solution

vector<int> tweakTheArray(vector<int> arr, int n){
    int TotalSum = 0;
    
    for(int i = 0; i < n; i++)
        TotalSum += arr[i];
    
    for(int i = 0; i < n; i++)
        arr[i] = TotalSum - arr[i];
    
	return arr;
}

