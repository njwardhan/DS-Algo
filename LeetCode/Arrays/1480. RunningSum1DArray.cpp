// O(N) time and constant space

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> returnvc;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
          sum += nums[i];
          returnvc.push_back(sum);   
        }
        return returnvc;
    }
};