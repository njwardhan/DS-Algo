// O(N) time and constant space

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, max_profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy && i != prices.size()-1)
                buy = prices[i];
            else if (prices[i] - buy > max_profit)
                max_profit = prices[i] - buy;
        }
        return max_profit;
    }
};