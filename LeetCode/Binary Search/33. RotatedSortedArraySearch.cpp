// O(2logN) = O(logN) time and constant space solution
// Here the key is to find the pivot index and understanding the intricacies behind the conditioning. After that things get simplified!
// The question has two more approaches btw .. (for the same complexities)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, middle, pivot_index;
        
        while(start < end)
        {   
            middle = (start + end)/2;
            
            if(nums[middle] >= nums[0])
                start = middle + 1;
            else
                end = middle;
        }
        
        pivot_index = start;
        
        if(target >= nums[pivot_index] && target <= nums[nums.size()-1])
        {
            start = pivot_index;
            end = nums.size()-1;
        }
        else
        {
            start = 0;
            end = pivot_index - 1;
        }
        
        while(start <= end)
        {
            middle = (start + end)/2;
            
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] > target)
                end = middle - 1;
            else
                start = middle + 1;
        }
        
        return -1;
    }
};