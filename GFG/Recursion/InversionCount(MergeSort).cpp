// Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int Merge(long long arr[], long long start, long long middle, long long end)
{
    long long int count = 0;
    
    long long size1 = middle-start+1;
    long long size2 = end-middle;
    
    long long left[size1];
    long long right[size2];
    
    long long mainIndex = start;
    for(long long i = 0; i < size1; i++)
        left[i] = arr[mainIndex++];
    
    for(long long i = 0; i < size2; i++)
        right[i] = arr[mainIndex++];
        
    mainIndex = start;
    long long index1 = 0, index2 = 0;
    while(index1 < size1 && index2 < size2)
    {
        if(left[index1] <= right[index2])
            arr[mainIndex++] = left[index1++];
        
        else
        {
            arr[mainIndex++] = right[index2++];
            count += size1-index1;
        }
    }
    while(index1 < size1)
        arr[mainIndex++] = left[index1++];
        
    while(index2 < size2)
        arr[mainIndex++] = right[index2++];
        
    return count;
}

long long int MergeSort(long long arr[], long long start, long long end)
{
    if(start >= end)
        return 0;
    
    long long int count = 0;
    long long middle = (start+end)/2;
    
    count += MergeSort(arr, start, middle);
    count += MergeSort(arr, middle+1, end);
    count += Merge(arr, start, middle, end);
    
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    return MergeSort(arr, 0 , N-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends