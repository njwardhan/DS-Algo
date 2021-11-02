// O(N) time and constant space

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int FS = 0, LS = 0, RS = 0, pi, answer = -1;
        
        for(int i = 0; i < nums.size(); i++)
            FS += nums[i];
        
        for(int j = 0; j < nums.size(); j++)
        {
            pi = j;
            if (pi == 0)
            {
                LS = 0;
                RS = FS - nums[j];
            }
            else if (pi == nums.size() - 1)
            {
                LS = FS - nums[j];
                RS = 0;
            }
            else
            {
                LS += nums[j-1];
                RS = FS - LS - nums[j];
            }
            
            if (LS == RS)
            {
                answer = pi;
                break;
            }                    
        }
        return answer;
    }
};