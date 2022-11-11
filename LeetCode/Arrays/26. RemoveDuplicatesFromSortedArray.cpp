// O(N) time and constant space solution --> decent LC performance

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current_index = 0;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[current_index])
                continue;
            else
                nums[++current_index] = nums[i];
        }
        return current_index+1;
    }
};