// Good recursive approach solution

void solve(vector<int>& nums, vector<vector<int>>& answer, vector<int> temp, int current_index)
{
    if(current_index == nums.size())
    {
        answer.push_back(temp);
        return;
    }
    
    // call for exclude
    solve(nums, answer, temp, current_index+1);
    
    // call for include
    temp.push_back(nums[current_index]);
    solve(nums, answer, temp, current_index+1);   
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        solve(nums, answer, temp, 0);
        return answer;
    }
};