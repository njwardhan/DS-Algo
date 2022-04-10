// 1. Using extra data structure: O(N) time and space, N = size of the input array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
            k %= nums.size();
        
        if(k == 0 or k == nums.size())
            return;
        
        vector<int> answer;
        int count = 0;
        while(count < k)
        {
            answer.push_back(nums.back());
            nums.pop_back();
            count++;
        }
        
        reverse(answer.begin(), answer.end());
        
        int i = 0;
        while(i < nums.size())
            answer.push_back(nums[i++]);
        
        nums = answer;
    }
};

// 2. Using the STL reverse functionality: O(N) time and O(1) space!

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
            k %= nums.size();
        
        if(k == 0 or k == nums.size())
            return;
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// 3. In-place swapping approach ..