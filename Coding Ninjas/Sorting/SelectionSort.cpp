// O(N^2) time and constant space solution
// Since it is quadratic time, didn't work on a large LC test case --> TLE xD :/

void selectionSort(vector<int>& arr, int n)
{   
    int i = 0;
        
    while(i < n-1)
    {
        int minimum_pos = i;
        // Find the minimum element for that position
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minimum_pos])
                minimum_pos = j;
        }
        // Swap the ith element with the correct minimum in place
        int temp = arr[i];   
        arr[i] = arr[minimum_pos];
        arr[minimum_pos] = temp;
            
        i++;
    }
}