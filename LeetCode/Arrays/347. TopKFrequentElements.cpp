// O(NlogN) time and O(number of distinct elements in the array) space

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        vector<int> temp;
        for(auto x : m)
            temp.push_back(x.second);
        
        sort(temp.begin(), temp.end());
        
        for(int i = temp.size()-1, count = 1; count <= k; count++, i--)
        {
            int njw = temp[i];
            
            for(auto x : m)
            {
                if(x.second == njw)
                {
                    answer.push_back(x.first);
                    m.erase(x.first);
                }
            }
        }
        
        return answer;
        
    }
};