// O(m*n) time and space approach
// Daily challenge: 12th April 2022

class Solution {
public:
    void findNeighbours(vector<vector<int>>& board, int i, int j, vector<int>& neighbours)
    {
        if(i != 0)
            neighbours.push_back(board[i-1][j]);
        if(i != board.size()-1)
            neighbours.push_back(board[i+1][j]);
        if(j != 0)
            neighbours.push_back(board[i][j-1]);
        if(j != board[i].size()-1)
            neighbours.push_back(board[i][j+1]);
        if(i != 0 and j != 0)
            neighbours.push_back(board[i-1][j-1]);
        if(i != 0 and j != board[i].size()-1)
            neighbours.push_back(board[i-1][j+1]);
        if(i != board.size()-1 and j != 0)
            neighbours.push_back(board[i+1][j-1]);
        if(i != board.size()-1 and j != board[i].size()-1)
            neighbours.push_back(board[i+1][j+1]);
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> neighbours;
        vector<int> help;
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                findNeighbours(board, i, j, neighbours);
                int one_count = 0, zero_count = 0;
                
                for(int k = 0; k < neighbours.size(); k++)
                {
                    if(neighbours[k] == 1)
                        one_count++;
                    else
                        zero_count++;
                }
                
                if(board[i][j] == 1 and one_count < 2)
                    help.push_back(0);
                else if(board[i][j] == 1 and (one_count == 2 or one_count ==3))
                    help.push_back(1);
                else if(board[i][j] == 1 and one_count > 3)
                    help.push_back(0);
                else if(board[i][j] == 0 and one_count == 3)
                    help.push_back(1);
                else
                    help.push_back(board[i][j]);
                
                neighbours.clear();
            }
        }
        int k = 0;
        while(k < help.size())
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[i].size(); j++)
                    board[i][j] = help[k++];
            }
        }
    }
};