// 1. O(N) time in worst case? --> lol solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// 2. O(N^2 + NlogN) = O(N^2) time in the worst case (when the array is sorted in decreasing order), O(NlogN) .. for sorting?

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ptr = nums.size()-2;
        if(ptr == -1)
            return;
        
        bool hope = false;
        int next_greator = INT_MAX;
        int next_greator_index = -1;
        
        while(ptr != -1)
        {
            int k = ptr+1;
            while(k <= nums.size()-1)
            {
                if(nums[k] > nums[ptr] and nums[k] < next_greator)
                {
                    next_greator = nums[k];
                    next_greator_index = k;
                }
                
                k++;
            }
            if(next_greator != INT_MAX)
            {
                swap(nums[next_greator_index], nums[ptr]);
                sort(nums.begin() + ptr + 1, nums.end());
                hope = true;
                break;
            }
            ptr--;
        }
        if(!hope)
            sort(nums.begin(), nums.end());
    }
};

// 3. O(N) time and constant space solution (ignoring the special functions used)
// LC performance same as that of the 2. Mostly because the range of input is not that large .. 
// Not very convinced with this solution either

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        for(int i = n-1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i;
                break;
            }
        }
        if(index == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            int njw = index;
            for(int i = index+1; i < n; i++)
            {
                if(nums[i] > nums[index-1] and nums[i] <= nums[njw])
                    njw = i;
            }
            swap(nums[index-1], nums[njw]);
            reverse(nums.begin()+index, nums.end());
        }
    }
};