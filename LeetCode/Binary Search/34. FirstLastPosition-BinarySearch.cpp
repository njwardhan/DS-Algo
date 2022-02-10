// O(2logN) = O(logN) time and constant space solution
// This question can also be modified as, find the number of occurrence of the target. That would be nothing but,
// number = (last index - first index) + 1

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        int middle, first = -1, last = -1;
        vector<int> answer{0, 0};
        
        // Checking for the first occurrence
        while(start <= end)
        {
            middle = (start + end)/2;
            
            if(target == nums[middle])
            {
                first = middle;
                end = middle - 1;
            }
    
            else if(target > nums[middle])
                start = middle + 1;
            
            else
                end = middle - 1;
        }
        answer[0] = first;
        
        start = 0, end = nums.size() - 1;

        // Checking for the last occurrence
        while(start <= end)
        {
            middle = (start + end)/2;
            
            if(target == nums[middle])
            {
                last = middle;
                start = middle + 1;
            }
    
            else if(target > nums[middle])
                start = middle + 1;
            
            else
                end = middle - 1;
        }
        answer[1] = last;
        
        return answer;
    }
};