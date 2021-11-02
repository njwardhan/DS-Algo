// 1. O(NlogN) time and constant space

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(NlogN) complexity
        if (nums.size() == 1)
            return nums[0];
        int z = 1, k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[i+1])
                z = 1;
            else
                z++;
            
            if (z > nums.size() / 2)
            {
                k = i;
                break;
            }
        }
        return nums[k];
    }
};

// 2. O(N) space-time

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> map;
        int answer;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
            for (auto x : map)
            {
                if(x.second > nums.size() / 2)
                    answer = x.first;
            }
        }
        return answer;
    }
};
