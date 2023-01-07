// 1. O(NlogN) time and constant space solution

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0, sum = 0;
        
        for(int i = 0; i < costs.size(); i++)
        {
            if(sum+costs[i] <= coins)
            {
                sum += costs[i];
                count++;
            }
        }
        return count;
    }
};

// 2. Using frequency, the complexity could be brought down to linear?!