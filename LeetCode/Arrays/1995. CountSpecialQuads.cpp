// 1. O(N^4) time and constant space, lol

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int N = nums.size();
        int count = 0;
        for(int i = 0; i < N-3; i++)
        {
            int temp1 = nums[i];
            for(int j = i+1; j < N-2; j++)
            {
                int temp2 = temp1 + nums[j];
                for(int k = j+1; k < N-1; k++)
                {
                    int temp3 = temp2 + nums[k];
                    for(int l = k+1; l < N; l++)
                    {
                        if(nums[l] == temp3)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};

// 2. O(N^2) time and O(N) space solution
// Good approach! .. 

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        map<int,int> m;
        int count = 0;
        
        for(int i = 1; i < nums.size()-1; i++)
        {
            for(int j = 0; j < i ; j++)
                m[nums[i] + nums[j]]++;
            
            for(int k = i+1; k < nums.size(); k++)
                count += m[nums[k] - nums[i+1]];
        }   
        return count;
    }
};