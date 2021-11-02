// 1. Brute force approach with time complexity of O(N*N) and a constant space complexity

class Solution {
public:
    int E1, E2;
    vector<int> returnvc;
    vector<int> twoSum(vector<int>& nums, int target) {    
        for (int i = 0; i < nums.size(); i++)
        {
            E1 = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                E2 = nums[j];
                if (E1 + E2 == target) {
                    returnvc = {i, j};
                }
            }
        }
        return returnvc;
    }
};

// 2. Hash table approach with a space-time complexity of O(N). The key here was to do the checking while populating the hash table, and not after!

class Solution {
public:
    vector<int> returnvc;
    vector<int> twoSum(vector<int>& nums, int target) {    
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map [i] = nums[i];
            for (auto x : map)
            {
                if (x.first != i && x.second == target - nums[i])
                    returnvc = {i, x.first};
            }
        }
        return returnvc;    
    }
        
};

// 3. Sort the array and then use two pointers (conceptually, not literally xD) to get a O(NlogN) time complexity and O(1) space complexity.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end()); // O(NlogN) complexity
        int left = 0, right = nums_copy.size() - 1;

        while (left != right)
        {
            int current_sum = nums_copy[left] + nums_copy[right]; 
            if (current_sum == target)
                break;
            else if (current_sum < target)
                left++;
            else
                right--;

        }
        int index1 = 0, index2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums_copy[left])
                index1 = i;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums_copy[right] && j != index1)
                index2 = j;
        }
        return {index1, index2};
    }   
};
