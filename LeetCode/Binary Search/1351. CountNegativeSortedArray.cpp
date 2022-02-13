// Binary Search approach giving a m*log(N) time and constant space solution
// Brute Force being O(m*n) time approach
// Apparently the problem can be done in O(m+n) too .. 

int BinarySearch(vector<int> arr)
{
    int start = 0, end = arr.size()-1, middle, c = 0;
    
    while(start <= end)
    {
        middle = start + (end-start)/2;
                    
        if(arr[middle] >= 0)
            start = middle + 1;
        else
        {
            c += end - middle + 1;
            end = middle - 1;
        }
    }
    return c;
}

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negative_count = 0;
        
        for(int i = 0; i < grid.size(); i++)
            negative_count += BinarySearch(grid[i]);
        
        return negative_count;
    }
};