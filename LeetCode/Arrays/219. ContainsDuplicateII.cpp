// O(N) time-space solution

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]].empty())
                m[nums[i]].push_back(i);
            else
            {
                int temp = m[nums[i]].back();
                if(abs(temp - i) <= k)
                    return true;
                else
                    m[nums[i]].push_back(i);
            }
        }
        return false;
    }
};