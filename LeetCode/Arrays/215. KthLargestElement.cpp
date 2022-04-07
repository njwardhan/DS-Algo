// O(NlogN) time and constant space
// xDD

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size()-k];
    }
};