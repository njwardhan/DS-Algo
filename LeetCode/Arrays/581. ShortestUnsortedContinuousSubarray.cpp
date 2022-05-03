// Daily Challenge: 3rd May 2022
// O(N) time and space approach
// Just checking the order of two elements a time from either sides wouldn't work as cases like: [1,3,2,2,2] would break
// Hence a sorted copy of the original array was required.


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {        
        int start = 0, end = nums.size()-1;
        int answer = 0;
        
        vector<int> check = nums;
        sort(nums.begin(), nums.end());
        
        while(start < nums.size() and nums[start] == check[start])
            start++;
        
        while(end > start and nums[end] == check[end])
            end--;
        
        return end-start+1;
    }
};