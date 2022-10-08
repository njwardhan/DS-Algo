// O(NlogN) time and constant space solution. Decently good LC performance

class Solution {
public:
    int distance = INT_MAX, answer;
    int threeSumClosest(vector<int>& nums, int target) {        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++)
        {
            int T = nums[i];
            int left = i+1, right = nums.size() - 1;
            while(left < right)
            {
                int temp = nums[left] + nums[right] + T;
                
                if (temp == target)
                    return temp;

                else if (temp < target)
                {
                    int closeness = abs(target - temp);
                    if (closeness < distance)
                    {
                        answer = temp;
                        distance = closeness;
                    }
                    left++;
                }
                else   
                {
                    int closeness = abs(target - temp);
                    if (closeness < distance)
                    {
                        answer = temp;
                        distance = closeness;
                    }
                    right--;
                }
            }
        }
        return answer;
    }
};