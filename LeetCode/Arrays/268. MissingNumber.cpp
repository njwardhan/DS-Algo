// Daily Challenge: 28th May 2022
// 1. O(N) space and O(NlogN) time approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> compare;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            compare.push_back(i);
        
        sort(nums.begin(), nums.end());
        
        int i;
        for(i = 0; i < n; i++)
        {
            if(compare[i] == nums[i])
                continue;
            else
                break;
        }
        return i;
    }
};

// 2. No need of the compare array lol --> O(NlogN) time and constant space

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i;
        
        for(i = 0; i < n; i++)
        {
            if(i == nums[i])
                continue;
            else
                break;
        }
        return i;
    }
};