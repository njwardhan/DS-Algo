// O(NlogN) time and O(N) space (where N is the size for each vector) - doubt!

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i = 0; i < nums1.size(); i++)
            s1.insert(nums1[i]);
        for(int j = 0; j < nums2.size(); j++)
            s2.insert(nums2[j]);
        for(auto x : s1)
        {
            if(s2.count(x))
               answer.push_back(x);
        }
        return answer;
    }
};