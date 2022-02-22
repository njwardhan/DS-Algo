// ~O(N)? time and constant space

int gcd(int a , int b)
{    
    while(a != b)
    {
        if(a > b)
            a = a-b;
        else
            b = b-a;
    }
    return b;
}

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max)
                max = nums[i];
            if(nums[i] < min)
                min = nums[i];
        }
        
        // Using the Euclid's method to find the GCD
        // GCD(max, min) = GCD(max-min, min) or GCD(max, min) = GCD(max % min, min)

        // ALSO, LCM(a,b) * GCD(a,b) = a * b
        
        int k = gcd(max, min);
        return k;
        
    }
};