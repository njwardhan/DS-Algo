// Just had to apply an in-place sorting algorithm: Hence, Bubble Sort worked good enough
// O(N^2) in worst case and O(N) in the best case, O(1) space 

class Solution {
public:
    void bubbleSort(vector<int>& arr, int n)
    {   
        // Bubble Sort
        int i = 0;
        while(i < n-1)
        {
            int j = 0, key = 0;
            while(j < n-i-1)
            {
                if(arr[j+1] < arr[j])
                {
                    swap(arr[j], arr[j+1]);
                    key = 1;
                }
                j++;
            }
            if(key == 0)
                break;
            else
                i++;
        }
    }
    
    void sortColors(vector<int>& nums) {
        bubbleSort(nums, nums.size());
    }
};