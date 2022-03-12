// Question Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
// Recursive solution

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int row, int col, int n, vector<vector<int>> &m, vector<vector<int>> visited)
    {
        if((row >= 0 and row < n) and (col >= 0 and col < n) and visited[row][col] == 0 and m[row][col] == 1)
            return true;
        else
            return false;
    }
    
    void solve(vector<vector<int>> &m, vector<string>& answer, string s, vector<vector<int>> visited, int row, int col, int n)
    {
        // base case
        if(row == n-1 and col == n-1)
        {
            answer.push_back(s);
            return;
        }
        
        visited[row][col] = 1;
        
        // check for possible solutions and then make recursive calls
        // Up check
        int new_row = row-1;
        int new_col = col;
        if(isSafe(new_row, new_col, n, m, visited))
        {
            s.push_back('U');
            solve(m, answer, s, visited, new_row, new_col, n);
            s.pop_back();
        }
        // Down check
        new_row = row+1;
        new_col = col;
        if(isSafe(new_row, new_col, n, m, visited))
        {
            s.push_back('D');
            solve(m, answer, s, visited, new_row, new_col, n);
            s.pop_back();
        }
        // Right check
        new_row = row;
        new_col = col+1;
        if(isSafe(new_row, new_col, n, m, visited))
        {
            s.push_back('R');
            solve(m, answer, s, visited, new_row, new_col, n);
            s.pop_back();
        }
        // Left check
        new_row = row;
        new_col = col-1;
        if(isSafe(new_row, new_col, n, m, visited))
        {
            s.push_back('L');
            solve(m, answer, s, visited, new_row, new_col, n);
            s.pop_back();
        }
        visited[row][col] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> answer;
        if(m[0][0] == 0)
            return answer;
            
        string s = "";
        vector<vector<int>> visited = m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                visited[i][j] = 0;
        }
        solve(m, answer, s, visited, 0, 0, n);
        sort(answer.begin(), answer.end());
        return answer;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends