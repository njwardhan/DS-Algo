// Test case: https://leetcode.com/submissions/detail/643733392/testcase/ failed earlier due to O(N^2) solutions .. obviously!
// Merge Sort: O(NlogN) time and O(N) space solution

void Merge(vector<int>& arr, int start, int middle, int end)
{
    int size1 = middle-start+1;
    int size2 = end-middle;
    
    int *left = new int[size1];
    int *right = new int[size2];
    
    int mainIndex = start;
    for(int i = 0; i < size1; i++)
        left[i] = arr[mainIndex++];
    
    for(int i = 0; i < size2; i++)
        right[i] = arr[mainIndex++];
    
    mainIndex = start;
    int index1 = 0, index2 = 0;
    
    while(index1 < size1 and index2 < size2)
    {
        if(left[index1] <= right[index2])
            arr[mainIndex++] = left[index1++];
        else
            arr[mainIndex++] = right[index2++];
    }
    
    while(index1 < size1)
        arr[mainIndex++] = left[index1++];
    
    while(index2 < size2)
        arr[mainIndex++] = right[index2++];
}

void MergeSort(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;
    
    int middle = (start+end)/2;
    
    MergeSort(arr, start, middle);
    MergeSort(arr, middle+1, end);
    Merge(arr, start, middle, end);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};