// O(rows + log(coloumns)) time and constant space solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int speculated_row = 0;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] > target)
            {
                speculated_row = i-1;
                break;
            }
            else if(matrix[i][0] == target)
                return true;
            else
                speculated_row = matrix.size()-1;
        }
        
        if(speculated_row == -1)
            return false;
        
        int start = 0, end = matrix[0].size()-1, middle;
        while(start <= end)
        {
            middle = start + (end-start)/2;
            
            if(matrix[speculated_row][middle] == target)
                return true;
            else if(matrix[speculated_row][middle] > target)
                end = middle - 1;
            else
                start = middle + 1;
        }
        return false;
    }
};