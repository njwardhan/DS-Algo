// Daily Challenge: 2nd May 2022
// 1. O(N) space and time solution

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> answer;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
                answer.push_back(nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != 0)
                answer.push_back(nums[i]);
        }
        return answer;
    }
};

// 2. O(N) space and O(1) time
// Sweet logic!

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd_start = 0, even_start = nums.size()-1;
        
        while(odd_start <= even_start)
        {
            if(nums[odd_start] % 2 != 0 and nums[even_start] % 2 == 0)
                swap(nums[odd_start++], nums[even_start--]);
            
            else if(nums[odd_start] % 2 == 0)
                odd_start++;
            
            else if(nums[even_start] % 2 != 0)
                even_start--;
        }
        return nums;
    }
};