// Couldn't solve in time :(
// 1. O(N) space and time in worst case --> poor LC performance though

class Solution {
public:
    int answer = INT_MAX;
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> last_occ;
        
        for(int i = 0; i < cards.size(); i++)
        {
            if(!last_occ[cards[i]])
                last_occ[cards[i]] = i+1;
            
            else
            {
                int temp = i - last_occ[cards[i]] + 2;
                last_occ[cards[i]] = i+1;
                if(temp <= answer)
                    answer = temp;
            }
        }
        if(answer == INT_MAX)
            return -1;
        
        return answer;
    }
};

// 2. A different hashmap approach, but similar LC performance
// O(N) space and time again

class Solution {
public:
    int answer = INT_MAX;
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> m;
        
        for(int i = 0; i < cards.size(); i++)
        {
            if(m.find(cards[i]) != m.end())
                answer = min(answer, i-m[cards[i]]+1);
            
            m[cards[i]] = i;
        }
        if(answer == INT_MAX)
            return -1;
        
        return answer;
    }
};