// O(N*M) time and constant space solution -- okayish LC performance. Also, first of 2023!

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int stringLength = strs[0].size();
        int count = 0;

        for(int i = 0; i < stringLength; i++)
        {
            for(int j = 0; j < strs.size()-1; j++)
            {
                if(strs[j][i] <= strs[j+1][i])
                    continue;
                else
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};