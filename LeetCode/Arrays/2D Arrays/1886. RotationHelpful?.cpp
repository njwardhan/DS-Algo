// O(rows*column) time and constant space

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int count = 1;
        int size = target.size();
        
        while(count <= 4)
        {
            for(int i = 0; i < size; i++)
                for(int j = 0; j <= i; j++)
                    swap(mat[i][j], mat[j][i]);
            
            for(int i = 0; i < size; i++)
                reverse(mat[i].begin(), mat[i].end());
            
            if(mat == target)
                return true;
            
            count++;
        }
        return false;
    }
};