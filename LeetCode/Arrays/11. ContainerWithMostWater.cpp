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

// Much similar to the above code only
// Daily challenge: 5th April 2022 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int max_area = INT_MIN;
        
        while(start <= end)
        {
            int temp_area = min(height[start], height[end]) * (end-start);
            
            if(temp_area >= max_area)
                max_area = temp_area;
            
            if(height[start] <= height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};