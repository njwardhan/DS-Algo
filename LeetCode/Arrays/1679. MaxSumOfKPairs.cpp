// Daily Challenge: 4/5/22
// 1. Two pointer approach: O(NlogN + N) time and constant space

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int start = 0, end = nums.size()-1;
        int count = 0;
        
        sort(nums.begin(), nums.end());
        
        while(start < end)
        {
            if(nums[start] + nums[end] == k)
            {
                start++;
                end--;
                count++;
            }
            else if(nums[start] + nums[end] < k)
                start++;
            else
                end--;
        }
        return count;
    }
};

// 2. HashMap appraoch: O(N) time and space solution

class Solution {
public:    
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        map<int,int> freq;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = k - nums[i];
            if(freq[temp] > 0)
            {
                count++;
                freq[temp]--;
            }
            else
                freq[nums[i]]++;
        }
        return count;
    }
};