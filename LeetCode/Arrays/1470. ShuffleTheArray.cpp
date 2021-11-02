// 1.a O(N) space-time 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        int a = 0, b = n;
        for(int i = 0; i < nums.size(); i++)
        {
            if(a <= n-1)
            {
                answer.push_back(nums[a]);
                a++;
            }
            if(b <= nums.size()-1)
            {
                answer.push_back(nums[b]);
                b++;
            }
        }
        return answer;
    }
};

// 1.b O(N) space-time

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        for(int i = 0; i < nums.size() / 2; i++)
        {
            answer.push_back(nums[i]);
            answer.push_back(nums[i + n]);
        }
        return answer;
    }
};