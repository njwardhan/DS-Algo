// O(N) time and constant space

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_capacity = INT_MIN, temp_capacity = 0, L = 0, R = height.size() - 1;
        
        while(L != R)
        {
            if(height[L] < height[R])
            {
                temp_capacity = height[L] * (R-L);
                L++;
            }
            else
            {
                temp_capacity = height[R] * (R-L);
                R--;
            }
            
            if(temp_capacity > max_capacity)
                max_capacity = temp_capacity;
        }
        return max_capacity;
    }
};