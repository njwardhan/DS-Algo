// O(N) time and constant space. The answer vector has 1-incremented values as the questions poses an unconventional 1-indexed array

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left != right)
        {
            int current_sum = numbers[left] + numbers[right]; 
            if (current_sum == target)
                break;
            else if (current_sum < target)
                left++;
            else
                right--;
        }
        vector<int> answer = {left + 1, right + 1}; 
        return answer;
    }
};