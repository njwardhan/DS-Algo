// Daily Challenge: 28th April 2022
// Need to revisit the question ..
// O(N * M * log(maximum height value)) time approach .. where N, M = number of rows and columns in the heights vector ..  

class Solution {
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
public:
    void Solve(vector<vector<int>>& heights, vector<vector<int>>& visited, int threshold, int row, int col, int n, int m)
    {   
        if(!visited[row][col])
        {
            visited[row][col] = 1;
            
            for(int i = 0; i < 4; i++)
            {
                int new_row = row + dir[i].first;
                int new_col = col + dir[i].second;
                
                if(new_row < n and new_row >= 0 and new_col < m and new_col >= 0 and abs(heights[new_row][new_col] - heights[row][col]) <= threshold)
                    Solve(heights, visited, threshold, new_row, new_col, n, m);
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int min_effort = 0, max_effort = 1000000;
        int n = heights.size();
        int m = heights[0].size();
        
        while(min_effort < max_effort)
        {
            int mid = min_effort + (max_effort - min_effort) / 2;
            vector<vector<int>> visited(n, vector<int> (m, 0));
            
            Solve(heights, visited, mid, 0, 0, n, m);
            
            if(visited[n-1][m-1] == 1)
                max_effort = mid;
            else
                min_effort = mid + 1;
        }
        return min_effort;
    }
};