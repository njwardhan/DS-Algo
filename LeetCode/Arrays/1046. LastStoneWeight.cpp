// O(N^3*logN) time and constant space?!!
// Daily challenge: 7th April 2022

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];
        
        while(1)
        {
            sort(stones.begin(), stones.end());
            
            if(stones[stones.size()-1] == stones[stones.size()-2])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                int temp = stones[stones.size()-1] - stones[stones.size()-2];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(temp);
            }
            
            if(stones.size() == 1)
                return stones[0];
            if(stones.size() == 0)
                return 0;
        }
    }
};