// O(N) time and constant space solution
// Wasn't able to solve cleanly, took a long time

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, s = INT_MAX, N = nums.size();
        
        if(N < 3)
            return false;
        
        for(int i = 0; i < N; i++)
        {
            int temp = nums[i];
            if(temp <= f)
                f = temp;
            else if(temp <= s)
                s = temp;
            else
                return true;
        }
        return false;
    }
};