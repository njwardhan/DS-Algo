// O(MN) time and O(M) space solution
// Daily Challenge: 27th March 2022

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> answer;
        map<int, int> help;
        int count = 0;
        
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 1)
                    help[i]++;
            }
            if(help[i] == 0)
                help[i] = 0;
        }
        
        int min_val = 0;
        while(1)
        {
            int val = min_val;
            for(auto x : help)
            {
                if(x.second == val and count != k)
                {
                    answer.push_back(x.first);
                    count++;
                }
            }
            if(count == k)
                break;
            min_val++;
        }
        return answer;
    }
};