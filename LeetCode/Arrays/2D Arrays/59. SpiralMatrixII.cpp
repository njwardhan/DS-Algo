// O(N*N) time and space solution --> 0 ms, faster than 100% LC solutions!
// Daily challenge: 13th April 2022

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int> (n, 0));
        
        int starting_row = 0, ending_row = n-1;
        int starting_col = 0, ending_col = n-1;
        
        int k = 1;
        
        while(1)
        {
            for(int i = starting_col; i <= ending_col; i++)
                answer[starting_row][i] = k++;
            starting_row++;
            
            if(k > n*n)
                break;
            
            for(int i = starting_row; i <= ending_row; i++)
                answer[i][ending_col] = k++;
            ending_col--;
            
            if(k > n*n)
                break;
            
            for(int i = ending_col; i >= starting_col; i--)
                answer[ending_row][i] = k++;
            ending_row--;
            
            if(k > n*n)
                break;
            
            for(int i = ending_row; i >= starting_row; i--)
                answer[i][starting_col] = k++;
            starting_col++;
            
            if(k > n*n)
                break;       
        }
        return answer;
    }
};