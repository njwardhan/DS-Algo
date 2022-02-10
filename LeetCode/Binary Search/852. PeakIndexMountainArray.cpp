// 1. O(logN) time and constant space --> Variation of the standard binary search algorithm!

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        
        int middle;
        int peak_index;
        
        while(start <= end)
        {
            middle  = (start + end)/2;
            
            // Comparing with the next element
            if(arr[middle] > arr[middle + 1])
            {
                peak_index = middle;
                end = middle - 1;
            }
            
            else if(arr[middle] < arr[middle + 1])
                start = middle + 1;
            
            // Comparing with the previous element
            else if(arr[middle] > arr[middle - 1])
            {
                peak_index = middle;
                start = middle + 1;
            }
            
            else if (arr[middle] < arr[middle -1])
                end = middle - 1;
        }
        return peak_index;
    }
};

// 2. Another type of conditioning with same complexities. Smaller code here but with poor Leetcode performance!

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        
        int middle;
        
        while(start < end)
        {
            middle  = (start + end)/2;
            
            if(arr[middle] < arr[middle + 1])
                start = middle + 1;
            
            else
                end = middle;
            
        }
        return start;
    }
};