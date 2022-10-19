// O(NlogN + k) time and O(N) space (where N = number of distinct words in the initial vector) --> Decent LC performance
// New thing learnt: We can custom sort, even if it is a vector or pairs!
// One such reference: https://stackoverflow.com/questions/31197681/c-sort-custom-function

class Solution {
public:
    static bool comp(pair<int,string>& a, pair<int,string>& b)
    {
        if(a.first != b.first)
            return a.first > b.first;
        else 
            return a.second < b.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<pair<int, string>> temp;
        vector<string> answer;
        
        for(int i = 0; i < words.size(); i++)
            m[words[i]]++;
        
        for(auto x : m)
            temp.push_back({x.second, x.first});
        
        sort(temp.begin(), temp.end(), comp);
        
        int i = 0;
        while(k--)
        {
            answer.push_back(temp[i].second);
            i++;
        }
        
        return answer;
    }
};