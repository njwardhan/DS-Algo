// Recursive solution

class Solution {
public:
    void solve(vector<vector<int>>& answer, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            answer.push_back(nums); 
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(answer, nums, index+1);
            // Backtracking
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        solve(answer, nums, 0);
        return answer;
    }
};