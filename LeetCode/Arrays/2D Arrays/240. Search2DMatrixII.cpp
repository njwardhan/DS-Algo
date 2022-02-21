class Solution {
// 1. O(columns + log(rows)) time and constant space solution
// Not the best LC performance though

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int potential_column = -1;
            
        for(int i = 0; i < matrix[0].size(); i++)
        {
            if(target > matrix[matrix.size()-1][i])
                continue;
            else if(target == matrix[matrix.size()-1][i])
                return true;
            else if(target < matrix[matrix.size()-1][i])
            {
                potential_column = i;
                break;
            }
            else
                return false;
        }
        
        while(potential_column <= matrix[0].size()-1)
        {
            int start = 0, end = matrix.size()-1, middle;
            
            while(start <= end)
            {
                middle = start + (end-start)/2;
                
                if(matrix[middle][potential_column] == target)
                    return true;
                else if(matrix[middle][potential_column] < target)
                    start = middle + 1;
                else
                    end = middle - 1;
            }
            potential_column++;
        }
        return false;
    }
};

// 2. O(log(rows*columns))? time and constant space. Not the typical binary search here .. 
// Much better approach and much better LC performance!

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int search_row = 0, search_col = columns-1;
        
        while(search_row < rows && search_col >= 0)
        {
            int element = matrix[search_row][search_col];

            if(element == target)
                return true;
            else if(element < target)
                search_row++;
            else
                search_col--;
        }
        return false;
    }
};