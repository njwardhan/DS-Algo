// O(m*n) time and O(r*c) space solution

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> answer;
        
        if (rows * columns == r * c)
        {
            // valid shit
            // take out row wise elements and then go on placing it in the new vector
            
            vector<int> temp;
            for(int i = 0; i < mat.size(); i++)
            {
                for(int j = 0; j < mat[0].size(); j++)
                {
                    temp.push_back(mat[i][j]);
        
                    if(temp.size()==c)
                    {
                        answer.push_back(temp);
                        temp.clear();
                    }
                }
            }
            return answer;
        }
        else
            return mat;
    }
};