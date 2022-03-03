// O(N) time and constant space solution
// Daily Coding challenge of March 3 2022

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int subarray_count = 0;
        int i = 0;
        
        if(nums.size() == 1 or nums.size() == 2)
            return 0;
        
        while(i <= nums.size()-3)
        {
            int difference = nums[i+1] - nums[i];
            int k = i+1;
            int subarray_length = 0;
            while(k <= nums.size()-2 and nums[k+1]-nums[k] == difference)
                k++;
            
            subarray_length = k - i + 1;
            if(subarray_length >= 3)
                subarray_count += ((subarray_length-2)*(subarray_length-1))/2;
            
            i += subarray_length-1;
        }
        return subarray_count;
    }
};