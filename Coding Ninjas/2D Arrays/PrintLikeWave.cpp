// Problem Link: https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=1
// O(m * n) time and constant space solution

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> answer;
    for(int i = 0; i < mCols; i++)
    {
        if(i %2 == 0)
        {
            for(int j = 0; j < nRows; j++)
                answer.push_back(arr[j][i]);
        }
        else
        {
            for(int j = nRows-1; j >= 0; j--)
                answer.push_back(arr[j][i]);
        }
    }
    return answer;
}