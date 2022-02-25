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

// Recursive Code for Selection Sort

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void SelectionSort(int arr[], int size)
{
    if(size == 0 || size == 1)
        return;

    int min = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < arr[min])
            min = i;
    }
    swap(arr[0], arr[min]);
    SelectionSort(arr+1, size-1);
}

int main() 
{
    int arr[13] = {-1,541,3,-124221,11214, 12, 43, 122141, 125, -124, 0, 199, 7};

    SelectionSort(arr,13);

    for(int i = 0; i < 13; i++)
        cout<<arr[i]<<" ";
    return 0;
}
