// O(N) time and O(1) space solution

class Solution {
public:
    int kthFactor(int n, int k) {
        int factor_count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                factor_count++;
                if (factor_count == k)
                    return i;
            }
        }
        return -1;
    }
};