// 1. Not the most efficient performance on LC.
// ~O(rows*columns) time AND SPACE!! This space thing is the issue for this solution!

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = rows;
        int count = 1;
        
        int start_row = 0, start_col = 0;
        int end_row = rows-1, end_col = columns-1;
        
        int transformations = rows / 2;
               
        while(count <= transformations)
        {
            vector<int> row1;
            vector<int> row2;
            vector<int> col1;
            vector<int> col2;
            
            //storing values
            for(int i = start_col; i <= end_col; i++)
                row1.push_back(matrix[start_row][i]);

            for(int i = end_col; i >= start_col; i--)
                row2.push_back(matrix[end_row][i]);

            for(int i = start_row; i <= end_row; i++)
                col1.push_back(matrix[i][end_col]);

            for(int i = end_row; i >= start_row; i--)
                col2.push_back(matrix[i][start_col]);

            
            // settling the first row
            for(int i = end_row; i >= start_row; i--)
            {
                matrix[i][end_col] = row1.back();
                row1.pop_back();
            }
            
            // settling the end column
            for(int i = start_col; i <= end_col; i++)
            {
                matrix[end_row][i] = col1.back();
                col1.pop_back();
            }
            
            // settling the end row
            for(int i = start_row; i <= end_row; i++)
            {
                matrix[i][start_col] = row2.back();
                row2.pop_back();
            }
            
            //settling the first column
            for(int i = end_col; i >= start_col; i--)
            {
                matrix[start_row][i] = col2.back();
                col2.pop_back();
            }
            
            // continuing for further iterations
            count++;
            start_row++;
            start_col++;
            end_row--;
            end_col--;
        }
    }
};

// 2. The solution was much simpler lol
// O(rows * column) time and constant space. Great LC performance!

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // For clockwise 90 degree rotation --> Transpose + row reversal
        // For anti-clockwise 90 degree rotation --> Transpose + column reversal
        
        // Taking transpose for the matrix
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
              swap(matrix[i][j],matrix[j][i]);
        
        // Reversing the rows to get the result
        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};