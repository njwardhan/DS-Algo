// O(NlogN + N) = O(NlogN) time and constant space
// Daily Challenge: 24th March 2022

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start = 0, end = people.size()-1, count = 0;
        
        sort(people.begin(), people.end());
        
        while(start <= end)
        {
            if(people[end] == limit)
            {
                count++;
                end--;
            }
            if(people[start] == limit)
            {
                count++;
                start++;
            }
            
            if(people[end] + people[start] <= limit)
            {
                count++;
                start++;
                end--;
            }
            else
            {
                count++;
                end--;
            }
        }
        return count;
    }
};