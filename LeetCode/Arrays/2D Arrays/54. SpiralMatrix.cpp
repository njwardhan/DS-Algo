// O(n * m) time and constant space solution. Good leetcode performance!

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int starting_row = 0, ending_row = rows-1;
        int starting_col = 0, ending_col = columns-1;
        
        while(answer.size() < rows*columns)
        {
            // print the start row
            for(int i = starting_col; i <= ending_col; i++)
                answer.push_back(matrix[starting_row][i]);
            starting_row++;
            
            if(answer.size() == rows*columns)
                break;
            
            // print the end column
            for(int i = starting_row; i <= ending_row; i++)
                answer.push_back(matrix[i][ending_col]);
            ending_col--;
            
            if(answer.size() == rows*columns)
                break;
            
            // print the end row
            for(int i = ending_col; i >= starting_col; i--)
                answer.push_back(matrix[ending_row][i]);
            ending_row--;
            
            if(answer.size() == rows*columns)
                break;
            
            // print the start column
            for(int i = ending_row; i >= starting_row; i--)
                answer.push_back(matrix[i][starting_col]);
            starting_col++;
            
            if(answer.size() == rows*columns)
                break;
        }
        return answer;
    }
};