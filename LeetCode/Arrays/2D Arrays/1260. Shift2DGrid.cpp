// O(kN^2) = O(N^2) time and constant extra space

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int carry_element;
        int count = 0;
        
        while(count < k)
        {
            carry_element = grid[grid.size()-1][grid[0].size()-1];
            for(int i = 0; i < grid.size(); i++)
            {
                for(int j = 0; j < grid[i].size(); j++)
                {
                    int temp = grid[i][j];
                    grid[i][j] = carry_element;
                    carry_element = temp;
                }
            }
            count++;
        }
        return grid;
    }
};