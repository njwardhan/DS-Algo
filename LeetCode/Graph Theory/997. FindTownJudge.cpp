// Simple indegree, outdegree question, messed up in LC submissions :/
// O(N) space and time approach, N = size of the trust array

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> inD;
        map<int,int> outD;
        
        if(trust.size() == 0 and n == 1)
            return 1;
        
        for(int i = 0; i < trust.size(); i++)
        {
            outD[trust[i][0]]++;
            inD[trust[i][1]]++;
        }
        
        for(auto it : inD)
        {
            if(it.second == n-1 and outD[it.first] == 0)
                return it.first;
        }
        return -1;
    }
};